package googlejam2014.qualification;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class DeceitfulWar {
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner scanner = new Scanner(new FileInputStream(args[0]));
		PrintWriter pw = new PrintWriter("output.txt");
		int testCases = scanner.nextInt();
		Outer: for (int test = 1; test <= testCases; test++) {
			pw.print("Case #"+ test + ": ");
			int n = scanner.nextInt();
			double[] w1 = new double[n];
			double[] w2 = new double[n];
			for (int i = 0; i < n; i++) {
				w1[i] = scanner.nextDouble();
			}
			for (int i = 0; i < n; i++) {
				w2[i] = scanner.nextDouble();
			}
			Arrays.sort(w1);
			Arrays.sort(w2);
			int y = 0;
			int i = 0, j = 0;
			while (i < n && j < n) {
				if (w1[i] > w2[j]) {
					y++;
					i++;
					j++;
				} else {
					i++;
				}
			}
			
			int z = 0;
			i = 0; j = 0;
			while (i < n && j < n) {
				if (w1[i] < w2[j]) {
					z++;
					i++;
					j++;
				} else {
					j++;
				}
			}
			z = n - z;
			pw.println(y + " " + z);
		}
		pw.close();
		scanner.close();
	}

	private static void printBoard(PrintWriter pw, char[][] board) {
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[0].length; j++) {
				pw.print(board[i][j]);
			}
			pw.println();
		}
	}
}
