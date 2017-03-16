import java.io.File;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class BFFs {
	public static void main(String[] args) throws Exception {
		 Scanner input = new Scanner(new File("input/c_small.in"));
		 PrintWriter output = new PrintWriter(new File("output/c_small.out"));
//		Scanner input = new Scanner(System.in);
//		PrintWriter output = new PrintWriter(System.out);

		int testCases = input.nextInt();
		input.nextLine();
		primary: for (int casen = 1; casen <= testCases; casen++) {
			output.printf("Case #%d: ", casen);
			
			int n = input.nextInt();
			int[] to = new int[n];
			Set<Integer>[] from = new HashSet[n];
			int[] best = new int[n];
			for (int i = 0; i < n; i++) {
				from[i] = new HashSet<>();
			}
			for (int i = 0; i < n; i++) {
				to[i] = input.nextInt() - 1;
				from[to[i]].add(i);
			}
			
			int open = 0;
			for (int i = 0; i < n; i++) {
				if (best[i] != 0) continue;
				open += findCycle(to, from, best, new HashSet<>(), i);
			}
			
			int max = open;
			for (int cur : best) {
				max = Math.max(cur, max);
			}
			
			output.println(max);
			
			output.flush();
		}
		output.close();
	}
	
	public static int findCycle(int[] to, Set<Integer>[] from, int[] best, Set<Integer> visited, int i) {
		if (!visited.add(i)) {
			if (i == to[to[i]]) { // Reciprocation
				best[i] = 1;
				for (int prev : from[i]) {
					if (prev == to[i]) continue;
					best[i] = Math.max(backwards(from, best, prev, 2), best[i]);
				}
				best[to[i]] = best[i] + 1;
				for (int prev : from[to[i]]) {
					if (prev == i) continue;
					best[to[i]] = Math.max(backwards(from, best, prev, best[i] + 2), best[to[i]]);
				}
				return best[to[i]];
			} else { // No reciprocation
				forwards(to, best, i, 1);
				return 0;
			}
		} else {
			return findCycle(to, from, best, visited, to[i]);
		}
	}
	
	public static void forwards(int[] to, int[] best, int i, int n) {
		if (best[i] != 0) return;
		best[i] = n;
		forwards(to, best, to[i], n+1);
	}
	
	public static int backwards(Set<Integer>[] from, int[] best, int i, int n) {
		if (best[i] != 0) return 0;
		best[i] = n;
		int max = n;
		for (int x : from[i]) {
			max = Math.max(backwards(from, best, x, n + 1), max);
		}
		return max;
	}
	
}