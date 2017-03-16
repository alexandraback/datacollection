import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(new FileInputStream(new File("large.txt")));
		int T = scanner.nextInt();
		scanner.nextLine();
		
		for (int t = 0; t < T; t++) {
			int N = scanner.nextInt();
			int M = scanner.nextInt();
			scanner.nextLine();
			int[] maxC = new int[M];
			int[] maxR = new int[N];
			int[][] lawn = new int[N][M];
			for (int n = 0; n < N; n++) {
				for (int m = 0; m < M; m++) {
					int a = scanner.nextInt();
					boolean c = true;
					boolean r = true;
					if (n == 0) {
						maxC[m] = a;
					} else {
						if (a > maxC[m]) {
							maxC[m] = a;
						}
					}
					if (m == 0) {
						maxR[n] = a;
					} else {
						if (a > maxR[n]) {
							maxR[n] = a;
						}
					}
					lawn[n][m] = a;
				}
				if (scanner.hasNextLine()) scanner.nextLine();
			}
			boolean possible = true;
			for (int n = 0; n < N; n++) {
				for (int m = 0; m < M; m++) {
					if (lawn[n][m] < maxC[m] && lawn[n][m] < maxR[n]) {
						possible = false;
						break;
					}
				}
				if (!possible) break;
			}
			System.out.println("Case #" + (t + 1) + ": " + (possible ? "YES" : "NO"));
		}
		
	}

}
