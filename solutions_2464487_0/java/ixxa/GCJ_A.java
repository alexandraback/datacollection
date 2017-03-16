import java.io.*;
import java.math.*;
import java.util.*;

public class GCJ_A {
	public static void main(String[] args) throws Exception {
		new GCJ_A().solve();
		// new FileInputStream(new File("input.txt")),
		// new PrintStream(new FileOutputStream(new File("output.txt"))));
	}

	int R = 4, C = 4;
	void solve() throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")));
		PrintStream out = new PrintStream(new FileOutputStream(new File("output.txt")));
		Scanner sc = new Scanner(new FileInputStream("input.txt"));
		String[] sp;

		int T = sc.nextInt();
		for (int test = 0; test < T; test++) {
			long r = sc.nextLong();
			long t = sc.nextLong();

			long lb = 0;
			long ub = t;

			while (lb + 1 < ub) {
				long k = (ub + lb) / 2;

				long area = k * (2 * k - 1 + 2 * r);
				double areaD = 1.0 * k * (2 * k - 1 + 2 * r);

				if (areaD / 2 > area || area > t) {
					ub = k;
				} else {
					lb = k;
				}
			}
			out.println("Case #" + (test + 1) + ": " + lb);
		}
	}
}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
