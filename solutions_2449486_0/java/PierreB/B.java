package y2013.q;

import static java.util.Arrays.deepToString;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.util.Scanner;

public class B {
	Scanner sc = new Scanner(System.in);
	int N, M;
	int [][] a;
	
	public void read() {
		N = sc.nextInt();
		M = sc.nextInt();
		a = new int[N][M];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				a[i][j] = sc.nextInt();
			}
		}
	}

	public void solve() {
		boolean illegal = false;
		outer:for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				illegal = checkIfIllegal(a[i][j], i, j);
				if(illegal) break outer;
			}
		}
		if(illegal) {
			System.out.println("NO");
		} else {
			System.out.println("YES");
		}
	}
	
	public boolean checkIfIllegal(int s, int c, int r) {
		boolean row = true;
		boolean column = true;
		
		for (int i = 0; i < M; i++) {
			if(a[c][i] > s) column = false;
		}
		
		for (int i = 0; i < N; i++) {
			if(a[i][r] > s) row = false;
		}
		
		if(row == false && column == false) {
			return true;
		} else {
			return false;
		}
	}

	public void run() {
		int caseT = sc.nextInt();
		for (int caseID = 1; caseID <= caseT; caseID++) {
			read();
			System.out.printf("Case #%d: ", caseID);
			solve();
			System.out.flush();
		}
	}

	public void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	public static void main(String[] args) {
		try {
			System.setIn(new BufferedInputStream(new FileInputStream(
					args.length > 0 ? args[0] : (B.class.getName() + ".in"))));
		} catch (Exception e) {
		}
		new B().run();
	}
}
