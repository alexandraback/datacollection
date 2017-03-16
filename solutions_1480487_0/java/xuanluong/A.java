package com.codejam2012.round1b;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class A {

	static int nTest;
	static Scanner scanner;
	static FileWriter writer;
	static File in;
	static File out;
	
	static int nContestants;
	static int[] S;
	static int X;
	static double[] Y;
	
	public static void main(String[] args) throws IOException {
		in = new File("input.txt");
		out = new File("output.txt");
		scanner = new Scanner(in);
		writer = new FileWriter(out);
		
		nTest = scanner.nextInt();
		for (int test=1;test<=nTest;++test) {
			nContestants = scanner.nextInt();
			S = new int[nContestants];
			Y = new double[nContestants];
			X = 0;
			for (int i=0;i<nContestants;++i) {
				S[i] = scanner.nextInt();
				X += S[i];
			}
			
			writer.write("Case #" + test + ":");
			int n = nContestants;
			int ts = 0;
			for (int i=0;i<nContestants;++i) {
				if (2*X <= nContestants * S[i]) {
					n--;
					ts += S[i];
					Y[i] = 0.0;
				}
			}
			for (int i=0;i<nContestants;++i) {
				if (2*X > nContestants * S[i]) {
					int nume = (2*X - ts - n*S[i]) * 100;
					int deno = n*X;
					Y[i] = (double)nume / (double)deno;
				}
//				int nume = (2*X - nContestants*S[i]) * 100;
//				int deno = nContestants*X;
//				if (nume < 0) {
//					Y[i] = 0.0;
//				}
//				else {
//					Y[i] = (double)nume / (double)deno;
//				}
//				writer.write(" " + String.format("%.6f", Y[i]));
				writer.write(" " + Y[i]);
			}
			if (test < nTest) {
				writer.write("\n");
			}
			writer.flush();
		}
		writer.close();
	}
}
