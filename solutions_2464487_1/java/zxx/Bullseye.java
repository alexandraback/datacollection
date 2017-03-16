import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Bullseye {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			String[] s = br.readLine().split(" ");
			long r = Long.parseLong(s[0]), t = Long.parseLong(s[1]);
			System.out.println("Case #" + (i + 1) + ": " + calc2(r, t));
		}
	}

	private static long calc(long r, long t) {
		int res = 0;
		while (can(r, res, t)) {
			res++;
		}
		return res - 1;
	}

	private static long calc2(long r, long t) {
		long left = 0, right = 100000000000L;
		while (left <= right) {
			long mid = (left + right) / 2;
			if (can(r, mid, t)) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		return left - 1;
	}

	private static boolean can(long r, long k, long t) {
		double res = 2.0 * k * r + (2.0 * k - 1) * k;
		return res <= t;
	}
}
