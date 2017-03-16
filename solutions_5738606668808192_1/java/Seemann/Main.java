import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ConcurrentMap;

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Solver solver = new Solver();
		solver.solve(in, out);
		out.close();
	}
}

class Solver {
	ConcurrentMap<String, int[]> map;
	static final int N = 32;
	static final int THREADS = 1;
	static final int CERTAINTY = 5;
	static final int MAXDIV = 100000;
	static final int MAXSIZE = 500;
	public void solve(InputReader in, PrintWriter out) {
		map = new ConcurrentHashMap<>();
		Random random = new Random();
		Thread[] threads = new Thread[THREADS];
		for (int i = 0; i < THREADS; i++) {
			threads[i] = (new Thread(new Searcher(random.nextLong())));
			threads[i].start();
		}
		for (int i = 0; i < THREADS; i++) {
			try {
				threads[i].join();
			} catch (InterruptedException e) {
				continue;
			}
		}
		out.println("Case #1:");
		for (String bits : map.keySet()) {
			out.print(bits);
			out.print(" ");
			int[] divs = map.get(bits);
			for (int i = 0; i < divs.length; i++) {
				out.print(divs[i] + " ");
			} 
			out.println();
		}
		
	}
	class Searcher implements Runnable {
		long seed;
		
		public Searcher(long seed) {
			this.seed = seed;
		}
		boolean check(int[] a) {
			BigInteger res = BigInteger.ZERO;
			for (int base = 2; base <= 10; ++base) {
				BigInteger bbase = BigInteger.valueOf(base);
				BigInteger pw = BigInteger.ONE;
				for (int i = 0; i < N; i++) {
					if (a[i] == 1) {
						res = res.add(pw);
					}
					pw = pw.multiply(bbase);
				}
				if (res.isProbablePrime(CERTAINTY)) {
					return false;
				}
			}
			return true;
		}
		int findDiv(BigInteger b) {
//			System.err.print(b + " ");
			for (int i = 2; i < MAXDIV; ++i) {
				if (b.mod(BigInteger.valueOf(i)).equals(BigInteger.ZERO)) {
	//				System.err.println(i);
					return i;
				}
			}
			return 0;
		}
		int[] findDivs(int[] a) {
			
			int[] divs = new int[9];
			for (int base = 2; base <= 10; ++base) {
				BigInteger res = BigInteger.ZERO;
				BigInteger bbase = BigInteger.valueOf(base);
				BigInteger pw = BigInteger.ONE;
				for (int i = 0; i < N; i++) {
					if (a[i] == 1) {
						res = res.add(pw);
					}
					pw = pw.multiply(bbase);
				}
				int div = findDiv(res);
				if (div == 0)
					return null;
				divs[base - 2] = div;
			}
			return divs;
		}
		String getString(int[] a) {
			StringBuffer sb = new StringBuffer();
			for (int i = N - 1; i >= 0; --i) {
				sb.append(Integer.toString(a[i]));
			}
			return sb.toString();
		}
		public void run() {
			Random random = new Random(seed);
			for (int tries = 1;;++tries) {
				int[] bits = new int[N];
				bits[0] = bits[N - 1] = 1;
				for (int i = 1; i < N - 1; ++i) {
					bits[i] = random.nextInt(2);
				}
				if (check(bits)) {
					int[] divs = findDivs(bits);
					if (divs == null)
						continue;
					
					map.put(getString(bits), divs);
					System.err.println("Thread #" + Thread.currentThread().getId() +", try #" 
					+ tries + ": " + Arrays.toString(bits));
					if (map.size() >= MAXSIZE)
						break;
				}
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

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}
}
