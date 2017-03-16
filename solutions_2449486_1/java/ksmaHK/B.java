import java.util.*;

public class B {
public static void main(String [] args) {
	Scanner scanner = new Scanner(System.in);
	int nCase = scanner.nextInt();
	
	for (int nc = 1; nc <= nCase; nc++) {
		int N = scanner.nextInt();
		int M = scanner.nextInt();
		int[][] a = new int[N][M];
		
		for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			a[i][j] = scanner.nextInt();
		
		boolean possible = true;
		if (N > 1 && M > 1) {
			for (int i = 0; i < N && possible; i++)
			for (int j = 0; j < M; j++) {
				// check row
				boolean rowBlocked = false;
				for (int jj = 0; jj < M; jj++)
					rowBlocked |= (a[i][jj] > a[i][j]);
				boolean colBlocked = false;
				for (int ii = 0; ii < N; ii++)
					colBlocked |= (a[ii][j] > a[i][j]);
				if (rowBlocked && colBlocked) {
					possible = false;
					break;
				}
			}
			
		}
		System.out.println("Case #" + nc + ": " + (possible ? "YES" : "NO"));
	}
}
}