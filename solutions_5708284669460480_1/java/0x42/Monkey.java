import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Monkey {

	public static void main(String[] args) throws Exception {
		Monkey object = new Monkey();
		String className = object.getClass().getSimpleName();

		FileReader fileReader = new FileReader(new File(className.toLowerCase() + ".in"));
		Scanner scanner = new Scanner(new BufferedReader(fileReader));

		FileWriter wr = new FileWriter(className.toLowerCase() + ".out");

		int testCases = scanner.nextInt();

		for (int tc = 1; tc <= testCases; tc++) {

			int k = scanner.nextInt();
			int l = scanner.nextInt();
			int s = scanner.nextInt();
			String keyboard = scanner.next();
			String target = scanner.next();

			double result = object.solve(keyboard, target, s);

			//System.out.println("Done " + result);
			DecimalFormat df = new DecimalFormat("0.000000000");
			wr.write("Case #" + tc + ": " + df.format(result) + "\r\n");
		}

		scanner.close();
		wr.close();
	}

	private double solve(String keyboard, String target, int s) throws Exception {
		
		double[][][] prob = new double[s+1][target.length()][s + 1];
		
		for (int x=0; x < s+1; x++)
			for (int y=0; y<target.length(); y++)
				Arrays.fill(prob[x][y], 0);
		
		
		Map<Character, Double> letterProb = new HashMap<>();
		for (char ch='A'; ch <= 'Z'; ch++) {
			letterProb.put(ch, 0.0);
			
			if (keyboard.contains(ch + "")) {
				double count = 0;
				for (int z=0; z<keyboard.length(); z++)
					if (keyboard.charAt(z) == ch)
						count += 1.0;
				
				letterProb.put(ch, count / (keyboard.length()));
			}
		}
		
		int[][] dp = new int[target.length()][30];
		for (int previousHits=0; previousHits < target.length(); previousHits++)
			for (char ch='A'; ch <= 'Z'; ch++) {
				int id = ch - 'A';
				
				String str = target.substring(0, previousHits) + ch;
				
				int result = 0;
				
				for (int st=1; st < str.length(); st++) {
					if (target.startsWith(str.substring(st))) {
						result = str.length() - st;
						break;
					}
				}
				
				dp[previousHits][id] = result;
				//System.out.println("dp[" + previousHits + "][" + id + "] = " + result + "   (  " + str + " ) ");
			}
		
		
		prob[0][0][0] = 1.0;
		
		for (int x=0; x<=s; x++)
			for (int y=0; y<target.length(); y++)
				for (int z=0; z<=s; z++)
					if (prob[x][y][z] > 0) {
						//work from here
						//System.out.println(x + " " + y + " " + z + "    " + prob[x][y][z]);
						
						if (x == s)
							continue;
						
						for (char nextCh='A'; nextCh <= 'Z'; nextCh++) {
							
							double probToHit = letterProb.get(nextCh);
							if (probToHit < 1e-10)
								continue; //character doesn't exist
							
							if (nextCh == target.charAt(y)) {
								int nextY = y + 1;
								int nextZ = z;
								
								if (nextY == target.length()) {
									//hit everything
									nextY = dp[y][nextCh - 'A'];
									nextZ++;
								}
								
								//System.out.println("Hit. Going to " + (x + 1) + " "  + nextY + " " + nextZ + "    " + " from  " + x + " " +  y + " " + z + " " + nextCh);
								prob[x+1][nextY][nextZ] += prob[x][y][z] * probToHit;
							} else {
								int nextY = dp[y][nextCh - 'A'];
								int nextZ = z;
								
								//System.out.println("Miss. Going to " + (x + 1) + " "  + nextY + " " + nextZ + "    " + " from  " + x + " " +  y + " " + z + " " + nextCh);
								prob[x+1][nextY][nextZ] += prob[x][y][z] * probToHit;
							}							
						}
					}
		
		
		int maxHit = 0;
		for (int y=0; y<target.length(); y++)
			for (int z=0; z<s + 1; z++)
				if (prob[s][y][z] > 0) {
					maxHit = Math.max(maxHit, z);
				}
		
		double result = maxHit;
		for (int y=0; y<target.length(); y++)
			for (int z=0; z<s + 1; z++)
				if (prob[s][y][z] > 0) {
					result -= prob[s][y][z] * z;
				}
		
		//System.out.println("Max hit is " + maxHit);
		return result;
		
		
	}

}
