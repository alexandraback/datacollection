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
public class Treasure extends Problem {

	private BitSet current;
	private Set<Object> tried;
	private int N;
	private int opened;
	private int hand[];
	private Chest[] chests;
	private int[] order;

	public Treasure() {
		super("D", false);
	}

	@Override
	protected String solve(Scanner in) {
		int K = in.nextInt();
		N = in.nextInt();
		
		hand = new int[201];
		
		for (int i=0;i<K;i++) {
			int t = in.nextInt();
			hand[t]++;
		}
		
		
		chests = new Chest[N];
		
		for (int i=0;i<N;i++) {
			Chest ch = new Chest();
			chests[i] = ch;
			
			ch.open = in.nextInt();
			
			int Ki = in.nextInt();
			
			for (int j=0;j<Ki;j++) {
				ch.keys.add(in.nextInt());
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
		
		for (int i=0;i<N;i++) {
			if (!current.get(i)) {
				Chest ch = chests[i];
				if (hand[ch.open]>0) {
					order[opened] = i+1;
					ch.open();
					current.set(i);
					search();
					current.clear(i);
					ch.unopen();
				}
			}
		}
		
		
		
	}
	
	class Chest {
		int open;
		Multiset<Integer> keys = HashMultiset.create();
		
		void open() {
			hand[open]--;
			for (Multiset.Entry<Integer> entry : keys.entrySet()) {
				hand[entry.getElement()]+=entry.getCount();
			}
			opened++;
		}
		
		void unopen() {
			opened--;
			for (Multiset.Entry<Integer> entry : keys.entrySet()) {
				hand[entry.getElement()]-=entry.getCount();
			}
			hand[open]++;
		}
	}

	@SuppressWarnings("serial")
	class End extends RuntimeException {
		
	}
	
}
