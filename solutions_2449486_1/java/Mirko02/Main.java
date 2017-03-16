import java.util.Scanner;

public class Main {

	private static final int MX = 100;

	private int a[][] = new int[MX][MX];
	private int b[][] = new int[MX][MX];

	private int n;
	private int m;

	private Scanner in;

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Main main = new Main();
		main.doWork();
	}

	private void doWork() {
		int T = in.nextInt();

		for (int i = 0; i < T; i++) {
			System.out.print("Case #" + (i + 1) + ": ");
			doCase();
		}
	}

	private void doCase() {
		n = in.nextInt();
		m = in.nextInt();

		for (int i = 0; i < n; i++) {
			for (int t = 0; t < m; t++) {
				a[i][t] = in.nextInt();
				b[i][t] = MX;
			}
		}

		if (calc()) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
	}

	private boolean calc() {
		int d = 0;
		for (int i = 0; i < n; i++) {
			d = maxRow(i);
			
			for (int t = 0; t < m; t++) {
				b[i][t] = Math.min(b[i][t], d);
			}
		}
		
		for (int t = 0; t < m; t++) {
			d = maxCol(t);
			for (int i = 0; i < n; i++) {
				b[i][t] = Math.min(b[i][t], d);
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int t = 0; t < m; t++) {
				if (a[i][t] != b[i][t]) {
					return false;
				}
			}
		}

		return true;
	}

	private int maxRow(int i) {
		int ans = 0;
		
		for (int t = 0; t < m; t++) {
			ans = Math.max(a[i][t], ans);
		}
		
		return ans;
	}
	
	private int maxCol(int t) {
		int ans = 0;
		
		for (int i = 0; i < n; i++) {
			ans = Math.max(a[i][t], ans);
		}
		
		return ans;
	}

	public Main() {
		in = new Scanner(System.in);
	}
}
