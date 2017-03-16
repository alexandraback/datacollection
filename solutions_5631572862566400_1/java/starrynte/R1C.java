import java.io.*;
import java.util.*;

public class R1C {
	public static void main(String[] args) throws Exception {
		Scanner scan = new Scanner(System.in);
		int nCases = scan.nextInt();
		for (int z = 0; z < nCases; z++) {
			int nKids = scan.nextInt();
			HashSet[] children = new HashSet[nKids];
			for (int i = 0; i < nKids; i++) {
				children[i] = new HashSet<Integer>();
			}
			int[] bffs = new int[nKids];
			for (int i = 0; i < nKids; i++) {
				bffs[i] = scan.nextInt() - 1;
				children[bffs[i]].add(i);
			}

			// Find cycles.
			boolean[] visited = new boolean[nKids];
			int longestCycle = 0;
			Queue<int[]> pairs = new LinkedList<int[]>();
			for (int i = 0; i < nKids; i++) {
				longestCycle = Math.max(longestCycle, findCycle(i, bffs, visited, pairs));
			}

			// Find trees from pairs.
			int pairCircle = 0;
			while (!pairs.isEmpty()) {
				int[] pair = pairs.poll();
				children[pair[0]].remove(pair[1]);
				children[pair[1]].remove(pair[0]);
				pairCircle += findMaxDepth(pair[0], children) + findMaxDepth(pair[1], children);
			}

			System.out.printf("Case #%d: %d\n", z + 1, Math.max(longestCycle, pairCircle));
		}
		scan.close();
	}

	static int findCycle(int node, int[] next, boolean[] visited, Queue<int[]> pairs) {
		int counter = 0;
		// node -> counter
		HashMap<Integer, Integer> history = new HashMap<Integer, Integer>();
		while (!visited[node]) {
			history.put(node, counter);
			visited[node] = true;
			node = next[node];
			counter++;
		}

		if (!history.containsKey(node)) {
			return 0;
		}
		// We just discovered a cycle.
		int cycle = counter - history.get(node);
		if (cycle == 2) {
			pairs.add(new int[]{ node, next[node] });
		}
		return cycle;
	}

	static int findMaxDepth(int node, HashSet[] children) {
		int max = 0;
		HashSet<Integer> myChildren = children[node];
		for (int child : myChildren) {
			max = Math.max(max, findMaxDepth(child, children));
		}

		return max + 1;
	}
}
