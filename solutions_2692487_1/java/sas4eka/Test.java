import java.io.*;
import java.util.*;

public class Test {
	static BufferedReader reader;
	static StringTokenizer tokenizer;
	static PrintWriter writer;

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	public static void main(String[] args) throws IOException {
		reader = new BufferedReader(new InputStreamReader(new FileInputStream(
				"A-large.in")));
		tokenizer = null;
		writer = new PrintWriter("A-large.out");

		int t = nextInt();
		for (int i = 1; i <= t; i++) {
			writer.print("Case #" + i + ": ");
			banana();
		}

		reader.close();
		writer.close();
	}

	private static void banana() throws IOException {
		int a = nextInt();
		int n = nextInt();
		ArrayList<Integer> al = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			al.add(nextInt());
		}
		Collections.sort(al);
		int res = n;

		if (a == 1) {
			writer.println(n);
			return;
		}

		int curr = 0;
		for (int i = 0; i < n; i++) {
			if (al.get(i) < a) {
				a += al.get(i);
				continue;
			} else {
				res = Math.min(res, curr + n - i);
				while (al.get(i) >= a) {
					a += a - 1;
					curr++;
				}
				a += al.get(i);
			}
		}
		res = Math.min(res, curr);
		writer.println(res);
	}
}