import java.io.InputStreamReader;
import java.util.Scanner;


public class B {

	public static void main(String[] args) {

		Scanner sc = new Scanner(new InputStreamReader(System.in));
		int cases = sc.nextInt();
		
		for (int c = 1; c <= cases; ++c) {
			int N = sc.nextInt();
			int M = sc.nextInt();
			
			int[][] wanted = new int[N][M];
			int[][] current = new int[N][M];
			
			for (int n = 0; n < N; ++n) {
				for (int m = 0; m < M; ++m) {
					wanted[n][m] = sc.nextInt();
					current[n][m] = 100;
				}
			}
			
			// first cut each row to the maximum in that row
			for (int n = 0; n < N; ++n) {
				int max = wanted[n][getMaxInd(wanted[n])];
				for (int m = 0; m < M; ++m) current[n][m] = max;
			}
			
			// now the same column-wise
			for (int m = 0; m < M; ++m) {
				int max = wanted[0][m];
				for (int n = 1; n < N; ++n) {
					if (wanted[n][m] > max) max = wanted[n][m];
				}

				for (int n = 0; n < N; ++n) {
					current[n][m] = Math.min(max, current[n][m]);
				}
			}
			
			// we cannot cut any more.. done?
			boolean worked = true;
			for (int n = 0; n < N; ++n) {
				for (int m = 0; m < M; ++m) {
					if (wanted[n][m] - current[n][m] != 0) {
						worked = false;
						break;
					}
				}
				if (!worked) break;
			}
			
			System.out.println("Case #" + c + ": " + ((worked) ? "YES" : "NO"));
		}
		
	}
	
	public static int getMaxInd(int[] ar) {
		if (ar.length <= 0) return -1;
		int maxInd = 0;
		for (int i = 1; i < ar.length; ++i) {
			if (ar[i] > ar[maxInd]) maxInd = i;
		}
		return maxInd;
	}

}
