import java.io.*;
import java.util.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Solution implements Runnable {
	
	boolean check (char s [][], char c) {
		int count = 0;
		for (int i = 0; i < 4; i++) {
			count = 0;
			for (int j = 0; j < 4; j++) {
				if (s[i][j] == 'T' || s[i][j] == c)
					count++;
				else
					break;
			}
			if (count == 4) return true;
		}
		for (int j = 0; j < 4; j++) {
			count = 0;
			for (int i = 0; i < 4; i++) {
				if (s[i][j] == 'T' || s[i][j] == c)
					count++;
				else
					break;
			}
			if (count == 4) return true;
		}
		
		count = 0;
		for (int i = 0; i < 4; i++) {
			if (s[i][i] == 'T' || s[i][i] == c)
				count++;
			else
				break;
		}
		if (count == 4) return true;
		count = 0;
		for (int i = 0; i < 4; i++) {
			if (s[i][4 - i - 1] == 'T' || s[i][4 - i - 1] == c)
				count++;
			else
				break;
		}
		if (count == 4) return true;
		return false;
	}
	
	boolean allFilled(char s [][]) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (s[i][j] == '.') return false;
			}
		}
		return true;
	}
	
	public void solve() throws Throwable {
		int tests = sc.nextInt();
		for (int test = 1; test <= tests; test++) {
			char s [][] = new char[4][4];
			for (int i = 0; i < 4; i++) {
				s[i] = sc.nextToken().toCharArray();
			}
			out.print("Case #"+test+": ");
			if (check(s, 'X')) {
				out.println("X won");
			} else if (check(s, 'O')) {
				out.println("O won");
			} else if (allFilled(s)) {
				out.println("Draw");
			} else {
				out.println("Game has not completed");
			}
		}
	}

	BufferedReader in;
	PrintWriter out;
	FastScanner sc;

	static Throwable uncaught;

	@Override
	public void run() {
		try {
			in = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter(new FileWriter("output.txt"));
			sc = new FastScanner(in);
			solve();
		} catch (Throwable t) {
			Solution.uncaught = t;
		} finally {
			out.close();
		}
	}

	public static void main(String[] args) throws Throwable {
		Thread t = new Thread(null, new Solution(), "", (1 << 26));
		t.start();
		t.join();
		if (uncaught != null) {
			throw uncaught;
		}
	}

}

class FastScanner {

	BufferedReader reader;
	StringTokenizer strTok;

	public FastScanner(BufferedReader reader) {
		this.reader = reader;
	}

	public String nextToken() throws IOException {
		while (strTok == null || !strTok.hasMoreTokens()) {
			strTok = new StringTokenizer(reader.readLine().trim());
		}
		return strTok.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

}