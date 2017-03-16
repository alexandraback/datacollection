import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class B {
	public static void main(String args[]) throws Exception {
		Scanner in = new Scanner(new File("in.txt"));
		BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));
		long T = in.nextLong();

		for (long num = 1; num <= T; num++) {
			int N = in.nextInt();
			int X = in.nextInt();
			int Y = in.nextInt();

			int S = Math.abs(X) + Y;

			int s = 1;
			int c = 0;

			for (long n = 2;; n += 2) {
				if (s + n + n + 1 <= N) {
					s += n + n + 1;
					c += 2;
				} else
					break;
			}

			if (S <= c) {
				out.write("Case #" + num + ": 1.0\n");
				continue;
			}

			if (X == 0) {
				out.write("Case #" + num + ": 0.0\n");
				continue;
			}

			int A = N - s;

			double d[] = new double[A + 1];
			double prob = Math.pow(.5, A);

			for (int n = 0; n <= A; n++) {
				d[n] = prob * choose(A, n);
			}

			//c += 2;
			double ans = 0;
			for (int n = 0; n < d.length; n++) {
				if (n > Y) {
					ans += d[n];
				} else if (A - n > c && A - c > Y) {
					ans += d[n];
				}
			}

			out.write("Case #" + num + ": " + ans + "\n");
		}

		in.close();
		out.close();
	}

	public static long choose(long n, long r) {
		long nf = fact(n);
		long rf = fact(r);
		long nrf = fact(n - r);
		long npr = nf / nrf;
		long ncr = npr / rf;
		return ncr;
	}

	public static long fact(long n) {
		long result = 1;
		for (long j = n; j >= 1; j--)
			result = result * j;
		return result;
	}
}