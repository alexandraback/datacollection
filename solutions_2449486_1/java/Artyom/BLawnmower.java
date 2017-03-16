package com.artyom.contest.codejam.y2013.qualification;

import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class BLawnmower {
	
	private boolean isPossible(int[][] lawn) {
		int n = lawn.length;
		int m = lawn[0].length;
		for (int min = this.getMin(lawn); min != Integer.MAX_VALUE; min = this.getMin(lawn)) {
			boolean found = false;
			for (int r = 0; r < n; r++) {
				boolean good = true;
				boolean nonZero = false;
				for (int c = 0; c < m; c++) {
					if (lawn[r][c] > 0) nonZero = true;
					if (lawn[r][c] > min || (c > 0 && lawn[r][c] != 0 && lawn[r][c] != lawn[r][c - 1] && lawn[r][c - 1] != 0)) {
						good = false;
						break;
					}
				}
				if (good && nonZero) {
					found = true;
					for (int c = 0; c < m; c++) {
						lawn[r][c] = 0;
					}
					break;
				}
			}
			if (!found) {
				for (int c = 0; c < m; c++) {
					boolean good = true;
					boolean nonZero = false;
					for (int r = 0; r < n; r++) {
						if (lawn[r][c] > 0) nonZero = true;
						if (lawn[r][c] > min || (r > 0 && lawn[r][c] != 0 && lawn[r][c] != lawn[r - 1][c] && lawn[r - 1][c] != 0)) {
							good = false;
							break;
						}
					}
					if (good && nonZero) {
						found = true;
						for (int r = 0; r < n; r++) {
							lawn[r][c] = 0;
						}
						break;
					}
				}
			}
			if (!found) return false;
		}
		return true;
	}
	
	private int getMin(int[][] lawn) {
		int min = Integer.MAX_VALUE;
		for (int r = 0; r < lawn.length; r++) {
			for (int c = 0; c < lawn[r].length; c++) {
				if (lawn[r][c] != 0) {
					min = Math.min(min, lawn[r][c]);
				}
			}
		}
		return min;
	}
	
	public static void main(String[] args) {
		if (args.length != 2) {
			System.err.println("Arguments: input_file output_file");
			System.exit(1);
		}
		
		Scanner input = null;
		PrintWriter output = null;
		try {
			input = new Scanner(new FileReader(args[0]));
			output = new PrintWriter(new BufferedWriter(new FileWriter(args[1])));
			int t = Integer.parseInt(input.nextLine());
			for (int i = 1; i <= t; i++) {
				String[] tokens = input.nextLine().split(" ");
				int n = Integer.parseInt(tokens[0]);
				int m = Integer.parseInt(tokens[1]);
				int[][] lawn = new int[n][m];
				for (int r = 0; r < n; r++) {
					String[] rowTokens = input.nextLine().split(" ");
					for (int c = 0; c < m; c++) {
						lawn[r][c] = Integer.parseInt(rowTokens[c]);
					}
				}
				String out = String.format("Case #%s: %s", i, new BLawnmower().isPossible(lawn) ? "YES" : "NO");
				System.out.println(out);
				output.println(out);
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			input.close();
			output.close();
		}
	}
}
