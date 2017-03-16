package com.desing.codejam.y2014.round1b;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class NewLotteryGame {
	
	public static void main(String[] args) throws FileNotFoundException {

		String inputPathName = "inputs3/NewLotteryGame-small-practice.in";
		// String inputPathName = "inputs3/NewLotteryGame-large-practice.in";
		String outputPathName = "C:/Users/desingurajan_s/Desktop/out.txt";

		try (Scanner sc = new Scanner(new BufferedReader(new FileReader(
				new File(inputPathName))));
				PrintWriter pw = new PrintWriter(new File(outputPathName))) {
			int T = sc.nextInt();
			for (int t = 1; t <= T; t++) {
				long A = sc.nextLong();
				long B = sc.nextLong();
				long K = sc.nextLong();

				// Worst				
				long count = 0;
				for (long i = 0; i < A; i++) {
					for (long j = 0; j < B; j++) {
						if ((i & j) < K) {
							count++;
						}
					}
				}

				// System.out.format("Case #%d: %d%n", t, count);
				pw.format("Case #%d: %d%n", t, count);
			}
		}
	}
}
