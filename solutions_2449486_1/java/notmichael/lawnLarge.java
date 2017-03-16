import java.util.*;

public class lawnLarge {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = Integer.parseInt(in.nextLine());
		for (int i=0; i<cases; i++) {
			int n = in.nextInt();
			int m = in.nextInt();
			in.nextLine();
			int[][] lawn = new int[n][m];
			for (int j=0; j<n; j++) {
				for (int k=0; k<m; k++) {
					lawn[j][k] = in.nextInt();
				}
				if (j!=n-1) {
					in.nextLine();
				}
			}
			if (i!=cases-1) {
				in.nextLine();
			}
			int[] rows = new int[n];
			int[] columns = new int[m];
			for (int j=0; j<n; j++) {
				rows[j] = 0;
			}
			for (int j=0; j<m; j++) {
				columns[j] = 0;
			}
			for (int j=0; j<n; j++) {
				for (int k=0; k<m; k++) {
					if (lawn[j][k] > rows[j]) {
						rows[j] = lawn[j][k];
					}
					if (lawn[j][k] > columns[k]) {
						columns[k] = lawn[j][k];
					}
				}
			}
			boolean possible = true;
			for (int j=0; j<n; j++) {
				for (int k=0; k<m; k++) {
					if (lawn[j][k]!=min(rows[j],columns[k])) {
						possible = false;
						break;
					}
				}
				if (!possible) {
					break;
				}
			}
			if (possible) {
				System.out.println("Case #" + (i+1) + ": YES");
			}
			else {
				System.out.println("Case #" + (i+1) + ": NO");
			}
		}
	}
	private static int min(int a, int b) {
		if (a<b) {
			return a;
		}
		else {
			return b;
		}
	}

}
