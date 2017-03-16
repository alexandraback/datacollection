import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class C {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			System.out.print("Case #" + tc + ": ");

			int N = sc.nextInt();
			int[] bffs = new int[N];
			for (int i = 0; i < bffs.length; i++) {
				bffs[i] = sc.nextInt() - 1;
			}
			System.out.println(solve(bffs));
		}

		sc.close();
	}

	static int solve(int[] bffs) {
		int maxCircle = 0;

		int N = bffs.length;

		boolean[] liked = new boolean[N];
		for (int bff : bffs) {
			liked[bff] = true;
		}

		int[] maxLikedLength = new int[N];
		Set<Pair> pairs = new HashSet<Pair>();

		boolean[] visited = new boolean[N];

		for (int i = 0; i < N; i++) {
			if (!liked[i]) {
				StartNPeriod sp = search(bffs, visited, i);
				maxCircle = Math.max(maxCircle, sp.period);
				if (sp.period == 2) {
					maxLikedLength[sp.startNode] = Math.max(maxLikedLength[sp.startNode], sp.distToStart);

					Pair pair = new Pair(sp.startNode, bffs[sp.startNode]);
					pairs.add(pair);
				}
			}
		}

		for (int i = 0; i < N; i++) {
			if (!visited[i]) {
				StartNPeriod sp = search(bffs, visited, i);
				maxCircle = Math.max(maxCircle, sp.period);
				if (sp.period == 2) {
					Pair pair = new Pair(sp.startNode, bffs[sp.startNode]);
					pairs.add(pair);
				}
			}
		}

		int pairLength = 0;
		for (Pair pair : pairs) {
			// System.out.println("pair: " + maxLikedLength[pair.node1] + ", " +
			// maxLikedLength[pair.node2]);

			pairLength += 2 + maxLikedLength[pair.node1] + maxLikedLength[pair.node2];
		}

		// System.out.println("maxCircle: " + maxCircle);
		// System.out.println("pairLength: " + pairLength);

		maxCircle = Math.max(maxCircle, pairLength);

		return maxCircle;
	}

	static StartNPeriod search(int[] bffs, boolean[] visited, int fromNode) {
		Map<Integer, Integer> node2length = new HashMap<Integer, Integer>();
		int length = 0;
		int node = fromNode;
		while (!node2length.containsKey(node)) {
			node2length.put(node, length);
			visited[node] = true;

			node = bffs[node];
			length++;
		}
		return new StartNPeriod(node, node2length.get(node), length - node2length.get(node));
	}
}

class StartNPeriod {
	int startNode;
	int distToStart;
	int period;

	StartNPeriod(int startNode, int distToStart, int period) {
		this.startNode = startNode;
		this.distToStart = distToStart;
		this.period = period;
	}
}

class Pair {
	int node1;
	int node2;

	Pair(int node1, int node2) {
		this.node1 = Math.min(node1, node2);
		this.node2 = Math.max(node1, node2);
	}

	@Override
	public int hashCode() {
		return node1 * node2;
	}

	@Override
	public boolean equals(Object obj) {
		Pair other = (Pair) obj;
		return node1 == other.node1 && node2 == other.node2;
	}
}