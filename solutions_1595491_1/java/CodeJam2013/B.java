package com.google.codejam.Qualification2012;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.Scanner;

public class B {

	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(new BufferedReader(new FileReader(args[0] + ".in")));
		Writer writer = new BufferedWriter(new FileWriter(args[0] + ".out"));
		
		int T = scanner.nextInt();

		for (int x = 1; x <= T; ++x) {
			int N = scanner.nextInt();
			int S = scanner.nextInt();
			int p = scanner.nextInt();
			
			int[] t = new int[N];
			for (int i = 0; i < N; ++i)
				t[i] = scanner.nextInt();
			
			int y = 0;
			
			for (int i = 0; i < N; ++i) {
				if (t[i] < p)
					continue;
				
				int min = (t[i] - p) / 2;
				if (min >= p - 1) {
					++y;
				} else if (min == p - 2 && S > 0) {
					--S;
					++y;
				}
			}
			
			System.out.println("Case #" + x + ": " + y);
			writer.write("Case #" + x + ": " + y + "\n");
		}
		
		writer.close();
		scanner.close();
	}
	
}
