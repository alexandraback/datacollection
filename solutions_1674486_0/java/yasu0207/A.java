import java.util.*;
import java.io.*;

public class A {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(System.in);
		System.setOut(new PrintStream(new File("A.out")));
		
		int T = sc.nextInt();
		for(int tc = 1; tc <= T; tc++) {
			int N = sc.nextInt();
			Dinic d = new Dinic(N);
			for(int i=0; i<N; i++) {
				int m = sc.nextInt();
				for(int j=0; j<m; j++) {
					int k = sc.nextInt() - 1;
					d.make(i, k, 1);
				}
			}
			boolean diam = false;
			L: for(int i=0; i<N; i++)
				for(int j=0; j<N; j++) {
					if(i == j) continue;
					int x = (int)d.maxflow(i, j);
					if(x == 2) {
						diam = true;
						break L;
					}
				}
			if(diam)
				System.out.printf("Case #%d: Yes\n", tc);
			else 
				System.out.printf("Case #%d: No\n", tc);
		}
	}
	static class Dinic {
		static final long INF = Integer.MAX_VALUE;
		int n;
		V s, t;
		V[] vs;
		public Dinic(int n) {
			this.n = n;
			vs = new V[n];
			for(int i=0; i<n; i++) vs[i] = new V();
		}
		void make(int from, int to, long cap) {
			E e = new E(vs[to], cap);
			E r = new E(vs[from], 0);
			e.rev = r;
			r.rev = e;
			vs[from].add(e);
			vs[to].add(r);
		}
		long maxflow(int si, int ti) {
			init();
			s = vs[si];
			t = vs[ti];
			long flow=0;
			for (int p=1;; p++) {
				Queue<V> q = new LinkedList<V>();
				s.p=p;
				s.level=0;
				q.offer(s);
				while (!q.isEmpty()) {
					V v = q.poll();
					v.i = v.size()-1;
					for(E e : v)
						if (e.to.p < p && e.cap > 0) {
							e.to.level = v.level + 1;
							e.to.p = p;
							q.offer(e.to);
						}
				}
				if(t.p < p) return flow;
				for(long f;(f=dfs(s, INF))>0;) flow += f;
				if(flow > 1) return 2; 
			}
		}
		long dfs(V v, long f) {
			if (v == t) return f;
			for (; v.i >= 0; v.i--) {
				E e = v.get(v.i);
				if (e.to.level > v.level && e.cap > 0) {
					long min = dfs(e.to, Math.min(e.cap, f));
					if (min > 0) {
						e.cap -= min;
						e.rev.cap += min;
						return min;
					}
				}
			}
			return 0;
		}
		void init() {
			for (V v : vs) {
				v.level = 0;
				v.p = 0;
				v.i = 0;
				for (E e : v) {
					e.cap = e.CAP;
				}
			}
		}
		class V extends ArrayList<E> {
			int level, p, i;
		}
		class E {
			E rev;
			V to;
			long cap;
			final long CAP;
			E(V to, long cap) {
				this.to = to;
				this.cap = cap;
				CAP = cap;
			}
		}
	}
}
