package gcj.y2015.r1c;

import java.io.File;
import java.util.Scanner;

public class MainA {

	static int t;

	public static void main(String[] args) throws Exception {
		// 問題の読み込み
		Scanner sc = new Scanner(new File("src/in.txt"));

		int T = sc.nextInt();

		for (t=1; t<=T; t++) {

			int R = sc.nextInt();
			int C = sc.nextInt();
			int W = sc.nextInt();

			solve(R,C,W);
		}
	}

	static void solve(int R, int C, int W) {
		int ans = 0;

		int n = C/W; // 1行に入るshipの数

		if (R > 1) {
			ans = ans + n*(R-1);
		}

		int col = C;
		while (true) {
			if (col >= W*2) {
				ans++;
				col = col-W;
			} else if (col < W*2 && col > W) {
				ans++;
				col = W;
			} else {
				ans = ans + col;
				break;
			}
		}

		output(t, ans);

	}

	static void output(int i, Object ans) {
		System.out.println("Case #" + i + ": " + ans);
	}
}