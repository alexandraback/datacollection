package round1a;


import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

public class ProblemC {
	
	// Workaround for not being able to pipe a file to stdin in Eclipse.
	private static final String IN_FILE = "text/" + "C-small-attempt1.in";
	
	public static void main(String[] args) throws Exception {
		try (Scanner in = new Scanner(new BufferedReader(new FileReader(IN_FILE)))) {
			int numCases = in.nextInt();
			for (int i = 0; i < numCases; i++) {
				int numNodes = in.nextInt();
				Graph g = new Graph(numNodes);
				for (int j = 0; j < numNodes; j++) {
					int bff = in.nextInt() - 1;
//					g.adjMat[j][bff] = true;
					g.bffs[j] = bff;
				}
				
				long result = solve(g);
				String resultStr = "" + result;
				
				System.out.println(String.format("Case #%s: %s", i+1, resultStr));
			}
		}
	}

	private static long solve(Graph g) {
		long best = 1;
		
		for (int start = 0; start < g.numNodes; start++) {
			Stack<SearchNode> trace = new Stack<>();
			boolean[] initVisited = new boolean[g.numNodes];
			trace.push(new SearchNode(start, start, 0, initVisited));
			while (!trace.isEmpty()) {
				SearchNode next = trace.pop();
				if (g.bffs[next.position] == start || g.bffs[next.position] == next.prev) {
					best = Math.max(best, next.depth + 1);
				}
				for (SearchNode neighbor : next.neighbors(g)) {
					trace.push(neighbor);
				}
			}
		}
		
		return best;
	}
	
	private static class SearchNode {
		int position;
		int prev;
		int depth;
		boolean[] visited;
		
		public SearchNode(int position, int prev, int depth, boolean[] prevVisited) {
			this.position = position;
			this.prev = prev;
			this.depth = depth;
			assert (!prevVisited[position]);
			this.visited = new boolean[prevVisited.length];
			System.arraycopy(prevVisited, 0, this.visited, 0, prevVisited.length);
			this.visited[position] = true;
		}
		
		public List<SearchNode> neighbors(Graph g) {
			List<SearchNode> result = new ArrayList<>();
			if (g.bffs[position] == prev) {
				for (int i = 0; i < g.numNodes; i++) {
					if (!visited[i]) {
					  result.add(new SearchNode(i, position, depth+1, visited));
					}
				}
			}
			else {
				if (!visited[g.bffs[position]]) {
					result.add(new SearchNode(g.bffs[position], position, depth+1, visited));
				}
			}
			
			return result;
		}
	}
	
	private static class Graph {
		int numNodes;
//		boolean[][] adjMat;
		int[] bffs;
		
		public Graph(int numNodes) {
			this.numNodes = numNodes;
//			this.adjMat = new boolean[numNodes][numNodes];
			this.bffs = new int[numNodes];
		}
	}
}
