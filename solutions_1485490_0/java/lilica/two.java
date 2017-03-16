import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class two implements Runnable {

	long aN[], bN[], temp[];
	int aT[], bT[], used;

	public void run() {
		int t = nextInt();
		aN = new long[10];
		aT = new int[10];
		bN = new long[110];
		bT = new int[110];
		temp = new long[110];

		for (int k = 1; k <= t; k++) {
			out.print("Case #");
			out.print(k);
			out.print(": ");

			// ////
			int n = nextInt(), m = nextInt();
			aN = new long[n];
			aT = new int[n];
			bN = new long[m];
			bT = new int[m];
			temp = new long[m];
			for (int i = 0; i < n; i++) {
				aN[i] = nextLong();
				aT[i] = nextInt();
			}

			for (int i = 0; i < m; i++) {
				bN[i] = nextLong();
				bT[i] = nextInt();
			}

			// System.out.println(Long.MAX_VALUE);
//			System.out.println(Arrays.toString(aN));
//			System.out.println(Arrays.toString(aT));
//			System.out.println(Arrays.toString(bN));
//			System.out.println(Arrays.toString(bT));
			long max = 0;
			if (n == 1) {
				long ans = 0;
				// temp = new long[m];

				for (int kk = 0; kk < m; kk++)
					temp[kk] = bN[kk];

				ans += calc(0, m, 0);
				max = max(max, ans);
			}

			if (n == 2) {
				for (int i = 0; i < m; i++) {
					// temp = new long[m];
					// System.out.println(i + " " + " :::");

					for (int kk = 0; kk < m; kk++)
						temp[kk] = bN[kk];

					used = 0;
					long ans = 0;

					ans += calc(0, min(i + 1, m), 0);
					ans += calc(used, m, 1);

					max = max(max, ans);
				}
			}
			if (n == 3) {
				for (int i = 0; i < m; i++) {
					for (int j = i; j < m; j++) {
						// temp = n-ew long[m];

						for (int kk = 0; kk < m; kk++)
							temp[kk] = bN[kk];

						used = 0;
//						System.out.println(i + " " + j + " :::");
						long ans = 0;

						ans += calc(0, min(m, i + 1), 0);
						ans += calc(used, min(m, j + 1), 1);
						ans += calc(used, m, 2);

						max = max(max, ans);
					}
				}
			}
			out.println(max);
//			System.out.println("max " + max);

			// System.out.println();
		}

		// --------------------------------------------------------------------------------------------
		out.close();
		System.exit(0);
	}

	long calc(int from, int till, int aInd) {
		// System.out.println(from + " " + till);
		long a = aN[aInd];
		long ans = 0;
		for (int i = from; i < till; i++) {
			if (aT[aInd] == bT[i]) {
				long add = min(a, temp[i]);
				ans += add;
				a -= add;
				temp[i] -= add;
				used = i;
				if (a == 0)
					return ans;
			}
		}
		// System.out.println(ans);
		return ans;
	}

	private static boolean fileIOMode = true;
	private static String problemName =  "C-small-attempt5";//
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

		new Thread(new two()).start();
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

	private static long nextLong() {
		return Long.parseLong(nextToken());
	}
}
