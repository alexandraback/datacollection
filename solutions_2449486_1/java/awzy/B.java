import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	public static void main(String[] args) throws IOException {
		String name = "B-large";
		Scanner sc = new Scanner(new File(name + ".in"));
		//Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new FileWriter(name + ".out"));
		int n = sc.nextInt();
		cases: for (int c = 1; c <= n; c++) {
			int N = sc.nextInt(), M = sc.nextInt();
			int[][] grass = new int[N][M];
			int[] rowmax = new int[N];
			int[] colmax = new int[M];
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < M; j++) {
					grass[i][j] = sc.nextInt();
					rowmax[i] = Math.max(rowmax[i], grass[i][j]);
					colmax[j] = Math.max(colmax[j], grass[i][j]);
				}
			}
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < M; j++) {
					if(grass[i][j] != Math.min(rowmax[i], colmax[j])) {
						out.println("Case #" + c + ": " + "NO");
						//System.out.println("Case #" + c + ": " + "NO");
						continue cases;
					}
				}
			}
			out.println("Case #" + c + ": " + "YES");
			//System.out.println("Case #" + c + ": " + "YES");
		}
		out.close();
		sc.close();
	}

}
