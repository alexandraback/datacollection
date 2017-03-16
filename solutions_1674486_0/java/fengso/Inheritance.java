import java.util.Scanner;

public class Inheritance {
	static int n;
	static boolean[][] map;
	static int[] count;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		for (int C = 1; C <= N; C++) {

			n = sc.nextInt();

			map = new boolean[n][n];
			boolean[] not_head = new boolean[n];

			for (int i = 0; i < n; i++) {
				int num_in = sc.nextInt();
				for (int j = 0; j < num_in; j++) {
					int in = sc.nextInt() - 1;
					map[i][in] = true;
					not_head[in] = true;
				}
			}

			boolean yes = false;
			for (int i = 0; i < n; i++) {
				if (!not_head[i]) {
					count = new int[n];
					if (!dfs(i)) {
						yes = true;
						break;
					}
				}
			}

			System.out.printf("Case #%d: ", C);
			if (yes) System.out.println("Yes");
			else System.out.println("No");
		}
	}

	static boolean dfs(int head) {
		count[head] ++;
		if (count[head]>1) return false;
		else {
			for (int i=0;i<n;i++) {
				if (map[head][i]) {
					if (!dfs(i)) return false;
				}
			}
			return true;
		}
	}
}
