import java.util.*;
import java.math.*;

public class B {
public static void main(String [] args) {
	Scanner scanner = new Scanner(System.in);
	int nCase = scanner.nextInt();
	
	for (int nc = 1; nc <= nCase; nc++) {
		int E = scanner.nextInt();
		int R = scanner.nextInt();
		int N = scanner.nextInt();
		int[] v = new int[N];
		for (int i = 0; i < N; i++)
			v[i] = scanner.nextInt();
		int[][] ans = new int[N][E+1];
		boolean[][] valid = new boolean[N][E+1];
		
		for (int i = 0; i <= E; i++) {
			int gain =  v[0]*i;
			int remain = Math.min(E, E-i+R);
			ans[0][remain] = Math.max(gain, ans[0][remain]);
			valid[0][remain] = true;
		}
		
		for (int k = 0; k < N-1; k++) {
			for (int a = 0; a <= E; a++) {
				if (valid[k][a]) {					
					for (int b = 0; b <= a; b++) {
						int gain = ans[k][a] + b * v[k+1];
						int remain = Math.min(E, a-b+R);
						valid[k+1][remain] = true;
						if (gain > ans[k+1][remain])
							ans[k+1][remain] = gain;
					}
				}
			}
		}
		
		int fAns = 0;
		for (int i = 0; i <= E; i++)
			if (ans[N-1][i] > fAns)
				fAns = ans[N-1][i];

		System.out.println("Case #" + nc + ": " + fAns);
	}
}

}