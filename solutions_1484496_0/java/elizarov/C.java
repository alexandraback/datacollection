package round1B;

import java.io.*;
import java.util.Scanner;

/**
 * @author Roman Elizarov
 */
public class C {
	public static void main(String[] args) throws IOException {
		new C().go();
	}

	Scanner in;
	PrintWriter out;

	private void go() throws IOException  {
		in = new Scanner(new File("src\\round1B\\c.in"));
		out = new PrintWriter(new File("src\\round1B\\c.out"));
		int t = in.nextInt();
		for (int tn = 1; tn <= t; tn++) {
			out.println("Case #" + tn + ": ");
			solveCase();
		}
		in.close();
		out.close();
	}

	int n;
	long[] s;

	private void solveCase() {
		n = in.nextInt();
		s = new long[n];
		for (int i = 0; i < n; i++)
			s[i] = in.nextLong();
		int k = 1 << n;
		long[] sum = new long[k];
		for (int i = 0; i < k; i++) {
			long ss = 0;
			for (int j = 0; j < n; j++)
				if ((i & (1 << j)) != 0)
					ss += s[j];
			sum[i] = ss;
		}
		for (int i = 1; i < k; i++) {
			for (int j = k; (j = (j - 1) & ~i) > 0;) {
				if (sum[i] == sum[j]) {
					print(i);
					print(j);
					return;
				}
			}
		}
		out.println("impossible");
	}

	private void print(int i) {
		boolean first = true;
		for (int j = 0; j < n; j++)
			if ((i & (1 << j)) != 0) {
				if (first)
					first = false;
				else
					out.print(' ');
				out.print(s[j]);
			}
		out.println();
	}
}
