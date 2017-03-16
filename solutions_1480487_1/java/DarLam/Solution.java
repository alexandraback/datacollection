import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;


public class Solution implements Runnable {
	
	private static final double eps = 1e-9;
	
	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;
	
	private double[] solve(int[] s) {
		int n = s.length;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += s[i];
		}
		double[] jx = new double[n];
		for (int i = 0; i < n; i++) {
			jx[i] = 1.0 * s[i] / sum;
		}
		double[] result = new double[s.length];
		for (int i = 0; i < s.length; i++) {
			result[i] = 100 * find(jx, i);
		}
		return result;
	}
	
	private double find(double[] jx, int i) {
		double dv = 0.0;
		double uv = 1.0;
		while (true) {
			double m = (dv + uv) / 2;
			if (uv > eps && dv == m || uv == m) {
				break;
			}
			if (cant(jx, i, m)) {
				uv = m;
			} else {
				dv = m;
			}
		}
		return uv;
	}

	private boolean cant(double[] jx, int i, double m) {
		double fs = jx[i] + m;
		double rem = 1.0 - m;
		for (int op = 0; op < jx.length; op++) {
			if (op == i) {
				continue;
			}
			double need = fs - jx[op];
			if (need < 0) {
				need = 0;
			}
			rem -= need;
		}
		return rem <= 0;
	}

	private void solve() throws IOException {
		int t = nextInt();
		for (int test = 1; test <= t; test++) {
			int n = nextInt();
			int[] s = new int[n];
			for (int i = 0; i < n; i++) {
				s[i] = nextInt();
			}
			double[] answer = solve(s);
			out.print("Case #" + test + ":");
			for (int i = 0; i < n; i++) {
				out.print(" " + answer[i]);
			}
			out.println();
		}
	}

	@Override
	public void run() {
		try {
			solve();
		} catch (Throwable e) {
			apstenu(e);
		} finally {
			out.close();
		}
	}
	
	private int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	private String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}
	
	private void apstenu(Throwable e) {
		e.printStackTrace();
		System.exit(1);
	}
	
	public Solution(String filename) {
		try {
			in = new BufferedReader(new FileReader(filename + ".in"));
			st = new StringTokenizer("");
			out = new PrintWriter(new FileWriter(filename + ".out"));
		} catch (IOException e) {
			apstenu(e);
		}
	}
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new Solution("data").run();
	}
	
}
