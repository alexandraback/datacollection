package com.mw.google.codejam2014;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;

public class NewLotteryGame {
	
	public static long solve(long a, long b, long k) {
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
	
	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
		if (args.length < 1) {
			throw new IllegalArgumentException("Need filename as input");
		}

		File file = new File(args[0]);
		PrintWriter writer = new PrintWriter(args[0] + ".out", "UTF-8");
		Scanner scanner = new Scanner(file);
		int numOfTests = scanner.nextInt();
		for (int i = 1; i <= numOfTests; i++) {
			long a = scanner.nextLong();
			long b = scanner.nextLong();
			long k = scanner.nextLong();
			writer.println("Case #" + i + ": " + solve(a, b, k));
		}
		scanner.close();
		writer.close();

	}
}
