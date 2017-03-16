import java.util.ArrayList;
import java.util.Scanner;


public class Diamond {
	private static class Graph {
		private ArrayList<Integer>[] adj;
		int counter;
		boolean[] marked;
		int V;
		public Graph(int V) {
			this.V = V;
			adj = (ArrayList<Integer>[]) new ArrayList[V];
			for (int v=0; v < V; v++) {
				adj[v] = new ArrayList<Integer>();
			}
		}
		public void addEdge(int v, int w) {
			adj[v].add(w);
		}
		public boolean isThereTwo(int from, int to) {
			marked = new boolean[V];
			counter = 0;
			dfs(from, to);
			if (counter >= 2) return true;
			return false;
		}
		private void dfs(int from, int to) {
			if (from==to) {
				counter++;
				return;
			}
			else marked[from] = true;
			if (counter==2) return;
			for (int dest : adj[from]) {
				if (!marked[dest]) dfs(dest, to);
			}
		}
		public int V() {
			return V;
		}
	}
	private static String process(Graph g) {
		for (int v1=0; v1 < g.V(); v1++) {
			for (int v2=v1+1; v2 < g.V(); v2++) {
				if (g.isThereTwo(v1, v2)) return "Yes";
				if (g.isThereTwo(v2, v1)) return "Yes";
			}
		}
		return "No";
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int i=0; i < T; i++) {
			int N = in.nextInt();
			Graph G = new Graph(N);
			for (int j=0; j < N; j++) {
				int Mi = in.nextInt();
				for (int k=0; k < Mi; k++) {
					int w = in.nextInt();
					G.addEdge(j, w-1);
				}
			}
			System.out.println("Case #"+(i+1)+": "+process(G));
		}
	}
}
