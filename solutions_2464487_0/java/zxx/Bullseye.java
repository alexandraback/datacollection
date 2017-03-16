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
			System.out.println("Case #" + (i + 1) + ": " + calc(r, t));
		}
	}

	private static long calc(long r, long t) {
		int res = 0;
		while (can(r, res, t)) {
			res++;
		}
		return res - 1;
	}

	private static boolean can(long r, long k, long t) {
		// double res = k * r * r + 2 * k * r * (2 * k - 3) + 2 * (k - 1) * k * (2 * k - 1) / 3.0;
		double res = 2 * k * r + (2 * k - 1) * k;
//		System.out.println(res);
		return res <= t;
	}

}
