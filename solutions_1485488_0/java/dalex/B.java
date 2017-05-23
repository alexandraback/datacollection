import java.awt.Point;
import java.io.*;
import java.util.*;

import static java.lang.Math.*;

/**
 * Google Code Jam 2012
 * Round 1B
 * Problem B
 * @author dalex
 */
public class B implements Runnable {
	
	BufferedReader in;
	PrintWriter out;
	StringTokenizer tok;

	public static void main(String[] args) {
		new Thread(null, new B(), "", 256 * (1L << 20)).start();
	}

	@Override
	public void run() {
		try {
			in = new BufferedReader(new FileReader("/home/useruser/datacollection/input/1485488_0.in"));
			out = new PrintWriter("output.txt");
			Locale.setDefault(Locale.US);
			tok = new StringTokenizer("");
			int tests = readInt();
			int p = tests / 10;
			long startTime = System.currentTimeMillis();
			for (int test = 1; test <= tests; test++) {
				out.printf("Case #%d: ", test);
				solveTest();
				if (p == 0 || test % p == 0 || test == tests) {
					long newTime = System.currentTimeMillis();
					System.err.printf("Test %d of %d completed, time = %d\n", test, tests, newTime - startTime);
				}
			}
			in.close();
			out.close();
		} catch (Throwable t) {
			t.printStackTrace(System.err);
			System.exit(-1);
		}
	}

	String readString() throws IOException {
		while (!tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	int readInt() throws IOException {
		return Integer.parseInt(readString());
	}

	long readLong() throws IOException {
		return Long.parseLong(readString());
	}

	double readDouble() throws IOException {
		return Double.parseDouble(readString());
	}
	
	void debug(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}

	// solution
	
	final int[] dx = {1, 0, -1, 0};
	final int[] dy = {0, 1, 0, -1};
	final int DOWN = 0, RIGHT = 1, UP = 2, LEFT = 3;
	final int INF = 1000 * 1000 * 1000;
	
	boolean good(int x, int y, int n, int m) {
		return x >= 0 && x < n && y >= 0 && y < m;
	}
	
	class Vertex implements Comparable<Vertex> {
		int x, y;
		int dist;
		
		public Vertex(int x, int y, int dist) {
			this.x = x;
			this.y = y;
			this.dist = dist;
		}
		
		@Override
		public int compareTo(Vertex v) {
			return dist - v.dist;
		}
		
	}
	
	void solveTest() throws IOException {
		int h = readInt() * 10;
		int n = readInt();
		int m = readInt();
		int[][] up = new int[n][m];
		int[][] down = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				up[i][j] = readInt() * 10;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				down[i][j] = readInt() * 10;
			}
		}
		int[][][] waitTime = new int[n][m][4];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				waitTime[i][j][UP] = i == 0 ? INF : getWaitTimeForMoving(up[i][j], down[i][j], up[i-1][j], down[i-1][j], h);
				waitTime[i][j][LEFT] = j == 0 ? INF : getWaitTimeForMoving(up[i][j], down[i][j], up[i][j-1], down[i][j-1], h);
				waitTime[i][j][DOWN] = i == n-1 ? INF : getWaitTimeForMoving(up[i][j], down[i][j], up[i+1][j], down[i+1][j], h);
				waitTime[i][j][RIGHT] = j == m-1 ? INF : getWaitTimeForMoving(up[i][j], down[i][j], up[i][j+1], down[i][j+1], h);
			}
		}
		int[][] best = new int[n][m];
		for (int[] arr : best) {
			Arrays.fill(arr, INF);
		}
		PriorityQueue<Vertex> pq = new PriorityQueue<Vertex>();
		best[0][0] = 0;
		Queue<Point> q = new ArrayDeque<Point>();
		q.add(new Point(0, 0));
		while (!q.isEmpty()) {
			Point v = q.poll();
			int x = v.x;
			int y = v.y;
			pq.add(new Vertex(x, y, 0));
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (good(nx, ny, n, m)) {
					if (canGo(up[x][y], down[x][y], up[nx][ny], down[nx][ny], h)) {
						if (best[nx][ny] > 0) {
							best[nx][ny] = 0;
							q.add(new Point(nx, ny));
						}
					}
				}
			}
		}
		while (!pq.isEmpty()) {
			Vertex v = pq.poll();
			int x = v.x;
			int y = v.y;
			if (v.dist > best[x][y]) {
				continue;
			}
			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (good(nx, ny, n, m)) {
					int thisTimeForMoving = max(best[x][y], waitTime[x][y][dir]);
					if (thisTimeForMoving < INF) {
						int level = h - thisTimeForMoving;
						if (level - down[x][y] >= 200) {
							tryUpdate(pq, nx, ny, best, thisTimeForMoving + 100);
						} else {
							tryUpdate(pq, nx, ny, best, thisTimeForMoving + 1000);
						}
					}
				}
			}
		}
		int result = best[n-1][m-1];
		out.printf("%.12f\n", result / 100.0);
	}

	private void tryUpdate(PriorityQueue<Vertex> pq, int nx, int ny, int[][] best, int arriveTime) {
		if (best[nx][ny] > arriveTime) {
			best[nx][ny] = arriveTime;
			pq.add(new Vertex(nx, ny, arriveTime));
		}
	}

	private int getWaitTimeForMoving(int upFrom, int downFrom, int upTo, int downTo, int h) {
		int left = 0, right = h, ans = INF;
		while (left <= right) {
			int t = (left + right) / 2;
			int level = h - t;
			if (canGo(upFrom, downFrom, upTo, downTo, level)) {
				ans = t;
				right = t - 1;
			} else {
				left = t + 1;
			}
		}
		return ans;
	}

	private boolean canGo(int upFrom, int downFrom, int upTo, int downTo, int level) {
		if (upTo - level < 500) return false;
		if (upTo - downFrom < 500) return false;
		if (upTo - downTo < 500) return false;
		if (upFrom - downTo < 500) return false;
		return true;
	}

}
