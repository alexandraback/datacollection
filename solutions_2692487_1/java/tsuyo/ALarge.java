import static java.lang.Math.*;
import static java.util.Arrays.*;

import java.io.*;
import java.util.*;

public class ALarge {
	Scanner sc = new Scanner(System.in);

	int A, N;
	int[] m;

	void input() {
		A = sc.nextInt();
		N = sc.nextInt();
		m = new int[N];
		for (int i = 0; i < N; i++) {
			m[i] = sc.nextInt();
		}
		sort(m);
	}

	void solve() {
		System.out.println(dfs(A, 0, N - 1, 0));
	}

	int dfs(long val, int from, int to, int min) {
		if (from > to)
			return min;
		if (val > m[from]) {
			return dfs(val + m[from], from + 1, to, min);
		} else {
			if (val == 1)
				return dfs(val, from, to - 1, min + 1);
			return min(dfs(val * 2 - 1, from, to, min + 1), min + to - from + 1);
		}
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
		new ALarge().start();
	}

}
