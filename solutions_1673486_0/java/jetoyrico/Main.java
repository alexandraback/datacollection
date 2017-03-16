import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("Main/input.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("Main/output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		A solver = new A();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class A {
	public void solve(int testNumber, Scanner in, PrintWriter out) {
		int A = in.nextInt(), B = in.nextInt();
		double[] p = new double[A];
		for (int i = 0; i < A; ++i) p[i] = in.nextDouble();
		double res = 2 + B;
		for (int back = 0; back <= A; ++back) {
			double cur = 0;
			for (int mask = 0; mask < two(A); ++mask) {
				double pp = 1;
				for (int i = 0; i < A; ++i)
					if (contain(mask, i))
						pp *= p[i];
					else
						pp *= 1 - p[i];
				if ((mask & two(A - back) - 1) == two(A - back) - 1)
					cur += pp * (back + (B-(A-back)) + 1);
				else
					cur += pp * (back + (B-(A-back)) + 1 + B + 1);
			}
			res = Math.min(res, cur);
		}
		out.print(String.format("Case #%d: %f\n", testNumber, res));
	}

	public static int two(int x) {
		return (1 << x);
	}

	public static boolean contain(int m, int x) {
		return (m & two(x)) != 0;
	}
}

