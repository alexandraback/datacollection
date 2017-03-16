package gcj.y2015.r1c;

import java.io.File;
import java.util.Scanner;

public class MainB {

	static int t;

	public static void main(String[] args) throws Exception {
		// 問題の読み込み
		Scanner sc = new Scanner(new File("src/in.txt"));

		int T = sc.nextInt();

		for (t=1; t<=T; t++) {

			int K = sc.nextInt();
			int L = sc.nextInt();
			int S = sc.nextInt();

			String keys = sc.next();
			String targets = sc.next();

			solve(K, L, S, keys, targets);

		}
	}

	static void solve(int K, int L, int S, String keys, String targets) {
		// keyが十分かチェック
		for (int i=0; i<L; i++) {
			String let = targets.substring(i,i+1);

			int num = keys.indexOf(let);
			if (num == -1) {
				output(t, 0.0);
				return;
			}
		}

		// keyが十分なら以下を実施
		int max = 0;

		int count = 1;
		for (int i=0; i<S; i++) {
			count = count * K;
		}

		double avg = 0;

		int[] P = new int[S];
		for (int i=0; i<count; i++) {
			// 文字列のインデックスを作る
			int tmp = i;
			for (int j=0; j<S; j++) {
				P[j] = tmp%K;
				tmp = tmp/K;
			}

			String result = "";

			for (int j=0; j<S; j++) {
				result = result.concat(keys.substring(P[j],P[j]+1));
			}

			// resultに含まれるtargetの数を確認
			int banana = 0;
			while (true) {
				int num = result.indexOf(targets);
				if (num == -1) {
					break;
				} else {
					avg = avg+1;
					banana = banana+1;
					result = result.substring(num+1, result.length());
				}
			}

			if (banana > max) {
				max = banana;
			}
		}

		// 答え
		double exp = avg/count;
		double ans = max - exp;

		output(t, ans);
	}

	static void output(int t, Object ans) {
		System.out.printf("Case #%d: %1.9f", t, ans);
		System.out.println("");
	}
}