import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Treasure {

	private static final int MAX_KEYS = 40;
	private Chest[] chests;
	private int[] haveKeys;
	private int numKeys;
	private ArrayList<Integer> sequence;
	private HashMap<Integer, Boolean> checkRepeatedStatus; 

	public Treasure(ArrayList<Integer> startKeys, Chest[] chests) {
		this.chests = chests;
		haveKeys = new int[MAX_KEYS];
		for (Integer key : startKeys)
			haveKeys[key]++;
		numKeys = startKeys.size();
		sequence = new ArrayList<Integer>();
		checkRepeatedStatus = new HashMap<Integer, Boolean>();
	}

	private String solve() {
		if (numKeys == 0)
			return "IMPOSSIBLE";
		int chestOpenStatus = 0;
		if (dfs(0, chestOpenStatus))
			return printSequence();
		else
			return "IMPOSSIBLE";
	}

	private String printSequence() {
		String result = "";
		for (Integer index : sequence)
			result = result + String.format("%d ", index + 1);
		return result.trim();
	}

	private boolean dfs(int depth, int chestOpenStatus) {
		if (checkRepeatedStatus.containsKey(chestOpenStatus))
			return false;
		checkRepeatedStatus.put(chestOpenStatus, true);
		//System.out.println(depth);
		if (depth == chests.length)
			return true;
		for (int i = 0; i < chests.length; i++) {
			if (canOpenChest(i, chestOpenStatus)) {
				// open chest
				int[] keys = haveKeys.clone();
				haveKeys[chests[i].requireKey]--;
				for (int j = 0; j < chests[i].containKeys.length; j++)
					haveKeys[chests[i].containKeys[j]]++;
				int temp = chestOpenStatus;
				chestOpenStatus += Math.pow(2, i);
				sequence.add(i);
				if (dfs(depth + 1, chestOpenStatus))
					return true;
				haveKeys = keys;
				chestOpenStatus = temp;
				sequence.remove(sequence.size() - 1);
			}
		}
		return false;
	}

	private boolean canOpenChest(int index, int chestOpenStatus) {
		if ((haveKeys[chests[index].requireKey] > 0) && ((chestOpenStatus & (int) (Math.pow(2, index))) == 0))
			return true;
		return false;
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int numSets = scanner.nextInt();
		for (int i = 0; i < numSets; i++) {
			int numKeys = scanner.nextInt();
			int numChests = scanner.nextInt();
			ArrayList<Integer> startKeys = new ArrayList<Integer>();
			for (int j = 0; j < numKeys; j++) {
				startKeys.add(scanner.nextInt());
			}
			Chest[] chests = new Chest[numChests];
			for (int j = 0; j < numChests; j++) {
				int requireKey = scanner.nextInt();
				int[] containKeys = new int[scanner.nextInt()];
				for (int k = 0; k < containKeys.length; k++) {
					containKeys[k] = scanner.nextInt();
				}
				chests[j] = new Chest(requireKey, containKeys);
			}
			System.out.println("Case #" + (i + 1) + ": " + new Treasure(startKeys, chests).solve());
		}
	}
}

class Chest {
	int requireKey;
	int[] containKeys;

	Chest(int requireKey, int[] containKeys) {
		this.requireKey = requireKey;
		this.containKeys = containKeys;
	}
}
