import java.io.File;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.Locale;
import java.util.Queue;
import java.util.Scanner;

public class A {

	final static String PREFIX = "C:\\codejam\\A";
//	final static String FILE_NAME = PREFIX + "-test";
	 final static String FILE_NAME = PREFIX + "-small-attempt0";
	// final static String FILE_NAME = PREFIX + "-large";

	private Scanner in;
	private PrintWriter out;

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);
		new A().solveAll();
	}

	private void solveAll() throws Exception {
		in = new Scanner(new File(FILE_NAME + ".in"));
		out = new PrintWriter(new File(FILE_NAME + ".out"));
		int tcn = in.nextInt();
		for (int tc = 1; tc <= tcn; tc++) {
			solve(tc);
		}
		out.close();
	}

	private void solve(int tc) {
		int n = in.nextInt();
		boolean[][] t = new boolean[n + 1][n + 1];
		for (int i = 1; i <= n; i++) {
			int m = in.nextInt();
			for (int j = 0; j < m; j++) {
				int a = in.nextInt();
				t[i][a] = true;
			}
		}
		String res = "No";
		loop: for (int i = 1; i <= n; i++) {
			boolean[] v = new boolean[n + 1];
			Queue<Integer> q = new LinkedList<Integer>();
			q.add(i);
			while (!q.isEmpty()) {
				int x = q.poll();
				if (v[x]) {
					res = "Yes";
					break loop;
				}
				v[x] = true;
				for (int j = 1; j <= n; j++) {
					if (t[x][j]) {
						q.add(j);
					}
				}
			}
		}

		out.format("Case #%d: %s\n", tc, res);
		System.out.format("Case #%d: %s\n", tc, res);
	}

}
