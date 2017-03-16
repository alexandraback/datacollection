import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.util.*;

public class B {
	Scanner sc = new Scanner(System.in);
	
	int n, m;
	int[][] a;
	
	void solve() {
		n = sc.nextInt();
		m = sc.nextInt();
		a = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = sc.nextInt();
			}
		}
		boolean[] okI = new boolean[n], okJ = new boolean[m];
		fill(okI, true);
		fill(okJ, true);
		for (int h = 100; h > 0; h--) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) if (a[i][j] == h) {
					if (!okI[i] && !okJ[j]) {
						System.out.println("NO");
						return;
					}
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) if (a[i][j] == h) {
					okI[i] = okJ[j] = false;
				}
			}
		}
		System.out.println("YES");
	}
	
	void run() {
		int T = sc.nextInt();
		for (int caseID = 1; caseID <= T; caseID++) {
			System.out.printf("Case #%d: ", caseID);
			solve();
		}
	}
	
	void debug(Object...os) {
		System.err.println(deepToString(os));
	}
	
	public static void main(String[] args) {
		new B().run();
	}
}
