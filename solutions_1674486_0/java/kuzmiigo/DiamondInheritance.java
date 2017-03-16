package gcj2012.r1c;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;

class Graph {
	private final int V;
	private int E;
	private Set<Integer>[] adj;
	private boolean[] marked;
	private int count;
	
	public Graph(int V) {
		this.V = V;
		this.E = 0;
		adj = (HashSet<Integer>[]) new HashSet[V];
		for (int v = 0; v < V; v++) {
			adj[v] = new HashSet<Integer>();
		}
	}
	
	public int V() { return V; }
	public int E() { return E; }
	
	public void addEdge(int v, int w) {
		adj[v].add(w);
		E++;
	}
	
	public Iterable<Integer> adj(int v) {
		return adj[v];
	}
	
	public boolean check() {
		for (int v = 0; v < V; v++) {
			marked = new boolean[V];
			if (dfs(v)) return true;
		}
		return false;
	}
	
	private boolean dfs(int v) {
		marked[v] = true;
		for (int w: adj(v)) {
			if (marked[w]) return true;
			if (dfs(w)) return true;
		}
		return false;
	}
}

public class DiamondInheritance {

	public static void main(String[] args) throws NumberFormatException, IOException {
		DiamondInheritance sit = new DiamondInheritance();
		if (args.length < 1 ) {
			System.out.println("File name not given");
			System.exit(1);
		}
		BufferedReader br = new BufferedReader(new FileReader(args[0]));
		int t = Integer.parseInt(br.readLine());
		for (int i = 1; i <= t; i++) {
			int n = Integer.parseInt(br.readLine());
			Graph g = new Graph(n);
			for (int j = 1; j <= n; j++) {
				String[] parents = br.readLine().split(" ");
				int m = Integer.parseInt(parents[0]);
				for (int k = 1; k <= m; k++) {
					int p = Integer.parseInt(parents[k]);
					g.addEdge(j - 1, p - 1);
				}
			}
			boolean res = g.check();
			System.out.printf("Case #%d: %s\n", i, res ? "Yes" : "No");
		}
		br.close();
	}

}
