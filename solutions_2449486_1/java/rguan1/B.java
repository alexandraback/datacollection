package codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {

	public static void main(String args[]) throws FileNotFoundException, IOException {
		String filein = "B-large.in";
		String fileout = "B-large.out";
		Scanner sc = new Scanner(new FileReader(new File(filein)));
		PrintWriter out = new PrintWriter(new FileWriter(new File(fileout)));
		int n, m;
		int cases = sc.nextInt();
		
		for (int i = 0; i < cases; i++) {
			n = sc.nextInt();
			m = sc.nextInt();
			
			int[][] pattern = new int[n][m]; // original pattern
			int[][] lawn = new int[n][m]; // fresh lawn

			// load pattern into matrix
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < m; k++) {
					pattern[j][k] = sc.nextInt();
				}
			}
			
			// load lawn into matrix
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < m; k++) {
					lawn[j][k] = 100;
				}
			}
			
			// mow rows
			for (int j = 0; j < pattern.length; j++) {
				int max = 0;
				
				// find max in row
				for (int k = 0; k < pattern[0].length; k++) {
					max = pattern[j][k] > max ? pattern[j][k] : max;
				}
				
				// mow row
				for (int k = 0; k < pattern[0].length; k++) {
					lawn[j][k] = Math.min(lawn[j][k], max);
				}
			}
			
			// mow columns
			for (int k = 0; k < pattern[0].length; k++) {
				int max = 0;
				
				// find max in col
				for (int j = 0; j < pattern.length; j++) {
					max = pattern[j][k] > max ? pattern[j][k] : max;
				}
				
				// mow col
				for (int j = 0; j < pattern.length; j++) {
					lawn[j][k] = Math.min(lawn[j][k], max);
				}
			}
			
			if(matrixEquals(pattern, lawn)) {
				out.println("Case #" + (i + 1) + ": YES");
			}
			else {
				out.println("Case #" + (i + 1) + ": NO");
			}
		}
		out.close();
	}
	
	public static boolean matrixEquals(int[][] pattern, int[][] lawn) {
		for (int i = 0; i < pattern.length; i++) {
			for (int j = 0; j < pattern[0].length; j++){
				if(pattern[i][j] != lawn[i][j]) {
					return false;
				}
			}
		}
		return true;
	}
	
	public static void printMatrix(int[][] matrix) {
		for (int i = 0; i < matrix.length; i++) {
			for (int j = 0; j < matrix[0].length; j++) {
				System.out.print(matrix[i][j]);
			}
			System.out.println();
		}
	}
}