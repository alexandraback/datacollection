import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class A implements Runnable {

	
	private void solve() throws IOException {
		int cases = nextInt();
		
		while (cases-- > 0) {
			int r = nextInt();
			int t = nextInt();
			
			int cur = r;
			int res = 0;
			
			while (t > 0) {	
				if (t < ((cur + 1) * (cur + 1) - cur * cur)) break;
				t -= ((cur + 1) * (cur + 1) - cur * cur);
				cur += 2;
				res++;
			}
			pf();
			pl(res);
		}
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