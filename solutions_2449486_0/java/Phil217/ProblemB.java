import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;


public class ProblemB {
	
	public static void solve(Scanner sc) {
		int N = sc.nextInt();
		int M = sc.nextInt();
		int[][] grass = new int[M][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				grass[j][i] = sc.nextInt();
			}
		}
		
		int[] rows = new int[N];
		int[] cols = new int[M];
		for (int i = 0; i < N; i++) {
			rows[i] = grass[0][i];
			for (int j = 1; j < M; j++) {
				if (grass[j][i] > rows[i]) {
					rows[i] = grass[j][i];
				}
			}
		}
		for (int i = 0; i < M; i++) {
			cols[i] = grass[i][0];
			for (int j = 1; j < N; j++) {
				if (grass[i][j] > cols[i]) {
					cols[i] = grass[i][j];
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (grass[j][i] < rows[i] && grass[j][i] < cols[j]) {
					System.out.println("NO");
					return;
				}
			}
		}
		System.out.println("YES");
	}
	
	
	
	
	public static void main(String[] args) throws FileNotFoundException {
//		 Scanner sc = new Scanner(new File("B-practice.in"));
		 Scanner sc = new Scanner(new File("B-small-attempt0.in"));
//		Scanner sc = new Scanner(new File("B-large.in"));
		sc.useLocale(Locale.US);
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			System.out.format(Locale.US, "Case #%d: ", i);
			solve(sc);
		}
		sc.close();
	}
}
