import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.HashMap;
import java.util.Map;
import java.util.Queue;
import java.util.StringTokenizer;

public class B {
	
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;
	
	static class Point {
		final int x, y;
		
		Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		public boolean equals(Object obj) {
			if (!(obj instanceof Point)) {
				return false;
			}
			Point point = (Point) obj;
			return x == point.x && y == point.y;
		}
		
		public int hashCode() {
			return x * 239 + y * 31;
		}
	}
	
	static class Backtrace {
		final int dist;
		final int dir;
		
		Backtrace(int dist, int dir) {
			this.dist = dist;
			this.dir = dir;
		}
	}
	
	static final int DX[] = {1, 0, -1, 0};
	static final int DY[] = {0, 1, 0, -1};
	static final char DC[] = {'E', 'N', 'W', 'S'};
	
	static void solve() throws Exception {
		int x = nextInt();
		int y = nextInt();
		Point target = new Point(x, y);
		Map<Point, Backtrace> dist = new HashMap<>();
		Queue<Point> queue = new ArrayDeque<>();
		Point start = new Point(0, 0);
		dist.put(start, new Backtrace(0, -1));
		queue.add(start);
		find: while (true) {
			Point cur = queue.remove();
			int curDist = dist.get(cur).dist;
			int newDist = curDist + 1;
			for (int d = 0; d < 4; d++) {
				Point next = new Point(cur.x + DX[d] * newDist, cur.y + DY[d] * newDist);
				if (!dist.containsKey(next)) {
					dist.put(next, new Backtrace(newDist, d));
					queue.add(next);
				}
				if (next.equals(target)) {
					break find;
				}
			}
		}
		printCase();
		StringBuilder sb = new StringBuilder();
		Point cur = target;
		while (!cur.equals(start)) {
			Backtrace bt = dist.get(cur);
			sb.append(DC[bt.dir]);
			cur = new Point(cur.x - DX[bt.dir] * bt.dist, cur.y - DY[bt.dir] * bt.dist);
		}
		sb.reverse();
		out.println(sb.toString());
	}
	
	static void printCase() {
		out.print("Case #" + test + ": ");
	}
	
	static void printlnCase() {
		out.println("Case #" + test + ":");
	}
	
	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			int tests = nextInt();
			for (test = 1; test <= tests; test++) {
				solve();
			}
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}