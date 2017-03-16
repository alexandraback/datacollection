package com.google.codejam.ka;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;

public class Elf {

	private static PrintStream output;

	public static void main(String args[]) throws IOException {
		output = new PrintStream(new FileOutputStream(Elf.class.getSimpleName() + ".out"));
		parseInput(args[0]);
		output.close();
	}

	private static void parseInput(String arg) throws IOException {
		Scanner scanner = new Scanner(new File(arg));
		int testCases = scanner.nextInt();
		for (int i = 0; i < testCases; i++) {
			String[] pAndQ = scanner.next().split("/");
			long p = Long.parseLong(pAndQ[0]);
			long q = Long.parseLong(pAndQ[1]);
			long gcd = new BigInteger(pAndQ[0]).gcd(new BigInteger(pAndQ[1])).longValue();
			p = p/gcd;
			q = q/gcd;
			int anc = findAnc(p, q);
			printOutput(i + 1, (anc == -1 ? "impossible" : "" + anc));
		}
	}

	private static int findAnc(long p, long q) {
		int level = 0;
		long r = p;
		int first = -1;
		while (r > 0 && level <= 40) {
			r *= 2;
			++level;
			if (r >= q) {
				if (first == -1) {
					first = level;
				}
				r = r - q;
			}
		}
		if (level > 40) {
			return -1;
		}
		return first;
	}

	private static void printOutput(int i, String s) throws IOException {
		String outStr = String.format("Case #%d: %s", i, s);
		System.out.println(outStr);
		output.println(outStr);
	}
}
