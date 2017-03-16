import java.awt.Point;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.StringTokenizer;


public class BNew {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = br.readLine();
		StringTokenizer tok = new StringTokenizer(line);
		int T = ti(tok.nextToken());
		for (int ii = 0; ii < T; ii++) {
			tok = new StringTokenizer(br.readLine());
			int X = ti(tok.nextToken());
			int Y = ti(tok.nextToken());
			System.err.printf("case %d: X=%d, Y=%d\n", ii, X, Y);
//			if (ii == 18) break;
			System.out.printf("Case #%d: %s\n", ii+1, solve(X, Y));			
		}
	}

	// U, D, L, R
	static char[] dir = { 'N', 'S', 'W', 'E' };
	static long[] dx = { 0, 0, -1, 1 };
	static long[] dy = { 1, -1, 0, 0 };
	
	static Map<Point, String> map = new HashMap<Point, String>();
	static {
		map.put(new Point(0, 0), "");
		
		map.put(new Point(0, 1), "N");
		map.put(new Point(0, -1), "S");
		map.put(new Point(1, 0), "E");
		map.put(new Point(-1, 0), "W");
		
		//
		map.put(new Point(1, 1), "NWE");
		map.put(new Point(-1, 1), "NEW");
		map.put(new Point(1, -1), "SWE");
		map.put(new Point(-1, -1), "SEW");
	}
	
	static String solve(int X, int Y) {
		Point p = new Point(X, Y);
		if (map.containsKey(p)) {
			return map.get(p);
		} else {
			int ax = Math.abs(X);
			int ay = Math.abs(Y);
			if ( ax > ay ) {
				if (X > 0 ) {
					String res = solve(X-1, Y) + "WE";
					map.put(p, res);
					return res;
				} else {
					String res = solve(X+1, Y) + "EW";
					map.put(p, res);
					return res;
				}
			} else {
				if (Y > 0) {
					String res = solve(X, Y - 1) + "SN";
					map.put(p, res);
					return res;
				} else {
					String res = solve(X, Y + 1) + "NS";
					map.put(p, res);
					return res;
				}
			}
		}
	}
	
//	private static boolean isBetween(long n, int f, int t) {
//		return f <= n && n <= t;
//	}

//	static class State {
//		long x;
//		long y;
//		int idx;
//		char[] track = new char[510]; 
//	}

	static int ti(String s) {
		return Integer.parseInt(s);
	}

	static long tl(String s) {
		return Long.parseLong(s);
	}

}
