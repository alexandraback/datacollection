import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.AbstractQueue;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Stack;


public class Treasure {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		
		String line = null;
		line = br.readLine();

		int T = Integer.parseInt(line);
		int MAX_KEY_TYPES = 200;
		
		String[] results = new String[T];
		
		for (int t=0; t<T; t++) {
			String[] keysAndChests = br.readLine().split(" ");
			
			int K = Integer.parseInt(keysAndChests[0]);
			int N = Integer.parseInt(keysAndChests[1]);
			
			String[] keyTypesStr = br.readLine().split(" ");
			int[] keysWithMe = new int[MAX_KEY_TYPES];
			int[] totalKeyTypesAvailable = new int[MAX_KEY_TYPES];
			int totalKeysAvailable = K;
			
			for (int i=0; i<K; i++) {
				int keyType = Integer.parseInt(keyTypesStr[i]);
				keysWithMe[keyType]++;
				totalKeyTypesAvailable[keyType]++;
			}
			
			int[][] keysInChest = new int[N][];
			int[] keyTypeToOpen = new int[N];
			int[] numKeysInChest = new int[N];
			
			for (int i=0; i<N; i++) {
				String[] typeToOpenAndKeysPresent = br.readLine().split(" ");
				keyTypeToOpen[i] = Integer.parseInt(typeToOpenAndKeysPresent[0]);
				totalKeyTypesAvailable[keyTypeToOpen[i]]--;
				numKeysInChest[i] = Integer.parseInt(typeToOpenAndKeysPresent[1]);
				totalKeysAvailable += numKeysInChest[i];
				keysInChest[i] = new int[numKeysInChest[i]];
				
				for (int j=0; j<numKeysInChest[i]; j++) {
					keysInChest[i][j] = Integer.parseInt(typeToOpenAndKeysPresent[j+2]);
					totalKeyTypesAvailable[keysInChest[i][j]]++;
				}
			}
			
			boolean notPossible = false;
			
			if (totalKeysAvailable < N) {
				notPossible = true;
			} else {
				for (int i=0; i<MAX_KEY_TYPES; i++) {
					if (totalKeyTypesAvailable[i] < 0) {
						notPossible = true;
						break;
					}
				}
			}
			
			List<Integer> path = new LinkedList<Integer>();
			boolean[] chestOpened = new boolean[N];
			
			boolean found = false;
			
			Queue<Integer> keyTypeMissed = new LinkedList<Integer>();
			
			if (!notPossible) {
				found = findPath(K, N, keysWithMe, keyTypeToOpen, keysInChest, path, chestOpened, keyTypeMissed);
			}
			
			String pathStr = "";
			if (found) {
				for (int i=0; i<path.size(); i++) {
					pathStr += (path.get(i)+1) + " ";
				}
				pathStr = pathStr.trim();
			}
			else {
				pathStr = "IMPOSSIBLE";
			}
			
			results[t] = "Case #" + (t+1) + ": " + pathStr;
			System.out.println(results[t]);
		}
		
		resultsToFile("Treasure.txt", results);
	}

	private static boolean findPath(int K, int N, int[] keysWithMe,
			int[] keyTypeToOpen, int[][] keysInChest, List<Integer> path,
			boolean[] chestOpened, Queue<Integer> keyTypeMissed) {
		if (path.size() == N) {
			return true;
		}
		
		for (Integer i=0; i<N; i++) {
			if (chestOpened[i]) {
				continue;
			}
			
			Integer keyType = keyTypeToOpen[i];
			
			if (keysWithMe[keyType] > 0) {
				chestOpened[i] = true;
				keysWithMe[keyType]--;
				for (int j=0; j<keysInChest[i].length; j++) {
					keysWithMe[keysInChest[i][j]]++;
				}
				path.add(i);
				
				if (findPath(K, N, keysWithMe, keyTypeToOpen, keysInChest, path, chestOpened, keyTypeMissed)) {
					return true;
				}
				else {
					chestOpened[i] = false;
					keysWithMe[keyType]++;
					for (int j=0; j<keysInChest[i].length; j++) {
						keysWithMe[keysInChest[i][j]]--;
					}
					path.remove(i);
					
					Queue<Integer> tmpStack = new LinkedList<Integer>();
					while (!keyTypeMissed.isEmpty()) {
						Integer tmpKeyType = keyTypeMissed.peek();
						if (keyType == tmpKeyType) {
							break;
						}
						else {
							keyTypeMissed.remove();
							tmpStack.add(tmpKeyType);
						}
					}
					
					if (keyTypeMissed.isEmpty()) {
						while (!tmpStack.isEmpty()) {
							keyTypeMissed.add(tmpStack.remove());
						}
						return false;
					}
					else {
						keyTypeMissed.remove();
					}
				}
			}
			else {
				keyTypeMissed.add(keyType);
			}
		}
		
		return false;
	}

	private static void resultsToFile(String fileName, String[] results) throws IOException {
		File file = new File(fileName);
        BufferedWriter output = new BufferedWriter(new FileWriter(file));
        for (int i=0; i< results.length; i++) {
        	output.write(results[i]);
        	if (i < results.length - 1) {
        		output.write("\n");
        	}
        }
        output.close();
	}
}
