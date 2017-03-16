package codejam2013;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class Treasure2 {
	private static final int MAX_CHESTS = 201;

	private static class Chest implements Comparable<Chest> {
		private Map<Integer, Integer> keys;
		private int canOpenChests = 0;
		private int id;
		private int index;
		private ChestPriorityQueue queue;

		public Chest(int id) {
			this.id = id;
			this.keys = new HashMap<Integer, Integer>();
		}

		public void add(int key) {
			if (keys.containsKey(key)) {
				keys.put(key, keys.get(key) + 1);
			} else {
				keys.put(key, 1);
			}
		}

		public void appendSelf(Map<Integer, List<Chest>> insideKeyToChests) {
			for (Map.Entry<Integer, Integer> entry : keys.entrySet()) {
				int key = entry.getKey();
				int value = entry.getValue();
				if (value > 0) {
					List<Chest> chests = insideKeyToChests.get(key);
					if (chests == null) {
						chests = new ArrayList<Chest>();
						insideKeyToChests.put(key, chests);
					}
					chests.add(this);
				}
			}
		}

		public void addOwnKeys(Map<Integer, Integer> chestKeys) {
			for (Map.Entry<Integer, Integer> entry : keys.entrySet()) {
				Integer value = chestKeys.get(entry.getKey());
				if (value == null) {
					value = 0;
				}
				value += entry.getValue();

				if (value > 0) {
					chestKeys.put(entry.getKey(), value);
				}
			}
		}

		public void update(Map<Integer, List<Chest>> insideKeyToChests, int key) {
			Integer value = keys.get(key);
			if (value != null && value > 0) {
				List<Chest> chests = insideKeyToChests.get(key);
				for (Chest chest : chests) {
					chest.queue.decreaseKey(chest.getIndex(), key);
				}
			}
		}

		public void computeChestPotential(
				Map<Integer, Set<Integer>> keyToChestsMap) {
			canOpenChests = 0;
			for (Map.Entry<Integer, Integer> entry : keys.entrySet()) {
				int key = entry.getKey();
				int value = entry.getValue();
				Set<Integer> chests = keyToChestsMap.get(key);
				if (chests != null) {
					int chestCount = chests.size();
					if (chests.contains(id)) {
						chestCount--;
					}
					value = Math.min(chestCount, value);
					entry.setValue(value);
					canOpenChests += value;
				}
			}
		}

		public void setIndex(int index) {
			this.index = index;
		}

		public int getIndex() {
			return index;
		}

		public void setQueue(ChestPriorityQueue queue) {
			this.queue = queue;
		}

		public boolean decreaseKey(int key) {
			Integer value = keys.get(key);
			if (value != null && value > 0) {
				keys.put(key, value - 1);
				canOpenChests--;
				return true;
			}

			return false;
		}

		@Override
		public int compareTo(Chest o) {
			int diff = o.canOpenChests - this.canOpenChests;
			if (diff != 0) {
				return diff;
			}

			return this.id - o.id;
		}

		public String toString() {
			return String.format("(%d %d)", canOpenChests, id);
		}
	}

	private static class ChestPriorityQueue {

		private Chest[] chests = new Chest[MAX_CHESTS];
		private int size = 0;

		private void siftDown(int index) {
			int childIndex = 2 * index + 1;
			while (childIndex < size) {
				if (childIndex + 1 < size
						&& chests[childIndex].compareTo(chests[childIndex + 1]) > 0) {
					childIndex++;
				}
				if (chests[index].compareTo(chests[childIndex]) > 0) {
					// swap
					Chest child = chests[childIndex];
					chests[childIndex] = chests[index];
					chests[index] = child;

					// update indices
					child.setIndex(index);
					chests[childIndex].setIndex(childIndex);
					index = childIndex;
					childIndex = 2 * index + 1;
				} else {
					break;
				}
			}
		}

		private void siftUp(int index) {
			Chest initialChest = chests[index];
			int currentIndex = index;
			int parentIndex = (currentIndex - 1) / 2;
			while (currentIndex > 0
					&& chests[currentIndex].compareTo(chests[parentIndex]) < 0) {
				chests[currentIndex] = chests[parentIndex];
				chests[currentIndex].setIndex(currentIndex);
				currentIndex = parentIndex;
				parentIndex = (currentIndex - 1) / 2;
			}

			// swap index with currentIndex
			chests[currentIndex] = initialChest;
			chests[currentIndex].setIndex(currentIndex);
		}

		public boolean offer(Chest chest) {
			if (size >= chests.length) {
				return false;
			}

			chests[size++] = chest;
			chest.setIndex(size - 1);
			siftUp(size - 1);
			return true;
		}

		public Chest peek() {
			if (size == 0) {
				return null;
			}
			return chests[0];
		}

		public Chest poll() {
			if (size < 1) {
				return null;
			}

			Chest chest = chests[0];
			chests[0] = chests[size - 1];
			chests[size - 1] = null;
			size--;
			if (size > 0) {
				chests[0].setIndex(0);
			}
			siftDown(0);

			return chest;
		}

		public void decreaseKey(int index, int key) {
			if (index < size && chests[index].decreaseKey(key)) {
				siftDown(index);
			}
		}

		public String toString() {
			return Arrays.toString(chests);
		}
	}

	public static String getSolution(int N, Map<Integer, Integer> initialKeys,
			Map<Integer, Set<Integer>> keyToChestsMap, Chest[] chests) {
		Map<Integer, ChestPriorityQueue> keyToPriority = new HashMap<Integer, ChestPriorityQueue>();
		Map<Integer, List<Chest>> insideKeyToChests = new HashMap<Integer, List<Chest>>();

		// compute opening potentials
		for (int i = 1; i < chests.length; ++i) {
			chests[i].computeChestPotential(keyToChestsMap);
			chests[i].appendSelf(insideKeyToChests);
		}

		for (Map.Entry<Integer, Set<Integer>> entry : keyToChestsMap.entrySet()) {
			ChestPriorityQueue queue = new ChestPriorityQueue();
			keyToPriority.put(entry.getKey(), queue);

			for (int id : entry.getValue()) {
				queue.offer(chests[id]);
				chests[id].setQueue(queue);
			}
		}

		return computeSolution(N, initialKeys, keyToPriority, insideKeyToChests);
	}

	public static String computeSolution(int N,
			Map<Integer, Integer> initialKeys,
			Map<Integer, ChestPriorityQueue> keyToPriority,
			Map<Integer, List<Chest>> insideKeyToChests) {
		StringBuilder builder = new StringBuilder();
		int openedCount = 0;

		Chest minChest = null;

		do {
			minChest = null;
			ChestPriorityQueue minQueue = null;
			int minKey = 0;

			for (Map.Entry<Integer, Integer> entry : initialKeys.entrySet()) {
				int key = entry.getKey();
				int value = entry.getValue();
				if (value < 1) {
					continue;
				}

				ChestPriorityQueue queue = keyToPriority.get(key);
				if (queue == null) {
					continue;
				}

				Chest current = queue.peek();
				if (current != null) {
					if (minChest == null || minChest.id > current.id) {
						minChest = current;
						minQueue = queue;
						minKey = key;
					}
				}
			}

			if (minQueue != null) {
				// open chest and remove it from queue
				minChest = minQueue.poll();
				builder.append(minChest.id).append(" ");

				// update the keys with the new key set
				minChest.addOwnKeys(initialKeys);

				// update chest potential
				minChest.update(insideKeyToChests, minKey);

				// remove key used to open chest
				int count = initialKeys.get(minKey);
				count--;
				if (count < 1) {
					initialKeys.remove(minKey);
				} else {
					initialKeys.put(minKey, count);
				}

				openedCount++;
			}
		} while (minChest != null);

		return openedCount < N ? "IMPOSSIBLE" : builder.toString().substring(0,
				builder.length() - 1);
	}

	public static void solve(String fileName, String outputFileName)
			throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(
				new FileInputStream(fileName)));
		PrintWriter writer = new PrintWriter(outputFileName);

		int testCases = Integer.parseInt(reader.readLine());
		for (int t = 0; t < testCases; ++t) {
			String[] splits = reader.readLine().split(" ");
			int K = Integer.parseInt(splits[0]);
			int N = Integer.parseInt(splits[1]);

			// parse keys
			Map<Integer, Integer> initialKeys = new HashMap<Integer, Integer>();
			splits = reader.readLine().split(" ");
			for (int i = 0; i < K; ++i) {
				int key = Integer.parseInt(splits[i]);
				if (initialKeys.containsKey(key)) {
					initialKeys.put(key, initialKeys.get(key) + 1);
				} else {
					initialKeys.put(key, 1);
				}
			}

			// parse chests
			Map<Integer, Set<Integer>> keyToChestsMap = new HashMap<Integer, Set<Integer>>();
			// Map<Integer, Map<Integer, Integer>> chestToKeysMap = new
			// HashMap<Integer, Map<Integer, Integer>>();
			Chest[] chests = new Chest[N + 1];

			for (int i = 0; i < N; ++i) {
				splits = reader.readLine().split(" ");

				// key to open chest "i + 1"
				int key = Integer.parseInt(splits[0]);
				Set<Integer> set = keyToChestsMap.get(key);
				if (set == null) {
					set = new HashSet<Integer>();
					keyToChestsMap.put(key, set);
				}
				set.add(i + 1);

				Chest chest = new Chest(i + 1);
				chests[i + 1] = chest;

				// keys inside chest
				int keysCount = Integer.parseInt(splits[1]);
				for (int j = 0; j < keysCount; ++j) {
					chest.add(Integer.parseInt(splits[j + 2]));
				}
			}

			String result = getSolution(N, initialKeys, keyToChestsMap, chests);
			writer.format("Case #%d: %s\n", t + 1, result);
		}

		writer.close();
		reader.close();
	}

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		solve("D-small-attempt2.in", "D.out");
	}

}
