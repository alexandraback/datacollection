import java.util.*;
import java.io.*;

/**
  * @author Mighty Cohadar 
  */
public class Charlie {

	static final int INF = Integer.MAX_VALUE / 2;

	final int nn;
	final List<List<Integer>> U;
	final List<List<Integer>> V;
	final Integer[] PU;
	final Integer[] PV; 
	final int[] D;
	final int NIL;
	
	public Charlie(int nn, List<List<Integer>> U, List<List<Integer>> V) {
		this.nn = nn;
		this.U = U;
		this.V = V;
		this.PU = new Integer[U.size()];
		this.PV = new Integer[V.size()];
		this.D = new int[nn + U.size() + V.size()];
		this.NIL = D.length - 1;
	}

	public int ss(Integer x) {
		return (x == null) ? NIL : x;
	}

	public boolean bfs() {
		ArrayDeque<Integer> Q = new ArrayDeque<>();
		for (int u = 0; u < U.size(); u++) {
			if (PU[u] == null) {
				D[u] = 0;
				Q.add(u);
			} else {
				D[u] = INF;
			}

		}
		D[NIL] = INF;
		while (!Q.isEmpty()) {
			int u = Q.remove();
			if (D[u] < D[NIL]) {
				for (int v : U.get(u)) {
					if (D[ss(PV[v])] == INF) {
						D[ss(PV[v])] = D[u] + 1;
						if (PV[v] != null) {
							Q.add(PV[v]);	
						}
					}
				}
			}
		}
		return D[NIL] != INF;
	}

	public boolean dfs(Integer u) {
		if (u != null) {
			for (int v : U.get(u)) {
				if (D[ss(PV[v])] == D[u] + 1) {
					if (dfs(PV[v])) {
						PV[v] = u;
						PU[u] = v;
						return true;
					}
				}
			}
			D[u] = INF;
			return false;
		}
		return true;
	}

	public int HopcroftKarp() {
		int matching = 0;
		while (bfs()) {
			for (int u = 0; u < U.size(); u++) {
				if (PU[u] == null) {
					if (dfs(u)) {
						matching++;
					}
				}
			}
		}
		return matching;
	}

	public int solve(int it) {
		debug(nn, U, V);
		HopcroftKarp();
		debug("PU", PU);
		debug("PV", PV);
		List<Edge> E = new ArrayList<>();
		for (int u = 0; u < U.size(); u++) {
			for (int v : U.get(u)) {
				if (PU[u] != null && PU[u] == v) {
					E.add(new Edge(u, v));
				}
			}
		}
		for (int u = 0; u < U.size(); u++) {
			for (int v : U.get(u)) {
				if (PU[u] == null || PU[u] != v) {
					E.add(new Edge(u, v));
				}
			}
		}
		debug(E);
		int fake = 0;
		List<Integer> L = new ArrayList<>();
		List<Integer> R = new ArrayList<>();
		for (Edge e : E) {
			if (L.contains(e.a) && R.contains(e.b)) {
				fake++;
			}
			L.add(e.a);
			R.add(e.b);
		}
		return fake;
	}

	public static int index(String s, Map<String, Integer> M) {
		Integer r = M.get(s);
		if (r == null) {
			r = M.size();
			M.put(s, r);
		}
		return r;
	}	

	public static Charlie load(Scanner scanner) {
		int nn = scanner.nextInt();
		scanner.nextLine();
		Map<String, Integer> A = new HashMap<>();
		Map<String, Integer> B = new HashMap<>();

		List<List<Integer>> U = new ArrayList<>();
		List<List<Integer>> V = new ArrayList<>();
		for (int i = 0; i < nn; i++) {
			String[] S = scanner.nextLine().split(" ");
			int a = index(S[0], A);
			int b = index(S[1], B);
			if (a == U.size()) {
				U.add(new ArrayList<Integer>());
			}
			if (b == V.size()) {
				V.add(new ArrayList<Integer>());
			}
			U.get(a).add(b);
			V.get(b).add(a);
		}
		return new Charlie(nn, U, V);
	}	

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int nt = scanner.nextInt();
		scanner.nextLine();
		assert 1 <= nt && nt <= 100 : "out of range, nt: " + nt;
		for (int it = 1; it <= nt; it++) {
			Charlie o = Charlie.load(scanner);
			System.out.printf("Case #%d: %d\n", it, o.solve(it));
		}
	}

	static void debug(Object...os) {
		// System.err.printf("%.65536s\n", Arrays.deepToString(os));
	}	

	static class Edge implements Comparable<Edge> {
		final int a;
		final int b;
		Edge(int a, int b) {
			this.a = a;
			this.b = b;
		}
		public int compareTo(Edge that) {
			if (this.a == that.a) {
				return Integer.compare(this.b, that.b);
			} else {
				return Integer.compare(this.a, that.a);
			}
		}
		public String toString() {
			return String.format("(a=%d, b=%d)", a, b);
		}	
	}

}
