import java.util.Arrays;
import java.util.Scanner;


public class WarFast {

	static int n;
	static double a[];
	static double b[];
	
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
        int ind = 0;
        int ret = 0;
        for (int i = 0;i < n;i++) {
        	if (a[i] > b[ind]) {
        		++ind;
        		++ret;
        	}
        }
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
