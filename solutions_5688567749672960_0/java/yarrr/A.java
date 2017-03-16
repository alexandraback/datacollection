import java.io.*;
import java.util.*;
import java.math.*;

public class A implements Runnable {
	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer st;
	private static Random rnd;

	private void solve() throws IOException {
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			out.print("Case #" + test + ": ");
			solveOne();
		}
	}

	private void solveOne() throws IOException {
		int value = nextInt();
		int[] minSteps = new int[value + 1];
		Arrays.fill(minSteps, Integer.MAX_VALUE / 2);
		minSteps[1] = 1;
		for (int i = 1; i < value; i++) {
			int reversed = reverse(i);
			minSteps[i + 1] = Math.min(minSteps[i + 1], minSteps[i] + 1);
			if (reversed > i && reversed <= value)
				minSteps[reversed] = Math.min(minSteps[reversed],
						minSteps[i] + 1);
		}
		out.println(minSteps[value]);
	}

	private int reverse(int n) {
		int m = 0;
		while (n != 0) {
			int digit = n % 10;
			m = (10 * m + digit);
			n /= 10;
		}
		return m;
	}

	public static void main(String[] args) {
		new A().run();
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