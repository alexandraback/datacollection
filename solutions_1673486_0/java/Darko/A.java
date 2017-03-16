import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {

	private int n, total;
	private double[] p, c, memo;

	private void work() throws IOException {
		Scanner sc = new Scanner(new FileReader("A-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("A-small-attempt0.out"));
		// Scanner sc = new Scanner(new FileReader("a.in"));
		// PrintWriter pw = new PrintWriter(new FileWriter("a.out"));
		int nc = sc.nextInt();
		p = new double[100010];
		c = new double[100010];
		memo = new double[100010];
		for (int tc = 1; tc <= nc; tc++) {
			n = sc.nextInt();
			total = sc.nextInt();
			p[n] = c[n] = 1.0;
			for (int i = n - 1; i >= 0; i--) {
				p[i] = sc.nextDouble();
				c[i] = p[i] * c[i + 1];
			}
			Arrays.fill(memo, Double.NEGATIVE_INFINITY);
			double res = go(0);
			if (res > total + 2)
				res = total + 2; // case 3
			pw.printf("Case #%d: %.7f\n", tc, res);
		}
		pw.close();
	}

	private double go(int k) {
		if (k == n) {
			return total + 1;
		}
		if (!Double.isInfinite(memo[k]))
			return memo[k];
		double ret = total - n + k + 1 + (1 - c[k]) * (total + 1); // case 1
		double t = 1 + go(k + 1); // case 2
		if (t < ret)
			ret = t;
		return memo[k] = ret;
	}

	public static void main(String[] args) throws IOException {
		new A().work();
	}
}
