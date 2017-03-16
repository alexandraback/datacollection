import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


public class Treasure {

	static String filePath = //"files/test.in"; 
			"files/D-small-attempt1.in";
	static int currentResultPath[];
	static boolean haveResult;
	static List<Chest> chests;
	public static void main(String[] args) throws IOException {

		FileReader fileReader = new FileReader(filePath);
		BufferedReader bufferedReader = new BufferedReader(fileReader);

		String line;
		line = bufferedReader.readLine();
		int noTestCases = Integer.parseInt(line);
		for (int i = 0; i < noTestCases; i++) {
			//System.out.println("CASE " + (i + 1));
			int noStartKeys;
			int noChest;
			line = bufferedReader.readLine();
			String[] temp = line.split(" ");
			noStartKeys = Integer.parseInt(temp[0]);
			noChest = Integer.parseInt(temp[1]);
			//currentResultPath = new int[noChest];
			haveResult = false;
			List<Integer> keyList = new ArrayList<Integer>();
			line = bufferedReader.readLine();
			temp = line.split(" ");
			for (int j = 0; j < noStartKeys; j++) {
				keyList.add(Integer.parseInt(temp[j]));
			}
			chests = new ArrayList<Chest>();
			for (int j = 0; j < noChest; j++) {
				line = bufferedReader.readLine();
				temp = line.split(" ");
				Chest chest = new Chest();
				chest.openKey = Integer.parseInt(temp[0]);
				chest.index = j;
				int noOfKeys = Integer.parseInt(temp[1]);
				for (int k = 0; k < noOfKeys; k++) {
					chest.keysInside.add(Integer.parseInt(temp[2 + k]));
				}
				chests.add(chest);
			}
			if (checkImpossible(keyList, chests)) {
				String outputtext = "Case #" + (i + 1) + ": IMPOSSIBLE";
				System.out.println(outputtext);
				continue;
			}
			int[] moves = new int[noChest];
			Map<Integer, List<Integer>> possibleMoves = new HashMap<Integer, List<Integer>>();
			for (int j = 0; j < noChest; j++) {
				List<Integer> tempList = new ArrayList<Integer>();
				possibleMoves.put(j, tempList);
			}
			Map<Integer, Integer>  currentKeys = new HashMap<Integer, Integer>();
			boolean[] currentChests = new boolean[noChest];
			initializeKeys(currentKeys, keyList, chests);
			boolean findPossibleMoves = true;
			boolean isImpossible = false;
			int count = 0;
			for (int j = 0; j < noChest; ) {
				if (count > 10000000) {
					isImpossible = true;
					break;
				}
				if (findPossibleMoves) {
					findPossibleMoves(j, possibleMoves, currentChests, currentKeys);
				}
				if (possibleMoves.get(j).size() == 0) {
					if (j == 0) {
						//System.out.println((i + 1) + " IMPOSSIBLE");
						isImpossible = true;
						break;
					}
					j = j - 1;
					count++;
					//System.out.println(possibleMoves);
					int index = chests.get(moves[j]).openKey;
					currentKeys.put(index, currentKeys.get(index) + 1);
					for (int key: chests.get(moves[j]).keysInside) {
						currentKeys.put(key, currentKeys.get(key) - 1);
					}
					currentChests[moves[j]] = false;
					findPossibleMoves = false;
					continue;
				} 
				moves[j] = possibleMoves.get(j).get(0);
				possibleMoves.get(j).remove(0);
				int index = chests.get(moves[j]).openKey;
				currentChests[moves[j]] = true;
				currentKeys.put(index, currentKeys.get(index) - 1);
				for (int key: chests.get(moves[j]).keysInside) {
					currentKeys.put(key, currentKeys.get(key) + 1);
				}
				j++;
				findPossibleMoves = true;
			}
			System.out.print("Case #" + (i + 1) + ":");
			if (isImpossible) {
				System.out.println(" IMPOSSIBLE");
				continue;
			}
			for (int j = 0; j < noChest; j++) {
				System.out.print(" " + (moves[j] + 1));
			}
			System.out.println();
			/*
			while (possibleMoves.get(0).size() > 0) {
				
				int moveTo = possibleMoves.get(0).get(0);
				int index = chests.get(moveTo).openKey;
				moves[0] = moveTo;
				currentKeys.put(index, currentKeys.get(index) - 1);
			}
			/*
			Map<Integer, Integer> keys = new HashMap<Integer, Integer>();
			for (int key: keyList) {
				if (keys.containsKey(key)) {
					keys.put(key, keys.get(key) + 1);
				} else {
					keys.put(key, 1);
				}
			}
			int[] currentMoves = new int[noChest + 1];
			boolean[] oppenedChests = new boolean[noChest + 1];
			int currentStep = 0;
			moveForward[]
			*/
			/*
			List<Move> initialMoveList = new ArrayList<Move>();
			for (int possibleMove: findPossibleMoves(keyList, chests)) {
				Move move = new Move();
				move.move = possibleMove;
				move.stepNo = 1;
				List<Integer> keysAfterMove = new ArrayList<Integer>();
				boolean keyRemoved = false;
				for (int key: keyList) {
					if (!keyRemoved && key == chests.get(possibleMove).openKey) {
						keyRemoved = true;
						continue;
					}
					keysAfterMove.add(key);
				}
				List<Chest> chestToOpenAfterMove = new ArrayList<Chest>();
				for (Chest chest: chests) {
					if (chest.index != possibleMove) {
						chestToOpenAfterMove.add(chest);
					}
				}
				move.chestsToOpen = chestToOpenAfterMove;
				keysAfterMove.addAll(chests.get(possibleMove).keysInside);
				move.currentKeys = keysAfterMove;
				//System.out.println("keys: " + keysAfterMove);
				initialMoveList.add(move);
			}
			List<Move> succesfullMoves = new ArrayList<Move>();
			for (Move move: initialMoveList) {
				findNextMoves(move, noChest, succesfullMoves, chests);
			}
			int numberOfResults = succesfullMoves.size();
			if (numberOfResults == 0) {
				String outputtext = "Case #" + (i + 1) + ": IMPOSSIBLE";
				System.out.println(outputtext);
				continue;
			}
			List<String> results = new ArrayList<String>();
			for (Move move: succesfullMoves) {
				String result = "" + (move.move + 1);
				Move previousMove = move.previousMove;
				for (int j = 0; j < noChest - 1; j++) {
					if (j > 0) {
						previousMove = previousMove.previousMove;
					}
					result += " " + (previousMove.move + 1);
				}
				String[] temp2 = result.split(" ");
				result = "";
				for (int j = noChest - 1; j >= 0; j--) {
					result += temp2[j] + " ";
				}
				result = result.trim();
				//System.out.println(result);
				results.add(result);
			}
			Collections.sort(results);
			System.out.println("Case #" + (i + 1) + ": " + results.get(0));
			*/
		}
	}
	
	private static void findPossibleMoves(int i,
			Map<Integer, List<Integer>> possibleMoves, boolean[] currentChests,
			Map<Integer, Integer> currentKeys) {
		possibleMoves.get(i).clear();
		for (int j = 0; j < currentChests.length; j++) {
			if (!currentChests[j] && currentKeys.get(chests.get(j).openKey) > 0) {
				possibleMoves.get(i).add(j);
			}
		}
		
	}

	private static void initializeKeys(Map<Integer, Integer> currentKeys,
			List<Integer> keyList, List<Chest> chests) {
		for (int key: keyList) {
			if (!currentKeys.containsKey(key)) {
				currentKeys.put(key, 1);
			} else {
				currentKeys.put(key, currentKeys.get(key) + 1);
			}
		}
		for (Chest chest: chests) {
			for (int key: chest.keysInside) {
				if (!currentKeys.containsKey(key)) {
					currentKeys.put(key, 0);
				}
			}
		}
		
	}

	private static boolean checkImpossible(List<Integer> keyList,
			List<Chest> chests) {
		Map<Integer, Integer> keyType = new HashMap<Integer, Integer>();
		for (Chest chest: chests) {
			int chestType = chest.openKey;
			if (!keyType.containsKey(chestType)) {
				keyType.put(chestType, 0);
			}
		}
		for (int key: keyList) {
			if (!keyType.containsKey(key)) {
				keyType.put(key, 1);
			}
			keyType.put(key, keyType.get(key) + 1);
		}
		for (Chest chest: chests) {
			for (int key: chest.keysInside) {
				if (!keyType.containsKey(key)) {
					keyType.put(key, 1);
				}
				keyType.put(key, keyType.get(key) + 1);
			}
		}
		for (Chest chest: chests) {
			keyType.put(chest.openKey, keyType.get(chest.openKey) - 1);
		}
		for (int key: keyType.keySet()) {
			if (keyType.get(key) < 0) {
				return true;
			}
		}
		return false;
	}

	private static void findNextMoves(Move currentMove, int noChest, List<Move> succesfullMoves, List<Chest> allChests) {
		if (haveResult) {
			return;
		}
		//System.out.println(currentMove.stepNo);
		if (noChest == currentMove.stepNo) {
			succesfullMoves.add(currentMove);
			haveResult = true;
			return;
		}
		for (Integer possibleMove: findPossibleMoves(currentMove.currentKeys, currentMove.chestsToOpen)) {
			Move move = new Move();
			move.previousMove = currentMove;
			move.move = possibleMove;
			move.stepNo = currentMove.stepNo + 1;
			List<Integer> keysAfterMove = new ArrayList<Integer>();
			boolean keyRemoved = false;
			for (int key: currentMove.currentKeys) {
				if (!keyRemoved && key == allChests.get(possibleMove).openKey) {
					keyRemoved = true;
					continue;
				}
				keysAfterMove.add(key);
			}
			List<Chest> chestToOpenAfterMove = new ArrayList<Chest>();
			for (Chest chest: currentMove.chestsToOpen) {
				if (chest.index != possibleMove) {
					chestToOpenAfterMove.add(chest);
				}
			}
			move.chestsToOpen = chestToOpenAfterMove;
			keysAfterMove.addAll(allChests.get(possibleMove).keysInside);
			move.currentKeys = keysAfterMove;
			if (!checkImpossible(move.currentKeys, move.chestsToOpen)) {
				findNextMoves(move, noChest, succesfullMoves, allChests);
			}
		}	
	}
	
	static List<Integer> findPossibleMoves(List<Integer> keys, List<Chest> chestsToOpen) {
		List<Integer> result = new ArrayList<Integer>();
		for (int key: keys) {
			for (Chest chest: chestsToOpen) {
				if (key == chest.openKey) {
					if (!result.contains(chest.index)) {
						result.add(chest.index);
					}
				}
			}
		}
		Collections.sort(result);
		return result;
	}
	
}

class Chest {
	int openKey;
	int index;
	List<Integer> keysInside = new ArrayList<Integer>();
}

class Move {
	int move;
	int stepNo;
	Move previousMove;
	List<Chest> chestsToOpen = new ArrayList<Chest>();
	List<Integer> currentKeys = new ArrayList<Integer>();
}