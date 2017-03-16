package bull;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class bull {
	public static void main(String[] args) throws IOException {
		BufferedReader r = new BufferedReader(new FileReader("bull.in"));
		PrintWriter w = new PrintWriter(new BufferedWriter(new FileWriter("bull.out")));

		int cases = in(r.readLine());
		for (int test = 1; test <= cases; ++test) {
			StringTokenizer tk = new StringTokenizer(r.readLine());
			long rad = lg(tk), paint = lg(tk);
			w.print("Case #");
			w.print(test);
			w.print(": ");
			w.println(getMax(rad, paint, 0, 1_414_213_564));
		}

		r.close();
		w.close();
	}

	private static long getMax(long r, long paint, long min, long max) {
		if (max < min)
			return max;
		long mid = (min + max) / 2;
		long size = getSize(r, mid);
		if (size > paint) {
			return getMax(r, paint, min, mid - 1);
		} else {
			return getMax(r, paint, mid + 1, max);
		}
	}

	private static long getSize(long r, long n) {
		long prefac = r + r + n + n - 1;
		if (Long.MAX_VALUE / prefac <= n)
			return Long.MAX_VALUE;
		return prefac * n;
	}

	private static final long lg(StringTokenizer tk) {
		return lg(tk.nextToken());
	}

	private static final long lg(String s) {
		return Long.parseLong(s);
	}

	private static final int in(StringTokenizer tk) {
		return in(tk.nextToken());
	}

	private static final int in(String s) {
		return Integer.parseInt(s);
	}
}
