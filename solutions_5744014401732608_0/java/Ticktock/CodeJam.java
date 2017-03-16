import java.util.Scanner;

public class CodeJam {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		final int T = Integer.parseInt(sc.nextLine());
		for (int caseCount = 1; caseCount <= T; caseCount++) {
			final int B = sc.nextInt();
			final int M = sc.nextInt();
			int[][] g = new int[B][B];
			int[] pathCounts = new int[B];
			g[B-2][B-1] = 1;
			pathCounts[B-1] = 1;
			for (int y = B - 2; y >= 0; y--) {
				int count = 0;
				for (int x = y + 1; x < B; x++) {
					if (count + pathCounts[x] <= M) {
						g[y][x] = 1;
						count += pathCounts[x];
					}
				}
				pathCounts[y] = count;
				/*System.out.println("COUNT");
				for(int i = 0; i < B; i++) {
					System.out.println(pathCounts[i]);
				}*/
			}
			boolean possible = (pathCounts[0] == M);

			System.out.print("Case #" + caseCount + ": ");
			if (possible) {
				System.out.println("POSSIBLE");
				for (int y = 0; y < B; y++) {
					for (int x = 0; x < B; x++) {
						System.out.print(g[y][x]);
					}
					System.out.println();
				}
			} else {
				System.out.println("IMPOSSIBLE");
				/*for (int y = 0; y < B; y++) {
					for (int x = 0; x < B; x++) {
						System.out.print(g[y][x]);
					}
					System.out.println();
				}*/
			}
		}
		sc.close();
	}

}