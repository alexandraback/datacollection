import java.util.*;
import java.io.*;
import java.math.*;

public class C {
	public static void main(String[] args) {
		C value = new C();
		value.start();
		value.out.close();
	}
	InputStream inputStream = System.in;
	OutputStream outputStream = System.out;
	InputReader in = new InputReader(inputStream);
	PrintWriter out = new PrintWriter(outputStream);

	class Answer {
		long n;
		BigInteger[] c;
		Answer() {
			n = 0;
			c = new BigInteger[11];
		}
		void work() {
			if (n == 0) {
				return;
			}
			String s = Long.toString(n, 2);
			for (int i = 2; i <= 10; i++) {
				BigInteger t = new BigInteger(s, i);
				for (BigInteger j = BigInteger.valueOf(2); ; j = j.add(BigInteger.ONE)) {
					if (t.mod(j).equals(BigInteger.ZERO)) {
						c[i] = j;
						break;
					}
				}
			}
		}
		void print() {
			System.out.print(Long.toString(n, 2));
			for (int i = 2; i <= 10; i++) {
				System.out.print(" " + c[i]);
			}
			System.out.println();
		}
	}
	Answer[] ans;

	boolean test(long n) {
		String s = Long.toString(n, 2);
		for (int i = 2; i <= 10; i++) {
			BigInteger t = new BigInteger(s, i);
			if (t.isProbablePrime(50)) {
				return false;
			}
		}
		return true;
	}

	public void start() {
		System.out.println("Case #1:");
		int n = 16, J = 50, j = 0;
		ans = new Answer[J];
		for (long i = (1l << 15) + 1l; j < J && i < (1l << 16); i += 2l) {
			if (test(i)) {
				System.err.println("Answer " + (j + 1) + " judged!");
				ans[j] = new Answer();
				ans[j].n = i;
				ans[j].work();
				System.err.println("Answer " + (j + 1) + " done!");
				ans[j].print();
				j++;
			}
		}
	}
}

class InputReader {
	private BufferedReader reader;
	private StringTokenizer tokenizer;
	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream));
		tokenizer = null;
	}
	public boolean hasNext() {
		try {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				String str = nextLine();
				if (str == null) {
					return false;
				}
				tokenizer = new StringTokenizer(str);
			}
		} catch (IOError e) {
			return false;
		}
		return true;
	}
	public String next() {
		if (hasNext()) {
			return tokenizer.nextToken();
		} else {
			return null;
		}
	}
	public int nextInt() {
		return Integer.parseInt(next());
	}
	public double nextDouble() {
		return Double.parseDouble(next());
	}
	public long nextLong() {
		return Long.parseLong(next());
	}
	public String nextLine() {
		try {
			return reader.readLine();
		} catch (IOException e) {
			throw new IOError(e);
		}
	}
}
