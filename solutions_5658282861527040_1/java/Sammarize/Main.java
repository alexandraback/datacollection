import java.io.*;
import java.util.*;
import java.lang.reflect.*;


public class Main {

	static long CURRENT_TIME_NANO = System.nanoTime();

	public static void main(String[] args) throws Exception {

		int tests = next();

		for (int test = 1; test <= tests; test++) {
			int a = next();
			int b = next();
			int k = next();
			
			int[] as = new int[32];
			for (int i = 0; i < 31; i++) as[i] = a & ~((1 << i) - 1);
			int[] bs = new int[32];
			for (int i = 0; i < 31; i++) bs[i] = b & ~((1 << i) - 1);
			int[] ks = new int[32];
			for (int i = 0; i < 31; i++) ks[i] = k & ~((1 << i) - 1);

			long answ = 0;
			for (int t = 0; t <= 30; t++) if (ks[t + 1] != ks[t])
				for (int i = 0; i <= 30; i++) if (as[i + 1] != as[i])
					for (int j = 0; j <= 30; j++) if (bs[j + 1] != bs[j]) {
						long count = 1;
						for (int x = 0; x <= 30; x++) {
							int possa = 0;
							if (x >= i) {
								if (((as[i + 1] >> x) & 1) == 1) possa = 1;
							} else possa = 2;

							int possb = 0;
							if (x >= j) {
								if (((bs[j + 1] >> x) & 1) == 1) possb = 1;
							} else possb = 2;

							int possk = 0;
							if (x >= t) {
								if (((ks[t + 1] >> x) & 1) == 1) possk = 1;
							} else possk = 2;
							
							int mult1 = (possa >= 1 && possb >= 1) ? 1 : 0;
							int mult0 = 0;
							if (possa < 2 && possb < 2) if (possa == 0 || possb == 0) mult0 = 1;
							if (possa == 2 && possb == 0) mult0 = 2;
							if (possa == 2 && possb == 1) mult0 = 1;
							if (possa == 0 && possb == 2) mult0 = 2;
							if (possa == 1 && possb == 2) mult0 = 1;
							if (possa == 2 && possb == 2) mult0 = 3;
							if (possk == 0) count *= mult0;
							if (possk == 1) count *= mult1;
							if (possk == 2) count *= (mult0 + mult1);
						}
						answ += count;
					}
			out.println("Case #" + test + ": " + answ);
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