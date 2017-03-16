import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;

public class Pancakes {

	public static void main(String[] args) throws Exception {
		Pancakes object = new Pancakes();
		String className = object.getClass().getSimpleName();

		FileReader fileReader = new FileReader(new File(className.toLowerCase() + ".in"));
		Scanner scanner = new Scanner(new BufferedReader(fileReader));

		FileWriter wr = new FileWriter(className.toLowerCase() + ".out");

		int testCases = scanner.nextInt();
		
		object.initDp();

		for (int tc = 1; tc <= testCases; tc++) {

			int D = scanner.nextInt();

			int[] P = new int[D];

			for (int i = 0; i < D; i++)
				P[i] = scanner.nextInt();

			int result = object.solve(P);

			wr.write("Case #" + tc + ": " + result + "\r\n");
		}

		scanner.close();
		wr.close();
	}
	
	private void initDp() {
		dp = new int[1001][1001];
		
		for (int i=0; i<1001; i++)
			for (int j=0; j<1001; j++)
				dp[i][j] = -1;
		
		for (int i=0; i<1001; i++)
			for (int j=0; j<1001; j++)
				calc(i, j);
	}

	private int solve(int[] P) throws Exception {

		int result = 1000000000;
		
		for (int max=1; max<=1000; max++) {
			
			int requiredSplits = 0;
			
			for (int number : P)
				requiredSplits += calc(number, max);
			
			result = Math.min(result, max + requiredSplits);
		}
		
		return result;		
	}
	
	int dp[][];

	private int calc(int number, int max) {
		
		if (dp[number][max] != -1)
			return dp[number][max];
		
		if (number <= max)
			return (dp[number][max] = 0);
		
		
		int best = 1000000000;
		//where to split it?
		for (int at=1; at<number; at++) {
			best = Math.min(best, calc(at, max) + calc(number - at, max) + 1);
		}
				
		return (dp[number][max] = best);
	}
}
