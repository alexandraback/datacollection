import java.util.Scanner;


public class Main {

	private static final int MAX_E = 10000001;
	private static final int MAX_N = 10001;
	private static final int MAX_V = 10000001;
			
	private int[][] a = new int[2][MAX_E];
	
	private Scanner in;
	
	private int e;
	private int r;
	private int n;
	
	public static void main(String[] args) {
		Main main = new Main();
		main.doWork();
	}

	private void doWork() {
		int T = in.nextInt();

		for (int i = 0; i < T; i++) {
			System.out.println("Case #" + (i + 1) + ": " + doCase());
		}
	}
	
	private int doCase() {
		e = in.nextInt();
		r = in.nextInt();
		n = in.nextInt();
		
		r = Math.min(e, r);
		
		int c1 = 0;
		int c2 = 1;
		int v = in.nextInt();
		int ans = 0;
		int t;
		for (t = 0; t < r; t++) {
			a[c2][t] = 0;
		}
		
		for (t = 0; t <= e - r; t++) {
			a[c2][t + r] = (e - t) * v;
			ans = Math.max(a[c2][t + r],  ans);
		}
		
		for (int i = 1; i < n; i++) {
			v = in.nextInt();
			for (t = 0; t <= e - r; t++) {
				a[c1][t + r] = a[c2][t];
				
				for (int j = t + 1; j <= e; j++) {
					a[c1][t + r] = Math.max(a[c1][t + r], a[c2][j] + (j - t) * v);
					ans = Math.max(a[c1][t + r],  ans);
				}
			}
			
			for (; t <= e; t++) {
				for (int j = e - r; j <= e; j++) {
					a[c1][e] = Math.max(a[c1][e], a[c2][j] + (j - t) * v);
					ans = Math.max(a[c1][e],  ans);
				}
			}
			
			c1++;
			c2++;
			c1 %= 2;
			c2 %= 2;
		}
		
		return ans;
	}
	
	public Main() {
		in = new Scanner(System.in);
	}
}
