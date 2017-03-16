package codejam.qual;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class D {

	private static BufferedReader br;

	private static int numChests;
	private static int startKeysNum;

	private static int leftKeys;
	private static Map<Integer, Integer> keys;
	private static Map<Integer, Set<Integer>> opens;
	private static Map<Integer, Integer> chestToOpenKey;
	private static Map<Integer, Map<Integer, Integer>> chests;

	private static Set<Pair<List<Integer>, Map<Integer, Integer>>> cache;
	private static List<Integer> order;

	private static List<Integer> leftChest;

	public static void main(final String[] args) {
		// setStreams("C:\\Users\\Yariv\\Desktop\\D-small-attempt1");
		br = new BufferedReader(new InputStreamReader(System.in));
		final int numCases = (int) readNumber();
		handleCases(numCases);
	}

	private static void setStreams(final String baseFileName) {
		try {
			System.setIn(new FileInputStream(baseFileName + ".in"));
			System.setOut(new PrintStream(baseFileName + ".out"));
		} catch (final FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	private static void handleCases(final long numCases) {
		for (int i = 1; i <= numCases; i++) {
			handleCase(i);
		}
	}

	private static void handleCase(final int caseNumber) {
		final int[] numbers = readNumbers();
		startKeysNum = numbers[0];
		numChests = numbers[1];

		cache = new HashSet<Pair<List<Integer>, Map<Integer, Integer>>>();
		leftKeys = 0;
		order = new LinkedList<Integer>();
		leftChest = new ArrayList<Integer>();
		for (int i = 1; i <= numChests; i++) {
			leftChest.add(i);
		}
		readKeys();
		readChests();

		// log("Keys: " + keys);
		// log("Opens" + opens);
		// log("chest to open key" + chestToOpenKey);
		// log("Chests: " + chests);

		final boolean success = tryNextChest();
		if (success) {
			System.out.print("Case #" + caseNumber + ":");
			for (final Integer num : order) {
				System.out.print(" " + num);
			}
			System.out.println("");
		} else {
			System.out.println("Case #" + caseNumber + ": IMPOSSIBLE");
		}
	}

	private static boolean tryNextChest() {
		if (cache.contains(new Pair<List<Integer>, Map<Integer, Integer>>(
				leftChest, keys))) {
			return false;
		}
		// log("Chests: " + leftChest + " Left keys: " + leftKeys + " Keys: "
		// + keys);
		if (leftChest.isEmpty()) {
			return true;
		}

		if (leftKeys == 0) {
			cache.add(new Pair<List<Integer>, Map<Integer, Integer>>(
					new ArrayList<Integer>(leftChest), keys));
			return false;
		}
		final List<Integer> funcLeftChests = new ArrayList<Integer>(leftChest);
		int index = -1;
		for (final Integer chest : funcLeftChests) {
			index++;
			final int keyToOpen = chestToOpenKey.get(chest);
			if (!hasKey(keyToOpen)) {
				continue;
			}

			openChest(chest, keyToOpen, index);
			if (tryNextChest()) {
				return true;
			}
			undoOpenChest(chest, keyToOpen, index);
		}

		cache.add(new Pair<List<Integer>, Map<Integer, Integer>>(
				new ArrayList<Integer>(leftChest), keys));
		return false;
	}

	private static void openChest(final int i, final int keyToOpen,
			final int index) {
		final Integer numKeysLeft = keys.get(keyToOpen) - 1;
		keys.put(keyToOpen, numKeysLeft);
		leftChest.remove(index);
		order.add(i);
		leftKeys--;
		final Map<Integer, Integer> keysInChest = chests.get(i);
		for (final Map.Entry<Integer, Integer> entry : keysInChest.entrySet()) {
			final Integer key = entry.getKey();
			final Integer numOfKeys = entry.getValue();

			Integer oldNumOfKeys = keys.get(key);
			if (oldNumOfKeys == null) {
				oldNumOfKeys = 0;
			}
			final Integer newNumOfKeys = oldNumOfKeys + numOfKeys;
			leftKeys += numOfKeys;
			keys.put(key, newNumOfKeys);
		}
	}

	private static void undoOpenChest(final int i, final int keyToOpen,
			final int index) {
		final Integer numKeysLeft = keys.get(keyToOpen) + 1;
		keys.put(keyToOpen, numKeysLeft);
		leftChest.add(index, i);
		order.remove(order.size() - 1);
		leftKeys++;
		final Map<Integer, Integer> keysInChest = chests.get(i);
		for (final Map.Entry<Integer, Integer> entry : keysInChest.entrySet()) {
			final Integer key = entry.getKey();
			final Integer numOfKeys = entry.getValue();

			Integer oldNumOfKeys = keys.get(key);
			if (oldNumOfKeys == null) {
				oldNumOfKeys = 0;
			}
			final Integer newNumOfKeys = oldNumOfKeys - numOfKeys;
			leftKeys -= numOfKeys;
			keys.put(key, newNumOfKeys);
		}
	}

	private static boolean hasKey(final int key) {
		if (keys.get(key) != null && keys.get(key) > 0) {
			return true;
		}

		return false;
	}

	private static void readChests() {
		opens = new HashMap<Integer, Set<Integer>>();
		chests = new HashMap<Integer, Map<Integer, Integer>>();
		chestToOpenKey = new HashMap<Integer, Integer>();
		for (int i = 1; i <= numChests; i++) {
			final Map<Integer, Integer> chestMap = new HashMap<Integer, Integer>();
			final int[] numbers = readNumbers();
			final int toOpen = numbers[0];
			Set<Integer> chestNumsSet = opens.get(toOpen);
			if (chestNumsSet == null) {
				chestNumsSet = new HashSet<Integer>();
			}
			chestNumsSet.add(i);
			chestToOpenKey.put(i, toOpen);
			opens.put(toOpen, chestNumsSet);

			final int keysInside = numbers[1];
			for (int j = 0; j < keysInside; j++) {
				final int key = numbers[2 + j];
				Integer typeInChest = chestMap.get(key);
				if (typeInChest == null) {
					typeInChest = 0;
				}
				chestMap.put(key, typeInChest + 1);
			}

			chests.put(i, chestMap);
		}
	}

	private static void readKeys() {
		keys = new HashMap<Integer, Integer>();
		final int[] nums = readNumbers();
		for (int i = 0; i < startKeysNum; i++) {
			Integer curr = keys.get(nums[i]);
			if (curr == null) {
				curr = 0;
			}
			keys.put(nums[i], curr + 1);
			leftKeys++;
		}
	}

	private static long readNumber() {
		final String line = readLine();
		final long number = Long.parseLong(line);
		return number;
	}

	private static int[] readNumbers() {
		final String line = readLine();
		final String[] numbersStr = line.split(" ");
		final int[] numbers = new int[numbersStr.length];
		for (int i = 0; i < numbersStr.length; i++) {
			numbers[i] = Integer.parseInt(numbersStr[i]);
		}
		return numbers;
	}

	private static String readLine() {
		String line = null;
		try {
			line = br.readLine();
		} catch (final IOException e) {
			e.printStackTrace();
		}
		return line;
	}

	private static void log(final String message) {
		System.out.println(message);
	}

	private static final class Pair<F, S> {
		private F first;
		private S second;

		public Pair(final F first, final S second) {
			this.first = first;
			this.second = second;
		}

		public F getFirst() {
			return first;
		}

		public void setFirst(final F first) {
			this.first = first;
		}

		public S getSecond() {
			return second;
		}

		public void setSecond(final S second) {
			this.second = second;
		}

		@SuppressWarnings("unchecked")
		@Override
		public boolean equals(final Object o) {
			if (!(o instanceof Pair)) {
				return false;
			}

			final Pair<F, S> other = (Pair<F, S>) o;
			return other.first.equals(first) && other.second.equals(second);
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = prime + first.hashCode();
			result = prime * result + second.hashCode();
			return result;
		}
	}
}
