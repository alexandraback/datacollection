import java.util.Scanner;

public class CRoundC {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int i = 0; i < T; i++) {
			int ans = solve(in);
			System.out.printf("Case #%d: %d\n", i + 1, ans);
		}

	}

	static int[] denoms;
	static int C, D, V;

	public static int solve(Scanner in) {
		C = in.nextInt(); // Max number of each denom able to use
		D = in.nextInt(); // # of existing denominations
		V = in.nextInt(); // <= V must be supported

		denoms = new int[V + 1];
		for (int i = 0; i < D; i++) {
			denoms[in.nextInt()] = C;
		}

		// Num that we select
		for (int num = 0; num < V; num++) {
			if (possible(0, num)) {
				return num;
			}
		}

		return -1;
	}

	public static boolean possible(int idx, int count) {

		if (count == 0) {
			return canSumToAll();
		}

		for (int i = idx; i < denoms.length; i++) {
			if (denoms[i] == 0) {
				denoms[i] = C;
				if (possible(idx + 1, count - 1)) {
					return true;
				}
				denoms[i] = 0;
			}
		}

		return false;
	}

	// Returns whether we can sum to this target using each value only once
	// Returns the value of what we can't sum to -- alternatively returns
	// -1 if we can sum to all
	public static boolean canSumToAll() {
		boolean[] canReach = new boolean[V + 1];
		dfs(0, 0, canReach);

		for (int i = 0; i <= V; i++) {
			if (!canReach[i]) {
				return false;
			}
		}

		return true;
	}

	// Fills in all possible reachable values by doing a DFS
	public static void dfs(int curVal, int curIdx, boolean[] canReach) {
		if (curVal >= canReach.length) {
			return;
		}

		canReach[curVal] = true;

		// Try each!
		for (int i = curIdx; i < canReach.length; i++) {
			if (denoms[i] > 0) {
				denoms[i]--;
				dfs(curVal + i, i, canReach);
				denoms[i]++;
			}
		}
	}

}
