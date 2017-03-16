import java.io.*;
import java.util.*;
import static java.lang.Math.*;

/**
 * Google Code Jam 2012
 * Round 1A
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
	
	void solveTest() throws IOException {
		int a = readInt();
		int b = readInt();
		double[] p = new double[a];
		for (int i = 0; i < a; i++) {
			p[i] = readDouble();
		}
		double[] s = new double[a + 1];
		s[0] = 1;
		for (int i = 1; i <= a; i++) {
			s[i] = s[i-1] * p[i-1];
		}
		double best = 1 + b + 1;
		for (int back = 0; back <= a; back++) {
			double good = s[a - back];
			double bad = 1 - good;
			int goodCnt = back + (b - a + back) + 1;
			int badCnt = goodCnt + b + 1;
			double cur = good * goodCnt + bad * badCnt;
			best = min(best, cur);
		}
		out.printf("%.12f\n", best);
	}

}
