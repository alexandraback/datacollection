import java.io.*;

public class KingdomRush {
	private static final String IN_FILE = "B-large.in";
	private static final String OUT_FILE = "B-large_output.txt";

	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new FileReader(IN_FILE));
			BufferedWriter bw = new BufferedWriter(new FileWriter(OUT_FILE));
			String line = br.readLine();
			final int T_CASES = Integer.parseInt(line);
			
			for (int t = 1; t <= T_CASES; t++) {
				line = br.readLine();
				final int N = Integer.parseInt(line);
				int[] oneStarThresholds = new int[N];
				int[] twoStarThresholds = new int[N];
				for (int i = 0; i < N; i++) {
					line = br.readLine();
					String parts[] = line.split(" ");
					oneStarThresholds[i] = Integer.parseInt(parts[0]); //stars needed for one-star rating
					twoStarThresholds[i] = Integer.parseInt(parts[1]); //stars needed for two-star rating
				}
				
				int result = processCase(N, oneStarThresholds, twoStarThresholds);
				if (result == -1) {
					bw.write("Case #" + t + ": " + "Too Bad");
				} else {
					bw.write("Case #" + t + ": " + result);
				}
				bw.newLine();
			}
			
			bw.close();
			br.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private static int processCase(int n, int[] oneStarThresholds, int[] twoStarThresholds) {
		int stars = 0;
		int completion = 0;
		int times = 0;
		while (completion < n) {
			boolean foundTwoStarLevel = false;
			for (int i = 0; i < n; i++) {
				if (twoStarThresholds[i] <= stars) {
					if (oneStarThresholds[i] != Integer.MAX_VALUE) {
						oneStarThresholds[i] = Integer.MAX_VALUE;
						stars++;
					}
					twoStarThresholds[i] = Integer.MAX_VALUE;
					stars++;
					completion++;
					times++;
					foundTwoStarLevel = true;
					break;
				}
			}
			
			if (!foundTwoStarLevel) {
				int maxTwoStarThreshold = -1;
				int chosenIndex = -1;
				for (int j = 0; j < n; j++) {
					if (oneStarThresholds[j] <= stars) {
						// search for the incomplete level with the highest two-star rating
						if (twoStarThresholds[j] > maxTwoStarThreshold) {
							chosenIndex = j;
							maxTwoStarThreshold = twoStarThresholds[j]; 
						}
					}
				}
				
				if (chosenIndex == -1) {
					return -1;
				} else {
					oneStarThresholds[chosenIndex] = Integer.MAX_VALUE;
					stars++;
					times++;
				}
			}
		}
		return times;
	}
	
}
