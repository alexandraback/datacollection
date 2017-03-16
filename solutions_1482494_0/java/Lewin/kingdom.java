import java.util.*;
import java.io.*;

public class kingdom {
	private static Reader in;
	private static PrintWriter out;
	public static final String NAME = "B-small-attempt0";

	private static int curstars;
	static class Level1 implements Comparable <Level1> {
		public int s1, s2, idx;
		
		public Level1 (int s1, int s2, int idx) {
			this.s1 = s1;
			this.s2 = s2;
			this.idx = idx;
		}
		
		public int compareTo (Level1 other) {
			return s1 == other.s1 ? other.s2 - s2 : s1 - other.s1;
		}
	}
	
	static class Level2 implements Comparable <Level2> {
		public int s2, idx;
		public Level2 (int s2, int idx) {
			this.s2 = s2;
			this.idx = idx;
		}
		
		public int compareTo (Level2 other) {
			return s2 - other.s2;
		}
	}
	
	private static void main2() throws IOException {
		int N = in.nextInt();
		Level1 [] levels1 = new Level1 [N];
		Level2 [] levels2 = new Level2 [N];
		for (int i = 0; i < N; i++) {
			levels1 [i] = new Level1 (in.nextInt(), in.nextInt(), i);
			levels2 [i] = new Level2 (levels1 [i].s2, i);
		}
		
		Arrays.sort (levels1);
		Arrays.sort (levels2);
		int idx1 = 0, idx2 = 0;
		curstars = 0;
		int i;
		int [] stars = new int [N]; 
		for (i = 1; curstars < 2 * N && i <= 2 * N; i++) {
			if (idx2 < N && levels2 [idx2].s2 <= curstars) {
				curstars += 2 - stars [levels2 [idx2].idx];
				stars [levels2 [idx2].idx] = 2;
				idx2++;
			} else if (idx1 < N && levels1 [idx1].s1 <= curstars) {
				curstars += 1 - stars [levels1 [idx1].idx];
				stars [levels1 [idx1].idx] = 1;
				idx1++;
			}
		}
		out.println (curstars == 2 * N ? i - 1 : "Too Bad");
		
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
