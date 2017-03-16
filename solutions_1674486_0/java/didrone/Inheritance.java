import java.util.*;
import java.io.*;

public class Inheritance {

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	
	public static void main(String[] args) throws IOException {
		new Inheritance().run();
	}
	
	int dfs(int[] ts, int cts, int n, int[][] edges, boolean[] visited) {
		visited[n] = true;
		for (int i = 0; i < edges[n].length; i++) {
			int d = edges[n][i];
			if (!visited[d]) {
				cts = dfs(ts, cts, d, edges, visited);
			}
		}
		ts[cts] = n;
		return cts + 1;
	}
	
	int[] topsort(int[][] edges) {
		int n = edges.length;
		int[] ts = new int[n];
		int cts = 0;
		
		boolean[] visited = new boolean[n];
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				cts = dfs(ts, cts, i, edges, visited);
			}
		}
		
		return ts;
	}
	
	void run() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		
		int T = nextInt();
		for (int tt = 1; tt <= T; ++tt) {
			int n = nextInt();
			
			int[][] edges = new int[n][];
			for (int i = 0; i < n; i++) {
				int t = nextInt();
				edges[i] = new int[t];
				for (int j = 0; j < t; j++) {
					edges[i][j] = nextInt() - 1;
				}
			}
			
			int[] ts = topsort(edges);
			
			boolean diam = false;
			
			boolean[][] ih = new boolean[n][n];
			main: for (int i = 0; i < n; i++) {
				int v = ts[i];
				for (int j = 0; j < edges[v].length; j++) {
					int u = edges[v][j];
					if (ih[v][u]) {
						diam = true;
						break main;
					}
					ih[v][u] = true;
					for (int k = 0; k < n; k++) {
						if (ih[v][k] && ih[u][k]) {
							diam = true;
							break main;
						}
						ih[v][k] |= ih[u][k];
					}
				}
			}
			
			// System.err.println(Arrays.toString(ts));
			
			String ans = diam ? "Yes" : "No";
			out.printf("Case #%d: %s\n", tt, ans);
		}
		
		out.close();
	}
	
	String next() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
	
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	
}
