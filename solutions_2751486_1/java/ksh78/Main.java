import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.Locale;
import java.util.SortedSet;
import java.util.TreeSet;

public class Main 
{	
	public static boolean iscons(char c) {
		if (c == 'a') return false;
		if (c == 'e') return false;
		if (c == 'i') return false;
		if (c == 'o') return false;
		if (c == 'u') return false;
		
		return true;
	}
	
	public static void main() throws IOException {
		setStandardIO();
		setFileIO("test");

		int T = nextInt();
		for (int t = 1; t <= T; ++t) {
			String s = nextString();
			int n = nextInt(), N = s.length();
			
			if (n > N) {
				println("Case #" + t + ": " + 0);				
			}
			else {
				int cons = 0;
				for (int i = 0; i < n; ++i)
					if (iscons(s.charAt(i))) cons ++;
				
				SortedSet<Integer> set = new TreeSet<Integer>();
				if (cons == n)
					set.add(n - 1);
				
				for (int b = 1, e = n; e < N; ++b, ++e) {
					if (iscons(s.charAt(b - 1))) cons--;
					if (iscons(s.charAt(e))) cons++;
					if (cons == n)
						set.add(e);
				}

				long res = 0;
				for (int b = 0, e = n - 1; e < N; ++b, e++) {
					SortedSet<Integer> subset = set.subSet(e, 10000000);
					if (!subset.isEmpty()) {
						res += (long)(N - subset.first());  
					}
				}
				println("Case #" + t + ": " + res);
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