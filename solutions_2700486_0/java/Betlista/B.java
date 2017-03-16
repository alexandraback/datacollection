import java.awt.Point;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;


public class B {

	public static void main(String[] args) throws Exception {
		init();
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		String line;
		StringTokenizer tok;
		for (int ii = 0; ii < T; ii++) {
			line = br.readLine();
			tok = new StringTokenizer(line);
			int N, X, Y;
			N = Integer.parseInt(tok.nextToken());
			X = Integer.parseInt(tok.nextToken());
			Y = Integer.parseInt(tok.nextToken());
			System.out.printf("Case #%d: %.9f\n", ii+1, solve(N, X, Y));
		}
	}

	static HashMap<Integer, HashMap<Point, Double>> data = new HashMap<>();

	public static void init() {
		HashMap<Point, Double> n1map = new HashMap<>();
		n1map.put(new Point(0, 0),  1D);
		data.put(1, n1map);
		
		data.put(6, getN6());

		data.put(15, getN15());
	}

	private static HashMap<Point, Double> getN6() {
		HashMap<Point, Double> res = new HashMap<>();
		res.putAll(data.get(1));
		int x = -2;
		int y = 0;
		res.put(new Point(x, y), 1D);
		for (int i = 0; i < 2; i++) {
			++x;
			++y;
			res.put(new Point(x, y), 1D);
		}
		for (int i = 0; i < 2; i++) {
			++x;
			--y;
			res.put(new Point(x, y), 1D);
		}
		return res;
	}

	private static HashMap<Point, Double> getN15() {
		HashMap<Point, Double> res = new HashMap<>();
		res.putAll(data.get(6));
		int x = -4;
		int y = 0;
		res.put(new Point(x, y), 1D);
		for (int i = 0; i < 3; i++) {
			++x;
			++y;
			res.put(new Point(x, y), 1D);
		}
		for (int i = 0; i < 3; i++) {
			++x;
			--y;
			res.put(new Point(x, y), 1D);
		}
		return res;
	}

	public static double solve(int N, int X, int Y) {
		Set<Integer> special = new HashSet<Integer>(); special.add(1); special.add(6); special.add(15);
		HashMap<Point, Double> map;
		if (special.contains(N)) {
			map = data.get(N);
		} else {
			if (data.containsKey(N)) {
				map = data.get(N);
			} else {
				if (N > 15) {
					map = get(15, N - 15, 6);
				} else if (N > 6 ) {
					map = get(6, N - 6, 4);
				} else {
					map = get(1, N - 1, 2);
				}
				data.put(N, map);
			}
		}
		Double res = map.get(new Point(X, Y));
		return res == null ? 0 : res;
	}

	private static HashMap<Point, Double> get(int SN, int cnt, int max) {
		// SN = special N
		HashMap<Point, Double> res = new HashMap<>();
		int pos = 0;
		for (int mask = 0; mask < (1 << cnt); mask++) {
			int rc = Integer.bitCount(mask);
			int lc = cnt - rc;
			if (rc > max || lc > max ) {
				continue;
			}
			++pos;
			for (int i = 0; i < lc; i++) {
				Point p = getLeft(SN, i);
				inc(p, res);
			}
			for (int i = 0; i < rc; i++) {
				Point p = getRight(SN, i);
				inc(p, res);
			}
		}
		// divide by pos
		for (Point p : res.keySet()) {
			double prob = res.get(p);
			res.put(p, prob / pos);
		}
		// add special points
		res.putAll(data.get(SN));
		return res;
	}

	private static Point getLeft(int SN, int idx) {
		int y = 0;
		int x;
		switch(SN) {
		case 1: x = -2; break;
		case 6: x = -4; break;
		case 15: x = -6; break;
		default: throw new IllegalArgumentException("SN=" + SN);
		}
		for (int i = 0; i < idx; i++) {
			++y;
			++x;
		}
		return new Point(x, y);
	}

	private static Point getRight(int SN, int idx) {
		int y = 0;
		int x;
		switch(SN) {
		case 1: x = 2; break;
		case 6: x = 4; break;
		case 15: x = 6; break;
		default: throw new IllegalArgumentException("SN=" + SN);
		}
		for (int i = 0; i < idx; i++) {
			++y;
			--x;
		}
		return new Point(x, y);
	}

	private static void inc(Point p, Map<Point, Double> map) {
		Double val = map.get(p);
		if (val == null) val = 0D;
		map.put(p, val + 1);
	}

}
