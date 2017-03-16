package com.elleson.joe;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.List;

public class TTTT {

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("D:/codejam/tttt/in"));
		PrintStream out = new PrintStream("D:/codejam/tttt/out");
		
		int T = Integer.parseInt(in.readLine());
		
		for (int t = 0; t < T; t++) {
			char[][] grid = new char[4][4];
			for (int i = 0; i < 4; i++) {
				String nextLine = in.readLine();
				for (int j = 0; j < 4; j++) {
					grid[i][j] = nextLine.charAt(j);
				}
			}
			
			Result result = Result.D;
			
			// h
			for (int i = 0; i < 4; i++) {
				Result res = checkNums(grid[i][0], grid[i][1], grid[i][2], grid[i][3]);
				if (res != Result.D) {
					result = res;
					break;
				}
			}
			
			// v
			if (result == Result.D) {
				for (int i = 0; i < 4; i++) {
					Result res = checkNums(grid[0][i], grid[1][i], grid[2][i], grid[3][i]);
					if (res != Result.D) {
						result = res;
						break;
					}
				}	
			}
			// d
			if (result == Result.D) {
				Result res = checkNums(grid[0][3], grid[1][2], grid[2][1], grid[3][0]);
				if (res != Result.D) {
					result = res;
				}
			}
			if (result == Result.D) {
				Result res = checkNums(grid[3][3], grid[2][2], grid[1][1], grid[0][0]);
				if (res != Result.D) {
					result = res;
				}
			}
			
			if (result == Result.D) {
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						if (grid[i][j] == '.') {
							result = Result.Z;
							break;
						}
					}
				}
			}
			
			out.println("Case #" + (t+1) + ": " + result.getMessage());
			
			in.readLine();
		}
		out.close();
	}
	
	private static Result checkNums(char i1, char i2, char i3, char i4) {
		if ((i1 == 'X' || i1 == 'T') &&
				(i2 == 'X' || i2 == 'T') &&
				(i3 == 'X' || i3 == 'T') &&
				(i4 == 'X' || i4 == 'T')) {
			return Result.X;
		} else if ((i1 == 'O' || i1 == 'T') &&
				(i2 == 'O' || i2 == 'T') &&
				(i3 == 'O' || i3 == 'T') &&
				(i4 == 'O' || i4 == 'T')) {
			return Result.O;
		} else {
			return Result.D;
		}
	}
	
	enum Result {
		
		X("X won"),
		O("O won"),
		D("Draw"),
		Z("Game has not completed");
		
		private String message;
		
		private Result(String message) {
			this.message = message;
		}
		
		public String getMessage() {
			return message;
		}
		
	}
	
}
