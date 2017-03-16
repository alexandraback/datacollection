package codejam2015;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class ProblemC {

	public static void main(String[] args) throws NumberFormatException, IOException {
		FileWriter writer = new FileWriter("C:\\Users\\mchang\\workspace\\Google Code Jam\\src\\output.txt");
		String filename = "C:\\Users\\mchang\\workspace\\Google Code Jam\\src\\input.txt";
		try {
			BufferedReader br = new BufferedReader(new FileReader(filename));
			int numCases = Integer.parseInt(br.readLine());
			for (int caseNum = 1; caseNum <= numCases; caseNum++) {
				String line = br.readLine();
				int n = Integer.parseInt(line);
				int[] bffs = new int[n + 1];
				line = br.readLine();
				Scanner sc = new Scanner(line);
				for(int i = 0; i < n; i++){
					bffs[i + 1] = Integer.parseInt(sc.next());
				}
				boolean[] used = new boolean[n + 1];
				int[] remainingStraightLength = new int[n + 1];
				int[] straightLabel = new int[n + 1];
				int straightCount = 0;
				int maxLoop = 0;
				
				for(int seed = 1; seed <= n; seed++){
					if(used[seed]) continue;
					used[seed] = true;
					ArrayList<Integer> chain = new ArrayList<Integer>();
					chain.add(seed);
					HashMap<Integer, Integer> index = new HashMap<Integer, Integer>();
					index.put(seed, chain.size() - 1);
					int last = seed;
					while(true){	
						int bff = bffs[last];
						if(used[bff]){
							break;
						} else {
							chain.add(bff);
							index.put(bff, chain.size() - 1);
							used[bff] = true;
							last = bff;
						}
					}
					if(index.containsKey(bffs[last])){
						int endOfLoop = index.get(bffs[last]).intValue();
						if(endOfLoop == chain.size() - 2){
							// straight
							for(int i = 0; i < chain.size() - 2; i++){
								remainingStraightLength[chain.get(i)] = chain.size() - i - 1; 
								straightLabel[chain.get(i)] = chain.get(chain.size() - 2);
							}
							remainingStraightLength[chain.get(chain.size() - 2)] = 1;
							remainingStraightLength[chain.get(chain.size() - 1)] = 1;
							straightLabel[chain.get(chain.size() - 2)] = chain.get(chain.size() - 2);
							straightLabel[chain.get(chain.size() - 1)] = chain.get(chain.size() - 1);
						} else {
							int lengthOfLoop = chain.size() - endOfLoop;
							if(lengthOfLoop > maxLoop){
								maxLoop = lengthOfLoop;
							}
						}
					} else {
						if(straightLabel[bffs[last]] > 0){
							for(int i = 0; i < chain.size(); i++){
								remainingStraightLength[chain.get(i)] = chain.size() - i + remainingStraightLength[bffs[last]];
								straightLabel[chain.get(i)] = straightLabel[bffs[last]];
							}
						} 
					}
				}
				// all straights
				int[] maxPerStraight = new int[n + 1];
				for(int i = 1; i <= n; i++){
					if(remainingStraightLength[i] > maxPerStraight[straightLabel[i]]){
						maxPerStraight[straightLabel[i]] = remainingStraightLength[i];
					}
				}
				int allStraights = 0;
				for(int i = 0; i <= n; i++){
					allStraights += maxPerStraight[i];
				}
				if(allStraights > maxLoop){
					maxLoop = allStraights;
				}
				printAnswer("" + maxLoop, caseNum, writer);
			}
			br.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		writer.close();
	}

	public static long getFactor(long x){
		for(int i = 2; i <= Math.sqrt(x); i++){
			if(x % i == 0) return i;
		}
		return -1;
	}
	
	public static String prependZeroes(String base, int targetLength){
		while(base.length() < targetLength){
			base = "0" + base;
		}
		return base;
	}
	
	public static void printAnswer(String answer, int caseNumber,
			FileWriter writer) throws IOException {
		writer.write("Case #" + caseNumber + ": " + answer + "\n");
	}
}
