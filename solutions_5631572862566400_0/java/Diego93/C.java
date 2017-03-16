import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;

public class C {
	public static void main(String[] args) throws IOException {
		Scanner s = new Scanner(new File("c.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("c.out"));
		int T = s.nextInt();
		for (int i = 1; i <= T; i++) {
			out.write("Case #" + i + ": ");
			int N = s.nextInt();
			int[] neighbour = new int[N];
			iGraph g = new iGraph(N);
			for (int j = 0; j < N; j++) {
				neighbour[j] = s.nextInt() - 1;
				g.addEdge(j, neighbour[j]);
			}
			out.write(g.bff() + "\n");
		}
		out.close();
	}

	static public class iGraph {

		List<Edge>[] edges;
		List<Integer>[] graph;
		List<Integer>[] inverse;
		BiconnectedComponents bc;

		public iGraph(int size) {
			edges = new List[size];
			graph = new List[size];
			inverse = new List[size];
			for (int i = 0; i < size; i++) {
				edges[i] = new LinkedList<Edge>();
				graph[i] = new LinkedList<Integer>();
				inverse[i] = new LinkedList<Integer>();

			}
			bc = new BiconnectedComponents();
		}

		static int res = 0;

		public int bff() {
			boolean[] used = new boolean[graph.length];
			res = 0;
			for (int i = 0; i < graph.length; i++) {
				used[i] = true;
				dfs(used, i, i, i, 1);
				used[i] = false;
			}
			return res;
		}

		private void dfs(boolean[] used, int u, int prev, int first, int cant) {
			for (int v : graph[u]) {
				if (!used[v]) {
					used[v] = true;
					dfs(used, v, u, first, cant + 1);
					used[v] = false;
				} else {
					if (v == prev) {
						inversedfs(used, u, cant);
					} else if (v == first) {
						res = Math.max(res, cant);
					}
				}
			}
		}

		private void inversedfs(boolean[] used, int u, int cant) {
			for (int v : inverse[u]) {
				if (!used[v]) {
					used[v]=true;
					inversedfs(used, v, cant+1);
					used[v]=false;
				}
			}
			res = Math.max(res, cant);
		}

		public List<List<Integer>> components() {
			List<List<Integer>> list = new LinkedList<List<Integer>>();
			boolean[] used = new boolean[graph.length];
			for (int i = 0; i < graph.length; i++) {
				if (!used[i]) {
					List<Integer> auxList = new LinkedList<Integer>();
					dfs(graph, auxList, used, i);
					list.add(auxList);
				}
			}
			return list;
		}

		private void dfs(List<Integer>[] graph, List<Integer> res,
				boolean[] used, int u) {
			used[u] = true;
			for (int v : graph[u]) {
				if (!used[v])
					dfs(graph, used, res, v);
			}
			res.add(u);
		}

		public void addEdge(int v, int w) {
			graph[v].add(w);
			inverse[w].add(v);
		}

		public void addEfficientEdge(int v, int w, long weight) {
			edges[v].add(new Edge(w, weight));
		}

		public void addEdge(int v, int w, long weight) {
			graph[v].add(w);
			edges[v].add(new Edge(w, weight));
		}

		public void addUndirectedEdge(int v, int w) {
			addEdge(v, w);
			addEdge(w, v);
		}

		public void addUndirectedEdge(int v, int w, long weight) {
			addEdge(v, w, weight);
			addEdge(w, v, weight);
		}

		public void addEfficientUndirectedEdge(int v, int w, long weight) {
			addEfficientEdge(v, w, weight);
			addEfficientEdge(w, v, weight);
		}

		public static iGraph readUndirectedGraph(Scanner s) {
			int N = s.nextInt();
			int M = s.nextInt();
			iGraph g = new iGraph(N);
			for (int i = 0; i < M; i++) {
				int v = s.nextInt() - 1;
				int w = s.nextInt() - 1;
				g.addUndirectedEdge(v, w);
			}
			return g;
		}

		public static iGraph readUndirectedGraphWithWeight(Scanner s) {
			int N = s.nextInt();
			int M = s.nextInt();
			iGraph g = new iGraph(N);
			for (int i = 0; i < M; i++) {
				int v = s.nextInt() - 1;
				int w = s.nextInt() - 1;
				long weight = s.nextLong();
				g.addUndirectedEdge(v, w, weight);
			}
			return g;
		}

		public static iGraph readDirectedGraph(Scanner s) {
			int N = s.nextInt();
			int M = s.nextInt();
			iGraph g = new iGraph(N);
			for (int i = 0; i < M; i++) {
				int v = s.nextInt() - 1;
				int w = s.nextInt() - 1;
				g.addEdge(v, w);
			}
			return g;
		}

		public static iGraph readDirectedGraphWithWeight(Scanner s) {
			int N = s.nextInt();
			int M = s.nextInt();
			iGraph g = new iGraph(N);
			for (int i = 0; i < M; i++) {
				int v = s.nextInt() - 1;
				int w = s.nextInt() - 1;
				long weight = s.nextLong();
				g.addEdge(v, w, weight);
			}
			return g;
		}

		public List<List<Integer>> biconnectedComponents() {
			if (bc.components == null)
				bc.biconnectedComponents(graph);
			return bc.components;
		}

		public List<Integer> cutPoints() {
			if (bc.cutPoints == null)
				bc.biconnectedComponents(graph);
			return bc.cutPoints;
		}

		public List<Pair> bridges() {
			if (bc.bridges == null)
				bc.biconnectedComponents(graph);
			return bc.bridges;
		}

		private static class Edge {
			int v;
			long cost;

			public Edge(int node, long weight) {
				this.v = node;
				this.cost = weight;
			}
		}

		public static class Pair {
			int v, w;

			public Pair(int v, int w) {
				this.v = v;
				this.w = w;
			}
		}

		private void dfs(List<Integer>[] graph, boolean[] used,
				List<Integer> res, int u) {
			used[u] = true;
			for (int v : graph[u])
				if (!used[v])
					dfs(graph, used, res, v);
			res.add(u);
		}

		/*
		 * static int res=0;
		 * 
		 * public int bff(){ int[] ans = new int[graph.length]; boolean[] used =
		 * new boolean[graph.length]; for(int i=0; i<graph.length; i++){
		 * if(used[i] && graph[i].size()==1) res=Math.max(res, dfs(graph, used,
		 * i)); } return res; }
		 * 
		 * private int dfs(List<Integer>[] graph, boolean[] used, int u){
		 * used[u] = true; int val=0; for(int v: graph[u]){ if(!used[v]){ int
		 * aux=dfs(graph, used, v); if(aux>val){ res=Math.max(aux+val+1,res);
		 * val=aux; }
		 * 
		 * } } return val+1; }
		 */

		/* ---------------------------------------------- */

		public List<List<Integer>> stronglyConnectedComponents() {
			int n = graph.length;
			boolean[] used = new boolean[n];
			List<Integer> order = new ArrayList<>();
			for (int i = 0; i < n; i++)
				if (!used[i])
					dfs(graph, used, order, i);

			List<Integer>[] reverseGraph = new List[n];
			for (int i = 0; i < n; i++)
				reverseGraph[i] = new ArrayList<>();
			for (int i = 0; i < n; i++)
				for (int j : graph[i])
					reverseGraph[j].add(i);

			List<List<Integer>> components = new ArrayList<>();
			Arrays.fill(used, false);
			Collections.reverse(order);

			for (int u : order)
				if (!used[u]) {
					List<Integer> component = new ArrayList<>();
					dfs(reverseGraph, used, component, u);
					components.add(component);
				}

			return components;
		}

		/* ---------------------------------------------- */

		/* No checkea que sea valido */
		public List<Integer> eulerCycleUndirected(int u) {
			Set<Long> usedEdges = new HashSet<>();
			int n = graph.length;
			int[] curEdge = new int[n];
			List<Integer> res = new ArrayList<>();
			dfs(graph, curEdge, usedEdges, res, u);
			Collections.reverse(res);
			return res;
		}

		private void dfs(List<Integer>[] graph, int[] curEdge,
				Set<Long> usedEdges, List<Integer> res, int u) {
			while (curEdge[u] < graph[u].size()) {
				int v = graph[u].get(curEdge[u]++);
				if (usedEdges.add(((long) Math.min(u, v) << 32)
						+ Math.max(u, v)))
					dfs(graph, curEdge, usedEdges, res, v);
			}
			res.add(u);
		}

		public List<Integer> eulerCycleDirected(int u) {
			int n = graph.length;
			int[] curEdge = new int[n];
			List<Integer> res = new ArrayList<>();
			dfs(graph, curEdge, res, u);
			Collections.reverse(res);
			return res;
		}

		private void dfs(List<Integer>[] graph, int[] curEdge,
				List<Integer> res, int u) {
			while (curEdge[u] < graph[u].size()) {
				dfs(graph, curEdge, res, graph[u].get(curEdge[u]++));
			}
			res.add(u);
		}

		/* ---------------------------------------------- */

		private static class BiconnectedComponents {

			List<Integer>[] graph;
			boolean[] visited;
			Stack<Integer> stack;
			int time;
			int[] tin;
			int[] lowlink;
			List<List<Integer>> components;
			List<Integer> cutPoints;
			List<Pair> bridges;

			public List<List<Integer>> biconnectedComponents(
					List<Integer>[] graph) {
				int n = graph.length;
				this.graph = graph;
				visited = new boolean[n];
				stack = new Stack<>();
				time = 0;
				tin = new int[n];
				lowlink = new int[n];
				components = new ArrayList<>();
				cutPoints = new ArrayList<>();
				bridges = new ArrayList<>();

				for (int u = 0; u < n; u++)
					if (!visited[u])
						dfs(u, -1);

				return components;
			}

			void dfs(int u, int p) {
				visited[u] = true;
				lowlink[u] = tin[u] = time++;
				stack.add(u);
				int children = 0;
				boolean cutPoint = false;
				for (int v : graph[u]) {
					if (v == p)
						continue;
					if (visited[v]) {
						// lowlink[u] = Math.min(lowlink[u], lowlink[v]);
						lowlink[u] = Math.min(lowlink[u], tin[v]);
					} else {
						dfs(v, u);
						lowlink[u] = Math.min(lowlink[u], lowlink[v]);
						cutPoint |= lowlink[v] >= tin[u];
						// if (lowlink[v] == tin[v])
						if (lowlink[v] > tin[u])
							bridges.add(new Pair(u, v));
						++children;
					}
				}
				if (p == -1)
					cutPoint = children >= 2;
				if (cutPoint)
					cutPoints.add(u);
				if (lowlink[u] == tin[u]) {
					List<Integer> component = new ArrayList<>();
					while (true) {
						int x = stack.pop();
						component.add(x);
						if (x == u)
							break;
					}
					components.add(component);
				}
			}
		}

		/* ---------------------------------------------- */

		public Long[][] floyd() {
			int size = edges.length;
			Long[][] ans = new Long[size][size];
			for (int i = 0; i < size; i++) {
				for (Edge e : edges[i]) {
					ans[i][e.v] = (ans[i][e.v] == null ? e.cost : Math.min(
							ans[i][e.v], e.cost));
				}
			}
			for (int k = 0; k < size; k++) {
				for (int i = 0; i < size; i++) {
					for (int j = 0; j < size; j++) {
						if (ans[i][k] != null && ans[k][j] != null) {
							if (ans[i][j] == null
									|| ans[i][j] > ans[i][k] + ans[k][j]) {
								ans[i][j] = ans[i][k] + ans[k][j];
							}
						}
					}
				}
			}
			return ans;
		}

		/* ---------------------------------------------- */

		public List<Integer> topologicalSort() {
			int n = graph.length;
			boolean[] used = new boolean[n];
			List<Integer> res = new ArrayList<>();
			for (int i = 0; i < n; i++)
				if (!used[i])
					dfs(graph, used, res, i);
			Collections.reverse(res);
			return res;
		}

		/* ---------------------------------------------- */

		public long MinimumSpanningTreeValueElogV() {
			return mst(edges, new long[edges.length]);
		}

		private long mst(List<Edge>[] edges, long[] pred) {
			int n = edges.length;
			Arrays.fill(pred, -1);
			boolean[] used = new boolean[n];
			long[] prio = new long[n];
			Arrays.fill(prio, Integer.MAX_VALUE);
			prio[0] = 0;
			PriorityQueue<Long> q = new PriorityQueue<>();
			q.add(0L);
			long res = 0;

			while (!q.isEmpty()) {
				long cur = q.poll();
				int u = (int) cur;
				if (used[u])
					continue;
				used[u] = true;
				res += cur >>> 32;
				for (Edge e : edges[u]) {
					int v = e.v;
					if (!used[v] && prio[v] > e.cost) {
						prio[v] = e.cost;
						pred[v] = u;
						q.add(((long) prio[v] << 32) + v);
					}
				}
			}
			return res;
		}

		/* ---------------------------------------------- */

		public long MinimumSpanningTreeValueV2() {
			long[][] dist = new long[edges.length][edges.length];

			for (int i = 0; i < edges.length; i++) {
				Arrays.fill(dist[i], Integer.MAX_VALUE);
				for (Edge e : edges[i]) {
					dist[i][e.v] = e.cost;
				}
			}
			return mstPrim(dist);
		}

		private long mstPrim(long[][] d) {
			int n = d.length;
			int[] prev = new int[n];
			long[] dist = new long[n];
			Arrays.fill(dist, Integer.MAX_VALUE);
			dist[0] = 0;
			boolean[] visited = new boolean[n];
			long res = 0;
			for (int i = 0; i < n; i++) {
				int u = -1;
				for (int j = 0; j < n; j++) {
					if (!visited[j] && (u == -1 || dist[u] > dist[j]))
						u = j;
				}
				res += dist[u];
				visited[u] = true;
				for (int j = 0; j < n; j++) {
					if (!visited[j] && dist[j] > d[u][j]) {
						dist[j] = d[u][j];
						prev[j] = u;
					}
				}
			}
			return res;
		}

		/* ---------------------------------------------- */

		static final long INF = Long.MAX_VALUE / 2;

		public long[] bellmanFord(int s) {
			long[] ans = new long[edges.length];
			int[] pred = new int[edges.length];
			if (bellmanFord(s, ans, pred)) {
				return ans;
			}
			return null;
		}

		private boolean bellmanFord(int s, long[] dist, int[] pred) {
			Arrays.fill(pred, -1);
			Arrays.fill(dist, INF);
			System.out.println("diegui puti, vas a perder");
			dist[s] = 0;
			int n = edges.length;
			boolean updated = false;
			for (int step = 0; step < n; step++) {
				updated = false;
				for (int u = 0; u < n; u++) {
					if (dist[u] == INF)
						continue;
					for (Edge e : edges[u]) {
						if (dist[e.v] > dist[u] + e.cost) {
							dist[e.v] = dist[u] + e.cost;
							dist[e.v] = Math.max(dist[e.v], -INF);
							pred[e.v] = u;
							updated = true;
						}
					}
				}
				if (!updated)
					break;
			}
			// if updated is true then a negative cycle exists
			return updated == false;
		}

		public int[] findNegativeCycle() {
			int n = edges.length;
			int[] pred = new int[n];
			Arrays.fill(pred, -1);
			long[] dist = new long[n];
			int last = -1;
			for (int step = 0; step < n; step++) {
				last = -1;
				for (int u = 0; u < n; u++) {
					if (dist[u] == INF)
						continue;
					for (Edge e : edges[u]) {
						if (dist[e.v] > dist[u] + e.cost) {
							dist[e.v] = Math.max(dist[u] + e.cost, -INF);
							dist[e.v] = Math.max(dist[e.v], -INF);
							pred[e.v] = u;
							last = e.v;
						}
					}
				}
				if (last == -1)
					return null;
			}
			for (int i = 0; i < n; i++) {
				last = pred[last];
			}
			int[] p = new int[n];
			int cnt = 0;
			for (int u = last; u != last || cnt == 0; u = pred[u]) {
				p[cnt++] = u;
			}
			int[] cycle = new int[cnt];
			for (int i = 0; i < cycle.length; i++) {
				cycle[i] = p[--cnt];
			}
			return cycle;
		}

		/* ---------------------------------------------- */

		/*
		 * row 0 - return values of distance row 1 - return previous node
		 */

		public long[][] dijkstra(int start) {
			long[][] ans = new long[2][edges.length];
			shortestPaths(start, ans[0], ans[1]);
			// shortestPaths2(start, ans[0], ans[1]); for long values in cost;
			return ans;
		}

		private void shortestPaths(int s, long[] prio, long[] pred) {
			Arrays.fill(pred, -1);
			Arrays.fill(prio, Integer.MAX_VALUE);
			prio[s] = 0;
			PriorityQueue<Long> q = new PriorityQueue<>();
			q.add((long) s);
			while (!q.isEmpty()) {
				long cur = q.remove();
				int curu = (int) cur;
				if (cur >>> 32 != prio[curu])
					continue;
				for (Edge e : edges[curu]) {
					int v = e.v;
					long nprio = prio[curu] + e.cost;
					if (prio[v] > nprio) {
						prio[v] = nprio;
						pred[v] = curu;
						q.add(((long) nprio << 32) + v);
					}
				}
			}
		}

		private void shortestPaths2(int s, long[] prio, long[] pred) {
			Arrays.fill(pred, -1);
			Arrays.fill(prio, Integer.MAX_VALUE);
			prio[s] = 0;
			PriorityQueue<Edge> q = new PriorityQueue<>(new Comparator<Edge>() {
				public int compare(Edge o1, Edge o2) {
					return Long.compare(o1.cost, o2.cost);
				}
			});
			q.add(new Edge(s, 0));
			while (!q.isEmpty()) {
				Edge ed = q.remove();
				long cur = ed.cost;
				int curu = ed.v;
				if (cur != prio[curu])
					continue;
				for (Edge e : edges[curu]) {
					int v = e.v;
					long nprio = prio[curu] + e.cost;
					if (prio[v] > nprio) {
						prio[v] = nprio;
						pred[v] = curu;
						q.add(new Edge(v, nprio));
					}
				}
			}
		}

		/* ---------------------------------------------- */

		public List<Integer> findCenters() {
			int n = graph.length;
			List<Integer> leaves = new ArrayList<>();
			int[] degree = new int[n];
			for (int i = 0; i < n; i++) {
				degree[i] = graph[i].size();
				if (degree[i] <= 1) {
					leaves.add(i);
				}
			}
			int removedLeaves = leaves.size();
			while (removedLeaves < n) {
				List<Integer> nleaves = new ArrayList<>();
				for (int u : leaves) {
					for (int v : graph[u]) {
						if (--degree[v] == 1) {
							nleaves.add(v);
						}
					}
				}
				leaves = nleaves;
				removedLeaves += leaves.size();
			}
			return leaves;
		}

		public int findCentroid() {
			return findCentroid(0, -1);
		}

		// returns vertex that has all its subtrees sizes <= n/2
		private int findCentroid(int u, int p) {
			int n = graph.length;
			int cnt = 1;
			boolean goodCenter = true;
			for (int v : graph[u]) {
				if (v == p)
					continue;
				int res = findCentroid(v, u);
				if (res >= 0)
					return res;
				int size = -res;
				goodCenter &= size <= n / 2;
				cnt += size;
			}
			goodCenter &= n - cnt <= n / 2;
			return goodCenter ? u : -cnt;
		}

		public int diameter() {
			int furthestVertex = (int) dfs(graph, 0, -1, 0);
			return (int) (dfs(graph, furthestVertex, -1, 0) >>> 32);
		}

		private long dfs(List<Integer>[] tree, int u, int p, int depth) {
			long res = ((long) depth << 32) + u;
			for (int v : tree[u])
				if (v != p)
					res = Math.max(res, dfs(tree, v, u, depth + 1));
			return res;
		}

		/* -------------------------------- */

		public int maxMatchingEV(int n1, int n2) {
			int[] matching = new int[n2];
			Arrays.fill(matching, -1);
			int matches = 0;
			for (int u = 0; u < n1; u++) {
				if (findPath(graph, u, matching, new boolean[n1]))
					++matches;
			}
			return matches;
		}

		private boolean findPath(List<Integer>[] graph, int u1, int[] matching,
				boolean[] vis) {
			vis[u1] = true;
			for (int v : graph[u1]) {
				int u2 = matching[v];
				if (u2 == -1 || !vis[u2] && findPath(graph, u2, matching, vis)) {
					matching[v] = u1;
					return true;
				}
			}
			return false;
		}
	}

}