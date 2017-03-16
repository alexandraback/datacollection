import java.io.File;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class ProblemC {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("C-large.in"));
		PrintStream out = new PrintStream("C-large.out");
		
		int T = in.nextInt();
		
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			int N = in.nextInt();
			int[] forward = new int[N];
			for (int i = 0; i < N; i++) {
				forward[i] = in.nextInt() - 1;
			}
			
			HashSet<Integer> roots = new HashSet<Integer>();
			for (int i = 0; i < N; i++) {
				roots.add(i);
			}
			for (int f : forward) {
				roots.remove(f);
			}
			
			int longest = 0;
			for (int i = 0; i < N; i++) {
				longest = Math.max(longest, longestFull(forward, i, 1, new int[N]));
			}
			
			HashSet<Integer> pairs = new HashSet<Integer>();
			HashMap<Integer, Integer> longestRoot = new HashMap<Integer, Integer>();
			for (int i = 0; i < N; i++) {
				int j = forward[i];
				if (forward[j] != i) continue;
				pairs.add(i);
				longestRoot.put(i, 1);
			}
			
			for (int r : roots) {
				int cur = r;
				boolean[] seen = new boolean[N];
				int len = 1;
				while (true) {
					if (seen[cur]) {
						break;
					}
					seen[cur] = true;
					if (pairs.contains(cur)) {
						longestRoot.put(cur, Math.max(longestRoot.get(cur), len));
						break;
					}
					cur = forward[cur];
					len++;
				}
			}
			
			int pairSum = 0;
			for (int p : longestRoot.values()) {
				pairSum += p;
			}
			longest = Math.max(longest, pairSum);
			
			out.printf("Case #%d: %d%n", caseNum, longest);
		}
	}
	
	private static int longestFull(int[] forward, int cur, int depth, int[] depths) {
		depths[cur] = depth;
		int n = forward[cur];
		if (depths[n] != 0) {
			return depth - depths[n] + 1;
		}
		return longestFull(forward, n, depth + 1, depths);
	}
}
