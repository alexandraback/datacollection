import java.io.*;
import java.util.*;
import java.math.*;

public class Dijkstra implements Runnable {
	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer st;
	private static Random rnd;

	private void solve() throws IOException {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			solveOne(test);
		}
	}

	final int[][] multTable = { { -1, -1, -1, -1, -1 }, { -1, 1, 2, 3, 4 },
			{ -1, 2, -1, 4, -3 }, { -1, 3, -4, -1, 2 }, { -1, 4, 3, -2, -1 } };
	final int[][] reverseMultTable = doReverse(multTable);

	private void solveOne(int test) throws IOException {
		int stringLength = nextInt();
		long timesRepeat = nextLong();
		long totalLength = timesRepeat * stringLength;
		String letters = nextToken();
		int[] convertedLetters = new int[stringLength];
		for (int i = 0; i < stringLength; i++) {
			convertedLetters[i] = convertLetter(letters.charAt(i));
		}
		int result = 1;
		for (int i = 0; i < stringLength; i++) {
			result = doMult(result, convertedLetters[i], multTable);
		}
		result = doPow(result, timesRepeat, multTable);
		boolean fail = (result != -1);

		if (!fail) {
			long firstIPos = -1, lastKPos = -1;

			final int buben = (int) Math.min(4 * stringLength, totalLength);

			{
				int currentResult = 1;
				for (int i = 0; i < buben; i++) {
					currentResult = doMult(currentResult, convertedLetters[i
							% stringLength], multTable);
					if (currentResult == 2) {
						firstIPos = i;
						break;
					}
				}
			}

			{
				int currentResult = 1;
				for (int i = 0; i < buben; i++) {
					long pos = (totalLength - i - 1);
					currentResult = doMult(currentResult,
							convertedLetters[(int) (pos % stringLength)],
							reverseMultTable);
					if (currentResult == 4) {
						lastKPos = pos;
						break;
					}
				}
			}

			if (firstIPos == -1 || lastKPos == -1 || firstIPos >= lastKPos) {
				fail = true;
			}
		}

		out.println("Case #" + test + ": " + (fail ? "NO" : "YES"));
	}

	private int doPow(int n, long p, int[][] table) {
		if (p == 0)
			throw new AssertionError();
		if (p == 1)
			return n;
		if (p % 2 == 0) {
			int t = doPow(n, p / 2, table);
			return doMult(t, t, table);
		} else {
			return doMult(doPow(n, p - 1, table), n, table);
		}
	}

	private int[][] doReverse(int[][] a) {
		int n = a.length;
		int[][] b = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				b[i][j] = a[j][i];
			}
		}
		return b;
	}

	private int doMult(int a, int b, int[][] table) {
		int sign = 1;
		if (a < 0) {
			sign = -sign;
			a = -a;
		}
		if (b < 0) {
			sign = -sign;
			b = -b;
		}
		return sign * table[a][b];
	}

	private int convertLetter(char c) {
		if (c == 'i')
			return 2;
		else if (c == 'j')
			return 3;
		else
			return 4;
	}

	public static void main(String[] args) {
		new Dijkstra().run();
	}

	public void run() {
		try {
			final String className = this.getClass().getName().toLowerCase();

			try {
				in = new BufferedReader(new FileReader(className + ".in"));
				out = new PrintWriter(new FileWriter(className + ".out"));
				// in = new BufferedReader(new FileReader("input.txt"));
				// out = new PrintWriter(new FileWriter("output.txt"));
			} catch (FileNotFoundException e) {
				in = new BufferedReader(new InputStreamReader(System.in));
				out = new PrintWriter(System.out);
			}

			rnd = new Random();

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(42);
		}
	}

	private String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = in.readLine();

			if (line == null)
				return null;

			st = new StringTokenizer(line);
		}

		return st.nextToken();
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}