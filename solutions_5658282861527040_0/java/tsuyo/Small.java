import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class Small {
	Scanner sc = new Scanner(System.in);

	int A, B, K;

	void input() {
		A = sc.nextInt();
		B = sc.nextInt();
		K = sc.nextInt();
	}

	void solve() {
		long cnt = 0;
		for (int a = 0; a < A; a++) {
			for (int b = 0; b < B; b++) {
				if ((a & b) < K) {
					//debug(a,b);
					cnt++;
				}
			}
		}
		System.out.println(cnt);
	}

	void start() {
		int T = sc.nextInt();
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			input();
			System.out.printf("Case #%d: ", caseNum);
			solve();
			System.out.flush();
		}
		sc.close();
	}

	void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	public static void main(String[] args) {
		new Small().start();
	}

}
