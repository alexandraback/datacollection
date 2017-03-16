package com.github.rd.blackbox.gcj2015.round1b;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class A {

	private static Map<Long, Long> cache = new HashMap<>();

	public static void main(String[] args) throws IOException {
		String inPath = "resources/2015/round1b/input/";
		String outPath = "resources/2015/round1b/output/";

//		File inFile = new File(inPath + "data.in");
//		File outFile = new File(outPath + "data.out");

		File inFile = new File(inPath + "A-small-attempt1.in");
		File outFile = new File(outPath + "A-small-attempt1.out");

//		File inFile = new File(inPath + "A-large.in");
//		File outFile = new File(outPath + "A-large.out");

		try (BufferedReader in = new BufferedReader(new FileReader(inFile));
				BufferedWriter out = new BufferedWriter(new FileWriter(outFile))) {
			int ts = Integer.parseInt(in.readLine());

			for (int t = 1; t <= ts; t++) {
				cache.clear();
				long n = Long.parseLong(in.readLine());
				long counter = rec(n);
				out.write(String.format("Case #%d: %d\n", t, counter));
			}
		}
	}

	private static long rec(long n) {
		if (n < 1) {
			return 0;
		} else if (cache.containsKey(n)) {
			return cache.get(n);
		} else {
			long fst = rec(n - 1) + 1;
			long rev = rev(n);
			long snd = Long.MAX_VALUE;

			if (rev < n) {
				snd = rec(rev) + 1;
			}
			long res = Math.min(fst, snd);
			cache.put(n, res);
			return res;
		}
	}

	private static long rev(long n) {
		if (n % 10 == 0) {
			return n;
		}
		long i = n;
		long res = 0;

		while (i > 0) {
			res *= 10;
			res += (i % 10);
			i /= 10;
		}
		return res;
	}
}
