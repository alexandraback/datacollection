import java.util.LinkedList;
import java.util.Scanner;

public class A {
	
	static boolean[] deja;
	static int[][] parent;
	static LinkedList<Integer> queue;
	
	static boolean dfs() {
		while (!queue.isEmpty()) {
			int i = queue.poll();
			deja[i] = true;
			for (int j = 1; j <= parent[i][0]; j++) {
				int k = parent[i][j];
				if (deja[k] || queue.contains(k))
					return true;
				queue.add(k);
			}
		}
		return false;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int cas = 1; cas <= T; cas++) {
			int N = in.nextInt();
			parent = new int[N+1][N+1];
			for (int i = 1; i<=N; i++) {
				int Mi = in.nextInt();
				parent[i][0] = Mi;
				for (int j = 1; j<=Mi; j++)
					parent[i][j] = in.nextInt();
			}
			boolean found = false;
			for (int i = 1; i<=N && !found; i++) {
				deja = new boolean[N+1];
				queue = new LinkedList<Integer>();
				queue.add(i);
				found = dfs();
			}
			System.out.print("Case #"+cas+": ");
			System.out.println(found ? "Yes" : "No");
		}

	}

}
