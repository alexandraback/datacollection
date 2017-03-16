import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static boolean winX, winO, haveFree;
	
	static void solve() throws Exception {
		char test[][] = new char[4][];
		winX = false;
		winO = false;
		haveFree = false;
		for (int i = 0; i < 4; i++) {
			test[i] = next().toCharArray();
			for (int j = 0; j < 4; j++) {
				if (test[i][j] == '.') {
					haveFree = true;
				}
			}
			test(test[i]);
		}
		char cur[] = new char[4];
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cur[j] = test[j][i];
			}
			test(cur);
		}
		for (int i = 0; i < 4; i++) {
			cur[i] = test[i][i];
		}
		test(cur);
		for (int i = 0; i < 4; i++) {
			cur[i] = test[i][3 - i];
		}
		test(cur);
		if (winX && winO) {
			throw new AssertionError();
		}
		printCase();
		if (winX) {
			out.println("X won");
		} else if (winO) {
			out.println("O won");
		} else if (haveFree) {
			out.println("Game has not completed");
		} else {
			out.println("Draw");
		}
	}
	
	static void test(char cur[]) {
		boolean x = true;
		boolean o = true;
		for (int i = 0; i < 4; i++) {
			if (cur[i] == 'T') {
				continue;
			}
			if (cur[i] != 'X') {
				x = false;
			}
			if (cur[i] != 'O') {
				o = false;
			}
		}
		if (x) {
			winX = true;
		}
		if (o) {
			winO = true;
		}
	}
	
	static void printCase() {
		out.print("Case #" + test + ": ");
	}
	
	static void printlnCase() {
		out.println("Case #" + test + ":");
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			int tests = nextInt();
			for (test = 1; test <= tests; test++) {
				solve();
			}
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}