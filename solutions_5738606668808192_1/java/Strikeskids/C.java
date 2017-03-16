import java.io.BufferedReader;
import java.io.Closeable;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C {

	public static void main(String... args) throws Exception {
		FastScan sc = new FastScan(new BufferedReader(new InputStreamReader(System.in)));
		PrintWriter pw = new PrintWriter(System.out);

		if (sc.in() != 1)
			throw new RuntimeException("More than one test case");
		pw.println("Case #1:");

		int N = sc.in();
		int J = sc.in();

		StringBuilder orig = new StringBuilder();
		orig.append('1');
		for (int i = 0; i < N - 2; ++i) {
			orig.append('0');
		}
		orig.append('1');
		
		BigInteger cur = new BigInteger(orig.toString(), 2);

		long foundCount = 0;

		outer: while (true) {
			String s = cur.toString(2);
			if (s.length() > N)
				break;

			for (int i = 3; i <= 10; ++i) {
				BigInteger bconv = new BigInteger(s, i);
				if (bconv.isProbablePrime(100)) {
					cur = nextCompositeIndex(cur);
					continue outer;
				}
			}

			BigInteger[] found = new BigInteger[11];

			for (int i = 2; i <= 10; ++i) {
				BigInteger bconv = new BigInteger(s, i);
				found[i] = findFactor(bconv);
			}

			if (isValid(found)) {
				pw.print(s);
				for (int j = 2; j <= 10; ++j) {
					pw.print(" ");
					pw.print(found[j]);
				}
				pw.println();
				pw.flush();
				if (++foundCount == J) {
					break outer;
				}
			}

			cur = nextCompositeIndex(cur);
		}

		sc.close();
		pw.close();
		System.exit(0);
	}

	private static boolean isValid(BigInteger[] found) {
		for (int i = 2; i < 11; ++i) {
			if (found[i] == null) {
				return false;
			}
		}
		return true;
	}

	private static BigInteger findFactor(BigInteger num) {
		BigInteger fac = BigInteger.valueOf(3);
		BigInteger two = BigInteger.valueOf(2);
		if (num.remainder(two).equals(BigInteger.ZERO)) {
			return two;
		}
		int tries = 0;
		while (!num.remainder(fac).equals(BigInteger.ZERO)) {
			if (tries++ > 100000)
				return null;
			fac = fac.add(two);
		}
		return fac;
	}

	private static BigInteger nextCompositeIndex(BigInteger cur) {
		do {
			cur = nextIndex(cur);
		} while (cur.isProbablePrime(100));
		return cur;
	}

	private static BigInteger nextIndex(BigInteger cur) {
		return cur.add(BigInteger.valueOf(2));
	}

	static class FastScan implements Closeable {
		private BufferedReader br;
		private StringTokenizer tk;

		public FastScan(BufferedReader br) {
			this.br = br;
		}

		public int in() throws NumberFormatException, IOException {
			return Integer.parseInt(next());
		}

		public long ln() throws NumberFormatException, IOException {
			return Long.parseLong(next());
		}

		public double db() throws NumberFormatException, IOException {
			return Double.parseDouble(next());
		}

		@Override
		public void close() throws IOException {
			tk = null;
			br.close();
		}

		public String next() throws IOException {
			while (tk == null || !tk.hasMoreTokens()) {
				String line = br.readLine();
				if (line == null)
					return null;
				tk = new StringTokenizer(line);
			}
			return tk.nextToken();
		}
	}
}
