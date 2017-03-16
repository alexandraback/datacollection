import java.util.*;
import java.io.*;

public class mirrors {
	private static BufferedReader in;
	private static PrintWriter out;
	public static final String NAME = "D-small-attempt2";
	
	
	static class Slope {
		public int x, y;
		
		public Slope (int x, int y) {
			this.x = x; this.y = y;
			if (Math.abs (x) < Math.abs (y)) {
				x ^= y; y ^= x; x ^= y;
			}
			int gcd = gcd (Math.abs (x), Math.abs (y));
			if (gcd == 0) return;
			this.x /= gcd; this.y /= gcd;
		}
		
		@Override
		public int hashCode() {
			return x << 15 + y;
		}
		
		@Override
		public boolean equals (Object other) {
			return (other instanceof Slope) && ((Slope)other).x == this.x
				&& ((Slope)other).y == this.y;
		}
	}
	
	static class Point {
		public int x, y;
		public Point (int x, int y) {
			this.x = x;
			this.y = y;
		}
		
		public int getX() {
			if (x % 2 == 0) return x * (H - 2) + posx;
			else return (x + 1) * (H - 2) - posx - 1;
		}
		
		public int getY() {
			if (y % 2 == 0) return y * (W - 2) + posy;
			else return (y + 1) * (W - 2) - posy - 1;
		}
		
		@Override
		public int hashCode() {
			return x << 15 + y;
		}
		
		@Override
		public boolean equals (Object other) {
			return (other instanceof Point) && ((Point)other).x == this.x
				&& ((Point)other).y == this.y;
		}
	}
	
	private static HashSet <Slope> mp;
	private static HashSet <Point> mp2;
	
	private static int gcd (int a, int b) {
		return b == 0 ? a : gcd (b, a % b);
	}
	
	private static int dist (int x1, int y1, int x2, int y2) {
		return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	}

	private static int H, W, D, posx, posy;
	private static void main2() throws IOException {
		StringTokenizer st = new StringTokenizer (in.readLine());
		H = Integer.parseInt (st.nextToken ());
		W = Integer.parseInt (st.nextToken ());
		D = Integer.parseInt (st.nextToken ());
		
		String s; in.readLine ();
		posx = -1; posy = -1;
		for (int i = 1; i < H - 1; i++) {
			s = in.readLine ();
			for (int j = 0; posx == -1 && j < W; j++)
				if (s.charAt (j) == 'X') {
					posx = i - 1;
					posy = j - 1;
				}
		}
		in.readLine ();
		
		mp = new HashSet <Slope> ();
		mp2 = new HashSet <Point> ();
		Point [] arr = new Point [10000];
		int front = 0, back = 0;
		arr [back++] = new Point (0, 0);
		mp2.add (new Point (0, 0));
		
		int count = 0;
		while (front < back) {
			Point curPoint = arr [front++];
			if (dist (curPoint.getX(), curPoint.getY(), posx, posy) > D * D) continue;
			Slope sl = new Slope (curPoint.getX() - posx, curPoint.getY() - posy);
			if (!mp.contains (sl)) {
				mp.add (sl);
				count++;
			}
			Point add = new Point (curPoint.x - 1, curPoint.y);
			if (!mp2.contains (add)) {
				arr [back++] = add;
				mp2.add (add);
			}
			Point add2 = new Point (curPoint.x + 1, curPoint.y);
			if (!mp2.contains (add2)) {
				arr [back++] = add2;
				mp2.add (add2);
			}
			Point add3 = new Point (curPoint.x, curPoint.y - 1);
			if (!mp2.contains (add3)) {
				arr [back++] = add3;
				mp2.add (add3);
			}
			Point add4 = new Point (curPoint.x, curPoint.y + 1);
			if (!mp2.contains (add4)) {
				arr [back++] = add4;
				mp2.add (add4);
			}
			
		}
		out.println (count - 1);
	}

	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new FileReader (NAME + ".in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter(NAME + ".out")));

		int numCases = Integer.parseInt (in.readLine ());
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
