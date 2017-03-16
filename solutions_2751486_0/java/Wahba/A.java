import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

public class A implements Runnable {

	private void solve() throws IOException {
		int t = nextInt();
		while (t-- > 0) {
			String s = nextToken();
			int n = nextInt();
			int res = 0;
			for (int i = 0; i < s.length(); i++) {
				for (int j = i + 1; j <= s.length(); j++) {
					String sub = s.substring(i, j);
//					System.out.println(sub + " " + valid(sub, n));
					if (valid(sub, n)) {
//						System.out.println(sub);
						++res;
					}
				}
			}
			pf();
			pl(res);
		}
	}

	private boolean valid(String sub, int n) {
//		sub = "stra";
		int mx = 0, c = 0;
		for (int i = 0; i < sub.length(); i++) {
			if (!is(sub.charAt(i))) ++c;
			else c = 0;
			mx = Math.max(mx, c);
		}
		return mx >= n;
	}

	private boolean is(char c) {
		return c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u';
	}

	public static void main(String[] args) {
		new A().run();
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	public void run() {
		try {
//			reader = new BufferedReader(new InputStreamReader(System.in));
			reader = new BufferedReader(new FileReader("A-small-attempt0.in"));
//			reader = new BufferedReader(new FileReader("A-large.in"));
//			writer = new PrintWriter(System.out);
			writer = new PrintWriter("A-small.out");
//			writer = new PrintWriter("A-large.out");
			tokenizer = null;
			solve();
			reader.close();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	BigInteger nextBigInteger() throws IOException {
		return new BigInteger(nextToken());
	}

	String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	void p(Object... objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	void pl(Object... objects) {
		p(objects);
		writer.println();
	}

	int cc;

	void pf() {
		writer.printf("Case #%d: ", ++cc);
	}

}