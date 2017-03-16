package com.yapark.codejam2013;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.LinkedList;

public class ProblemD {

	private int numKeys;
	private int numChests;
	private int maxKeyVal;
	private Chest[] chests;
	private short[] initialKeys;
	private short[] totalKeys;
	private short[] totalNeededKeys;

	class Chest {
		int openKey;
		int[] containedKeys;
		public Chest(String input) {
			String[] vals = input.split(" ");
			openKey = Integer.decode(vals[0]);
			containedKeys = new int[Integer.decode(vals[1])];
			for(int i=0; i<containedKeys.length; i++) {
				containedKeys[i] = Integer.decode(vals[i+2]);
			}
		}
	}
	
	public ProblemD(int keyCount, int chestCount) {
		numKeys = keyCount;
		numChests = chestCount;
		maxKeyVal = -1;
		initialKeys = new short[201];
		totalKeys = new short[201];
		totalNeededKeys = new short[201];
		chests = new Chest[numChests];
		return;
	}
	
	public void addKeys(String input) {
		String[] keys = input.split(" ");
		for(int i=0; i<numKeys; i++) {
			int keyType = Integer.decode(keys[i]);
			initialKeys[keyType] = (short) (initialKeys[keyType] + 1);
			totalKeys[keyType] = (short) (totalKeys[keyType] + 1);
		}
		return;
	}
	
	public void addChestInfo(String input, int chestCount) {
		chests[chestCount] = new Chest(input);
		for(int i=0; i<chests[chestCount].containedKeys.length; i++) {
			totalKeys[chests[chestCount].containedKeys[i]]++;
			maxKeyVal = Math.max(maxKeyVal, chests[chestCount].containedKeys[i]);
		}
		maxKeyVal = Math.max(maxKeyVal,chests[chestCount].openKey);
		totalNeededKeys[chests[chestCount].openKey]++;
	}
	
	public boolean[][] createReachableMap(boolean[] finishedChests) {
		boolean[][] reachableMap;
		reachableMap = new boolean[maxKeyVal+1][maxKeyVal+1];
		for(int i=0; i<numChests; i++) {
			if(!finishedChests[i]) {
				for(int j=0; j<chests[i].containedKeys.length; j++) {
					reachableMap[chests[i].openKey][chests[i].containedKeys[j]] = true;
				}
			}
		}
		boolean hasChange = true;
		while(hasChange) {
			hasChange = false;
			for(int i=1; i<maxKeyVal+1; i++) {
				for(int j=1; j<maxKeyVal+1; j++) {
					if(i!=j && reachableMap[i][j]) {
						for (int k=1; k<maxKeyVal+1; k++) {
							if(reachableMap[j][k] && !reachableMap[i][k]) {
								hasChange = true;
								reachableMap[i][k] = true;
							}
						}
					}
				}
			}
		}
		return reachableMap;
	}
	
	public LinkedList<Integer> solve() {
		for(int i=0; i<201; i++) {
			if(totalNeededKeys[i]>totalKeys[i]) {
				return null;
			}
		}
		return getPath(initialKeys, new boolean[numChests], totalNeededKeys, numChests, new ArrayList<Integer>());
	}
	
	public LinkedList<Integer> getPath(short[] currentKeys, boolean[] finishedChests, short[] neededKeys, int chestsToGo, ArrayList<Integer> history) {
		if(chestsToGo==0) {
			return new LinkedList<Integer>();
		}
		boolean[][] reachableMap = createReachableMap(finishedChests);
		for(int i=1; i<maxKeyVal+1; i++) {
			boolean unreachableState = true;
			if(neededKeys[i]>0 && currentKeys[i]==0) {
				//Check if this state is fixable
				for(int j=1; j<maxKeyVal+1; j++) {
					if(currentKeys[j]>0 && reachableMap[j][i]) {
						unreachableState = false;
						break;
					}
				}
				if(unreachableState) {
					return null;
				}
			}
		}
		for(int i=0; i<numChests; i++) {
			if(!finishedChests[i]) {
				if(currentKeys[chests[i].openKey]>0) {
					short[] newCurrentKeys = new short[maxKeyVal+1];
					boolean[] newFinishedChests = new boolean[numChests];
					short[] newNeededKeys = new short[maxKeyVal+1];
					System.arraycopy(neededKeys, 0, newNeededKeys, 0, newNeededKeys.length);
					newNeededKeys[chests[i].openKey]--;
					System.arraycopy(currentKeys, 0, newCurrentKeys, 0, newCurrentKeys.length);
					newCurrentKeys[chests[i].openKey]--;
					for(int j=0; j<chests[i].containedKeys.length; j++) {
						newCurrentKeys[chests[i].containedKeys[j]]++;
					}
					System.arraycopy(finishedChests, 0, newFinishedChests, 0, newFinishedChests.length);
					newFinishedChests[i] = true;
					
					ArrayList<Integer> newHistory = new ArrayList<Integer>(history);
					newHistory.add(i+1);
					
					LinkedList<Integer> retVal = getPath(newCurrentKeys, newFinishedChests, newNeededKeys, chestsToGo-1, newHistory);
					if (retVal != null) {
						retVal.addFirst(i);
						return retVal;
					}
				}
			}
		}
		return null;
	}
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			BufferedReader br = new BufferedReader(new FileReader("D-small-attempt1.in"));
			FileWriter fw = new FileWriter("outputDsmall.txt");
			BufferedWriter bw = new BufferedWriter(fw);

			String line;
			int numOfGames;
			line = br.readLine();
			numOfGames = Integer.decode(line);
			for(int i = 1; i<=numOfGames; i++) {
				int numStartKeys, numOfChests; 
				line = br.readLine();
				String[] vals = line.split(" ");
				numStartKeys = Integer.decode(vals[0]);
				numOfChests = Integer.decode(vals[1]);
				ProblemD prob = new ProblemD(numStartKeys,numOfChests);
				line = br.readLine();
				prob.addKeys(line);
				for(int j=0; j<numOfChests; j++) {
					line = br.readLine();
					prob.addChestInfo(line, j);
				}
				LinkedList<Integer> ans = prob.solve();
				if(ans==null) {
					bw.write("Case #"+i+": IMPOSSIBLE\n");
					bw.flush();
				}
				else {
					bw.write("Case #"+i+":");
					while(!ans.isEmpty()) {
						bw.write(" "+ (ans.removeFirst()+1));
					}
					bw.write("\n");
					bw.flush();
				}
			}
			br.close();
			bw.flush();
			bw.close();
		}
		catch (FileNotFoundException e) {
			System.out.println("ERROR: Cannot find file.");
			return;
		}
		catch (IOException e) {
			
		}
	}

}
