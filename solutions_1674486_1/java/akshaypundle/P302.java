import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class P302 {
	static String test = "3 3 1 2 1 3 0 5 2 2 3 1 4 1 5 1 5 0 3 2 2 3 1 3 0";

	public static void main(String[] args) {
		Scanner inp = new Scanner(System.in);
		int t = inp.nextInt();
		int i = 1;
		while (t > 0) {
			int n = inp.nextInt();
			List<List<Integer>> d = new ArrayList<List<Integer>>();
			for (int c = 0; c < n; c++) {
				int num = inp.nextInt();
				ArrayList<Integer> arr = new ArrayList<Integer>();
				for (int j = 0; j < num; j++) {
					arr.add(inp.nextInt());
				}
				d.add(arr);
			}
			System.out.println("Case #" + i + ": " + calc(n, d));
			--t;
			++i;
		}

	}

	private static String calc(int n, List<List<Integer>> d) {
		for (int i = 1; i <= n; i++) {
			Set<Integer> visited = new HashSet<Integer>();
			visited.add(i);
			if (dfs(visited, d, i)) {
				return "Yes";
			}
		}
		// TODO Auto-generated method stub
		return "No";
	}

	static boolean dfs(Set<Integer> visited, List<List<Integer>> tree, int cur) {
		List<Integer> children = tree.get(cur - 1);
		for (Integer child : children) {
			if (visited.contains(child)) {
				return true;
			}
			visited.add(child);
			if (dfs(visited, tree, child))
				return true;
		}

		return false;
	}

}
