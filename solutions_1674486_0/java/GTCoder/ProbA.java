import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.*;

public class ProbA {
	
	public static String solve(int[][] graph, int N) {
		
		for(int i=1; i<=N; i++) {
			if(bfs(graph, N, i)) {
				//System.out.println(i);
				return "Yes";
			}
		}
		return "No";
		
	}
	
	public static boolean bfs(int[][] graph, int N, int from) {
		 int[] visited = new int[N+1];
		 int[] len = new int[N+1];
	     Queue<Integer> queue = new LinkedList<Integer>();
	     queue.offer(from);
	     visited[from] = 1;
	     len[from] = 0;
		 while(!queue.isEmpty()) {
			int current = queue.poll();
			if(graph[current] != null) {
				for(int i=0; i< graph[current].length; i++) {
					if(visited[graph[current][i]] == 0) {
						queue.offer(graph[current][i]);
						visited[graph[current][i]] = 1;
						len[graph[current][i]] = len[current] + 1;
					} else {
						//if(len[current] >=1 && len[graph[current][i]] > 1)
						return true;
					}
				}
			}
		}
		return false;
	}
	public static boolean dfs(int[][] graph, int N, int from) {
		 int[] visited = new int[N+1];
	     Stack<Integer> stacks = new Stack<Integer>();
	     stacks.push(from);
	   //  visited[from] = 1;
		 while(!stacks.isEmpty()) {
			int current = stacks.peek();
			if(graph[current] != null) {
				if(visited[current] == 0) { visited[current] = 1;
				for(int i=0; i< graph[current].length; i++) {
					if(visited[graph[current][i]] == 0) {
						stacks.push(graph[current][i]);
						//visited[graph[current][i]] = 1;
					} 
					else if(visited[graph[current][i]] == 2) {
						return true;
					}
				}
				}
			}
			if(stacks.peek() == current) {
				visited[current] = 2;
				stacks.pop();
			}
		}
		return false;
	
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("A-small-attempt3.in"));
		PrintWriter out = new PrintWriter(new FileWriter("A-small-attempt3.out"));
		String line = in.readLine();
		int T = Integer.parseInt(line);
		for (int i = 1; i <= T; i++) {
			line = in.readLine();
			int N = Integer.parseInt(line);
			int[][] graph = new int[N+1][];
			for(int j = 1; j<=N; j++) {
				line = in.readLine();
				String[] comps = line.split("\\s+");
				int M = Integer.parseInt(comps[0]);
				if(M != 0) {
					graph[j] = new int[M];
					for(int k=0; k<M; k++) {
						graph[j][k] = Integer.parseInt(comps[k+1]);
					}
				}
			}
			
			
			out.print("Case #" + i + ": ");
	
			out.println(solve(graph, N));
	

		}

		out.flush();
		in.close();
		out.close();
	}
}
