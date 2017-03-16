package codejam;

import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.ArrayList;

public class _1C_A {
	public static void main(String[] args) throws Exception {
		String input_file = "A-small-attempt2.in";
		String output_file = "A-small-attempt2_out.txt";
		
		BufferedReader in = new BufferedReader(new FileReader(input_file));
		PrintStream out = new PrintStream(new FileOutputStream(output_file));
		
		int case_num = 1;
		in.readLine();
		String line;
		while ((line=in.readLine()) != null) {
			System.out.println("\nTry: " + case_num);
			
			int n = Integer.parseInt(line);
			System.out.println(n + " vertices");
			boolean[][] graph = new boolean[n+1][n+1];
			for (int i = 1; i <= n; ++i) {
				String[] next = in.readLine().split(" ");
				System.out.print("[" + i +"] " );
				for (int j = 1; j < next.length; ++j) {
					graph[i][Integer.parseInt(next[j])] = true;
					System.out.print(next[j] + " ");
				}
				System.out.println();
			}
			
			int[] to_here = new int[n+1];
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) {
					if (graph[i][j])
						++to_here[j];
				}
			}
			int[] from_here = new int[n+1];
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) {
					if (graph[i][j])
						++from_here[i];
				}
			}
			
			boolean diamond = false;
			for (int i = 1; i <= n; ++i) {
				if (diamond(graph, to_here, from_here, i)) {
					diamond = true;
					break;
				}
			}
			out.print("Case #" + case_num + ": ");
			if (diamond)
				out.println("Yes");
			else
				out.println("No");
			++case_num;
		}
	}

	private static boolean diamond(boolean[][] graph, int[] to_here, int[] from_here, int start) {
		for (int end = 1; end < to_here.length; ++end) {
			if (to_here[end] >= 2 && from_here[start] >= 2 && start != end) {
				System.out.println("check: from " + start + " to " + end);
				if (existOneMorePath(graph, start, end))
					return true;
			}
		}
		
		return false;		
	}

	private static boolean existOneMorePath(boolean[][] graph, int start, int end) {
		boolean[] visited = new boolean[graph.length];
		int[] end_hit = new int[1];
		end_hit[0] = 0;
		dfs(graph, visited, start, end, end_hit);
		if (end_hit[0] == 2)
			return true;
		return false;
	}

	private static void dfs(boolean[][] graph, boolean[] visited, int v, int end, int[] end_hit) {
		if (end_hit[0] == 2)
			return;
		
		visited[v] = true;
		for (int i = 1; i < graph.length; ++i) {
			if (graph[v][i]) {
				if (i == end) {
					++end_hit[0];
					System.out.println("END HIT! v=" + v);
					continue;
				}
				if (!visited[i])				
					dfs(graph, visited, i, end, end_hit);
				}
		}
	}
}
