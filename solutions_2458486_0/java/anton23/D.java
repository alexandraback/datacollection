import java.util.Arrays;
import java.util.Scanner;


public class D {
	public static void main(String[] args) {
		new D().solve();
	}
	
	int N;
	
	int[][] contains;
	int[] o;
	int[] feasible;
	int[] next;
	
	public boolean explore(int open) {
		if (feasible[open] != 0) return feasible[open] == 1;
		
		if (open == ((1 << (N+1)) - 1)) {
			feasible[open] = 1; return true;
		}
		int[] keys = new int[201];
		int total = 0;
		for (int i = 0; i <= N; i ++) {
			if ((open & (1 << i)) != 0) {
				if (i > 0) {
					keys[o[i]]--;
					total--;
				}
				for (int j = 0; j < contains[i].length; j++) {
					keys[contains[i][j]] ++;			
					total++;
				}
			}
		}
		if (total == 0) {
			feasible[open] = -1;
			return false;
		}
		for (int i = 1; i <= N; i++) {
			if ((open & (1 << i)) == 0 && keys[o[i]] > 0) {
				if (explore(open | (1 << i))) {
					feasible[open] = 1;
					next[open] = i;
					return true;
				}
			}
		}
		feasible[open] = -1;
		return false;
	}
	
	public void solve() {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			// Read input
			int K = sc.nextInt(); N = sc.nextInt();
			
			contains = new int[N+1][];
			contains[0] = new int[K];
			for (int i = 0; i < K; i++) {
				contains[0][i] = sc.nextInt();
			}
			o = new int[N+1];
			for (int i = 1; i <= N; i++) {
				o[i] = sc.nextInt();
				int Ki = sc.nextInt();
				contains[i] = new int[Ki];
				for (int j = 0; j < Ki; j++) {
					contains[i][j] = sc.nextInt();
				}
			}
			// Solve
			feasible = new int[1 << (N+1)];
			next = new int[1 << (N+1)];
			System.out.print("Case #" + t + ":");
			if (explore(1)) {
				int open = 1;
				for (int i = 1; i <= N; i++) {
					System.out.print(" " + next[open]);
					open |= (1 << next[open]);
				}
			} else {
				System.out.print(" IMPOSSIBLE");
			}
			System.out.println();
		}
	}
}
