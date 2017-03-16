package com.mw.google.codejam2014;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;

public class PartElf {
	
	public static String solve(int p, int q) {
		
		double d = (double)p / (double)q;
		boolean possible = false;
		double a = d;

		for (int i = 1; i <= 40; i++) {
			a = a * 2;
			int b = (int)a;
			double c = (double)b;
			System.out.println(p + " " + q + " " + a + " " + c);
			if (Math.abs(c - a) < 0.0000000001) {
				possible = true;
				break;
			}
		}
		
		if (!possible) {
			return "impossible";
		}

		for (int i = 1; i <= 40; i++) {
			System.out.println(d);
			d = d * 2;
			if (d >= 1d) {
				return String.valueOf(i);
			}
		}
		return "impossible";
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
			String s = scanner.next();
			String[] split = s.split("/");
			int p = Integer.valueOf(split[0]);
			int q = Integer.valueOf(split[1]);
			
			writer.println("Case #" + i + ": " + solve(p, q));
		}
		scanner.close();
		writer.close();

	}
}
