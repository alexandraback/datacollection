import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;

public class Main 
{	
	public static int M = 24;
	public static double trangle[][] = new double[M][M];

	public static List<Double> getline(int k, int n) {
		List<Double> res = new ArrayList<Double>();
		while (n > k - 1){
			res.add(1.0);
			n -= 2;
			k -= 1;
		}
		
		List<Double> ted = new ArrayList<Double>();		
		double s = 0;
		for (int f = n; f > 0; --f)
			ted.add(s += trangle[n][f]);
		
		for (int i = ted.size() - 1; i >= 0; --i)
			res.add(ted.get(i));
			
		for (int f = n + 1; f <= k; ++f)
			res.add(0.0);
		
		return res;
	}
	
	public static void main() throws IOException {
		setStandardIO();
		setFileIO("test");

		trangle[0][0] = 1.0;
		for (int i = 1; i < M; ++i) {
			trangle[i][0] = trangle[i - 1][0] / 2;
			trangle[i][i] = trangle[i - 1][0] / 2;
			for (int j = 1; j < i; ++j)
				trangle[i][j] = (trangle[i - 1][j - 1] + trangle[i - 1][j]) / 2; 
		}
		
		int T = nextInt();
		for (int t = 1; t <= T; ++t) {
			int N = nextInt();
			int X = Math.abs(nextInt());
			int Y = nextInt();
			
			int n = N, k = 1, s = 1, l = -2;
			while (n - s >= 0) {
				n -= s;
				k += 2;
				l += 2;
				s = 2 * k - 1;
			}
			
			if (X + Y <= l) { 
				println("Case #" + t + ": 1.0");
			}
			else if (X + Y >= l + 4) { 
				println("Case #" + t + ": 0.0");
			}
			else {
				println("Case #" + t + ": " + getline(k, n).get(Y));			
			}
		}			
		
		flush();
	}

	// ~ -----------------------------------------------------------------------
	// ~ - Auxiliary code ------------------------------------------------------
	// ~ -----------------------------------------------------------------------
	public static Exception exception = null;
	
	/**
	 * Start new thread with larger stack (64MB). Larger stack is usefull when
	 * using recursive functions. This new started thread will conduct all
	 * program execution.
	 */
	public static void main(String[] args) throws Exception {
		Thread thread = new Thread(null, new Runnable() {
			public void run() {
				try {
					main();
				}
				catch (Exception e) {
					exception = e;
				}
			}
		}, "thread", 1 << 26);
		thread.start();
		thread.join();
		
		if (exception != null)
			throw new IllegalStateException(exception);
	}

	static InputStream in;
	static PrintWriter out;

	/**
	 * Simple buffered reader class. Reads if buffer is empty. Try to fill up
	 * whole buffer.
	 */
	public static class SimpleBufferedInputStream extends InputStream {
		// ~ Static fields / Initializers --------------------------------------
		private static int defaultCharBufferSize = 16384;
		private InputStream in;
		byte[] buffer;
		int pos = 0;
		int len = 0;

		// ~ Constructors ------------------------------------------------------
		public SimpleBufferedInputStream(InputStream in) {
			this(in, defaultCharBufferSize);
		}

		public SimpleBufferedInputStream(InputStream in, int size) {
			this.in = in;
			this.buffer = new byte[size];
		}

		// ~ Methods -----------------------------------------------------------
		@Override
		public int read() throws IOException {
			if (pos < len)
				return buffer[pos++];

			len = in.read(buffer);
			if (len == -1)
				return len;

			pos = 0;
			if (len <= 0)
				return -1;

			return buffer[pos++];
		}
	}

	public static void setStandardIO() {
		in = new SimpleBufferedInputStream(System.in);
		out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
				System.out)));
	}

	public static void setFileIO(String fileName) throws IOException {
		in = new SimpleBufferedInputStream(
				new FileInputStream(fileName + ".in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter(fileName
				+ ".out")));
	}

	public static int skipWhitespaces() throws IOException {
		int c;
		for (;;) {
			c = in.read();
			if (!isWhitespace(c))
				break;
			if (c == -1)
				throw new IOException();
		}

		return c;
	}

	public static int nextNoWhitespace() throws IOException {
		int c = in.read();
		if (c == -1 || isWhitespace(c))
			return -1;

		return c;
	}

	public static long nextLong() throws IOException {
		int c;
		for (;;) {
			c = in.read();
			if (!isWhitespace(c))
				break;
			if (c == -1)
				throw new RuntimeException();
		}

		boolean neg = false;
		long val = 0;
		if (c == '-')
			neg = true;
		else
			val = c - '0';

		for (;;) {
			c = in.read();
			if (isWhitespace(c) || c == -1)
				break;

			val = val * 10 + (c - '0');
		}

		if (neg)
			return -val;

		return val;
	}

	public static int nextInt() throws IOException {
		int c;
		for (;;) {
			c = in.read();
			if (c >= '0' && c <= '9') break;
			if (c == -1)
				throw new RuntimeException();
		}

		int val = c - '0';
		for (;;) {
			c = in.read();
			if (isWhitespace(c) || c == -1)
				break;

			val = val * 10 + (c - '0');
		}

		return val;
	}

	public static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' ? true : false;
	}

	public static byte nextByte() throws IOException {
		return (byte) nextInt();
	}

	public static String nextString() throws IOException {
		int c = (char) skipWhitespaces();

		StringBuilder sb = new StringBuilder();
		sb.append((char) c);

		for (;;) {
			c = nextNoWhitespace();
			if (c == -1)
				break;

			sb.append((char) c);
		}

		return sb.toString();
	}

	public static BigDecimal nextBigDecimal() throws IOException {
		return new BigDecimal(nextString());
	}

	public static double nextDouble() throws IOException {
		return Double.parseDouble(nextString());
	}

	public static void flush() {
		out.flush();
	}

	public static void println(Object object) {
		out.println(object);
	}

	public static void printlnfl(Object object) {
		out.println(object);
		out.flush();
	}
	
	public static void print(Object object) {
		out.print(object);
	}

	public static void println(double d, int precision) {
		String s = "%1$." + precision + "f";
		out.format(Locale.ENGLISH, s, d);
		out.println();
	}

	public static void println(BigDecimal d, int precision) {
		String s = "%1$." + precision + "f";
		out.format(Locale.ENGLISH, s, d);
		out.println();
	}
}