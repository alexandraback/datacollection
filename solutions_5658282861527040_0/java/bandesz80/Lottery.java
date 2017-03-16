package com.google.codejam.ka;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Lottery {

	public static void main(String args[]) throws FileNotFoundException {
		parseInput(args[0]);
	}

	private static void parseInput(String arg) throws FileNotFoundException {
		Scanner scanner = new Scanner(new File(arg));
		int testCases = scanner.nextInt();
		for (int i = 0; i < testCases; i++) {
			long a = scanner.nextLong();
			long b = scanner.nextLong();
			long k = scanner.nextLong();
			long sol = solve(a,b,k);

			printOutput(i + 1, "" + sol);
		}
	}

	private static long solve(long a, long b, long k) {
		long cnt = 0;
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				if ((i&j)<k) {
					++cnt;
				}
			}
		}
		return cnt;
	}

	private static void printOutput(int i, String s) {
		System.out.println(String.format("Case #%d: %s", i, s));
	}
}
