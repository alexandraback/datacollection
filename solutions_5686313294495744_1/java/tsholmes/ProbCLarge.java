import java.io.File;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class ProbCLarge {

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("C-large.in"));
		PrintStream out = new PrintStream(new File("C-large.out"));
		
		int T = in.nextInt();
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			int N = in.nextInt();
			HashSet<String> firsts = new HashSet<String>();
			HashSet<String> seconds = new HashSet<String>();
			HashSet<String> pairs = new HashSet<String>();
			for (int i = 0; i < N; i++) {
				String f = in.next();
				String s = in.next();
				firsts.add(f);
				seconds.add(s);
				pairs.add(f + " " + s);
			}
			String[] fs = firsts.toArray(new String[0]);
			String[] ss = seconds.toArray(new String[0]);
			int F = fs.length;
			int S = ss.length;
			boolean[][] graph = new boolean[F][S];
			for (int i = 0; i < F; i++) {
				for (int j = 0; j < S; j++) {
					if (pairs.contains(fs[i] + " " + ss[j])) {
						graph[i][j] = true;
					}
				}
			}
			int match = maxMatch(graph);
			int res = N - match;
			res -= (F - match);
			res -= (S - match);
			out.printf("Case #%d: %d%n", caseNum, res);
		}
	}
	
	private static int maxMatch(boolean[][] graph) {
		int F = graph.length;
		int S = graph[0].length;
		
		int[] match = new int[S];
		
		Arrays.fill(match, -1);
		
		for (int i = 0; i < F; i++) {
			boolean[] visited = new boolean[S];
			
			findMatch(graph, match, visited, i);
		}
		
		int count = 0;
		for (int v : match) {
			if (v != -1) count++;
		}
		
		return count;
	}
	
	private static boolean findMatch(boolean[][] graph, int[] match, boolean[] visited, int i) {
		int S = graph[0].length;
		for (int j = 0; j < S; j++) {
			if (graph[i][j] && !visited[j]) {
				visited[j] = true;
				if (match[j] == -1 || findMatch(graph, match, visited, match[j])) {
					match[j] = i;
					return true;
				}
			}
		}
		return false;
	}
}
