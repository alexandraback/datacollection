package codejam2012.r1a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;

/**
 * @author julian
 */
public class A {

	public static final void main(String[] args) throws IOException {
		(new A()).run();
	}

	public void run() throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("A.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("A.out"));
		int t = Integer.parseInt(in.readLine());
		for (int i = 0; i < t; i++) {
			StringTokenizer stok1 = new StringTokenizer(in.readLine());
			int a = Integer.parseInt(stok1.nextToken());
			int b = Integer.parseInt(stok1.nextToken());
			StringTokenizer stok2 = new StringTokenizer(in.readLine());
			double[] p = new double[a];
			for (int k = 0; k < a; k++) {
				p[k] = Double.parseDouble(stok2.nextToken());
			}
			out.write("Case #" + (i + 1) + ": " + solve(a, b, p) + "\n");
		}
		in.close();
		out.flush();
		out.close();
	}

	private double solve(int a, int b, double p[]) {
		double ret = b + 2;

		for (int k = a; k > 0; k--) {

			double v = 1;
			for (int i = 0; i < k; i++) {
				v *= p[i];
			}

			int backspaces = a - k;
			int good = b - k + 1 + backspaces;
			int wrong = 2 * b - k + 2 + backspaces;
			double expected = v * good + (1 - v) * wrong;
			ret = Math.min(ret, expected);
		}

		return ret;
	}

}
