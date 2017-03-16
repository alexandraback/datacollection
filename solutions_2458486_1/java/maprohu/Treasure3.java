package com.google.codejam;

import hu.mapro.jam.commons.Problem;

import java.util.BitSet;
import java.util.Scanner;
import java.util.Set;

import com.google.common.base.Joiner;
import com.google.common.collect.HashMultiset;
import com.google.common.collect.Multiset;
import com.google.common.collect.Sets;
import com.google.common.primitives.Ints;

/**
 *  Using <a href="http://code.google.com/p/maprohu-codejam-lib/">Google Code Jam library</a>. 
 */
public class Treasure3 extends Problem {

	private static final int T = 201;
	
	private BitSet current;
	private Set<Object> tried;
	private int N;
	private int opened;
	private int hand[];
	private Chest[] chests;
	private int[] order;

	private Multiset<Integer> keyRequired;

	private HashMultiset<Object> keyAvailable;

	private boolean[] chestAccessible;

	public Treasure3() {
		super("D", false);
	}

	@Override
	protected String solve(Scanner in) {
		int K = in.nextInt();
		N = in.nextInt();
		
		hand = new int[T];
		
		for (int i=0;i<K;i++) {
			int t = in.nextInt();
			hand[t]++;
		}
		
		
		chests = new Chest[N];
		
		keyRequired = HashMultiset.create();
		keyAvailable = HashMultiset.create();
		
		for (int i=0;i<N;i++) {
			Chest ch = new Chest();
			chests[i] = ch;
			
			ch.id = i;
			ch.open = in.nextInt();
			keyRequired.add(ch.open);
			
			int Ki = in.nextInt();
			
			for (int j=0;j<Ki;j++) {
				int key = in.nextInt();
				ch.keys.add(key);
				keyAvailable.add(key);
			}
		}
		
		tried = Sets.newHashSet();
		
		current = new BitSet(N);
		
		opened = 0;
		
		order = new int[N];
		
		
		
		try {
			search();
			return "IMPOSSIBLE";
		} catch (End e) {
			return Joiner.on(" ").join(Ints.asList(order));
		}
	}

	void search() {
		if (opened==N) {
			throw new End();
		}
		
		if (tried.contains(current)) 
			return;
		
		tried.add(current.clone());
		
		if (!hasSolution()) 
			return;
		
		for (int i=0;i<N;i++) {
			Chest ch = chests[i];
			if (!ch.isOpen()) {
				if (hand[ch.open]>0) {
					ch.open();
					search();
					ch.unopen();
				}
			}
		}
		
		
		
	}
	
	
	
	private boolean hasSolution() {
		chestAccessible = new boolean[N];
		
		for (Chest ch : chests) {
			if (!ch.isOpen() && hand[ch.open]>0) {
				ch.access();
			}
		}

		for (Chest ch : chests) {
			if (!ch.isOpen() && !chestAccessible[ch.id]) {
				return false;
			}
		}
		
		Multiset<Integer> keysAccessible = HashMultiset.create();
		
		for (Chest ch : chests) {
			if (!ch.isOpen()) {
				keysAccessible.addAll(ch.keys);
			}
		}
		
		for (Multiset.Entry<Integer> entry : keyRequired.entrySet()) {
			if (entry.getCount() > hand[entry.getElement()] + keysAccessible.count(entry.getElement())) {
				return false;
			}
		}
		
		
		
		return true;
	}

	class Chest {
		int id;
		int open;
		Multiset<Integer> keys = HashMultiset.create();
		int[] keysArray = new int[T]; 
		
		void open() {
			order[opened] = id+1;
			hand[open]--;
			for (Multiset.Entry<Integer> entry : keys.entrySet()) {
				hand[entry.getElement()]+=entry.getCount();
			}
			opened++;
			current.set(id);
			keyRequired.remove(open);
		}
		
		public void access() {
			if (chestAccessible[id]) return;
			chestAccessible[id] = true;
			
			for (Chest ch : chests) {
				if (!ch.isOpen() && keys.contains(ch.open)) {
					ch.access();
				}
			}
		}

		void unopen() {
			keyRequired.add(open);
			current.clear(id);
			opened--;
			for (Multiset.Entry<Integer> entry : keys.entrySet()) {
				hand[entry.getElement()]-=entry.getCount();
			}
			hand[open]++;
		}
		
		boolean isOpen() {
			return current.get(id);
		}
	}

	@SuppressWarnings("serial")
	class End extends RuntimeException {
		
	}
	
}
