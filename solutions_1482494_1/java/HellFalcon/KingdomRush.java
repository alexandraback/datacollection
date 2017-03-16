package google.codejam2012.round1;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class KingdomRush {
	
	static private String UNABLE_TO_COMPLETE = "Too Bad";
	
	static private int solve(int n, int[] a, int[] b) {
		int stars = 0;
		int moves = 0;
		int[] starsUsed = new int[n];
		while (stars < 2*n) {
			boolean isGamePlayed = false;
			for (int i = 0; i < n; i++) {
				if (starsUsed[i] < 2 & b[i] <= stars) {
					stars += 2 - starsUsed[i];
					starsUsed[i] = 2;
					isGamePlayed = true;
					break;
				}
			}
			if (!isGamePlayed) {
				int max = -1;
				int maxi = -1;
				for (int i = 0; i < n; i++) {
					if (stars >= a[i] & starsUsed[i] == 0 & max < b[i]) {
						max = b[i];
						maxi = i;
					}
				}
				if (max >= 0) {
					stars += 1;
					starsUsed[maxi] += 1;
					isGamePlayed = true;
				}
			}
			if (!isGamePlayed) break;
			moves += 1;
		}
		return stars < 2*n ? -1 : moves;
	}
	
	static public void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in), 64 << 10);
			int testsNumber = Integer.parseInt(br.readLine().trim());
			for (int test = 1; test <= testsNumber; test++) {
				StringTokenizer tokenizer = new StringTokenizer(br.readLine());
				int n = Integer.parseInt(tokenizer.nextToken());
				int[] a = new int[n];
				int[] b = new int[n];
				for (int i = 0; i < n; i++) {
					tokenizer = new StringTokenizer(br.readLine());
					a[i] = Integer.parseInt(tokenizer.nextToken());
					b[i] = Integer.parseInt(tokenizer.nextToken());
				}
				int result = solve(n, a, b);
				if (result >= 0) {
					System.out.println("Case #" + test + ": " + result);
				}
				else {
					System.out.println("Case #" + test + ": " + UNABLE_TO_COMPLETE);
				}
			}
		}
		catch (Exception e) {
			System.err.println("Error:" + e.getMessage());
		}
	}
}
