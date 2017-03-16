import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;

public class ProblemC {
	public static void main(String[] args) throws Exception {

		Scanner in = new Scanner(//
				// System.in
				new FileInputStream("c-small.in")
		// new FileInputStream("b-large.in")
		);
		PrintStream out = new PrintStream( //
				// System.out
				new FileOutputStream("c-small.out")
		// new FileOutputStream("b-large.out")
		);

		int T = in.nextInt();
		for (int i = 1; i <= T; i++) {
			int A = in.nextInt();
			int B = in.nextInt();
			int res = 0;
			for (int x = A; x < B; x++) {
				res += cycle(x, A, B);
			}
			out.println("Case #" + i + ": " + res);
		}
	}

	private static int cycle(int n, int A, int B) {
		int m = n;
		int digits = (int) Math.log10(n) + 1;
		if (digits == 1)
			return 0;
		int mul = 1;
		for (int i = 1; i < digits; i++)
			mul *= 10;
		int ret = 0;
		HashSet<Integer> used = new HashSet<Integer>();
		for (int i = 0; i < digits; i++) {
			m = (m / 10) + (m % 10) * mul;
			if (m > n && m != n && m <= B && !used.contains(m)) {
				ret++;
				used.add(m);
			}
		}
		return ret;
	}

}
