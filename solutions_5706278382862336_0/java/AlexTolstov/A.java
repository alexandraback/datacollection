import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {

	private static final String path = "/home/tolstov.a.a/codejam/a/";

	private static final String problem = "A-small";

	Scanner in;

	PrintWriter out;

	long gcd(long a, long b) {
		if (a % b == 0) {
			return b;
		} else {
			return gcd(b, a % b);
		}
	}

	void solveOne() {
		String str = in.next();
		long first = Long.parseLong(str.substring(0, str.indexOf('/')));
		long second = Long.parseLong(str.substring(str.indexOf('/') + 1));

		if (second == 0 && first == 0) {
			out.print("impossible");
			return;
		}

		long div = gcd(first, second);
		first /= div;
		second /= div;

		boolean isGood = false;
		for (long p = 0; p <= 12; p++) {
			if (second == (1L << p)) {
				isGood = true;
				break;
			}
		}
		if (!isGood || first > second) {
			out.print("impossible");
			return;
		}

		int level = 1;
		while (first * 2L < second) {
			first *= 2L;
			level++;
		}
		out.print(level);

	}

	void solve() {
		int nTests = in.nextInt();
		for (int i = 1; i <= nTests; i++) {
			out.print("Case #" + i + ": ");
			solveOne();
			out.println();
		}
	}

	void run() {
		try {
			in = new Scanner(new FileReader(path + problem + ".in"));
			out = new PrintWriter(path + problem + ".out");
		} catch (IOException e) {
			in = new Scanner(System.in);
			out = new PrintWriter(System.out);
			out.println("cmd>");
			out.flush();
		}
		try {
			solve();
		} finally {
			out.close();
		}
	}

	public static void main(String[] args) {
		new A().run();
	}
}
