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

	static int a[] = new int[1000001];

	static int solution(int k) {
		return a[k];
	}

	static void prec() {
		Queue<Integer> q = new LinkedList<Integer>();

		q.add(1);
		a[1] = 1;
		while (q.size() != 0) {
			int cur = q.poll();

			if (a[cur + 1] == 0 && cur + 1 <= 1000000) {
				a[cur + 1] = a[cur] + 1;
				q.add(cur + 1);
			}
			int cc = reverse(cur);
			
			if (a[cc] == 0 && cc <= 1000000) {
				a[cc] = a[cur]+1;
				q.add(cc);
			}
		}
	}

	static int reverse(int k) {
		StringBuilder s = new StringBuilder(k + "");
		return Integer.parseInt(s.reverse().toString());
	}

	static void banana() throws IOException {
		int testCase = nextInt();
		prec();
		for (int i = 1; i <= testCase; ++i) {
			int c = nextInt();

			writer.println("Case #" + i + ": " + solution(c));
		}
	}
}