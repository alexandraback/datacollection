package com.elleson.joe;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;

public class Lawn {

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("D:/codejam/lawn/in"));
		PrintStream out = new PrintStream("D:/codejam/lawn/out");
		
		int T = Integer.parseInt(in.readLine());
		
		for (int t = 1; t <= T; t++) {
			String[] desc = in.readLine().split(" ");
			int N = Integer.parseInt(desc[0]);
			int M = Integer.parseInt(desc[1]);
			
			int[][] grid = new int[N][M];
			
			out.println("Case #" + t + ": " + (isPossible(grid, N, M, in) ? "YES" : "NO"));
		}
		
	}
	
	public static boolean isPossible(int[][] grid, int N, int M, BufferedReader in) throws IOException {
		for (int n = 0; n < N; n++) {
			String[] nextLine = in.readLine().split(" ");
			for (int m = 0; m < M; m++) {
				grid[n][m] = Integer.parseInt(nextLine[m]);
			}
		}
		
		int[] maxNs = new int[M];
		int[] maxMs = new int[N];
		
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				int i = grid[n][m];
				if (maxNs[m] < i) {
					maxNs[m] = i;
				}
				if (maxMs[n] < i) {
					maxMs[n] = i;
				}
			}
		}
		
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				if ((grid[n][m] < maxNs[m]) && (grid[n][m] < maxMs[n]))  {
					return false;
				}
			}
		}
		
		return true;
	}
	
}
