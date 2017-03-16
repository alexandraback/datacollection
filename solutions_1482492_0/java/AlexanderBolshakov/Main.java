import java.io.*;
import java.security.SecureRandom;
import java.util.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Main implements Runnable {
	
	static String filename = "B-small-attempt0";
	
	double findt(double a, double b, double c) {
		double d = b * b - 4 * a * c;
		if (d < 0) {
			d = 0;
			throw new RuntimeException();
		}
		return (-b + sqrt(d)) / (2 * a);
	}
	
	public void solve() throws Exception {
		int tests = sc.nextInt();
		for (int Case = 1; Case <= tests; Case++) {
			double d = sc.nextDouble();
			int n = sc.nextInt(), a = sc.nextInt();
			double[] t = new double[n];
			double[] x = new double[n];
			for (int i = 0; i < n; i++) {
				t[i] = sc.nextDouble();
				x[i] = sc.nextDouble();
			}
			double[] acc = new double[a];
			for (int i = 0; i < a; i++) {
				acc[i] = sc.nextDouble();
			}
			if (x[n - 1] > d) {
				while (n > 1 && x[n - 2] > d) {
					n--;
				}
				if (n == 1) {
					x[n - 1] = d;
				} else {
					double len = x[n - 1] - x[n - 2];
					double time = t[n - 1] - t[n - 2];
					double v = len / time;
					double newtime = (d - x[n - 2]) / v;
					t[n - 1] = t[n - 2] + newtime;
					x[n - 1] = d;
				}
			}
			out.printf(Locale.US, "Case #%d:\n", Case);
			for (int i = 0; i < a; i++) {
				double myx = 0;
				double myv = 0;
				for (int j = 0; j < n; j++) {
					double v = j == 0 ? 0 : (x[j] - x[j - 1]) / (t[j] - t[j - 1]);
					double time = findt(acc[i] / 2, myv - v, j == 0 ? 0 : myx - x[j - 1]);
					if (j == n - 1) {
						if (time >= t[j]) {
							out.printf(Locale.US, "%.18f\n", (j == 0 ? 0 : t[j - 1]) + findt(acc[i] / 2, myv, myx - d));
						} else {
							out.printf(Locale.US, "%.18f\n", t[j]);
						}
					}
					if (time >= t[j]) {
						myx += myv * t[j] + acc[i] * t[j] * t[j] / 2;
						myv += acc[i] * t[j];
					} else {
						double newt = findt(acc[i] / 2, myv, myx - x[j]);
						myx = x[j];
						myv = v + newt * acc[i];
					}
				}
			}
		}
		//out.println(findt(0.5, 1e-5, -1e4 + 0.1));
	}
	
	BufferedReader in;
	PrintWriter out;
	FastScanner sc;
	
	
	public static void main(String[] args) {
		new Thread(null, new Main(), "", 1 << 25).start();
	}
	
	@Override
	public void run() {
		try {
			init();
			solve();
		} catch (Exception e) {
			throw new RuntimeException(e);
		} finally {
			out.close();
		}
	}
	
	void init() throws Exception {
		in = new BufferedReader(new FileReader(filename + ".in"));
		out = new PrintWriter(new FileWriter(filename + ".out"));
		sc = new FastScanner(in);
	}
}

class FastScanner {
	
	BufferedReader reader;
	StringTokenizer strTok;
	
	public FastScanner(BufferedReader reader) {
		this.reader = reader;
	}
	
	public String nextToken() throws IOException {
		while (strTok == null || !strTok.hasMoreTokens()) {
			strTok = new StringTokenizer(reader.readLine());
		}
		
		return strTok.nextToken();
	}
	
	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	public long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	
	public double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
	
	public BigInteger nextBigInteger() throws IOException {
		return new BigInteger(nextToken());
	}
	
}
