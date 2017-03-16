import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {

	private int E, R, N, v[], memo[][];

	private int go(int e, int k) {
		if (k == N)
			return 0;
		if (memo[e][k] >= 0)
			return memo[e][k];
		int ret = 0;
		for (int i = 0; i <= e; i++) {
			int t = i * v[k] + go(Math.min(E, e - i + R), k + 1);
			if (t > ret)
				ret = t;
		}
		return memo[e][k] = ret;
	}

	private void work() throws IOException {
		// Scanner sc = new Scanner(new FileReader("B-large.in"));
		// PrintWriter pw = new PrintWriter(new FileWriter("B-large.out"));
		Scanner sc = new Scanner(new FileReader("B-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("B-small-attempt0.out"));
		// Scanner sc = new Scanner(new FileReader("b.in"));
		// PrintWriter pw = new PrintWriter(new FileWriter("b.out"));
		int nc = sc.nextInt();
		for (int tc = 1; tc <= nc; tc++) {
			E = sc.nextInt();
			R = sc.nextInt();
			N = sc.nextInt();
			v = new int[N];
			for (int i = 0; i < N; i++) {
				v[i] = sc.nextInt();
			}
			memo = new int[E + 1][N];
			for (int i = 0; i <= E; i++) {
				for (int j = 0; j < N; j++) {
					memo[i][j] = -1;
				}
			}
			pw.printf("Case #%d: %d\n", tc, go(E, 0));
		}
		pw.close();
	}

	public static void main(String[] args) throws IOException {
		new B().work();
	}

}
