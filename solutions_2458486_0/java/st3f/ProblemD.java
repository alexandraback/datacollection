import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

class Chest implements Comparable<Chest> {
	int no;
	int keyToOpen;
	List<Integer> keysInside = new ArrayList<Integer>();

	public int compareTo(Chest arg0) {
		return no - arg0.no;
	}
	
	public boolean dominates(Chest c) {
		int i = 0;
		int j = 0;
		while (i < keysInside.size() && j < c.keysInside.size()) {
			int ki = keysInside.get(i);
			int kj = c.keysInside.get(j);
			if (ki < kj) {
				i++;
			} else if (ki == kj) {
				i++;
				j++;
			} else {
				return false;
			}
		}
		return j == c.keysInside.size();
	}
	
	public boolean isDominatedByAny(List<Chest> l) {
		for (Chest c : l)
			if (c.dominates(this))
				return true;
		return false;
	}
}

class KeyRing {
	Map<Integer, Integer> keys = new HashMap<Integer, Integer>();

	void addKey(int type) {
		Integer count = keys.get(type);
		if (count == null)
			count = 0;
		count++;
		keys.put(type, count);
	}

	void removeKey(int type) {
		int count = keys.get(type);
		count--;
		if (count == 0)
			keys.remove(type);
		else
			keys.put(type, count);
	}

	boolean containsKey(int type) {
		return keys.containsKey(type);
	}
}

public class ProblemD {
	static Scanner sc;
	static PrintStream ps;

	static KeyRing keyRing;
	static List<Chest> closed;
	static List<Chest> open;
	static List<List<Chest>> tried;
	
	static int insertPos;
	static int index;
	
	static void choose() {
		insertPos = open.size();
		for (index = 0; index < closed.size(); index++)
			if (keyRing.containsKey(closed.get(index).keyToOpen))
				return;
		
		for (insertPos = open.size() - 1; insertPos >= 0; insertPos--) {
			int keyToUse = open.get(insertPos).keyToOpen;
			for (index = 0; index < closed.size(); index++) {
				Chest chest = closed.get(index);
				if (chest.keyToOpen == keyToUse && !chest.isDominatedByAny(tried.get(insertPos)))
					return;
			}
		}
	}
	
	
	
	static void nextCase() {
		int k = sc.nextInt();
		int n = sc.nextInt();
		System.out.println("n = " + n);
		keyRing = new KeyRing();
		for (int i = 0; i < k; i++)
			keyRing.addKey(sc.nextInt());
		closed = new ArrayList<Chest>();
		for (int i = 1; i <= n; i++) {
			Chest chest = new Chest();
			chest.no = i;
			chest.keyToOpen = sc.nextInt();
			int ki = sc.nextInt();
			for (int j = 0; j < ki; j++)
				chest.keysInside.add(sc.nextInt());
			Collections.sort(chest.keysInside);
			closed.add(chest);
		}
		
		open = new ArrayList<Chest>();
		tried = new ArrayList<List<Chest>>();
		tried.add(new ArrayList<Chest>());
		
		choose();
		while (insertPos >= 0) {
			Chest selected = closed.remove(index);
			
			while (open.size() > insertPos) {
				Chest chest = open.remove(open.size() - 1);
				tried.remove(tried.size() - 1);
				int i = -Collections.binarySearch(closed, chest) - 1;
				closed.add(i, chest);
				keyRing.addKey(chest.keyToOpen);
				for (int type : chest.keysInside)
					keyRing.removeKey(type);
			}
			
//			for (Chest ch : closed)
//				System.out.printf("%3d", ch.no);
//			System.out.println();
			
			open.add(selected);
			tried.get(tried.size() - 1).add(selected);
			tried.add(new ArrayList<Chest>());
			for (int type : selected.keysInside)
				keyRing.addKey(type);
			keyRing.removeKey(selected.keyToOpen);
			choose();
		}
	}

	static void printSol() {
		if (!closed.isEmpty()) 
			ps.println(" IMPOSSIBLE");
		else {
			for (Chest chest : open)
				ps.print(" " + chest.no);
			ps.println();
		}
	}

	public static void main(String[] args) throws FileNotFoundException {
		sc = new Scanner(new File(args[0] + ".in"));
		ps = new PrintStream(args[0] + ".out");
		int t = sc.nextInt();
		sc.nextLine();

		for (int c = 1; c <= t; c++) {
			System.out.printf("Case #%d: ", c);
			nextCase();
			ps.printf("Case #%d:", c);
			printSol();
		}
	}
}
