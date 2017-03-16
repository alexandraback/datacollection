import java.io.*;
import java.util.*;

public class Main implements Runnable {

	public void _main() throws IOException {	
		int numTests = nextInt();
		for (int test = 1; test <= numTests; test++) {
			double C = nextDouble();
			double F = nextDouble();
			double X = nextDouble();
			double ans = Double.POSITIVE_INFINITY;
			ans = Math.min(ans, f(C, F, X, 0));
			ans = Math.min(ans, f(C, F, X, 1));
			int best = (int)((X*F - C*F - 2*C) / (C*F));
			for (int k = best - 2; k <= best + 2; k++) {
				if (k >= 0) {
					ans = Math.min(ans, f(C, F, X, k));
				}
			}
			out.printf("Case #%d: %.7f\n", test, ans);
		}
	}

	private double f(double C, double F, double X, int k) {
		double sum = 0;
		for (int i = 0; i < k; i++) {
			sum += 1.0 / (2 + i*F);
		}
		return X / (2+k*F) + C*sum;		
	}


	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	private String next() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String rl = in.readLine();
			if (rl == null)
				return null;
			st = new StringTokenizer(rl);
		}
		return st.nextToken();
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	private long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	private double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.UK);
		new Thread(new Main()).start();
	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			in = new BufferedReader(new FileReader("B-small-attempt0.in"));
			out = new PrintWriter(new FileWriter("B-small-attempt0.out"));

			_main();

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(202);
		}
	}

}
