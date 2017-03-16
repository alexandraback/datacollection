

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;

//Using the Google Collections library.
public class B {

	public static void main(String [] args) throws IOException {
		String inputFile = "src/B-large-0.in";
		Scanner in = new Scanner(new File(inputFile));
		PrintStream out = new PrintStream(inputFile.substring(0, inputFile.length()-2)+"out");
		int cases = in.nextInt();
		for (int cs = 1; cs <= cases; cs++) {
			int n = in.nextInt();
			int m = in.nextInt();
			int [][] lawn = new int [n][m];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					lawn[i][j] = in.nextInt();
				}
			}
			boolean possible = isPossible(lawn, n, m);
			out.print("Case #"+cs+": " + (possible ? "YES" : "NO"));
			out.println();
		}
		out.close();
	}
	
	private static boolean isPossible(int [][] lawn, int n, int m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int cur = lawn[i][j];
				int nMax = 0;
				for (int k = 0; k < n; k++) {
					nMax = Math.max(nMax, lawn[k][j]);
				}
				int mMax = 0;
				for (int k = 0; k < m; k++) {
					mMax = Math.max(mMax, lawn[i][k]);
				}
				if (cur < nMax && cur < mMax) {
					return false;
				}
			}
		}
		return true;
	}
}
