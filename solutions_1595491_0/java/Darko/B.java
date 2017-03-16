import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {

	private int n, p, a[], memo[][];

	private void work() throws IOException {
		Scanner sc = new Scanner(new FileReader("B-small-attempt2.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("B-small-attempt2.out"));
		a = new int[200];
		memo = new int[200][200];
		int nc = sc.nextInt();
		for (int tc = 1; tc <= nc; tc++) {
			pw.printf("Case #%d: ", tc);
			n = sc.nextInt();
			int s = sc.nextInt();
			p = sc.nextInt();
			for (int i = 0; i < n; i++) {
				a[i] = sc.nextInt();
				Arrays.fill(memo[i], Integer.MIN_VALUE);
			}
			int res = go(0, s);
			if (res < 0)
				res = 0;
			pw.printf("%d\n", res);
		}
		pw.close();
	}

	private int go(int pos, int s) {
		if (pos == n)
			return s == 0 ? 0 : -200;
		if (memo[pos][s] > Integer.MIN_VALUE)
			return memo[pos][s];
		int k = a[pos] / 3;
		int m = a[pos] % 3;
		int max = k;
		if (m > 0)
			max++;
		int maxs = k + 1;
		if (m == 2)
			maxs++;
		int ret = (max >= p ? 1 : 0) + go(pos + 1, s);
		if (s > 0 && (k > 0 || m == 2)) {
			int t = (maxs >= p ? 1 : 0) + go(pos + 1, s - 1);
			if (t > ret)
				ret = t;
		}
		return memo[pos][s] = ret;
	}

	public static void main(String[] args) throws IOException {
		new B().work();
	}

}
