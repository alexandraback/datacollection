import java.io.*;
import java.util.*;

public class C {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();;
		for (int casenum = 1; casenum <= T; casenum++) {
			int N = in.nextInt();
			int[] adj = new int[N+1];
			List<Integer>[] reverseAdj = new List[N+1];
			for (int i = 1; i <= N; i++) {
				int j = in.nextInt();
				adj[i] = j;
				if (reverseAdj[j] == null) {
					reverseAdj[j] = new ArrayList<Integer>();
				}
				reverseAdj[j].add(i);
			}
			int[] height = new int[N+1];
			int best = 0;
			for (int i = 1; i <= N; i++) {
				best = Math.max(best, cycleLength(i, adj, N));
			}
			int noncirclesize = 0;
			for (int i = 1; i <= N; i++) {
				for (int j = i + 1; j <= N; j++) {
					if (adj[i] == j && adj[j] == i) {
						// add to non-circle size
						int bestFromi = 0;
						if (reverseAdj[i] != null) {
							for (int n : reverseAdj[i]) {
								if (n == j) continue;
								bestFromi = Math.max(bestFromi, computeHeight(n, height, reverseAdj));
							}
						}
						int bestFromj = 0;
						if (reverseAdj[j] != null) {
							for (int n : reverseAdj[j]) {
								if (n == i) continue;
								bestFromj = Math.max(bestFromj, computeHeight(n, height, reverseAdj));
							}
						}
						noncirclesize += 2 + bestFromi + bestFromj;
					}
				}
			}
			best = Math.max(best, noncirclesize);
			System.out.println("Case #" + casenum + ": " + best);
		}
	}
	public static int cycleLength(int start, int[] adj, int N) {
		boolean[] visited = new boolean[N+1];
		int[] lengthAt = new int[N+1];
		int cur = start;
		int len = 0;
		while (!visited[cur]) {
			visited[cur] = true;
			lengthAt[cur] = len++;
			cur = adj[cur];
		}
		return len - lengthAt[cur];
	}

	public static int computeHeight(int i, int[] height, List<Integer>[] reverseAdj) {
		if (height[i] != 0) {
			return height[i];
		}
		int curHeight = 0;
		if (reverseAdj[i] != null) {
			for (int n : reverseAdj[i]) {
				curHeight = Math.max(curHeight, computeHeight(n, height, reverseAdj));
			}
		}
		curHeight++;
		height[i] = curHeight;
		return curHeight;
	}
}
