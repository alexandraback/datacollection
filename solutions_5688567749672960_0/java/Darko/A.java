import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {

	private void work() throws Exception {
		Scanner sc = new Scanner(new BufferedReader(new FileReader(
				"A-small-attempt0.in")));
		PrintWriter pw = new PrintWriter(new FileWriter("A-small-attempt0.out"));

		a = new int[1000001];
		a[1] = 1;

		int nc = sc.nextInt();
		for (int tc = 1; tc <= nc; tc++) {
			int n = sc.nextInt();
			for (int i = 1000; i < n; i += 1000) {
				go(i);
			}
			pw.printf("Case #%d: %d\n", tc, go(n));
		}
		sc.close();
		pw.close();
	}

	private int[] a;

	private int go(int x) {
		if (a[x] > 0)
			return a[x];
		int ret = 1 + go(x - 1);
		if (x % 10 != 0) {
			int inv = inv(x);
			if (inv < x) {
				int t = 1 + go(inv);
				if (t < ret)
					ret = t;
			}
		}
		return a[x] = ret;
	}

	private int inv(int x) {
		return Integer.parseInt(new StringBuilder(Integer.toString(x))
				.reverse().toString());
	}

	public static void main(String[] args) throws Exception {
		new A().work();
	}

}
