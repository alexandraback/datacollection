import java.util.*;
import java.io.*;

public class safety {
	private static Reader in;
	private static PrintWriter out;
	public static final String NAME = "A-large";

	private static int [] arr;
	private static int sum;
	private static void main2() throws IOException {
		int N = in.nextInt();
		
		arr = new int [N];
		sum = 0;
		for (int i = 0; i < N; i++) {
			sum += arr [i] = in.nextInt();
		}
		
		out.printf ("%.5f", comp (0) * 100);
		for (int i = 1; i < N; i++)
			out.printf (" %.5f", comp (i) * 100);
		out.println();
	}
	
	private static double comp (int idx) {
		double lo = 0, hi = 1;
		while (hi - lo > 1e-12) {
			double mid = (lo + hi) / 2.;
			if (can (idx, mid)) lo = mid;
			else hi = mid;
		}
		return lo;
	}
	
	private static boolean can (int idx, double mult) {
		double left = (1 - mult) * sum, cur = arr[idx] + mult * sum;
		for (int i = 0; i < arr.length; i++) {
			if (i == idx) continue;
			if (arr [i] > cur) continue;
			left -= cur - arr [i];
		}
		return left + 1e-6 > 0;
	}

	public static void main(String[] args) throws IOException {
		in = new Reader(NAME + ".in");
		out = new PrintWriter(new BufferedWriter(new FileWriter(NAME + ".out")));

		int numCases = in.nextInt();
		for (int test = 1; test <= numCases; test++) {
			out.print("Case #" + test + ": ");
			main2();
		}

		out.close();
		System.exit(0);
	}

	/** Faster input **/
	static class Reader {
		final private int BUFFER_SIZE = 1 << 16;
		private DataInputStream din;
		private byte[] buffer;
		private int bufferPointer, bytesRead;

		public Reader() {
			din = new DataInputStream(System.in);
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}

		public Reader(String file_name) throws IOException {
			din = new DataInputStream(new FileInputStream(file_name));
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}

		public String readLine() throws IOException {
			byte[] buf = new byte[1024];
			int cnt = 0, c;
			while ((c = read()) != -1) {
				if (c == '\n')
					break;
				buf[cnt++] = (byte) c;
			}
			return new String(buf, 0, cnt);
		}

		public int nextInt() throws IOException {
			int ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');
			if (neg)
				return -ret;
			else
				return ret;
		}

		public long nextLong() throws IOException {
			long ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');
			if (neg)
				return -ret;
			else
				return ret;
		}

		public double nextDouble() throws IOException {
			double ret = 0, div = 1;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');
			if (c == '.') {
				while ((c = read()) >= '0' && c <= '9')
					ret += (c - '0') / (div *= 10);
			}
			if (neg)
				return -ret;
			else
				return ret;
		}

		public char nextChar() throws IOException {
			char ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			return (char) c;
		}

		private void fillBuffer() throws IOException {
			bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
			if (bytesRead == -1)
				buffer[0] = -1;
		}

		private byte read() throws IOException {
			if (bufferPointer == bytesRead)
				fillBuffer();
			return buffer[bufferPointer++];
		}

		public void close() throws IOException {
			if (din == null)
				return;
			din.close();
		}
	}
}
