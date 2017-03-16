package codejam.year2014.round1C;

import java.util.*;
import java.io.*;
import java.math.*;

public class C {

	private static Scanner sc;

	private static int M,N,K;
	public static void main(final String[] args) {
//		 setStreams("C:\\Users\\ybandiel\\Desktop\\testC");
		 setStreams("C:\\Users\\ybandiel\\Desktop\\C-small-attempt2");
		// setStreams("C:\\Users\\ybandiel\\Desktop\\C-large");
		sc = new Scanner(System.in);
		final int numCases = sc.nextInt();
		handleCases(numCases);
	}

	private static void setStreams(final String baseFileName) {
		try {
			System.setIn(new FileInputStream(baseFileName + ".in"));
			 System.setOut(new PrintStream(baseFileName + ".out"));
		} catch (final FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	private static void handleCases(final long numCases) {
		for (int i = 1; i <= numCases; i++) {
			handleCase(i);
		}
	}

	private static void handleCase(final int caseNumber) {
		N = sc.nextInt();
		M = sc.nextInt();
		K = sc.nextInt();
		
		if( K <= 4) {
			System.out.println("Case #" + caseNumber + ": " + K);
		}
		else if (N <= 2) {
			System.out.println("Case #" + caseNumber + ": " + K);
		}
		else if (M <= 2) {
			System.out.println("Case #" + caseNumber + ": " + K);
		}
		else {
			int res = run(N - 3, M - 3, K - 5, 1, 1, 4);
			System.out.println("Case #" + caseNumber + ": " + res);
		}
	}

	private static int run(int leftN, int leftM, int leftK, int gainN, int gainM, int stones) {
		if(leftK == 0) {
			return stones;
		}
		else if(leftK < 0) {
			int remove = 0;
			while(leftK <= -2) {
				remove++;
				leftK = leftK + 2;
			}
			return stones - remove;
		}
		if(leftK == 1) {
			return stones + 1;
		}
		
		if(gainN >= gainM && leftN > 0 ) {
			return run(leftN - 1, leftM, leftK - gainN - 2, gainN, gainM + 1, stones + 2);
		}
		else if(gainN >= gainM && leftM > 0) {
			return run(leftN, leftM - 1, leftK - gainM - 2, gainN + 1, gainM, stones + 2);
		}
		else if(gainM > gainN && leftM > 0) {
			return run(leftN, leftM - 1, leftK - gainM - 2, gainN + 1, gainM, stones + 2);
		}
		else if(gainM > gainN && leftN > 0) {
			return run(leftN - 1, leftM, leftK - gainN - 2, gainN, gainM + 1, stones + 2);
		}
		else {
			return stones + leftK;
		}
	}

	private static void log(final String message) {
		System.out.println(message);
	}
}
