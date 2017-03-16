import static java.lang.Integer.parseInt;
import static java.lang.Math.sqrt;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Square {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int total = parseInt(br.readLine());
//		long start = System.currentTimeMillis();
		for (int caseNum = 1; caseNum <= total; caseNum++) {
			String[] s = br.readLine().split(" ");
			long a = Long.parseLong(s[0].trim());
			long b = Long.parseLong(s[1].trim());
			System.out.println("Case #" + caseNum + ": " + count(a, b));
		}
//		System.out.println(System.currentTimeMillis()-start);
	}

	private static long count(long a, long b) {
		long qa = (long) Math.ceil(sqrt(a)), qb = (long) sqrt(b);
		long res = 0;
		for (long ll = qa; ll <= qb; ll++) {
			if (isPal(ll) && isPal(ll * ll)) {
				res++;
			}
		}
		return res;
	}

	private static boolean isPal(long ll) {
		char[] s = (ll + "").toCharArray();
		final int n = s.length;
		for (int i = 0; i < n / 2; i++) {
			if (s[i] != s[n - 1 - i]) {
				return false;
			}
		}
		return true;
	}
}
