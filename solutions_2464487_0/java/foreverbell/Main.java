import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		int tests = in.nextInt();
		for (int noT = 1; noT <= tests && in.hasNext(); ++noT) {
			TaskA solver = new TaskA();
			solver.solve(noT, in, out);
			solver = null;
			System.gc();
		}
		out.close();
	}
}

class TaskA {
	
	public BigInteger Sqrt(BigInteger x) {
		BigInteger begin = BigInteger.ZERO, end = x, mid;
		while (begin.compareTo(end) < 0) {
			mid = (begin.add(end)).divide(BigInteger.valueOf(2)).add(BigInteger.ONE);
			if (mid.multiply(mid).compareTo(x) <= 0) {
				begin = mid;
			} else {
				end = mid.subtract(BigInteger.ONE);
			}
		}
		return begin;
	}
	public void solve(int testNumber, InputReader in, PrintWriter out) {
		BigInteger r = new BigInteger(in.next());
		BigInteger t = new BigInteger(in.next());
		BigInteger a = BigInteger.ONE.add(BigInteger.ONE);
		BigInteger b = r.multiply(a).subtract(BigInteger.ONE);
		BigInteger c = t.negate();
		BigInteger d = b.multiply(b).subtract(a.multiply(c).multiply(BigInteger.valueOf(4)));
		d = Sqrt(d);
		BigInteger ans = b.negate().add(d).divide(a.multiply(BigInteger.valueOf(2)));
		out.println("Case #" + testNumber + ": " + ans.toString());
	}
}

// Built-in Plug
class InputReader {
	BufferedReader reader;
	StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream));
		tokenizer = null;
	}

	public boolean hasNext() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (Exception e) {
				return false;
			}
		}
		return tokenizer.hasMoreTokens();
	}

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (Exception e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}
}
