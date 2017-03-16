package com.codejam2012.round1b;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class C_small {

	static int nTest;
	static Scanner scanner;
	static FileWriter writer;
	static File in;
	static File out;
	
	static int n;
	static int[] N;
	static int[] map;
	public static void main(String[] args) throws IOException {
		
		in = new File("input.txt");
		out = new File("output.txt");
		scanner = new Scanner(in);
		writer = new FileWriter(out);
		
		nTest = scanner.nextInt();
		for (int test=1;test<=nTest;++test) {
			writer.write("Case #" + test + ":\n");
			n = scanner.nextInt();
			N = new int[n];

			map = new int[3000000];

			for (int i=0;i<n;++i) {
				N[i] = scanner.nextInt();
			}
			for (int i=1;i<(1<<n);++i) {
				int sum = 0;
				int num = i;
				for (int j=n-1;j>=0;--j) {
					int re = num % 2;
					num /= 2;
					if (re == 1) {
						sum += N[j];
					}
				}
				if (map[sum] > 0) {
					num = i;
					for (int j=n-1;j>=0;--j) {
						int re = num % 2;
						num /= 2;
						if (re == 1) {
							writer.write(N[j] + "");
							if (num > 0) {
								writer.write(" ");
							}
							else {
								writer.write("\n");
								break;
							}
						}
						
					}
					num = map[sum];
					for (int j=n-1;j>=0;--j) {
						int re = num % 2;
						num /= 2;
						if (re == 1) {
							writer.write(N[j] + "");
							if (num > 0) {
								writer.write(" ");
							}
							else {
								break;
							}
						}
						
					}
					break;
				}
				else {
					map[sum] = i;
				}
			}
			if (test < nTest) {
				writer.write("\n");
			}
			writer.flush();
		}
		writer.close();
	}
}
