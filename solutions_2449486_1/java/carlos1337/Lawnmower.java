import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class Lawnmower {

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File("B-large.in"));
		PrintWriter pw = new PrintWriter(new File("lawn.out"));
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			int n = sc.nextInt();
			int m = sc.nextInt();
			int[][] matriz = new int[n][m];
			int[] maxRows = new int[n];
			int[] maxCols = new int[m];
			for (int j = 0; j < n; j++) {
				int max = 0;
				for (int k = 0; k < m; k++) {					
					matriz[j][k] = sc.nextInt();
					if(matriz[j][k]>max)
						max = matriz[j][k];
				}
				maxRows[j] = max;
			}
			for (int j = 0; j < m; j++) {
				int max = 0;
				for (int k = 0; k < n; k++) {					
					if(matriz[k][j]>max)
						max = matriz[k][j];
				}
				maxCols[j] = max;
			}

			boolean possible = true;
			for (int j = 0; j < n && possible ; j++) {
				for (int j2 = 0; j2 < m && possible; j2++) {
					possible = (matriz[j][j2]== maxRows[j] || matriz[j][j2]== maxCols[j2]);
				}
			}
			pw.println("Case #"+i+": "+(possible?"YES":"NO"));
		}
		pw.close();
		
	}
	
}
