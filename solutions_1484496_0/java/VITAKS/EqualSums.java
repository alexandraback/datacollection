import java.io.*;
import java.util.*;

public class EqualSums implements Runnable {
	public static void main(String[] args) {
		new Thread(new EqualSums()).run();
	}

	BufferedReader br;
	StringTokenizer in;
	PrintWriter out;

	public String nextToken() throws IOException {
		while (in == null || !in.hasMoreTokens())
			in = new StringTokenizer(br.readLine());
		return in.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public void solve() throws IOException {
		int n = nextInt();

		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = nextInt();

		int[] sum = new int[1 << n];
		for (int i = 0; i < 1 << n; i++) {
			for (int j = 0; j < n; j++)
				if ((i & (1 << j)) > 0)
					sum[i] += a[j];
		}

		for (int i = 0; i < 1 << n; i++) {
			int o = (1 << n) - i - 1;
			for (int j = o; j > 0; j = ((j - 1) & o)) {
				if (sum[i] == sum[j]) {
					out.println();
					for (int k = 0; k < n; k++)
						if ((i & (1 << k)) > 0)
							out.print(a[k] + " ");
					out.println();
					for (int k = 0; k < n; k++)
						if ((j & (1 << k)) > 0)
							out.print(a[k] + " ");

					out.println();
					return;
				}
			}
		}

		out.println("Impossible");
	}

	public void run() {
		try {
			br = new BufferedReader(new FileReader("C.in"));
			out = new PrintWriter("C.out");

			int t = nextInt();
			for (int i = 0; i < t; i++) {
				out.print("Case #" + (i + 1) + ": ");
				solve();
				System.err.println(i);
			}

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
}
