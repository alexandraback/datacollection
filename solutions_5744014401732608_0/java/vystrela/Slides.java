package com.google.slides;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Slides {

	static String cj_letter = "B";
	static String cj_input = "small";
	// static String cj_input = "large";
	static String cj_attempt = "6";

	static BufferedWriter bw;

	static int total = 0;

	public static void main(String[] args) throws NumberFormatException, IOException {
		String fileIn = "/home/vys/Downloads/" + cj_letter + "-" + cj_input
				+ (cj_input.equals("small") ? "-attempt" + cj_attempt : "") + ".in";
		bw = new BufferedWriter(new FileWriter(fileIn.replaceAll(".in$", ".out")));
		BufferedReader br;
		if (new File(fileIn).exists()) {
			br = new BufferedReader(new FileReader(fileIn));
		} else {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		int numCases = Integer.parseInt(br.readLine());
		for (int i = 0; i < numCases; i++) {
			solve(br, i + 1);
		}
		bw.flush();
		bw.close();
	}

	public static <T> void out(T o) {
		System.out.print(o);
		try {
			bw.write("" + o);
		} catch (IOException e) {
		}
	}

	public static <T> void outln() {
		System.out.println();
		try {
			bw.write(System.lineSeparator());
		} catch (IOException e) {
		}
	}

	public static <T> void outln(T o) {
		out(o);
		System.out.println();
		try {
			bw.write(System.lineSeparator());
		} catch (IOException e) {
		}
	}

	private static void solve(BufferedReader br, int i) throws IOException {
		String[] BM = br.readLine().split(" ");

		int B = Integer.parseInt(BM[0]);
		BigInteger M = new BigInteger(BM[1]);

		BigInteger pow = new BigInteger("2").pow(B - 2);
		if (M.compareTo(pow) > 0 ) {
			outln("Case #" + i + ": IMPOSSIBLE");
			return;
		}
		
		if (M.compareTo(pow) == 0 ) {
			
			M = M.subtract(new BigInteger("1"));

			String bin = new StringBuilder(M.toString(2)).toString();

			for (int j = bin.length() ; j < B - 2; j++) {
				bin = "0" + bin;
			}
			
			outln("Case #" + i + ": POSSIBLE");
			if (bin.equals("0")){
				outln("01");
			} else {
				outln("0" + bin.replaceAll("(.)", "$1").trim() + "1");
			}
			for (int j = 1; j < B; j++) {
				StringBuilder b = new StringBuilder();
				for (int k = 0; k < B; k++) {
					b.append(k > j ? "1" : "0");
				}
				outln(b.toString().trim());
			}
			return;
		}
		
		String bin = new StringBuilder(M.toString(2)).toString();
		
		outln("Case #" + i + ": POSSIBLE");
		
		for (int j = bin.length() ; j < B - 2; j++) {
			bin = "0" + bin;
		}
		String trim = bin.replaceAll("(.)", "$1").trim();

		outln("0" + trim + "0");
		for (int j = 1; j < B; j++) {
			StringBuilder b = new StringBuilder();
			for (int k = 0; k < B; k++) {
				b.append(k > j ? "1" : "0");
			}
			outln(b.toString().trim());
		}
		
		

		return;
	}
}
