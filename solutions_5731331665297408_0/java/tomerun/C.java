import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;

public class C {

	static Scanner sc = new Scanner(System.in);
	static boolean[][] g;
	static int[] city;
	static int[] ord;
	static Stack<Integer> stack;
	static int N;

	public static void main(String[] args) {
		int T = sc.nextInt();
		for (int i = 1; i <= T; ++i) {
			System.out.printf("Case #%d: %s\n", i, solve());
		}
	}

	static String solve() {
		N = sc.nextInt();
		int M = sc.nextInt();
		int[] zip = new int[N];
		city = new int[N];
		ord = new int[N];
		for (int i = 0; i < N; ++i) {
			zip[i] = sc.nextInt();
			city[i] = (zip[i] << 10) + i;
		}
		Arrays.sort(city);
		for (int i = 0; i < N; ++i) {
			city[i] &= 0x3FF;
		}
		g = new boolean[N][N];
		for (int i = 0; i < M; ++i) {
			int t = sc.nextInt() - 1;
			int f = sc.nextInt() - 1;
			g[t][f] = g[f][t] = true;
		}
		ord[0] = city[0];
		boolean success = false;
		for (int i = 0; i < N; ++i) {
			stack = new Stack<>();
			stack.push(city[i]);
			if (dfs(1 << city[i], city[i], 1)) {
				success = true;
				break;
			}
		}
		if (!success) {
			System.err.println("fail");
		}
		String ret = "";
		for (int i = 0; i < N; ++i) {
			ret += zip[ord[i]];
		}
		return ret;
	}

	static boolean dfs(int state, int cur, int depth) {
		if (depth == N) {
			return true;
		}
		for (int i = 0; i < N; ++i) {
			int next = city[i];
			if ((state & (1 << next)) != 0) continue;
			ord[depth] = next;
			Stack<Integer> backup = new Stack<Integer>();
			backup.addAll(stack);
			while (!stack.isEmpty()) {
				int prev = stack.peek();
				if (g[prev][next]) {
					stack.push(next);
					if (dfs(state | (1 << next), next, depth + 1)) {
						return true;
					}
					stack.pop();
				}
				stack.pop();
			}
			stack = backup;
		}
		return false;
	}
}
