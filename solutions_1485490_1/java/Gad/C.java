package r2;

import java.util.Arrays;
import java.util.Scanner;

public class C {
	static long dp[][] = new long[111][111], na, nb;
	static long nia[] = new long[111];
	static int typeia[] = new int[111];
	static long nib[] = new long[111];
	static int typeib[] = new int[111];

	private static long solve(int ia, int ib, long rema, long remb) {
		if (ia >= na || ib >= nb)
			return 0;
		if (dp[ia][ib] > -1)
			return dp[ia][ib];

		long res = 0, tmp = 0;
		if (typeia[ia] == typeib[ib]) {
			res += Math.min(nia[ia], nib[ib]);
			tmp = res;
			nia[ia] -= tmp;
			nib[ib] -= tmp;
		}
		res += Math.max(solve(ia + 1, ib, nia[ia + 1], remb - res),
				solve(ia, ib + 1, rema - res, nib[ib + 1]));
		nia[ia] += tmp;
		nib[ib] += tmp;
		return dp[ia][ib]=res;
	}

	public static void main(String[] args) {
		Scanner myScanner = new Scanner(System.in);
		for (int i = 0; i < dp.length; i++)
			Arrays.fill(dp[i], -1);
		int t = myScanner.nextInt(), cnt = 1;
		while (t-- > 0) {
			na = myScanner.nextInt();
			nb = myScanner.nextInt();
			for (int i = 0; i < na; i++) {
				nia[i] = myScanner.nextLong();
				typeia[i] = myScanner.nextInt();
			}
			for (int i = 0; i < nb; i++) {
				nib[i] = myScanner.nextLong();
				typeib[i] = myScanner.nextInt();
			}
			long res = solve(0, 0, nia[0], nib[0]);
			System.out.println("Case #" + cnt++ + ": " + res);
		}
	}
}
