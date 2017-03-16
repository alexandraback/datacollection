import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class A {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = parseInt(br.readLine());
		// StringTokenizer tok;
		for (int ii = 1; ii <= T; ii++) {
			long P, Q;
			String[] parts = br.readLine().split("[/]");
			P = parseLong(parts[0]);
			Q = parseLong(parts[1]);
			long g = gcd(P, Q);
			int res = solve(P / g, Q / g);
			System.out.printf("Case #%d: %s\n", ii, res == -1 ? "impossible"
					: Long.toString(res));
		}
	}

	private static int solve(long P, long Q) {
		if (isPowerOf2(Q) == false) {
			return -1;
		}
		int res = 0;
		while (P / Q < 1) {
			++res;
			P <<= 1;
		}
		return res;
	}

	private static boolean isPowerOf2(long n) {
		long mod = n & 1;
		if (mod == 1) {
			return false;
		}
		n >>= 1;
		while (n > 1) {
			mod = n & 1;
			if (mod == 1) {
				return false;
			}
			n >>= 1;
		}
		return true;
	}

	static long gcd(long max, long min) {
		if (max < min) {
			long tmp = max;
			max = min;
			min = tmp;
		}
		if (min == 0) {
			return max;
		}
		return gcd(min, max % min);
	}

}
