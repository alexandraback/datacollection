import java.io.*;
import java.util.*;
import java.math.*;

public class Domino implements Runnable {
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

	private void solveOne(int test) throws IOException {
		int x = nextInt(), r = nextInt(), c = nextInt();
		boolean fail = (r * c % x != 0);

		for (int w = 1; w <= x; w++) {
			for (int h = 1; h <= x; h++) {
				int parts = w + h - 1;

				if (parts <= x) {
					if ((w > r || h > c) && (w > c || h > r)) {
						fail = true;
					}
				}
			}
		}

		out.println("Case #" + test + ": " + (!fail ? "GABRIEL" : "RICHARD"));
	}

	public static void main(String[] args) {
		new Domino().run();
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