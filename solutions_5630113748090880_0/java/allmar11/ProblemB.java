package round1a;


import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class ProblemB {
	
	// Workaround for not being able to pipe a file to stdin in Eclipse.
	private static final String IN_FILE = "text/" + "B-small-attempt0.in";
	
	public static void main(String[] args) throws Exception {
		try (Scanner in = new Scanner(new BufferedReader(new FileReader(IN_FILE)))) {
			int numCases = in.nextInt();
			for (int i = 0; i < numCases; i++) {
				int size = in.nextInt();
				int[][] lines = new int[2 * size - 1][size];
				for (int j = 0; j < 2 * size - 1; j++) {
					for (int k = 0; k < size; k++) {
						lines[j][k] = in.nextInt();
					}
				}
				
				int[] result = solve(lines);
				StringBuilder resultStr = new StringBuilder();
				for (int j = 0; j < result.length; j++) {
					resultStr.append(""+result[j]);
					if (j < result.length - 1) {
						resultStr.append(" ");
					}
				}
				
				System.out.println(String.format("Case #%s: %s", i+1, resultStr));
			}
		}
	}

	private static int[] solve(int[][] lines) {
		Solution result = backTrackSolve(new Solution(lines[0].length), Arrays.asList(lines));
		return result.soln();
	}
	
	private static Solution backTrackSolve(Solution curr, List<int[]> lines) {
		if (lines.isEmpty()) {
			return curr;
		}
		
		int[] nextLine = lines.get(0);
		for (int i = 0; i < curr.rows.length; i++) {
			if (curr.rowPossible(i, nextLine)) {
				curr.rows[i] = nextLine;
				Solution recurseResult = backTrackSolve(curr, lines.subList(1, lines.size()));
				if (recurseResult == null) {
					curr.rows[i] = null;
				}
				else {
					return recurseResult;
				}
			}
			if (curr.colPossible(i, nextLine)) {
				curr.cols[i] = nextLine;
				Solution recurseResult = backTrackSolve(curr, lines.subList(1, lines.size()));
				if (recurseResult == null) {
					curr.cols[i] = null;
				}
				else {
					return recurseResult;
				}
			}
		}
		
		return null;
	}
	
	private static class Solution {
		int[][] rows;
		int[][] cols;
		
		public Solution(int size) {
			rows = new int[size][];
			cols = new int[size][];
		}
		
		public boolean rowPossible(int row, int[] candidate) {
			if (rows[row] != null) {
				return false;
			}
			
			for (int col = 0; col < cols.length; col++) {
				if (cols[col] != null && cols[col][row] != candidate[col]) {
					return false;
				}
				if (row > 0 && rows[row-1] != null && rows[row-1][col] >= candidate[col]) {
					return false;
				}
				if (row < rows.length - 1 && rows[row+1] != null
						&& rows[row+1][col] <= candidate[col])
				{
					return false;
				}
			}
			
			return true;
		}
		
		public boolean colPossible(int col, int[] candidate) {
			if (cols[col] != null) {
				return false;
			}
			
			for (int row = 0; row < rows.length; row++) {
				if (rows[row] != null && rows[row][col] != candidate[row]) {
					return false;
				}
				if (col > 0 && cols[col-1] != null && cols[col-1][row] >= candidate[row]) {
					return false;
				}
				if (col < cols.length - 1 && cols[col+1] != null
						&& cols[col+1][row] <= candidate[row])
				{
					return false;
				}
			}
			
			return true;
		}
		
		public int[] soln() {
			Integer nullRow = null;
			Integer nullCol = null;
			int[][] board = new int[rows.length][cols.length];
			for (int i = 0; i < rows.length; i++) {
				if (rows[i] == null) {
					nullRow = i;
				}
				else {
					for (int j = 0; j < cols.length; j++) {
						board[i][j] = rows[i][j];
					}
				}
			}
			for (int i = 0; i < cols.length; i++) {
				if (cols[i] == null) {
					nullCol = i;
				}
				else {
					for (int j = 0; j < rows.length; j++) {
						board[j][i] = cols[i][j];
					}
				}
			}
			
			int[] result = new int[rows.length];
			if (nullRow != null) {
				for (int i = 0; i < rows.length; i++) {
					result[i] = board[nullRow][i];
				}
			}
			else {
				assert (nullCol != null);
				for (int i = 0; i < rows.length; i++) {
					result[i] = board[i][nullCol];
				}
			}
			
			return result;
		}
	}
}
