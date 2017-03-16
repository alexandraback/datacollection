import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A_2_counter {
	public long calc(final long x) {
		if (x % 10 == 0) {
			return calc(x - 1) + 1;
		}
		if (x < 21) {
			return x;
		}
		long bestjump = 0;
		long best = -1;
		long bestrev = -1;
		long t = 10;
		for (; t < x; t *= 10) {
			long slow = x / t * t + 1;
			long a = slow;
			long rev = 0;
			while (a != 0) {
				rev = rev * 10 + a % 10;
				a /= 10;
			}
			long jump = slow - rev - x + slow;
			if (jump > bestjump) {
				bestjump = jump;
				best = slow;
				bestrev = rev;
			}
		}
		if (bestjump == 0) {
			t = t / 10 - 1;
			return calc(t) + x - t;
		}
		return calc(bestrev) + x - best + 1;
	}
	
	public void solve(final Scanner sc, final PrintWriter pw) {
		final long n = sc.nextLong();
		pw.println(calc(n));
	}
	
	public static void main(final String... args) throws IOException {
		final String fname = "A-large";
		final Scanner sc = new Scanner(new File(fname + ".in"));
		final PrintWriter pw = new PrintWriter(fname + ".out");
		final int t = sc.nextInt();
		
		for (int i = 1; i <= t; ++i) {
			System.out.println(i);
			pw.print("Case #" + i + ": ");
			new A_2_counter().solve(sc, pw);
		}
		pw.close();
	}
}
