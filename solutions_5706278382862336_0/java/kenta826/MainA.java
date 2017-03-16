package gcj.r1c;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class MainA {

	static long[] pow2;

	public static void main(String[] args) throws FileNotFoundException {
		// 問題の読み込み
		Scanner sc = new Scanner(new File("src/in.txt"));

		pow2 = new long[41];
		long l = 1;
		for (int i=0; i<pow2.length; i++) {
			pow2[i] = l<<i;
		}
		int T = sc.nextInt();

		for (int t=1; t<=T; t++) {
			String PQ = sc.next();

			String[] strs = PQ.split("/");
			long P = Long.parseLong(strs[0]);
			long Q = Long.parseLong(strs[1]);

			output(t, solve(P, Q));
		}

	}

	static int solve(long P, long Q) {
		int ret = -1;

		for (int i=0; i<pow2.length; i++) {
			if (Q == pow2[i]) {
				ret = i;
			}
		}

		long p;
		int minus = 0;
		for (int i=0; i<pow2.length; i++) {
			p = P >> i;

			if (p > 0) {
				minus = i;
			} else {
				break;
			}
		}

		return ret - minus;
	}

	static void output(int i, int ans) {
		if (ans >= 0)
			System.out.println("Case #" + i + ": " + ans);
		else
			System.out.println("Case #" + i + ": " + "impossible");
	}
}