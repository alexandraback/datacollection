import java.util.*;
public class C {
	static final int P = 2, S = 1;
	static class Edge {
		int i, j, delta;
		public Edge(int i, int j, int delta) {
			this.i = i;
			this.j = j;
			this.delta = delta;
		}
	}
	static class Rat implements Comparable<Rat> {
		public static long gcd(long a, long b) {
			while (b != 0) {
				long t = a;
				a = b;
				b = t%b;
			}
			return a;
		}
		long num, den;
		public Rat(long num, long den) { // den > 0
			long g = gcd((num < 0) ? -num : num, den);
			this.num = num/g;
			this.den = den/g;
		}
		public int compareTo(Rat r) {
			if (num*r.den < den*r.num) return -1;
			if (num*r.den > den*r.num) return 1;
			return 0;
		}
		public double doubleValue() {
			return ((double)num)/den;
		}
		public String toString() {
			return ""+((double)num)/den;
		}
	}
	static class Graph {
		boolean[][] graph;
		int[] deg;
		Graph(int n) {
			graph = new boolean[n][n];
			deg = new int[n];
		}
		public void add(int i, int j) {
			graph[i][j] = true;
			graph[j][i] = true;
			deg[i]++;
			deg[j]++;
		}
		public void rem(int i, int j) {
			graph[i][j] = false;
			graph[j][i] = false;
			deg[i]--;
			deg[j]--;
		}
	}
	public static Rat ZERO = new Rat(0,1);
	public static void main(String[] args) {

		Scanner s = new Scanner(System.in);
		int T = s.nextInt();
		CASE: for (int ca = 1;ca <= T;ca++){
			int n = s.nextInt();
			int[][] car = new int[n][3];
			for (int i = 0; i < n; i++) {
				car[i][0] = s.next().equals("L") ? 0 : 1;
				car[i][1] = s.nextInt();
				car[i][2] = s.nextInt();
			}
			TreeMap<Rat, List<Edge>> changes = new TreeMap<Rat, List<Edge>>();
			Graph g = new Graph(n);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (i == j) continue;
					if (car[i][S] > car[j][S]) {
						Rat t1 = new Rat(car[j][P] - car[i][P] - 5,car[i][S] - car[j][S]);
						Rat t2 = new Rat(car[j][P] - car[i][P] + 5,car[i][S] - car[j][S]);
//	System.out.printf("From %s to %s: cars %d + %d\n",t1,t2,1+i,1+j);
						if (t2.compareTo(ZERO) < 0) {
							continue;
						} else if (t1.compareTo(ZERO) < 0) {
							g.add(i, j);
							add(changes, t2, new Edge(i,j,-1));
						} else {
							add(changes, t1, new Edge(i,j,1));
							add(changes, t2, new Edge(i,j,-1));
						}
					} else if (car[i][S] == car[j][S] && i < j) {
						if (Math.abs(car[i][P] - car[j][P]) < 5) {
							g.add(i, j);
						}
					}
				}
			}
			List<List<Integer>> toremove = new ArrayList<List<Integer>>();
			for (int i = 0; i < n; i++) toremove.add(new ArrayList<Integer>());
			for (Map.Entry<Rat, List<Edge>> kv : changes.entrySet()) {
				List<Edge> edges = kv.getValue();
				for (Edge e : edges) {
					if (e.delta == -1) {
						List<Integer> ri = toremove.get(e.i);
						List<Integer> rj = toremove.get(e.j);
						if (g.deg[e.i] - ri.size() == 1 || g.deg[e.j] - rj.size() == 1) {
							g.rem(e.i, e.j);
							// remove all the toremove edges using i or j
							ri.clear();
							rj.clear();
							
						} else {
							ri.add(e.j);
							rj.add(e.i);
						}
					} else {
						g.add(e.i, e.j);
					}
				}
//	System.out.println(kv.getKey().doubleValue());
//	print(g.graph);
				if (!isbipartite(g.graph)) {
					System.out.printf("Case #%d: %.6f\n",ca,kv.getKey().doubleValue());
					continue CASE;
				}
			}
			System.out.printf("Case #%d: Possible\n",ca);
		}
	}
	public static void print(boolean[][] graph) {
		for (int i = 0; i < graph.length; i++) {
			for (int j = i+1; j < graph.length; j++) {
				if (graph[i][j]) System.out.print(i+"~"+j+", ");
			}
		}
		System.out.println();
	}
	public static boolean isbipartite(boolean[][] graph) {
		int n = graph.length;
		boolean[] visited = new boolean[n];
		int[] color = new int[n];
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				visited[i] = true;
				if (color[i] == 0) color[i] = 1;
				if (!dfs(graph, visited, color, i)) return false;
			}
		}
		return true;
	}
	public static boolean dfs(boolean[][] graph, boolean[] visited, int[] color, int at) {
		for (int i = 0; i < graph.length; i++) {
			if (graph[at][i]) {
				if (color[at] == color[i]) return false;
				if (!visited[i]) {
					visited[i] = true;
					color[i] = color[at] == 1 ? 2 : 1;
					if (!dfs(graph, visited, color, i)) return false;
				}
			}
		}
		return true;
	}
	public static void add(TreeMap<Rat, List<Edge>> map, Rat key, Edge val) {
		List<Edge> list;
		if (!map.containsKey(key)) { list = new ArrayList<Edge>(); map.put(key, list); }
		else list = map.get(key);
		list.add(val);
	}
}
