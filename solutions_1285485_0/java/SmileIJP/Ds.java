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
import java.util.HashSet;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Ds implements Runnable {

	int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}
	
	class Pair implements Comparable<Pair> {
		int dx;
		int dy;
		Pair(int x, int y) {
			int g = Math.abs(gcd(x, y));
			this.dx = x / g;
			this.dy = y / g;
		}
		
		@Override
		public int compareTo(Pair arg0) {
			if (dx == arg0.dx) {
				return dy - arg0.dy;
			}
			return dx - arg0.dx;
		}
		
	}
	
	private void solve() throws IOException {
		int h = nextInt();
		int w = nextInt();
		int d = nextInt();
		
		char[][] map = new char[h][];
		for (int i = 0; i < h; ++i) {
			map[i] = next().toCharArray();
		}
		int x = 0;
		int y = 0;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if (map[i][j] == 'X') {
					x = i - 1;
					y = j - 1;
				}
			}
		}
		h -= 2;
		w -= 2;		
		int ans = 0;
		
		int limx = (d / h + 20) * 2 * h;
		int limy = (d / w + 20) * 2 * w;
		
		TreeSet<Pair> s = new TreeSet<Ds.Pair>();
		int tx, ty;
		for (int dx = -limx, cx = x; dx <= limx; dx += h, cx = h - cx - 1) {
			for (int dy = -limy, cy = y; dy <= limy; dy += w, cy = w - cy - 1) {
				tx = dx + cx - x;
				ty = dy + cy - y;
				if (tx * tx + ty * ty <= d * d && tx * tx + ty * ty > 0) {
					s.add(new Pair(tx, ty));
				}
			}
		}
		out.println(s.size());
			
	}

	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		(new Thread(new Ds())).start();
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
