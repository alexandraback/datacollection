import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

public class A {

	private void solve() throws IOException {
		int T = nextInt();
		while (T-- > 0) {
			String s = reader.readLine();
			String a = "";
			for (int i = 0; i < s.length(); i++)
				if (s.charAt(i) != ' ')
					a += c[s.charAt(i) - 'a'];
				else
					a += ' ';
			pf();
			pl(a);
		}
	}

	char[] c = { 'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g',
			'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a',
			'q' };

	public static void main(String[] args) {
		new A().run();
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	public void run() {
		try {
			reader = new BufferedReader(new FileReader("A.in"));
			//reader = new BufferedReader(new InputStreamReader(System.in));
			tokenizer = null;
			//writer = new PrintWriter(System.out);
			writer = new PrintWriter("A.out");
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
