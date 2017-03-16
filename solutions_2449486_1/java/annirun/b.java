import java.util.Scanner;

public class b {
	static int[][] lawn;
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		for (int i = 0; i < cases; i++) {
			int n = in.nextInt();
			int m = in.nextInt();

			lawn = new int[n][m];

			for (int j = 0; j < n; j++) {
				for (int k = 0; k < m; k++) {
					lawn[j][k] = in.nextInt();
				}
			}

			boolean works = true;
			outer: for (int j = 0; j < n; j++) {
				for (int k = 0; k < m; k++) {
					if (!(checkHor(j, k) || checkVer(j, k))) {
						works = false;
						break outer;
					}
				}
			}
			
			System.out.printf("Case #%d: %s\n", i+1, works ? "YES" : "NO");
		}
	}
	private static boolean checkVer(int j, int k) {
		for (int i = 0; i < lawn.length; i++) {
			if (lawn[i][k] > lawn[j][k])
				return false;
		}
		return true;
	}
	private static boolean checkHor(int j, int k) {
		for (int i = 0; i < lawn[j].length; i++) {
			if (lawn[j][i] > lawn[j][k])
				return false;
		}
		return true;
	}
}
