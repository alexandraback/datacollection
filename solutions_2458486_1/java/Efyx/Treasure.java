package gcj2013.D;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Treasure {
	public static void main(String args[]) throws FileNotFoundException {
		Scanner scanner = new Scanner(new File(args[0]));
		
		int T = scanner.nextInt();
		for(int t=0; t<T; t++) {
			int K = scanner.nextInt();
			int N = scanner.nextInt();
			
			Trousseau trousseau = new Trousseau();
			for(int k=0; k<K; k++) {
				int key = scanner.nextInt();
				trousseau.add(key, 1); 
			}
			
			Chest chests[] = new Chest[N];
			for(int n=0; n<N; n++) {
				chests[n] = new Chest();
				chests[n].key = scanner.nextInt();
				chests[n].keys = new int[scanner.nextInt()];
				for(int k=0; k<chests[n].keys.length; k++) {
					chests[n].keys[k] = scanner.nextInt();
				}
			}
			
			String result = openChests(trousseau, chests, chests.length);
			if(result == null) {
				result = "IMPOSSIBLE";
			}
			
			System.out.println("Case #" + (t+1) + ": " + result);
		}
	}

	private static String openChests(Trousseau trousseau, Chest[] chests, int toOpen) {
		if(!quickCheck(trousseau, chests)) {
			return null;
		}
		
		toOpen--;
		for(int i=0; i<chests.length; i++) {
			Chest chest = chests[i];
			if((!chest.opened) && trousseau.keys[chest.key] > 0) {
				chest.open(trousseau);
				
				if(toOpen == 0) {
					return Integer.toString(i+1);
				}
				
				if(trousseau.numKeys > 0) {
					String order = openChests(trousseau, chests, toOpen);
					if(order != null) {
						// found the solution
						return (i+1) + " " + order;
					}
				}
					
				// restore previous state
				chest.close(trousseau);
			}
		}
		return null;
	}
	
	// Return false if all chests cannot be solved
	// true if unsure
	private static boolean quickCheck(Trousseau trousseau, Chest[] chests) {
		int [] totalKeys = new int[400];
		int [] neededKeys = new int[400];
		for(Chest chest : chests) {
			chest.visited = chest.opened;
			if(!chest.opened) {
				neededKeys[chest.key]++;
			}
		}
		for(int k=0; k<trousseau.keys.length; k++) {
			totalKeys[k] = trousseau.keys[k];
		}
		boolean finished;
		do {
			finished = true;
			for(Chest chest : chests) {
				if((!chest.visited) && totalKeys[chest.key] > 0) {
					chest.visited = true;
					finished = false;
					for(int key : chest.keys) {
						totalKeys[key]++;
					}
				}
			}
		} while(!finished);
		
		return checkEnoughKeys(totalKeys, neededKeys);
	}
	
	private static boolean checkEnoughKeys(int[] totalKeys, int[] neededKeys) {
		for(int i=0; i<totalKeys.length; i++) {
			if(totalKeys[i] < neededKeys[i]) {
				return false;
			}
		}
		return true;
	}
}

class Chest {
	int key; // key type to open the chest
	int keys[]; // list of key types inside the chest
	boolean opened;
	boolean visited;
	
	void open(Trousseau trousseau) {
		opened = true;
		trousseau.add(key, -1);
		for(int key : keys) {
			trousseau.add(key, 1);
		}
	}
	
	void close(Trousseau trousseau) {
		for(int key : keys) {
			trousseau.add(key, -1);
		}
		trousseau.add(key, 1);
		opened = false;
	}
}

class Trousseau {
	int keys[] = new int[400];
	int numKeys = 0;
	
	void add(int key, int n) {
		keys[key] += n;
		numKeys += n;
	}
}
