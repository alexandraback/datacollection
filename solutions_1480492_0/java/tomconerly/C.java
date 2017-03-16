import java.util.*;
import static java.lang.Math.*;

public class C {
	static void p(Object ...o) { System.err.println(Arrays.deepToString(o));}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int zz = 1; zz <= T; zz++) {
			testcasenum = zz;
			int N = in.nextInt();
			boolean[] L = new boolean[N];
			long[] S = new long[N];
			long[] P = new long[N];
			for (int i = 0; i < N; i++) {
				L[i] = in.next().charAt(0) == 'L';
				S[i] = in.nextLong();
				P[i] = in.nextLong();
			}
			double low = 0.0;
			double high = 100000000;
			for (int i = 0; i < 200; i++) {
				double mid = (low + high)/2;
				if (solve(N, L, S, P, mid)) {
					low = mid;
				} else {
					high = mid;
				}
			}

			if (abs(100000000-high) < eps) 
				System.out.format("Case #%d: Possible\n", zz);
			else
				System.out.format("Case #%d: %.09f\n", zz, high);
		}
	}
	static int testcasenum;
	static class Intersection {
		int a, b;
		double t1, t2;
		public Intersection(int a, int b, double t1, double t2) {
			this.a = a;
			this.b = b;
			this.t1 = t1;
			this.t2 = t2;
		}
		public boolean intersects(Intersection i) {
			return (a == i.a || a == i.b || b == i.a || b == i.b) && t1 <= i.t2 - eps && i.t1 <= t2 - eps;
		}
		public String toString() {
			return String.format("[%d %d %.02f %.02f]", a, b, t1, t2);
		}
	}
	static double eps = 1e-9;
	static boolean eq(double a, double b) {
		return abs(a-b) < eps;
	}
	static boolean solve(int N, boolean[] L, long[] S, long[] P, double maxt) {
		ArrayList<Intersection> I = new ArrayList<Intersection>();
		for (int i = 0; i < N; i++) {
			for(int j = i+1; j < N; j++) {
				if (S[i] != S[j]) {
					double t1 = (P[j] - P[i] + 5) / (double)(S[i] - S[j]);
					double t2 = (P[j] - P[i] - 5) / (double)(S[i] - S[j]);
					if (!eq(P[j] + S[j]*t1 + 5, P[i] + S[i]*t1))
						throw new RuntimeException();
					if (!eq(P[j] + S[j]*t2 - 5, P[i] + S[i]*t2))
						throw new RuntimeException();

					double st = min(t1, t2);
					double en = max(t1, t2);
					if (en < -eps)
						continue;
					st = max(-eps, st);
					en = max(-eps, en);
					st = min(st, maxt);
					en = min(en, maxt);
					if (!eq(st, en))
						I.add(new Intersection(i, j, st, en));
				} else {
					if (abs(P[i] - P[j]) < 5) {
						I.add(new Intersection(i, j, -eps, maxt));
					}
				}
			}
		}
//		if (eq(maxt, 100000000/2))
//			p("ALL:",I);
		boolean[] U = new boolean[I.size()];
		ArrayList<ArrayList<Intersection>> G = new ArrayList<ArrayList<Intersection>>();
		for (int i = 0; i < I.size(); i++) {
			if (U[i])
				continue;
			ArrayList<Intersection> current = new ArrayList<Intersection>();
			current.add(I.get(i));
			U[i] = true;
			for(int at = 0; at < current.size(); at++) {
				for (int j = 0; j < I.size(); j++) {
					if(U[j])
						continue;
					if(current.get(at).intersects(I.get(j))) {
						U[j] = true;
						current.add(I.get(j));
					}
				}
			}
			G.add(current);
		}
		ArrayList<Integer>[] IG = new ArrayList[N*2];
		for (int i = 0; i < IG.length; i++)
			IG[i] = new ArrayList<Integer>();
		boolean[] visited = new boolean[2*N];
		for (ArrayList<Intersection> current: G) {
//			if (eq(maxt, 100000000/2)) {
//				p(current);
//			}
			for (int i = 0; i < IG.length; i++) {
				IG[i].clear();
			}
			for (Intersection i:current) {
				IG[i.a*2].add(i.b*2+1);
				IG[i.a*2+1].add(i.b*2);
				IG[i.b*2].add(i.a*2+1);
				IG[i.b*2+1].add(i.a*2);
				if (i.t1 <= -eps && i.t2 >= eps) {
					if (L[i.a]) {
						IG[i.a*2+1].add(i.a*2);
					} else {
						IG[i.a*2].add(i.a*2+1);
					}
					if (L[i.b]) {
						IG[i.b*2+1].add(i.b*2);
					} else {
						IG[i.b*2].add(i.b*2+1);
					}
				}
			}
			for (int i = 0; i < N; i++) {
				Arrays.fill(visited, false);
				boolean a = dfs(2*i, 2*i+1, visited, IG);
				Arrays.fill(visited, false);
				boolean b = dfs(2*i+1, 2*i, visited, IG);
				if (a && b)
					return false;
			}
		}
		return true;
	}
	private static boolean dfs(int at, int goal, boolean[] V, ArrayList<Integer>[] IG) {
		if (V[at])
			return false;
		V[at] = true;
		if (at == goal)
			return true;
		for (int e:IG[at]) {
			if (dfs(e, goal, V, IG))
				return true;
		}
		return false;
	}
}
