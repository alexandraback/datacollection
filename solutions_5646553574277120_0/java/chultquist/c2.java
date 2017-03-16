import java.util.Scanner;

public class c2 {
	private static int MAX_V = 100;
	private static boolean[] reachable = new boolean[MAX_V + 1];
	private static boolean[][] added = new boolean[MAX_V + 1][MAX_V + 1];
	private static boolean[] hasCoin = new boolean[MAX_V + 1];

	private static int solve(int c, int d, int v, int minCoin, int level)
	{
		boolean ok = true;
		for (int i = 0; i <= v; i++) {
			if (!reachable[i]) {
				if (i < minCoin) {
					return -1;
				}
				else {
					ok = false;
					break;
				}
			}
		}
		if (ok) {
			return 0;
		}
		else {
			int best = -1;
			for (int i = minCoin; i <= v; i++) {
				if (!hasCoin[i]) {
					/*for (int k = 0; k < level; k++) {
						System.err.print(" ");
					}
					System.err.println("Trying " + i);*/
					hasCoin[i] = true;
					for (int j = v; j >= 0; j--) {
						if (!reachable[j]) {
							boolean yes = false;
							for (int k = 1; k <= c; k++) {
								if (j < k * i) {
									break;
								}
								else if (reachable[j - k * i]) {
									yes = true;
									break;
								}
							}
							if (yes) {
								reachable[j] = true;
								added[i][j] = true;
							}
						}
					}
					int cur = solve(c, d, v, i + 1, level + 1);
					if (cur != -1 && (best == -1 || cur < best)) {
						best = cur + 1;
					}
					hasCoin[i] = false;
					for (int j = 0; j <= v; j++) {
						if (added[i][j]) {
							reachable[j] = false;
							added[i][j] = false;
						}
					}
				}
			}
			return best;
		}
	}

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int caseNum = 1; caseNum <= t; caseNum++) {
			int c = sc.nextInt();
			int d = sc.nextInt();
			int v = sc.nextInt();
			for (int i = 0; i <= v; i++) {
				reachable[i] = false;
				hasCoin[i] = false;
			}
			reachable[0] = true;
			for (int i = 0; i < d; i++) {
				int val = sc.nextInt();
				for (int j = v; j >= 0; j--) {
					if (j >= val && !reachable[j]) {
						boolean yes = false;
						for (int l = 1; l <= c; l++) {
							if (j < l * val) {
								break;
							}
							else if (reachable[j - l * val]) {
								yes = true;
								break;
							}
						}
						if (yes) {
							reachable[j] = true;
						}
					}
				}
				hasCoin[val] = true;
			}
			System.out.println("Case #" + caseNum + ": " + solve(c, d, v, 1, 0));
		}
	}
}
