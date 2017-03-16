import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class three implements Runnable {
	int arr[];
	boolean done;
	int ans[];
	int a, b;

	void rec(int sum, int i, int mask) {
		// System.out.println(Integer.toBinaryString(mask));
		if (done)
			return;
		if (ans[sum] > 0 && ans[sum] != mask) {
			done = true;
			a = ans[sum];
			b = mask;
			return;
		}
		ans[sum] = mask;
		if (i == arr.length) {
			return;
		}
		rec(sum, i + 1, mask);
		mask |= (1 << (i));
		rec(sum + arr[i], i + 1, mask);
		mask ^= (1 << (i));
	}

	public void run() {
		int t = nextInt();
		ans = new int[2000000];
		arr = new int[20];
		for (int k = 1; k <= t; k++) {
			done = false;
			Arrays.fill(ans, 0);

			int n = nextInt();

			for (int i = 0; i < n; i++) {
				arr[i] = nextInt();
			}
			rec(0, 0, 0);
			out.print("Case #");
			out.print(k);
			out.println(": ");

			if (!done) {
				out.println("Impossible");
				continue;
			}

			for (int i = 0; i < 22; i++) {
				if ((a & (1 << i)) > 0) {
					out.print(arr[i]);
					out.print(" ");
				}
			}
			out.println();
			for (int i = 0; i < 22; i++) {
				if ((b & (1 << i)) > 0) {
					out.print(arr[i]);
					out.print(" ");
				}
			}
			out.println();

		}

		// --------------------------------------------------------------------------------------------
		out.close();
		System.exit(0);
	}

	private static boolean fileIOMode = true;
	private static String problemName = "C-small-attempt0";
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

		new Thread(new three()).start();
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
