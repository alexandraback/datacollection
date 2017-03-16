import java.util.Scanner;


public class Bsmall {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			int N = sc.nextInt(); 
			int M = sc.nextInt(); 
			int[][] a = new int[N][M];
			int ones = 0;
			for (int n = 0; n < N; n++) {
				for (int m = 0; m < M; m++) {
					a[n][m] = sc.nextInt();
					if (a[n][m] == 1) {
						ones++;
					}
				}
			}
			for (int n = 0; n < N; n++) {
				
					boolean all = true;
					for (int m = 0; m < M; m++) {
						if (a[n][m] == 2) {
							all = false; break;
						}
					}
					if (all) {
						for (int m = 0; m < M; m++) {
							if (a[n][m] == 1) {
								ones--;
								a[n][m] = 0;
							}
						}
					}
				
			}
			
			for (int m = 0; m < M; m++) {
				
					boolean all = true;
					for (int n = 0; n < N; n++) {
						if (a[n][m] == 2) {
							all = false; break;
						}
					}
					if (all) {
						for (int n = 0; n < N; n++) {
							if (a[n][m] == 1) {
								ones--;
								a[n][m] = 0;
							}
						}
					}
				
			}
			String res = "NO";
			if (ones == 0) res = "YES";
			System.out.println("Case #" + t + ": " + res);
		}
	}
}
