package round1C2013;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Locale;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	private static class Point {
		public int x;
		public int y;
		public int step;
		
		public Point(int x, int y, int step) {
			super();
			this.x = x;
			this.y = y;
			this.step = step;
		}
	}

	private void solve() throws IOException {
		boolean[][][] used = new boolean[201][201][501];
		char[][][] dir = new char[201][201][501];
		Point[][][] prev = new Point[201][201][501];
		
		Queue<Point> q = new LinkedList<>();
		q.add(new Point(100, 100, 0));
		used[100][100][0] = true;
		while (!q.isEmpty()) {
			Point p = q.poll();
			int d = p.step + 1;
			int x = p.x;
			int y = p.y;
			if (x + d <= 200 && !used[x + d][y][d]) {
				used[x + d][y][d] = true;
				dir[x + d][y][d] = 'E';
				q.add(new Point(x + d, y, d));
				prev[x + d][y][d] = p;
			}
			if (x - d >= 0 && !used[x - d][y][d]) {
				used[x - d][y][d] = true;
				dir[x - d][y][d] = 'W';
				q.add(new Point(x - d, y, d));
				prev[x - d][y][d] = p;
			}
			if (y + d <= 200 && !used[x][y + d][d]) {
				used[x][y + d][d] = true;
				dir[x][y + d][d] = 'N';
				q.add(new Point(x, y + d, d));
				prev[x][y + d][d] = p;
			}
			if (y - d >= 0 && !used[x][y - d][d]) {
				used[x][y - d][d] = true;
				dir[x][y - d][d] = 'S';
				q.add(new Point(x, y - d, d));
				prev[x][y - d][d] = p;
			}
		}
		
		int tests = nextInt();
		for (int t = 1; t <= tests; t++) {
			print("Case #" + t + ": ");

			int x0 = nextInt() + 100;
			int y0 = nextInt() + 100;
			int d = 0;
			int x = x0;
			int y = y0;
			
			ArrayList<Character> res = new ArrayList<>();
			for (int i = 1; i <= 500; i++) {
				if (used[x][y][i]) {
					d = i;
					break;
				}
			}
			while (d != 0) {
				res.add(dir[x][y][d]);
				Point p = prev[x][y][d];
				x = p.x;
				y = p.y;
				d = p.step;
			}
			
			Collections.reverse(res);
			int X = 100;
			int Y = 100;
			d = 1;
			for (char c: res) {
				print(c);
				if (c == 'N') {
					Y += d;
				} else if (c == 'S') {
					Y -= d;
				} else if (c == 'W') {
					X -= d;
				} else {
					X += d;
				}
				d++;
			}
			if (X != x0 || Y != y0) {
				System.err.println(t + " " + X + " " + Y + " " + x0 + " " + y0);
			}
			println("");
		}
	}

	private String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	private int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(nextToken());
	}

	private double nextDouble() throws NumberFormatException, IOException {
		return Double.parseDouble(nextToken());
	}

	private long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private void print(Object o) {
		writer.print(o);
	}

	private void println(Object o) {
		writer.println(o);
	}

	private void printf(String format, Object... o) {
		writer.printf(format, o);
	}

	public static void main(String[] args) {
		long time = System.currentTimeMillis();
		Locale.setDefault(Locale.US);
		new Main().run();
		System.err.printf("%.3f\n", 1e-3 * (System.currentTimeMillis() - time));
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	private void run() {
		try {
			reader = new BufferedReader(new FileReader(new File("input.in")));
			writer = new PrintWriter(new File("output.out"));
			solve();
			reader.close();
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(13);
		}
	}
}