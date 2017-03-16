import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {

	private int n, lim, m[], memo[][];

	private void work() throws IOException {
		// Scanner sc = new Scanner(new FileReader("A.in"));
		// PrintWriter pw = new PrintWriter(new FileWriter("A.out"));
		Scanner sc = new Scanner(new FileReader("A-small-attempt3.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("A-small-attempt3.out"));
		// Scanner sc = new Scanner(new FileReader("A-large.in"));
		// PrintWriter pw = new PrintWriter(new FileWriter("A-large.out"));
		int nc = sc.nextInt();
		for (int tc = 1; tc <= nc; tc++) {
			int a = sc.nextInt();
			n = sc.nextInt();
			m = new int[n];
			lim = 1;
			for (int i = 0; i < n; i++) {
				m[i] = sc.nextInt();
				if (m[i] + 1 > lim)
					lim = m[i] + 1;
			}
			if (a > lim) {
				pw.printf("Case #%d: %d\n", tc, 0);
				continue;
			}
			memo = new int[n][lim + 1];
			for (int i = 0; i < n; i++) {
				Arrays.fill(memo[i], -1);
			}
			Arrays.sort(m);
			pw.printf("Case #%d: %d\n", tc, go(a, 0));
		}
		pw.close();
		sc.close();
	}

	private int go(int a, int k) {
		if (k == n)
			return 0;
		if (memo[k][a] >= 0)
			return memo[k][a];
		int ret = 1 + go(a, k + 1);
		if (m[k] < a) {
			int t = go(Math.min(a + m[k], lim), k + 1);
			if (t < ret)
				ret = t;
		}
		if (a > 1) {
			int tt = 0;
			int na = a;
			while (true) {
				tt++;
				na += na - 1;
				if (na > lim)
					break;
				if (na > m[k]) {
					int t = tt + go(Math.min(na + m[k], lim), k + 1);
					if (t < ret)
						ret = t;
				}
			}
			int t = tt + go(lim, k + 1);
			if (t < ret)
				ret = t;

		}
		return memo[k][a] = ret;
	}

	public static void main(String[] args) throws IOException {
		new A().work();
	}

}
