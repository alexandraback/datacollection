package in.codejam;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;

public class Treasure {

	public static Scanner in;

	public static void main(String[] args) throws IOException {
		in = new Scanner(System.in);
		in.useDelimiter("\\s+");
		int testCases = readNum();
		File f = new File("/home/vijay/out.txt");
		FileWriter fs = new FileWriter(f);
		String[] results = new String[testCases];
		for (int i = 1; i <= testCases; i++) {
			String solution = solveProblem();
			results[i - 1] = ("Case #" + i + ": " + solution);
			fs.write(results[i - 1]);
			fs.flush();
		}
		for (int i = 0; i < testCases; i++)
			System.out.println(results[i]);
		fs.close();
		in.close();
	}

	private static String solveProblem() {
		int myKeysCount = readNum();
		int numChests = readNum();
		List<Integer> myKeys = new ArrayList<Integer>();
		for (int i = 0; i < myKeysCount; i++) {
			myKeys.add(readNum());
		}
		List<Chest> chestsList = new ArrayList<Treasure.Chest>();
		for (int i = 1; i <= numChests; i++) {
			int chestKey = readNum();
			int numKeysInside = readNum();
			Chest c = new Chest(i, chestKey);
			for (int j = 0; j < numKeysInside; j++) {
				c.keysContained.add(readNum());
			}
			chestsList.add(c);
		}

		List<Integer> chestsOrdering = getChestOrdering(chestsList, myKeys, 0);
		if (chestsOrdering == null)
			return "IMPOSSIBLE";
		StringBuffer bf = new StringBuffer();
		for (Integer i : chestsOrdering) {
			bf.append(i + " ");
		}
		return bf.toString().trim();
	}

	public static List<Integer> getChestOrdering(List<Chest> chests,
			List<Integer> keys, int depth) {
		List<Integer> ordering = new ArrayList<Integer>();
		if (keys.size() == 0 && chests.size() > 0) {
			return null;
		}
		if (chests.size() == 0) {
			return ordering;
		}
		Iterator<Chest> it = chests.iterator();
		while (it.hasNext()) {
			Chest c = it.next();
			if (!keys.contains(Integer.valueOf(c.keyRequired))) {
				continue;
			}
			List<Chest> copy = new ArrayList<Treasure.Chest>(chests);
			List<Integer> keysCopy = new ArrayList<Integer>(keys);
			copy.remove(c);
			keysCopy.remove(Integer.valueOf(c.keyRequired));
			keysCopy.addAll(c.keysContained);
			if (copy.size() == 0) {
				ordering.add(c.chestNum);
				return ordering;
			}
			boolean solutionPossible = solutionPossible(copy, keysCopy);
			if (!solutionPossible) {
				continue;
			}
			List<Integer> subordering = getChestOrdering(copy, keysCopy,
					depth + 1);
			if (subordering != null) {
				ordering.add(c.chestNum);
				ordering.addAll(subordering);
				return ordering;
			}
		}
		return null;
	}

	public static boolean solutionPossible(List<Chest> chests,
			List<Integer> keys) {
		HashMap<Integer, Integer> availableKeys = new HashMap<Integer, Integer>();
		HashMap<Integer, Integer> requiredKeys = new HashMap<Integer, Integer>();
		HashMap<Integer, Integer> lockedKeys = new HashMap<Integer, Integer>();
		for (Integer key : keys)
			putKey(availableKeys, key);
		for (Chest c : chests) {
			putKey(requiredKeys, c.keyRequired);
			List<Integer> chestKeys = new ArrayList<Integer>(c.keysContained);
			for (Integer key : chestKeys)
				putKey(availableKeys, key);
			if (chestKeys.contains(c.keyRequired))
				putKey(lockedKeys, c.keyRequired);
		}
		// For every required key, make sure that number of keys required is
		// greater than locked keys
		for (Integer key : requiredKeys.keySet()) {
			int required = requiredKeys.get(key);
			Integer available = availableKeys.get(key);
			if (available == null)
				return false;
			if (required > available.intValue())
				return false;
			if (lockedKeys.containsKey(key)) {
				int locked = lockedKeys.get(key);
				if (available <= locked)
					return false;
			}
		}
		return true;
	}

	public static void putKey(HashMap<Integer, Integer> map, Integer key) {
		if (map.containsKey(key))
			map.put(key, map.get(key) + 1);
		else
			map.put(key, 1);
	}

	public static class Chest implements Comparable<Chest> {
		public final int chestNum;
		public final int keyRequired;
		public List<Integer> keysContained = new ArrayList<Integer>();

		public Chest(int chestNum, int keyRequired) {
			this.chestNum = chestNum;
			this.keyRequired = keyRequired;
		}

		public int compareTo(Chest o) {
			return Integer.valueOf(chestNum).compareTo(
					Integer.valueOf(o.chestNum));
		}

		public String toString() {
			return "{n:" + chestNum + ", key:" + keyRequired + ", keys:"
					+ keysContained + "}";
		}
	}

	public static int readNum() {
		int i = in.nextInt();
		return i;
	}

}
