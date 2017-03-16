import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A_1_counter {
	int[] x = new int[1000001];
	
	public void solve(final Scanner sc, final PrintWriter pw) {
		final int n = sc.nextInt();
		x[1] = 1;
		for (int i = 2; i <= n; ++i) {
			int t = x[i - 1];
			if (i % 10 != 0) {
				int a = i;
				int b = 0;
				while (a != 0) {
					b = b * 10 + a % 10;
					a /= 10;
				}
				if (b < i && t > x[b]) {
					t = x[b];
				}
			}
			x[i] = t + 1;
		}
		pw.println(x[n]);
	}
	
	public static void main(final String... args) throws IOException {
		final String fname = "A-small-attempt1";
		final Scanner sc = new Scanner(new File(fname + ".in"));
		final PrintWriter pw = new PrintWriter(fname + ".out");
		final int t = sc.nextInt();
		
		for (int i = 1; i <= t; ++i) {
			System.out.println(i);
			pw.print("Case #" + i + ": ");
			new A_1_counter().solve(sc, pw);
		}
		pw.close();
	}
}
