import java.io.*;
import java.util.*;

public class ProblemB {

    private static int max(int[] row) {
	int curr = 0;
	for (int i = 0; i < row.length; i++) {
	    curr = Math.max(curr, row[i]);
	}
	return curr;
    }

    private static int max(int[][] grid, int y) {
	int curr = 0;
	for (int i = 0; i < grid.length; i++) {
	    curr = Math.max(curr, grid[i][y]);
	}
	return curr;
    }

    private static String getResult(int[][] lawn) {
	int[] minH = new int[lawn.length];
	int[] minV = new int[lawn[0].length];
	for (int i = 0; i < lawn.length; i++) {
	    minH[i] = max(lawn[i]);
	}
	for (int j = 0; j < lawn[0].length; j++) {
	    minV[j] = max(lawn, j);
	}
	for (int i = 0; i < lawn.length; i++) {
	    for (int j = 0; j < lawn[i].length; j++) {
		if ((lawn[i][j] < minH[i]) && (lawn[i][j] < minV[j])) {
		    return "NO";
		}
	    }
	}
	return "YES";
    }

    public static void main(String[] args) throws Exception {
	Scanner input = new Scanner(System.in);
	int cases = Integer.parseInt(input.nextLine().trim());
	for (int c = 0; c < cases; c++) {
	    String[] nmLine = input.nextLine().split(" ");
	    int n = Integer.parseInt(nmLine[0]);
	    int m = Integer.parseInt(nmLine[1]);
	    int[][] lawn = new int[n][m];
	    for (int i = 0; i < n; i++) {
		String[] lawnLine = input.nextLine().split(" ");
		for (int j = 0; j < m; j++) {
		    lawn[i][j] = Integer.parseInt(lawnLine[j]);
		}
	    }
	    System.out.println("Case #" + (c+1) + ": " + getResult(lawn));
	}
    }
}