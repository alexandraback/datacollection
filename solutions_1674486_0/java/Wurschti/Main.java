
import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Locale;
import java.util.Scanner;
import java.util.Stack;

public class Main {
	public static void main(String[] args) throws FileNotFoundException {
//		Scanner sc = new Scanner(new File("A-practice.in"));
		 Scanner sc = new Scanner(new File("A-small-attempt0.in"));
		// Scanner sc = new Scanner(new File("A-large.in"));
		sc.useLocale(Locale.US);
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			int N = sc.nextInt();
			int[][] inherit = new int[N][];
			for (int j = 0; j < N; j++) {
				int count = sc.nextInt();
				inherit[j] = new int[count];
				for (int k = 0; k < inherit[j].length; k++) {
					inherit[j][k] = sc.nextInt();
				}
			}
			boolean found = dfs(inherit);
			// do case things here
			System.out.format(Locale.US, "Case #%d: ", i);
			System.out.println(found?"Yes":"No");
		}
	}
	
	private static boolean dfs(int[][] inherit) {
		boolean found = false;
		for (int i = 1; i <= inherit.length; i++) {
			found = found || dfs(inherit, i);
		}
		return found;
	}
	
	private static boolean dfs(int[][] inherit, int i) {
		HashSet<Integer> found = new HashSet<Integer>();
		Stack<Integer> S = new Stack<Integer>();
		S.push(i);
		return dfs(inherit, S, found);
	}
	
	private static boolean dfs(int[][] inherit, Stack<Integer> S, HashSet<Integer> found) {
		if (S.isEmpty()) {
			return false;
		}
		boolean f = false;
		while (!S.isEmpty()) {
			Integer node = S.pop();
			if (found.contains(node)) {
				return true;
			} else {
				found.add(node);
				for (int i = 0; i < inherit[node-1].length; i++) {
					S.push(inherit[node-1][i]);
				}
				f = f || dfs(inherit, S, found);
			}
		}
		return f;
	}
}