package google.roundB;

import java.util.Arrays;
import java.util.Scanner;

public class A {
	static long[] memo;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for (int ii = 1; ii <= t; ii++) {
			long a = in.nextLong();
			int n = in.nextInt();
			memo = new long[n];
			for (int i = 0; i < n; i++) {
				memo[i] = in.nextLong();
			}
			Arrays.sort(memo);
			System.out.println("Case #" + ii + ": " + op(a, 0));
		}
	}

	static long op(long a, int ind) {
		if (ind == memo.length) {
			return 0;
		}
		if (memo[ind] < a) {
			a += memo[ind];
			return op(a, ind + 1);
		}
		long ans1 = op(a, ind + 1) + 1;
		if (a == 1) {
			return ans1;
		}
		long temp = 0;
		while (memo[ind] >= a) {
			a += (a - 1);
			temp++;
		}
		a += memo[ind];
		temp += op(a, ind + 1);
		return Math.min(ans1, temp);
	}

}
