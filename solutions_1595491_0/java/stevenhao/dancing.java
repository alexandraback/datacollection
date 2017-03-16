import java.io.*;
import java.util.*;

public class dancing {
	static String next() {
		if (st == null || !st.hasMoreTokens())
			nextLine();
		return st.nextToken();
	}

	static int nextInt() {
		return Integer.parseInt(next());
	}

	static void nextLine() {
		try {
			st = new StringTokenizer(f.readLine());
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	static StringTokenizer st;
	static PrintWriter out;
	static BufferedReader f;

	public static void main(String[] args) throws IOException {
		String progName = (dancing.class.getCanonicalName()) + ".out";
		f = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		 out = new PrintWriter(new BufferedWriter(new FileWriter(progName)));
		int T = nextInt();
		for (int test = 1; test <= T; test++) {
			int N = nextInt(), S = nextInt(), p = nextInt();
			int a = 3 * p - 4, b = 3 * p - 2;
			if (p == 1)
				a = 1;
			int count = 0;
			for (int i = 0; i < N; i++) {
				int x = nextInt();
				if (x >= b) {
					count++;
				} else if (x >= a && S > 0) {
					S--;
					count++;
				}
			}
			out.printf("Case #%d: %d\n", test, count);
		}
		out.close();
		// System.exit(0);
	}

}