import java.util.*;
import java.io.*;

public class tide {
	private static Reader in;
	private static PrintWriter out;
	public static final String NAME = "B-small-attempt0";

	static class State implements Comparable <State> {
		public int x, y;
		public double time;
		
		public State (int x, int y, double time) {
			this.x = x;
			this.y = y;
			this.time = time;
		}
		
		@Override
		public int compareTo (State other) {
			return (int)Math.signum (time - other.time);
		}
	}
	
	private static boolean valid (int x, int y) {
		return x >= 0 && y >= 0 && x < N && y < M && floor [x][y] + 50 <= ceiling [x][y];
	}
	
	private static final double EPS = 1e-8;
	private static int H, N, M;
	private static int [][] floor, ceiling;
	private static final int [] dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
	private static void main2() throws IOException {
		H = in.nextInt(); N = in.nextInt(); M = in.nextInt();
		ceiling = new int [N][M];
		floor = new int [N][M];
		
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				ceiling [i][j] = in.nextInt();
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				floor [i][j] = in.nextInt();
		
		double [][] minTime = new double [N][M];
		for (int i = 0; i < N; i++)
			Arrays.fill (minTime [i], 1 << 29);
		
		boolean [][] vis = new boolean [N][M];
		int [][] queue = new int [N * M][2];
		int front = 0, back = 0;
		queue [back++] = new int [] {0, 0};
		vis [0][0] = true;
		minTime [0][0] = 0;
		while (front < back) {
			int [] pos = queue [front++];
			for (int i = 0; i < 4; i++) {
				int nx = pos[0] + dx [i], ny = pos[1] + dy [i];
				if (valid (nx, ny) && !vis [nx][ny] && Math.max (floor [pos[0]][pos[1]], H) + 50 <= ceiling [nx][ny] &&
						Math.max (floor [nx][ny], H) + 50 <= ceiling [pos[0]][pos[1]]) {
					vis [nx][ny] = true;
					minTime [nx][ny] = 0;
					queue [back++] = new int [] {nx, ny};
				}
			}
		}
		PriorityQueue <State> pq = new PriorityQueue <State> ();
		for (int i = 0; i < back; i++)
			pq.add (new State (queue [i][0], queue [i][1], 0));
		
		while (pq.size() > 0) {
			State pos = pq.poll();
			if (Math.abs (pos.time - minTime [pos.x][pos.y]) > 1e-6) continue;
			if (pos.x == N - 1 && pos.y == M - 1) break;
			double curHeight = Math.max (floor [pos.x][pos.y], H - pos.time * 10);
			for (int i = 0; i < 4; i++) {
				int nx = pos.x + dx [i], ny = pos.y + dy [i];
				if (valid (nx, ny) && floor [pos.x][pos.y] + 50 <= ceiling [nx][ny] &&
						floor [nx][ny] + 50 <= ceiling [pos.x][pos.y]) {
					double nheight = ceiling [nx][ny] - 50;
					if (floor [pos.x][pos.y] > nheight) continue;
					double help;
					if (curHeight < nheight && minTime [nx][ny] > (help = pos.time + 
							((curHeight + EPS > 20 + floor [pos.x][pos.y]) ? 1 : 10))) {
						pq.add (new State (nx, ny, minTime [nx][ny] = help));
					} else if (curHeight + 1e-6 > nheight && minTime [nx][ny] > (help = pos.time +
							((nheight + EPS > 20 + floor [pos.x][pos.y]) ? 1 : 10) + (curHeight - nheight) / 10.)){
						pq.add (new State (nx, ny, minTime [nx][ny] = help));
					}
				}
			}
		}
		
		out.printf ("%.5f\n", minTime [N - 1][M - 1]);
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

		public Reader(String "/home/useruser/datacollection/input/1485488_0.in") throws IOException {
			din = new DataInputStream(new FileInputStream("/home/useruser/datacollection/input/1485488_0.in"));
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
