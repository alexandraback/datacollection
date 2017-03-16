package R0;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Locale;
import java.util.PriorityQueue;
import java.util.Scanner;

// Infinite House of Pancakes
public class B {

	private static Scanner sc;
	private static PrintStream out;

	static int mskip;
	static PriorityQueue<Integer> q;

	static void add(int a) {
		if ( a < 4 )
			mskip = Math.max(mskip, a);
		else
			q.offer(a);
	}

	private static void solve(int TC) {
		int N = ni();
		q = new PriorityQueue<>(2 * N, (a, b) -> b - a);
		mskip = 0;
		for (int i = 0; i < N; i++)
			add(ni());

		int ret = Integer.MAX_VALUE;
		for (int i = 0; i < ret; i++) {
			if ( q.isEmpty() ) {
				ret = Math.min(ret, i + mskip);
				break;
			}
			int m = q.poll();
			ret = Math.min(ret, i + m);
			if ( m == 9 && (q.isEmpty() || (q.size() == 1 && q.peek() == 6)) ) {
				q.offer(6);
				continue;
			}
			int a = m >> 1;
			add(a);
			add(m - a);
		}
		out.println(String.format("Case #%d: %d", TC, ret));
	}

	public static void main(String[] args) throws FileNotFoundException {
		Locale.setDefault(Locale.ROOT);

		String file = "src/R0/B.sm";
		sc = new Scanner(new FileInputStream(file + ".in"));
		out = new PrintStream(file + ".out");

		int TC = ni();
		for (int i = 1; i <= TC; i++)
			solve(i);
	}

	private static int ni() {
		return sc.nextInt();
	}
}
