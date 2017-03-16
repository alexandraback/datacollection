import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class Treasure {
	
	public static void main(String[] args) {
		long start = System.currentTimeMillis();
		String inputFilename = "D-small-attempt0.in";
		StringBuilder answer = new StringBuilder();
		BufferedReader br;
		try {
			br = new BufferedReader(new FileReader(inputFilename));
			String line = br.readLine();
			int testCases = Integer.parseInt(line);
			for (int i=1; i<=testCases; i++) {
				line = br.readLine();
				int indexOfSpace = line.indexOf(" ");
				int numOfKeys = Integer.parseInt(line.substring(0, indexOfSpace));
				int numOfChests = Integer.parseInt(line.substring(indexOfSpace+1));
				int[] keys = new int[201];
				line = br.readLine();
				for (int j=0; j<numOfKeys; j++) { //get initial keys
					indexOfSpace = line.indexOf(" ");
					if (indexOfSpace == -1) //last one, j=numOfKeys-1
						keys[Integer.parseInt(line)]++;
					else {
						keys[Integer.parseInt(line.substring(0, indexOfSpace))]++;
						line = line.substring(indexOfSpace+1);
					}
				}
				int[][] chests = new int[numOfChests+1][201];
				//line 0 empty
				//col 0 = the key that open
				//cols 1-200 = num of keys inside from the type 1-200
				for (int j=1; j<=numOfChests; j++) {
					line = br.readLine();
					indexOfSpace = line.indexOf(" "); //get Ti
					chests[j][0] = Integer.parseInt(line.substring(0, indexOfSpace));
					line = line.substring(indexOfSpace+1);
					indexOfSpace = line.indexOf(" "); //get Ki
					if (indexOfSpace != -1) { //if Ki != 0
						int Ki = Integer.parseInt(line.substring(0, indexOfSpace));
						line = line.substring(indexOfSpace+1);
						for (int m=0; m<Ki; m++) {
							indexOfSpace = line.indexOf(" ");
							if (indexOfSpace == -1) //last one, m=Ki-1
								chests[j][Integer.parseInt(line)]++;
							else {
								chests[j][Integer.parseInt(line.substring(0, indexOfSpace))]++;
								line = line.substring(indexOfSpace+1);
							}
						}
					}
				}
				String ans = getAnswer(chests, keys, new int[numOfChests+1], numOfKeys, "");
				if (ans == null)
					ans = " IMPOSSIBLE";
				answer.append("Case #" + i + ":" + ans + System.lineSeparator());
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		writeOutput(answer.toString());
		System.out.println("in " + (System.currentTimeMillis() - start));
	}
	
	private static String getAnswer(int[][] chests, int[] keys,
			int[] openedChests, int numOfKeys, String acc) {
		int nextChestToOpen = 0;
		while ((nextChestToOpen = nextChest(openedChests, chests, keys, nextChestToOpen+1)) > 0) {
			if (numOfKeys == 0) { //shouldnt happen
				System.out.println("happaned!");
				return null; //there are open chests but no keys
			}
			//update keys
			int openingKey = chests[nextChestToOpen][0];
			int[] newKeys = new int[201];
			int newNumOfKeys = numOfKeys;
			for (int i=1; i<newKeys.length; i++) {
				newKeys[i] = keys[i] + chests[nextChestToOpen][i];
				newNumOfKeys += chests[nextChestToOpen][i];
			}
			newKeys[openingKey]--;
			newNumOfKeys--;
			//mark chest as open
			int[] newOpenedChests = openedChests.clone();
			newOpenedChests[nextChestToOpen] = 1;
			//do recursion
			String recursion = getAnswer(chests, newKeys, newOpenedChests, newNumOfKeys, acc + " " + nextChestToOpen);
			if (recursion != null) {
				return recursion;
			}
		}
		if (nextChestToOpen == -1) return null; //there is still some closed
		else return acc; //all open
	}

	//close=0,open=1
	private static int nextChest(int[] openedChests, int[][] chests, int[] keys, int i) {
		boolean isOneClosed = false;
		for (int j=i; j<openedChests.length; j++) {
			if (openedChests[j] == 0) {
				isOneClosed = true;
				if (keys[chests[j][0]]>0)
					return j; //closed and we have the key
			}
		}
		if (isOneClosed) return -1; //closed and we dont have key
		else return 0; //all open
	}

	private static void writeOutput(String string) {
		try {
			String outputFilename = "output.txt";
			BufferedWriter bw = new BufferedWriter(new FileWriter(outputFilename));
			bw.write(string);
			bw.close();
			System.out.println("success!");
		} catch (Exception e) {
			System.out.println("error!");
		}
	}

}
