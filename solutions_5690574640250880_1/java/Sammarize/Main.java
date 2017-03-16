import java.io.*;
import java.util.*;
import java.lang.reflect.*;


public class Main {

	static long CURRENT_TIME_NANO = System.nanoTime();

	public static void main(String[] args) throws Exception {

		int tests = next();

		for (int test = 1; test <= tests; test++) {
			int n = next();
			int m = next();

			boolean[][] mine = new boolean[n][m];
			int c = next();

			boolean can = true;

			if (c == n * m - 1) {
				for (int i = 0; i < n; i++)
					Arrays.fill(mine[i], true);
				mine[n - 1][m - 1] = false;
			} else {

			if (n >= 3 && m >= 3) {
				for (int i = 0; i < n - 2 && c > 0; i++)
					for (int j = 0; j < m - 2 && c > 0; j++) {
						mine[i][j] = true;
						c--;
					}

				if (c % 2 == 1) {
					c++;
					mine[n - 3][m - 3] = false;
				}
				for (int i = 0; i < (mine[n - 3][m - 3] ? (n - 2) : (n - 3)) && c > 0; i++) {
					mine[i][m - 2] = true;
					mine[i][m - 1] = true;
					c -= 2;
				}

				for (int j = 0; j < (mine[n - 3][m - 3] ? (m - 2) : (m - 3)) && c > 0; j++) {
					mine[n - 2][j] = true;
					mine[n - 1][j] = true;
					c -= 2;
				}

				if (c > 0) can = false;


			} else {
				boolean flip = n > m;
				if (n > m) {int t = n; n = m; m = t; mine = new boolean[n][m];}

				if (n == 2) {
					if (c % 2 == 0 && c <= n*m - 4) {
						for (int i = 0; c > 0; i++) {
							mine[0][i] = true;
							mine[1][i] = true;
							c -= 2;
						}
					} else can = false;
				} else {
					if (c <= m - 1) for (int i = 0; i < c; i++) mine[0][i] = true;
					else can = false;
				}

				if (flip) {
					boolean[][] mine2 = new boolean[m][n];
					for (int i = 0; i < n; i++)
						for (int j = 0; j < m; j++) mine2[j][i] = mine[i][j];

					mine = mine2;
					{int t = n; n = m; m = t;}
				}
			}

			}

			if (!can) out.print("Case #" + test + ":\nImpossible\n");
			else {
				out.print("Case #" + test + ":\n");
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++)
						out.print(mine[i][j] ? '*' : (i == n - 1 && j == m - 1 ? 'c' : '.'));
					out.println();
				}
			}

		}

		out.close();
	}
	
	static void printtime() {System.out.println((System.nanoTime() - CURRENT_TIME_NANO)*1e-9);}
	static void nexttime() {printtime(); CURRENT_TIME_NANO = System.nanoTime();}
	static PrintWriter out = new PrintWriter(System.out);
	
	static BufferedReader bufferedreader = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer in = new StringTokenizer("");

	static String nextToken() throws Exception {
		if (!in.hasMoreTokens()) in = new StringTokenizer(bufferedreader.readLine());
		return in.nextToken();
	}

	static int next()  throws Exception {return Integer.parseInt(nextToken());};
	static int[] next(int n) throws Exception {
		int[] x = new int[n];
		for (int i = 0; i < n; i++) x[i] = next();
		return x;
	}
	static int[][] next(int n, int m) throws Exception {
		int[][] x = new int[n][];
		for (int i = 0; i < n; i++) x[i] = next(m);
		return x;
	}

	static long nextl() throws Exception {return Long.parseLong(nextToken());};
	static long[] nextl(int n) throws Exception {
		long[] x = new long[n];
		for (int i = 0; i < n; i++) x[i] = nextl();
		return x;
	}
	static long[][] nextl(int n, int m) throws Exception {
		long[][] x = new long[n][];
		for (int i = 0; i < n; i++) x[i] = nextl(m);
		return x;
	}

	static double nextd() throws Exception {return Double.parseDouble(nextToken());};
	static double[] nextd(int n) throws Exception {
		double[] x = new double[n];
		for (int i = 0; i < n; i++) x[i] = nextd();
		return x;
	}
	static double[][] nextd(int n, int m) throws Exception {
		double[][] x = new double[n][];
		for (int i = 0; i < n; i++) x[i] = nextd(m);
		return x;
	}

	static String nextline() throws Exception {
		in = new StringTokenizer("");
		return bufferedreader.readLine();
	}

	static void sout(long x) {System.out.println(x);}
	static void sout(String s) {System.out.println(s);}
	static void sout(int[] x) {for (int xx : x) System.out.print(xx + " "); System.out.println();}
	static void sout(long[] x) {for (long xx : x) System.out.print(xx + " "); System.out.println();}
	static void sout(int[][] x) {for (int[] xx : x) sout(xx); System.out.println();}
	static void sout(long[][] x) {for (long[] xx : x) sout(xx); System.out.println();}


}