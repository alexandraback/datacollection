import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
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

	static boolean eof = false;

	static String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	public static void main(String[] args) throws IOException {
		tokenizer = null;
		reader = new BufferedReader(new FileReader("input.txt"));
		writer = new PrintWriter(new FileWriter("output.txt"));
		// reader = new BufferedReader(new InputStreamReader(System.in,
		// "ISO-8859-1"));
		// writer = new PrintWriter(System.out);
		banana();
		reader.close();
		writer.close();
	}

	static int a[] = new int[1001];

	static long solution(long k) {
		long counter = 0;
		while (true) {
			if (k <= 1000)
				return counter + a[(int) k];

			int len = (k + "").length();

			int cc = (len + 1) / 2;

			long s = k % pow(cc);
			if (s >= 1) {
				counter += s - 1;
				k = (k / pow(cc)) * pow(cc) + 1;
				if (k != reverse(k)) {
					k = reverse(k);
					++counter;
				}
				k -= 2;
				counter += 2;
			} else {
				counter++;
				k--;
			}
		}
	}

	static long pow(int x) {
		long t = 1l;

		for (int i = 0; i < x; ++i)
			t *= 10;

		return t;
	}

	static void prec() {
		Queue<Integer> q = new LinkedList<Integer>();

		q.add(1);
		a[1] = 1;
		while (q.size() != 0) {
			int cur = q.poll();

			if (cur + 1 <= 1000 && a[cur + 1] == 0) {
				a[cur + 1] = a[cur] + 1;
				q.add(cur + 1);
			}
			int cc = (int) reverse(cur);

			if (a[cc] == 0 && cc <= 1000) {
				a[cc] = a[cur] + 1;
				q.add(cc);
			}
		}
	}

	static long reverse(long k) {
		StringBuilder s = new StringBuilder(k + "");
		return Long.parseLong(s.reverse().toString());
	}

	static void banana() throws IOException {
		int testCase = nextInt();
		prec();
		for (int i = 1; i <= testCase; ++i) {
			long c = nextLong();

			writer.println("Case #" + i + ": " + solution(c));
		}
	}
}