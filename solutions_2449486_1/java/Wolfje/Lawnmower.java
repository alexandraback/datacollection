import static java.lang.Math.max;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class Lawnmower {
	String PROBLEM_ID = "problemB";

	enum TestType {
		EXAMPLE, SMALL, LARGE
	}

//	 TestType TYPE = TestType.EXAMPLE;
//	 TestType TYPE = TestType.SMALL;
	TestType TYPE = TestType.LARGE;

	public String getFileName() {
		String result = PROBLEM_ID + "_";
		switch (TYPE) {
		case EXAMPLE:
			result += "example";
			break;
		case SMALL:
			result += "small";
			break;
		case LARGE:
			result += "large";
			break;
		}
		return result;
	}

	public String getInFileName() {
		return getFileName() + ".in";
	}

	public String getOutFileName() {
		return getFileName() + ".out";
	}

	public static void main(String[] args) throws Exception {
		new Lawnmower();
	}

	public Lawnmower() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(getInFileName()));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				getOutFileName())));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			int n = scan.nextInt();
			int m = scan.nextInt();
			int[][] map = new int[n][m];
			int[] maxRow = new int[n];
			int[] maxCol = new int[m];
			for ( int r = 0; r < n; r++) {
				for ( int c = 0; c < m; c++) {
					int z = scan.nextInt();
					maxRow[r] = max(maxRow[r], z);
					maxCol[c] = max(maxCol[c], z);
					map[r][c] = z;
				}
			}
			boolean ok = true;
			for ( int r = 0; r < n; r++) 
				for ( int c = 0; c < m; c++ ) {
					ok &= (map[r][c] >= maxRow[r] || map[r][c] >= maxCol[c] );
				}
			String resultStr = String.format("Case #%d: %s", test + 1, ok ? "YES": "NO");
			// add answer here

			System.out.println(resultStr);
			out.println(resultStr);
		}
		out.close();
		System.out.println("*** in file =  " + getInFileName());
		System.out.println("*** out file = " + getOutFileName());
	}
}
