//package googlecodejam2013;

import java.util.Arrays;
import java.util.Scanner;

/**
 * DP
 * @author rex
 *
 */
public class ManageYourEnergy {
	
	int[] dpCurrent;
	int[] dpNext;
	int regain;
	int totalE;
	int[] acts;

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int t = scanner.nextInt();
		for (int i = 0; i < t; i++) {
			int e = scanner.nextInt();
			int r = scanner.nextInt();
			int n = scanner.nextInt();
			int[] acts = new int[n];
			for (int j = 0; j < n; j++) {
				acts[j] = scanner.nextInt();
			}
			new ManageYourEnergy().solve(e, r, n, acts);
			System.out.println("Case #" + (i + 1) + ": " + new ManageYourEnergy().solve(e, r, n, acts));
		}
	}

	private int solve(int e, int r, int n, int[] acts) {
		dpCurrent = new int[e + 1];
		dpNext = new int[e + 1];
		regain = r;
		if (regain > e)
			regain = e;
		totalE = e;
		this.acts = acts;
		for (int i = 0; i < n; i++) {
			for (int j = regain; j <= e; j++)
				dp(i, j);
			dpCurrent = dpNext;
			dpNext = new int[e + 1];
		}
		//System.out.println(Arrays.toString(dpCurrent));
		return dpCurrent[regain];
	}

	/**
	 * 
	 * @param numAct n activities completed after the call
	 * @param e
	 * @return
	 */
	private void dp(int numAct, int e) {
		int temp = Math.max(e + regain - totalE, 0);
		for (int i = temp; i <= e; i++) {
			int newValue = dpCurrent[e] + i * acts[numAct];
			if (dpNext[e - i + regain] < newValue)
				dpNext[e - i + regain] = newValue;
		}
	}
}
