import java.io.*;
import java.util.*;
import static java.lang.Math.*;

/**
 * Google Code Jam 2012
 * Round 1B
 * Problem A
 * @author dalex
 */
public class A implements Runnable {
	
	BufferedReader in;
	PrintWriter out;
	StringTokenizer tok;

	public static void main(String[] args) {
		new Thread(null, new A(), "", 256 * (1L << 20)).start();
	}

	@Override
	public void run() {
		try {
			in = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");
			Locale.setDefault(Locale.US);
			tok = new StringTokenizer("");
			int tests = readInt();
			int p = tests / 10;
			long startTime = System.currentTimeMillis();
			for (int test = 1; test <= tests; test++) {
				out.printf("Case #%d: ", test);
				solveTest();
				if (p == 0 || test % p == 0 || test == tests) {
					long newTime = System.currentTimeMillis();
					System.err.printf("Test %d of %d completed, time = %d\n", test, tests, newTime - startTime);
				}
			}
			in.close();
			out.close();
		} catch (Throwable t) {
			t.printStackTrace(System.err);
			System.exit(-1);
		}
	}

	String readString() throws IOException {
		while (!tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	int readInt() throws IOException {
		return Integer.parseInt(readString());
	}

	long readLong() throws IOException {
		return Long.parseLong(readString());
	}

	double readDouble() throws IOException {
		return Double.parseDouble(readString());
	}
	
	void debug(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}

	// solution
	
	final double EPS = 1e-12;
	
	void solveTest() throws IOException {
		int n = readInt();
		int[] a = new int[n];
		int s = 0;
		for (int i = 0; i < n; i++) {
			a[i] = readInt();
			s += a[i];
		}
		double[] ans = new double[n];
		for (int x = 0; x < n; x++) {
			double[] b = new double[n-1];
			for (int i = 0, j = 0; i < n; i++) {
				if (i != x) {
					b[j++] = a[i];
				}
			}
			Arrays.sort(b);
			double left = 0, right = 1;
			for (int it = 0; it < 111; it++) {
				double p = (left + right) / 2;
				double thisScore = a[x] + p * s;
				boolean loses = true;
				double q = 1 - p;
				for (int i = 0; i < n-1; i++) {
					double need = thisScore - b[i];
					if (need < EPS) {
						break;
					}
					double needP = need / s;
					if (needP < q + EPS) {
						q -= needP;
					} else {
						loses = false;
						break;
					}
				}
				if (loses) {
					left = p;
				} else {
					right = p;
				}
			}
			ans[x] = (left + right) * 50;
		}
		for (int i = 0; i < n; i++) {
			out.printf("%.12f", ans[i]);
			if (i == n-1) out.println(); else out.print(" ");
		}
	}

}
