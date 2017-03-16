import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;


public class DiamondInheritance {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			int N = sc.nextInt();
			List<List<Integer>> graph = new ArrayList<List<Integer>>();
			for (int j = 0; j < N; j++) {
				List<Integer> node = new ArrayList<Integer>();
				int M = sc.nextInt();
				for (int k = 0; k < M; k++) {
					int pointto = sc.nextInt() - 1;
					node.add(pointto);
				}
				graph.add(node);
			}
			boolean result = solve(graph);
			if (result) {
				System.out.println("Case #" + i + ": Yes");
			} else {
				System.out.println("Case #" + i + ": No");
			}
		}
	}

	private static boolean solve(List<List<Integer>> graph) {
		for (int i = 0; i < graph.size(); i++) {
			if (graph.get(i).size() < 2)
				continue;
			if (bfs(graph, i))
				return true;
		}
		
		return false;
	}

	private static boolean bfs(List<List<Integer>> graph, int node) {
		Set<Integer> visited = new HashSet<Integer>();
		visited.add(node);
		Queue<List<Integer>> queue = new LinkedList<List<Integer>>();
		queue.add(graph.get(node));
		while(!queue.isEmpty()) {
			List<Integer> point = queue.remove();
			for (Integer neighbor : point) {
				if (visited.contains(neighbor))
					return true;
				visited.add(neighbor);
				queue.add(graph.get(neighbor));
			}
		}
		
		return false;
	}

}
