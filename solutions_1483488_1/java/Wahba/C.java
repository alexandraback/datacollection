import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

public class C {


	private void solve() throws IOException {
		int T = nextInt();
		while (T-- > 0) {
			int A = nextInt();
			int B = nextInt();
			HashSet<String> H = new HashSet<String>();
			for (int i = A; i <= B; i++) {
				String s = "" + i;
				for (int c = 0; c < s.length(); c++) {
					String a = s.substring(c);
					String b = s.substring(0, c);
					String c1 = a + b;
					int n = Integer.parseInt(c1);
					if (n != i && n <= B && n >= i + 1) {
						H.add(n + " " + i);
					}
				}
			}
			pf();
			pl(H.size());
		}
	}

	public static void main(String[] args) {
		new C().run();
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	public void run() {
		try {
			 reader = new BufferedReader(new FileReader("C.in"));
//			reader = new BufferedReader(new InputStreamReader(System.in));
			tokenizer = null;
//			writer = new PrintWriter(System.out);
			 writer = new PrintWriter("C_.out");
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
			writer.flush();
			writer.print(objects[i]);
			writer.flush();
		}
	}

	void pl(Object... objects) {
		p(objects);
		writer.flush();
		writer.println();
		writer.flush();
	}

	int cc;

	void pf() {
		writer.printf("Case #%d: ", ++cc);
		writer.flush();
	}

}
