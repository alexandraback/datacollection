package com.figuraj.codejam.round1c;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Locale;
import java.util.Scanner;

public class A {

	private static boolean DEBUG = false;
	private static String FILE_IN = "D:/CodeJam/A-large.in";
	private static String FILE_OUT = "D:/CodeJam/out/A.txt";

	private static int solve(String input) {
		String[] parts = input.split("/");
		long a = Long.parseLong(parts[0]);
		long b = Long.parseLong(parts[1]);
		long gcd = gcd(a, b);
		a /= gcd;
		b /= gcd;

		int res = -1;
		for (int i = 0; i < 41; i++) {
			if (res < 0 && a >= b) {
				res = i;
			}
			a *= 2;
			gcd = gcd(a, b);
			a /= gcd;
			b /= gcd;
		}
		if (a % b != 0) {
			return -1;
		}
		return res;
	}

	private static long gcd(long a, long b) {
		while (b != 0) {
			long t = b;
			b = a % b;
			a = t;
		}
		return a;
	}

	private static void output(int result, int testCase) {
		String s = "Case #" + testCase + ": ";
		if (result < 0) {
			s += "impossible";
		} else {
			s += result;
		}
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
			String input = sc.next();
			output(solve(input), i);
		}
	}
}
