import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import javax.print.attribute.HashAttributeSet;

public class Main {

	private static class Chest {
		private final Integer index;
		private final List<Integer> internalKeys;
		private final Integer key;

		Chest(final Integer index, final Integer key,
				final List<Integer> internalKeys) {
			this.index = index;
			this.key = key;
			this.internalKeys = internalKeys;
		}

		boolean isOpened(final List<Integer> keys) {
			return keys.contains(key);
		}

		boolean canOpen(final Chest chest) {
			return internalKeys.contains(chest.key) && chest != this;
		}

		List<Chest> canOpen(final List<Chest> chests) {
			final List<Chest> result = new ArrayList<Chest>();
			for (final Chest chest : chests) {
				if (canOpen(chest)) {
					result.add(chest);
				}
			}
			return result;
		}

		List<Chest> isOpenedBy(final List<Chest> chests) {
			final List<Chest> result = new ArrayList<Chest>();
			for (final Chest chest : chests) {
				if (chest.canOpen(this)) {
					result.add(chest);
				}
			}
			return result;
		}

		Integer getIndex() {
			return index;
		}

		Integer getKey() {
			return key;
		}

		List<Integer> getInternalKeys() {
			return internalKeys;
		}

	}

	public static void main(String[] args) {
		try {
			//solvefromInputToOutPut("test.in", "test.out");
			solvefromInputToOutPut("D-small-attempt1.in",
			"D-small-attempt1.out");
			// solvefromInputToOutPut("C-large-2.in", "C-large-2.out");
		} catch (NumberFormatException | IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public static void solvefromInputToOutPut(final String inputFileName,
			final String outputFileName) throws NumberFormatException,
			IOException {
		final BufferedReader reader = new BufferedReader(new FileReader(
				inputFileName));
		final int testCases = Integer.parseInt(reader.readLine());
		final List<List<Chest>> chestsSet = new ArrayList<List<Chest>>(
				testCases);
		final List<List<Integer>> keysSet = new ArrayList<List<Integer>>(
				testCases);
		for (int i = 0; i < testCases; i++) {
			String[] line = reader.readLine().split(" ");
			final int k = Integer.parseInt(line[0]);
			final int n = Integer.parseInt(line[1]);
			final List<Integer> keys = new ArrayList<Integer>(k);
			line = reader.readLine().split(" ");
			for (int j = 0; j < k; j++) {
				keys.add(Integer.parseInt(line[j]));
			}
			final List<Chest> chests = new ArrayList<Chest>(n);
			for (int j = 0; j < n; j++) {
				line = reader.readLine().split(" ");
				final int key = Integer.parseInt(line[0]);
				final int number = Integer.parseInt(line[1]);
				final List<Integer> internalKeys = new ArrayList<Integer>(
						number);
				for (int l = 0; l < number; l++) {
					internalKeys.add(Integer.parseInt(line[l + 2]));
				}
				chests.add(new Chest(j + 1, key, internalKeys));
			}
			chestsSet.add(i, chests);
			keysSet.add(i, keys);
		}
		reader.close();
		final List<String> result = sequenceToGold(chestsSet, keysSet);
		final BufferedWriter writer = new BufferedWriter(new FileWriter(
				outputFileName));
		for (int i = 0; i < testCases; i++) {
			writer.write("Case #" + (i + 1) + ": " + result.get(i) + "\n");
		}
		writer.close();
	}

	private static List<String> sequenceToGold(
			final List<List<Chest>> chestsSet, List<List<Integer>> keysSet) {
		final List<String> result = new ArrayList<String>(chestsSet.size());
		for (int i = 0; i < chestsSet.size(); i++) {
			result.add(i, sequence(chestsSet.get(i), keysSet.get(i)));
		}
		return result;
	}

	private static String sequence(final List<Chest> originalChests,
			final List<Integer> originalKeys) {

		final Chest[] seq = sequenceChests(originalChests, originalKeys);
		if (seq == null) {
			return "IMPOSSIBLE";
		}
		String result = ((Integer) seq[0].getIndex()).toString();
		for (int i = 1; i < originalChests.size(); i++) {
			result = result + " " + seq[i].getIndex();
		}
		return result;
	}

	private static Chest[] sequenceChests(final List<Chest> originalChests,
			final List<Integer> originalKeys) {
		final List<Chest> chests = new ArrayList<Chest>(originalChests);
		final List<Integer> keys = new ArrayList<Integer>(originalKeys);
		final Chest[] seq = new Chest[chests.size()];
		int pos = 0;
		while (chests.size() > 0) {
			final Chest chest = selectOptimalChest(chests, keys);
			if (chest == null || !chest.isOpened(keys)) {
				return null;
			}
			chests.remove(chest);
			keys.remove((Integer) chest.getKey());
			keys.addAll(chest.getInternalKeys());
			seq[pos] = chest;
			pos++;
		}
		getLowerSequence(seq, originalChests, originalKeys);
		return seq;
	}

	private static void getLowerSequence(final Chest[] seq,
			final List<Chest> chests, final List<Integer> keys) {
		for (final Chest chest : chests) {
			if (chest.getIndex() <= seq[0].getIndex() && chest.isOpened(keys)) {
				final List<Chest> chestList = new ArrayList<Chest>(chests);
				chestList.remove(chest);
				final List<Integer> keyList = new ArrayList<Integer>(keys);
				keyList.remove((Integer) chest.getKey());
				keyList.addAll(chest.getInternalKeys());
				final Chest[] temp = sequenceChests(chestList, keyList);
				if (temp != null) {
					seq[0] = chest;
					for (int i = 1; i < seq.length; i++) {
						seq[i] = temp[i - 1];
					}
				}
			}
		}
	}

	private static Chest selectOptimalChest(final List<Chest> chests,
			final List<Integer> keys) {
		Chest bestChest = null;
		/*
		 * for (final Chest chest : chests) { if
		 * (chest.isOpenedBy(chests).size() == 0) { if (bestChest == null ||
		 * bestChest.getIndex() > chest.getIndex()) { bestChest = chest; } } }
		 * if (bestChest != null) { return bestChest; }
		 */
		final List<Set<Chest>> sets = getSets(chests, divideInSets(chests));
		for (int i = 0; i < sets.size(); i++) {
			final Set<Chest> setI = sets.get(i);
			boolean top = true;
			for (int j = 0; j < sets.size(); j++) {
				final Set<Chest> setJ = sets.get(j);
				if (i != j) {
					for (final Chest chestI : setI) {
						for (final Chest chestJ : setJ) {
							if (chestI.isOpened(chestJ.internalKeys)) {
								top = false;
								break;
							}
						}
						if (!top) {
							break;
						}
					}
					if (!top) {
						break;
					}
				}
			}
			if (top) {
				final Chest currentBest = selectBest(setI, keys);
				if (currentBest == null) {
					return null;
				} else if (bestChest == null
						|| bestChest.index > currentBest.index) {
					bestChest = currentBest;
				}
			}
		}
		return bestChest;
	}

	private static Chest selectBest(final Set<Chest> set,
			final List<Integer> keys) {
		Chest bestChest = null;
		for (final Chest chest : set) {
			if (chest.isOpened(keys)) {
				if (bestChest == null
						|| bestChest.getIndex() > chest.getIndex()) {
					bestChest = chest;
				}
			}
		}
		return bestChest;
	}

	private static List<Set<Chest>> getSets(final List<Chest> chests,
			final int[] setPositions) {
		final List<Set<Chest>> result = new ArrayList<Set<Chest>>();
		for (int i = 0; i < chests.size(); i++) {
			if (setPositions[i] == i) {
				final Set<Chest> set = new HashSet<Chest>();
				for (int j = 0; j < chests.size(); j++) {
					if (getSetPosition(setPositions, j) == i) {
						set.add(chests.get(j));
					}
				}
				result.add(set);
			}
		}
		return result;
	}

	private static int[] divideInSets(final List<Chest> chests) {
		final List<Set<Chest>> openedByChest = new ArrayList<Set<Chest>>();
		final int[] chestSetPosition = new int[chests.size()];
		final int[] chestSetQuantity = new int[chests.size()];
		for (int i = 0; i < chests.size(); i++) {
			final Set<Chest> set = new HashSet<Chest>();
			canOpen(chests, set, chests.get(i));
			openedByChest.add(i, set);
			chestSetPosition[i] = i;
			chestSetQuantity[i] = 1;
		}
		for (int i = 0; i < chests.size(); i++) {
			final int setPosI = getSetPosition(chestSetPosition, i);
			for (int j = i + 1; j < chests.size(); j++) {
				final int setPosJ = getSetPosition(chestSetPosition, j);
				if (setPosI != setPosJ
						&& openedByChest.get(i).contains(chests.get(j))
						&& openedByChest.get(j).contains(chests.get(i))) {
					if (chestSetQuantity[setPosI] >= chestSetQuantity[setPosJ]) {
						chestSetPosition[setPosJ] = setPosI;
					} else {
						chestSetPosition[setPosJ] = setPosI;
					}
				}
			}
		}
		return chestSetPosition;
	}

	private static int getSetPosition(final int[] positions, final int current) {
		int i = current;
		while (positions[i] != i) {
			i = positions[i];
		}
		return i;
	}

	private static void canOpen(final List<Chest> list,
			final Set<Chest> visited, final Chest current) {
		for (final Chest chest : list) {
			if (!visited.contains(chest) && current.canOpen(chest)) {
				visited.add(chest);
				canOpen(list, visited, chest);
			}
		}
	}

	/*
	 * (non-Java-doc)
	 * 
	 * @see java.lang.Object#Object()
	 */
	public Main() {
		super();
	}

}