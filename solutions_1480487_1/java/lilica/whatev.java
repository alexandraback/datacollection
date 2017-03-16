import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class whatev implements Runnable {

	public void run() {
		int t = nextInt();
		for (int k = 1; k <= t; k++) {

			int n = nextInt();
			double arr[] = new double[n];

			double s = 0;
			for (int i = 0; i < n; i++) {
				arr[i] = nextInt();
				s += arr[i];
			}

			double total = 2 * s;
			double need = (s * 2) / n;

			int nn = n;
			for (int i = 0; i < n; i++) {
				if (arr[i] >= (need + 1e-13)) {
					total -= arr[i];
					nn--;
				}
			}

			double newNeed = total / nn;

			out.print("Case #");
			out.print(k);
			out.print(": ");
			double ss = 0;
			for (int i = 0; i < n; i++) {
				double ans = max(0.0, ((newNeed - arr[i]) / s) * 100);
				ss+=ans;
				out.print(ans);
				out.print(" ");
			}
			out.println();
		}

		// --------------------------------------------------------------------------------------------
		out.close();
		System.exit(0);
	}

	private static boolean fileIOMode = true;
	private static String problemName = "A-large";
	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer tokenizer;

	public static void main(String[] args) throws Exception {
		if (fileIOMode) {
			in = new BufferedReader(new FileReader(problemName + ".in"));
			out = new PrintWriter(problemName + ".out");
		} else {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
		}
		tokenizer = new StringTokenizer("");

		new Thread(new whatev()).start();
	}

	private static String nextLine() {
		try {
			return in.readLine();
		} catch (IOException e) {
			return null;
		}
	}

	private static String nextToken() {
		while (!tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(nextLine());
		}
		return tokenizer.nextToken();
	}

	private static int nextInt() {
		return Integer.parseInt(nextToken());
	}
}
