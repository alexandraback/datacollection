import static java.lang.Integer.parseInt;
import static java.lang.Math.sqrt;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Square {
	private static ArrayList<Long> res = new ArrayList<Long>();

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int total = parseInt(br.readLine());
		count(1, 100000000000000L);
		// long start = System.currentTimeMillis();
		for (int caseNum = 1; caseNum <= total; caseNum++) {
			String[] s = br.readLine().split(" ");
			long a = Long.parseLong(s[0].trim());
			long b = Long.parseLong(s[1].trim());
			int count = 0;
			for (long ll : res) {
				if (ll >= a && ll <= b) {
					count++;
				}
			}
			System.out.println("Case #" + caseNum + ": " + count);
		}
		// System.out.println(System.currentTimeMillis()-start);
	}

	private static void count(long a, long b) {
		long qa = (long) Math.ceil(sqrt(a)), qb = (long) sqrt(b);
		for (long ll = qa; ll <= qb; ll++) {
			if (isPal(ll) && isPal(ll * ll)) {
				// System.out.println(ll + ", " + ll * ll);
				res.add(ll * ll);
			}
		}
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
