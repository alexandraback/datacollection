import java.util.*;
import java.io.*;

public class dancing {
	private static Reader in;
	private static PrintWriter out;
	public static final String NAME = "B-small-attempt1";

	private static void main2() throws IOException {
		int N = in.nextInt(), S = in.nextInt(), p = in.nextInt();
		int [] arr = new int [N + 1];
		for (int i = 1; i <= N; i++)
			arr [i] = in.nextInt();
		
		int [][] dp = new int [N + 1][S + 1];
		dp [0][0] = 0;
		for (int i = 1; i <= N; i++) {
			int curscore = (arr [i] + 2) / 3, nscore = (arr [i] + 4) / 3;
			if (arr [i] == 0) curscore = nscore = 0;
			dp [i][0] = dp [i - 1][0];
			if (curscore >= p)
				dp [i][0] = dp [i - 1][0] + 1;
			for (int j = 1; j <= S; j++) {
				dp [i][j] = Math.max (dp [i - 1][j - 1], dp [i - 1][j]);
				if (curscore >= p)
					dp [i][j] = Math.max (dp [i][j], dp [i - 1][j] + 1);
				if (nscore >= p)
					dp [i][j] = Math.max (dp [i][j], dp [i - 1][j - 1] + 1);
			}
		}
		
		out.println (dp [N][S]);
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
