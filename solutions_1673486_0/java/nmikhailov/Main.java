import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Locale;
import java.util.StringTokenizer;

public class Main implements Runnable {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		(new Thread(new Main())).start();
	}

	StringTokenizer st;
	BufferedReader in;
	PrintWriter out;

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			// in = new BufferedReader(new FileReader("input"));
			//out = new PrintWriter(System.out);
			out = new PrintWriter("out.txt");
			solve();
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			out.flush();
			out.close();
		}
	}

	String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}

	int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws NumberFormatException, IOException {
		return Long.parseLong(nextToken());
	}

	double calc() throws NumberFormatException, IOException {
		int A = nextInt(), B = nextInt();
		double[] p = new double[A];
		double mul = 1;
		for (int i = 0; i < A; i++) {
			p[i] = nextDouble();
			mul *= p[i];
		}
		// Strategy 1
		double s1 = (mul * (B - A + 1)) + (1 - mul) * (B - A + 1 + B + 1);
		//out.println("s1 => " + s1);
		// Strategy 2
		double s2 = 1e6, curM = 1.0;
		for (int i = 0; i < A; i++) {
			
			double i2 = A - i;
			double st = (curM * (i2 + (B - (A - i2)) + 1) + (1 - curM)
					* (i2 + (B - (A - i2)) + 1 + B + 1));
			s2 = Math.min(s2, st);
			
			curM *= p[i];
			//out.println("st => " + st);
		}
		// Strategy 3
		double s3 = B + 2;
		//out.println("s3 => " + s3);
		
		double res = Math.min(s1, Math.min(s2, s3));
		//out.println(res);
		return res;
	}

	private double nextDouble() throws NumberFormatException, IOException {
		return Double.parseDouble(nextToken());
	}

	void solve() throws Exception {
		int T = nextInt();
		for (int TT = 0; TT < T; TT++) {
			out.printf(Locale.US, "Case #%d: %.8f\n", TT + 1, calc());
		}
	}
}
