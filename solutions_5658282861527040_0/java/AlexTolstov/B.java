import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {

	private static final String PATH = "/home/tolstov.a.a/codejam/b/";

	private static final String TASK = "B-small";

	Scanner in;

	PrintWriter out;

	void solveOne() {
		int a = in.nextInt();
		int b = in.nextInt();
		int k = in.nextInt();

		int count[] = new int[k + 1];
		Arrays.fill(count, 0);
		int cnt = 0;
		for (int aa = 0; aa < a; aa++) {
			for (int bb = 0; bb < b; bb++) {
				int res = aa & bb;
				if (res < k) {
					count[res]++;
					cnt++;
				}
			}
		}
		out.print(cnt);
	}

	void solve() {
		int nTests = in.nextInt();
		for (int test = 1; test <= nTests; test++) {
			out.print("Case #" + test + ": ");
			solveOne();
			out.println();
		}
	}

	void run() {
		try {
			in = new Scanner(new FileReader(PATH + TASK + ".in"));
			out = new PrintWriter(PATH + TASK + ".out");
		} catch (IOException e) {
			in = new Scanner(System.in);
			out = new PrintWriter(System.out);
			out.println("debug>");
			out.flush();
		}

		try {
			solve();
		} finally {
			out.close();
		}
	}

	public static void main(String[] args) {
		new B().run();
	}
}
