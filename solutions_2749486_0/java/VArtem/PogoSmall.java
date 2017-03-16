import java.io.*;
import java.util.*;

public class PogoSmall {

	FastScanner in;
	PrintWriter out;

	int[] dx = new int[] {1, 0, -1, 0};
	int[] dy = new int[] {0, 1, 0, -1};
	String dir = "ENWS";
	
	
	
	class Point {
		int x, y;

		public Point(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + getOuterType().hashCode();
			result = prime * result + x;
			result = prime * result + y;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Point other = (Point) obj;
			if (!getOuterType().equals(other.getOuterType()))
				return false;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}

		private PogoSmall getOuterType() {
			return PogoSmall.this;
		}
	}
	
	void solve() {
		Point p = new Point(in.nextInt(), in.nextInt());
		
		List<Point> path = new ArrayList<>();
		path.add(p);
		while (prev.containsKey(p)) {
			p = prev.get(p);
			path.add(p);
		}
		
		
		Collections.reverse(path);
		
		for (int i = 0; i < path.size() - 1; i++) {
			out.print(getDir(path.get(i), path.get(i + 1)));
		}
		out.println();
	}
	
	private String getDir(Point a, Point b) {
		if (a.x < b.x) {
			return "E";
		} else if (a.x > b.x) {
			return "W";
		} else if (a.y < b.y) {
			return "N";
		} else {
			return "S";
		}
	}

	Map<Point, Point> prev;
	
	void doBFS() {
		Point start = new Point(0, 0);
		
		Map<Point, Integer> distance = new HashMap<>();
		prev = new HashMap<>();
		distance.put(start, 0);
		Queue<Point> queue = new ArrayDeque<>();
		queue.add(start);
		while (!queue.isEmpty()) {
			Point cur = queue.poll();
			int step = distance.get(cur) + 1;
			
			for (int i = 0; i < 4; i++) {
				int ax = cur.x + step * dx[i];
				int ay = cur.y + step * dy[i];
				if (Math.max(Math.abs(ax), Math.abs(ay)) > 300) {
					continue;
				}
				Point to = new Point(ax, ay);
				if (!distance.containsKey(to)) {
					distance.put(to, step);
					prev.put(to, cur);
					queue.add(to);
				}
			}
		}
	
	}
	
	void run() {
		try {
			in = new FastScanner(new File("input.txt"));
			out = new PrintWriter("output.txt");
			
			doBFS();
			int tests = in.nextInt();
			for (int i = 0; i < tests; i++) {
				out.printf("Case #%d: ", (i + 1));
				solve();
			}

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File file) {
			try {
				br = new BufferedReader(new FileReader(file));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new PogoSmall().run();
	}
}
