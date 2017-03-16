import java.awt.Polygon;
import java.awt.geom.Point2D;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeSet;



public class B implements Runnable {

	class State implements Comparable< State > {
		int x;
		int y;
		double time;
		State(int x, int y, int time) {
			this.x = x;
			this.y = y;
			this.time = time;				
		}
		@Override
		public int compareTo(State arg0) {
			if (Math.abs(time - arg0.time) < EPS) {
				return x == arg0.x ? y - arg0.y : x - arg0.x;
			}
			return time - arg0.time > 0 ? 1 : -1;
		}
	}
	private State[][] field;
	private TreeSet<State> queue;
	double EPS = 1e-8;
	
	void refreshTime(int x, int y, double time) {		
		queue.remove(field[x][y]);
		field[x][y].time = Math.min(field[x][y].time, time);
		queue.add(field[x][y]);		
	}
	private void solve() throws IOException {
		double H = nextInt();
		int height = nextInt();
		int width = nextInt();
		double[][] ceil = new double[height][width];
		double[][] floor = new double[height][width];
		field = new State[height][width];
		queue = new TreeSet<B.State>();
		
		
		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < width; ++j) {
				ceil[i][j] = nextInt();
				field[i][j] = new State(i, j, Integer.MAX_VALUE);
				queue.add(field[i][j]);
			}
		}
		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < width; ++j) {
				floor[i][j] = nextInt();
			}
		}
		
		refreshTime(0, 0, 0);
		int[][] d = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
		while (!queue.isEmpty()) {
			State cur = queue.pollFirst();
			if (cur.time == Integer.MAX_VALUE) {
				break;
			}
			for (int i = 0; i < d.length; ++i) {
				int nx = cur.x + d[i][0];
				int ny = cur.y + d[i][1];
				if (0 <= nx && nx < height && 0 <= ny && ny < width && queue.contains(field[nx][ny])) {
					double curh = H - cur.time * 10;
					double curt = cur.time;
					if (Math.min(ceil[nx][ny], ceil[cur.x][cur.y]) - Math.max(floor[nx][ny], floor[cur.x][cur.y]) >= 50) {
						double needh = ceil[nx][ny] - 50;
						if (curh - needh > 0) {
							curt += (curh - needh) / 10;
							curh = needh;
						}
						if (curt < EPS) {
							refreshTime(nx, ny, curt);
						} else {
							curt += curh > floor[cur.x][cur.y] + 20 - EPS ? 1 : 10;
							refreshTime(nx, ny, curt);
						}
					}
				}
			}
		}
		out.println(field[height - 1][width - 1].time);
	}

	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		(new Thread(new B())).start();
	}

	private BufferedReader br;
	private StringTokenizer st;
	private PrintWriter out;
	private String filename = "";

	@Override
	public void run() {
		try {
			br  = new BufferedReader(new FileReader("input.txt"));
			st  = new StringTokenizer("");
			out = new PrintWriter("output.txt");
			int T = nextInt();
			for (int i = 1; i <= T; ++i) {
				out.print("Case #" + i + ": ");
				solve();
			}
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(-1);
		}		
	}

	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String temp = br.readLine();
			if (temp == null) {
				return null;
			}
			st = new StringTokenizer(temp);
		}
		return st.nextToken();		
	}
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
}
