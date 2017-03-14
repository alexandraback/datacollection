import java.util.*;
import java.io.*;

public class D {
	static int D;
	static P bp;
	static Set<P> set;
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(System.in);
		System.setOut(new PrintStream(new File("D.out")));
		int T = sc.nextInt();
		for(int ca = 1; ca <= T; ca++) {
			int H = sc.nextInt();
			int W = sc.nextInt();
			D = sc.nextInt();
			int x = 0;
			int y = 0;
			set = new HashSet<P>();
			for(int i=0; i<H; i++) {
				String s = sc.next();
				int t = s.indexOf('X');
				if(t >= 0) {
					y = (i - 1)*2 + 1;
					x = (t - 1)*2 + 1;
				}
			}
			bp = new P(x, y);
			dx = new int[]{0, 2*(2*(W-2) - x), 0, -2*x};
			dy = new int[]{-2*y, 0, 2*(2*(H-2) - y), 0};
			search(bp);
			int ans = 0;
			List<P> counted = new ArrayList<P>();
			set.remove(bp);
			P ps[] = new P[set.size()];
			int k = 0;
			for(P p: set) {
				ps[k++] = p;
			}
			Arrays.sort(ps, new Comparator<P>() {
				@Override
				public int compare(P p, P q) {
					double dp = dist(bp, p);
					double dq = dist(bp, q);
					return Double.compare(dp, dq);
				}
			});
			L: for(P p: ps) {
				if(dist(bp, p) < 2 * D + EPS) {
					for(P q: counted) {
						if(onLine(bp, q, p))
							continue L;
					}
					ans++;
					counted.add(p);
				}
			}
			System.out.printf("Case #%d: %d\n", ca, ans);
		}
	}
	static int dx[];
	static int dy[];
	static P sub(P p, P q) { return new P(p.x-q.x, p.y-q.y); }
	static int extp(P p, P q) { return p.x*q.y - p.y*q.x; }
	static boolean onLine(P a, P b, P c) {
		double ext = extp(sub(c, a), sub(b, a));
		double minX = Math.min(a.x, c.x); 
		double minY = Math.min(a.y, c.y); 
		double maxX = Math.max(a.x, c.x); 
		double maxY = Math.max(a.y, c.y);
		return Math.abs(ext) < EPS && minX-EPS <= b.x && 
		b.x <= maxX+EPS && minY-EPS <= b.y && b.y <= maxY+EPS;
	}
	static void search(P pp) {
		Queue<P> Q = new LinkedList<P>();
		set.add(pp);
		Q.add(pp);
		for(;!Q.isEmpty();) {
			P p = Q.poll();
			for(int i=0; i<4; i++) {
				int nx = dx[i] + p.x;
				int ny = dy[i] + p.y;
				P np = new P(nx, ny);
				if(set.contains(np)) continue;
				double d = dist(bp, np);
				if(d > 2*D + EPS) continue;
				set.add(np);
				Q.add(np);
			}
		}
	}
	static double EPS = 1e-8;
	static double dist(P p, P q) {
		return Math.hypot(p.x-q.x, p.y-q.y);
	}
	static class P {
		int x, y;
		P(int x, int y) {
			this.x = x;
			this.y = y;
		}
		@Override
		public int hashCode() {
			return x * 31 + y;
		}
		@Override
		public boolean equals(Object obj) {
			return x==((P)obj).x && y ==((P)obj).y;
		}
		@Override
		public String toString() {
			return x +" "+ y;
		}
	}
}
