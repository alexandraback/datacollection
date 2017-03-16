import java.io.*;
import java.util.*;

public class CodeJamQualificationB 
{	
	//[i][j] represents (i (choose) j) % mod
	//O(n^2) **
	public static long[][] generateBinomialCoefficients(int n, long mod) {
		long[][] result = new long[n + 1][n + 1];
		if (mod == 1)
			return result;
		for (int i = 0; i <= n; i++) {
			result[i][0] = 1;
			for (int j = 1; j <= i; j++) {
				result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
				if (result[i][j] >= mod)
					result[i][j] -= mod;
			}
		}
		return result;
	}
	private static void solve() throws IOException {
		int T = nextInt();
		for(int t = 1; t <= T; t++) {
			int N = nextInt();
			int X = nextInt();
			int Y = nextInt();
			
			int row = (Math.abs(X) + Math.abs(Y)) / 2;
			int diamondRow = (int) Math.ceil( (-3 + Math.sqrt(9 + 8*(N-1)) ) / 4);
			System.out.println(diamondRow);
			double res = 0;
			if(diamondRow < row) {
				res = 0.0;
			} else if(diamondRow > row) {
				res = 1.0;
			} else {
				int totHeight = diamondRow * 2;
				int height = Y + 1;
				int used = (int) ( ( (diamondRow - 1) * 4 + 2 ) * (diamondRow / 2.0) );
				int left = N - used;
				if(totHeight + height <= left) {
					res = 1.0;
				} else if(height > left) {
					res = 0.0;
				} else if(height > totHeight) {
					if(2 * totHeight + 1 == left) {
						res = 1.0;
					} else {
						res = 0.0;
					}
				} else {
					long[][] choose = generateBinomialCoefficients(left, Long.MAX_VALUE);
					long totalGood = 0;
					for(int h = height; h <= left; h++) {
						totalGood += choose[left][h];
					}
					res = (double)totalGood / Math.pow(2, left);
				}
			}
			out.println("Case #" + t + ": " + res);
		}
	}
	
	public static void main(String[] args) {
		try {
			br = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter(new FileWriter("output.txt"));
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}