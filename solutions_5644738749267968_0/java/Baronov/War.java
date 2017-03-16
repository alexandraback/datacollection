import java.util.Arrays;
import java.util.Scanner;


public class War {

	static int n;
	static double a[];
	static double b[];
	static int ans[][][];
	static boolean v[][][];
	
	public static void main(String []args) {
		Scanner in = new Scanner(System.in);
		int tests = in.nextInt();
		int [] ans = new int[tests];
		int []dAns = new int[tests];
		for (int t = 0;t < tests;t++) {
			n = in.nextInt();
			a = new double[n];
			b = new double[n];
			for (int i = 0;i < n;i++) a[i] = in.nextDouble();
			for (int i = 0;i < n;i++) b[i] = in.nextDouble();
			ans[t] = war();
			dAns[t] = dWar();
		}
		for (int i = 0;i < tests;i++) {
			System.out.println("Case #" + String.valueOf(i+1) + ": " + dAns[i] + " " + ans[i]);
		}
	}
	
	static int dWar() {
		Arrays.sort(a);
		Arrays.sort(b);
        ans = new int[n][n][n];
        v = new boolean[n][n][n];
		return solve(0, 0, n-1);
	}
	
	static int solve(int m, int k, int l) {
		if (v[m][k][l]) return ans[m][k][l];
		if (m == n-1) {
			return a[n-1] > b[k] ? 1 : 0;
		}
		int ret = solve(m+1, k, l-1);
		if (a[m] > b[k] && ret < 1 + solve(m+1, k+1, l)) {
			ret = 1 + solve(m+1, k+1, l);
		}
		ans[m][k][l] = ret;
		v[m][k][l] = true;
		return ret;
	}
	
	static int war() {
		int ret = 0;
		boolean v[] = new boolean[n];
		for (int i = 0;i < n;i++) {
			double min = 10;
			int ind = -1;
			for (int j = 0;j < n;j++) {
				if (v[j]) continue;
				if (b[j] > a[i] && b[j] < min) {
					ind = j;
					min = b[j];
				}
			}
			if (ind > -1) {
				++ret;
				v[ind] = true;
			}
			
		}
		return n - ret;
	}
}
