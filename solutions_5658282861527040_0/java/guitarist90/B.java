package com.figuraj.codejam.round1b;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Locale;
import java.util.Scanner;

public class B {

	private static boolean DEBUG = false;
	private static String FILE_IN = "D:/CodeJam/B-small-attempt0.in";
	private static String FILE_OUT = "D:/CodeJam/out/B.txt";

	private static long solve(long a, long b, long k) {
		long count = 0;
		for (long i = 0; i < a; i++) {
			for (long j = 0; j < b; j++) {
				if ((i & j) < k) {
					count++;
				}
			}
		}
		return count;
	}

	private static void output(long result, int testCase) {
		String s = "Case #" + testCase + ": " + result;
		System.out.println(s);
	}

	public static void main(String[] args) throws FileNotFoundException {
		if (DEBUG) {
			System.setIn(new FileInputStream(FILE_IN));
			System.setOut(new PrintStream(FILE_OUT));
		}

		Scanner sc = new Scanner(System.in);
		sc.useLocale(Locale.US);
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			long a = sc.nextLong();
			long b = sc.nextLong();
			long c = sc.nextLong();
			output(solve(a, b, c), i);
		}
	}
}
