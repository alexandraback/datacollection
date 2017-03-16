import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		try {
			inputStream = new FileInputStream("a.in");
			outputStream = new FileOutputStream("a.out");
		} catch (FileNotFoundException e) {
			System.err.println("File not found");
			return;
		}
		
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Solver solver = new Solver();
		int n = in.nextInt();
		
		for (int i = 1; i <= n; i++) {
			solver.solve(i, in, out);
		}
		
		out.close();
	}
}

class Solver {
	public static final double EPS = 1e-9;
	public static final int NUM_STEPS = 100;
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		int n = in.nextInt();
		int[] s = new int[n];
		for (int i = 0; i < n; i++) {
			s[i] = in.nextInt();
		}
		out.print("Case #");
		out.print(testNumber);
		out.print(": ");
		for (int i = 0; i < n; i++) {
			double l = 0.0;
			double r = 1.0;
			for (int j = 0; j < NUM_STEPS; j++) {
				double m = (l + r) / 2;
				if (check(n, i, s, m)) {
					r = m;
				} else {
					l = m;
				}
			}
			out.format("%.6f ", l * 100);
		}
		out.println();
	}
	private boolean check(int n, int m, int[] s, double x) {
		int jury = 0;
		for (int i = 0; i < n; i++) {
			jury += s[i];
		}
		double sum = s[m] + x * jury + EPS;
		double rest = 1.0 - x;
		for (int i = 0; i < n; i++) {
			if (i == m)
				continue;
			double nx = (sum - s[i]) / jury;
			if (nx > 0)
				rest -= nx;
			if (rest < -EPS)
				return true;
		}
		return false;
	}
}

class InputReader {
	private BufferedReader reader;
	private StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream));
		tokenizer = null;
	}

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}
}
