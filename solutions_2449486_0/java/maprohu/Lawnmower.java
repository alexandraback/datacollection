package com.google.codejam;

import java.util.Scanner;

import hu.mapro.jam.commons.Problem;

/**
 *  Using <a href="http://code.google.com/p/maprohu-codejam-lib/">Google Code Jam library</a>. 
 */
public class Lawnmower extends Problem {

	public Lawnmower() {
		super("B", false);
	}

	@Override
	protected String solve(Scanner in) {
		int N = in.nextInt();
		int M = in.nextInt();
		
		int[][] grid = new int[N][M];
		
		for (int i=0;i<N;i++) {
			for (int j=0;j<M;j++) {
				grid[i][j] = in.nextInt();
			}
		}

		int topN[] = new int[N];
		int topM[] = new int[M];  

		for (int i=0;i<N;i++) {
			for (int j=0;j<M;j++) {
				topN[i] = Math.max(topN[i], grid[i][j]);
			}
		}
		for (int i=0;i<M;i++) {
			for (int j=0;j<N;j++) {
				topM[i] = Math.max(topM[i], grid[j][i]);
			}
		}
		
		for (int i=0;i<N;i++) {
			for (int j=0;j<M;j++) {
				int ch = grid[i][j];
				
				if (ch<topN[i] && ch<topM[j]) return "NO";
			}
		}
		
		return "YES";
	}


}
