import java.util.*;
import java.io.*;
public class Treasure {
	public static void main(String[] args) {
		String inputfile = args[0];
		BufferedReader input;
		try {
			input = new BufferedReader(new FileReader(inputfile));
		} catch (FileNotFoundException e) {
			System.err.println("File not found");
			return;
		}
		Scanner s = new Scanner(input);
		int T = s.nextInt();
		nextCase:
		for (int x = 1; x <=T; x++) {
			int K = s.nextInt();
			int N = s.nextInt();
			int totalKeys = K;
			TreeMap<Integer, Integer> keysInHand = new TreeMap<Integer, Integer>();
			int[] spareKeys = new int[201];
			for (int i = 0; i < K; i++) {
				int key = s.nextInt();
				spareKeys[key]++;
				addKey(keysInHand, key);
			}
			ArrayList<Chest> chest = new ArrayList<Chest>();
			for (int i = 0; i < N; i++) {
				int requiredKey = s.nextInt();
				spareKeys[requiredKey]--;
				chest.add(new Chest(requiredKey));
				int numKeysInside = s.nextInt();
				totalKeys += numKeysInside;
				for (int j = 0; j < numKeysInside; j++) {
					int key = s.nextInt();
					spareKeys[key]++;
					addKey(chest.get(i).keysInside, key);
				}
			}
			if (totalKeys < N) {
				System.out.println("Case #" + x + ": IMPOSSIBLE");
				continue;
			}
			for (int i = 0; i < 201; i++) {
				if (spareKeys[i] < 0) {
					System.out.println("Case #" + x + ": IMPOSSIBLE");
					continue nextCase;
				}
			}
			sequence = new LinkedList<Integer>();
			if (unlock(keysInHand, chest)) {
				System.out.print("Case #" + x + ":");
				for (int number : sequence) {
					System.out.print(" " + (number+1));
				}
				System.out.println();
			} else {
				System.out.println("Case #" + x + ": IMPOSSIBLE");
			}
		}
	}

	public static void addKey(TreeMap<Integer, Integer> keys, int newKey) {
		Integer numPresent = keys.get(newKey);
		if (numPresent == null) {
			keys.put(newKey, 1);
		} else {
			keys.put(newKey, numPresent+1);
		}
	}

	public static void addKeys(TreeMap<Integer, Integer> keys, int newKey, int number) {
		Integer numPresent = keys.get(newKey);
		if (numPresent == null) {
			keys.put(newKey, number);
		} else {
			keys.put(newKey, numPresent+number);
		}
	}

	public static void removeKey(TreeMap<Integer, Integer> keys, int key) {
		Integer numPresent = keys.get(key);
		if (numPresent == 1) {
			keys.remove(key);
		} else {
			keys.put(key, numPresent-1);
		}
	}

	public static void removeKeys(TreeMap<Integer, Integer> keys, int key, int number) {
		Integer numPresent = keys.get(key);
		if (numPresent == number) {
			keys.remove(key);
		} else {
			keys.put(key, numPresent-number);
		}
	}

	static LinkedList<Integer> sequence;
	public static boolean unlock(TreeMap<Integer, Integer> keysInHand, ArrayList<Chest> chest) {
		for (int i = 0; i < chest.size(); i++) {
			if (chest.get(i).isClosed) {
				Integer numKeys = keysInHand.get(chest.get(i).requiredKeyType);
				if (numKeys != null) {
					// We can open this chest.
					//System.out.println("Chest Opened: " + (i+1));
					chest.get(i).isClosed = false;
					sequence.addLast(i);
					// Remove this key from keysInHand.
					removeKey(keysInHand, chest.get(i).requiredKeyType);
					// Add keys present in this chest.
					for (Map.Entry<Integer, Integer> entry : chest.get(i).keysInside.entrySet()) {
						int key = entry.getKey();
						int number = entry.getValue();
						addKeys(keysInHand, key, number);
					}
					if (unlock(keysInHand, chest)) {
						return true;
					} else {
						// Revert this change.
						//System.out.println("Chest Closed: " + (i+1));
						chest.get(i).isClosed = true;
						sequence.removeLast();
						// Remove keys present in this chest.
						for (Map.Entry<Integer, Integer> entry : chest.get(i).keysInside.entrySet()) {
							int key = entry.getKey();
							int number = entry.getValue();
							removeKeys(keysInHand, key, number);
						}
						// Add key which opened this chest.
						addKey(keysInHand, chest.get(i).requiredKeyType);
					}
				}
			}
		}
		for (int i = 0; i < chest.size(); i++) {
			if (chest.get(i).isClosed) {
				return false;
			}
		}
		return true;
	}
}

class Chest {
	Integer requiredKeyType;
	boolean isClosed;
	TreeMap<Integer, Integer> keysInside;

	public Chest (int key) {
		requiredKeyType = key;
		keysInside = new TreeMap<Integer, Integer>();
		isClosed = true;
	}
}
