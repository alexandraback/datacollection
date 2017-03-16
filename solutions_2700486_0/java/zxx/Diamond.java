import static java.lang.Integer.parseInt;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Diamond {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = parseInt(br.readLine());
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			String[] s = br.readLine().split(" ");
			int n = parseInt(s[0]), x = parseInt(s[1]), y = parseInt(s[2]);
			System.out.println("Case #" + caseNum + ": " + calc(n, x, y));
		}
	}

	public static double calc(int n, int x, int y) {
		int sum = 1;
		int base = 1;
		for (;; base += 2) {
			if (sum + base + 1 + base + 2 > n) {
				break;
			}
			sum += base + 1 + base + 2;
		}
		if (x < 0) {
			x = -x;
		}
		int p = x + y;
		if (p <= base - 1) {
			return 1.0;
		}
		if (p >= base + 3) {
			return 0;
		}
		int remain = n - sum;
		if (remain == 0 || x == 0) {
			return 0.0;
		}
		int k = y + 1;
		double res = 0;
		for (int i = k; i <= remain; i++) {
			res += comb(remain, i) / Math.pow(2, remain);
		}
		return res;
	}

	static double comb(int n, int r) {
		if (r == 0) {
			return 1;
		}
		if (r > n / 2) {
			r = n - r;
		}
		double res = 1;
		// int base = 1;
		for (int i = n; i >= n - r + 1; i--) {
			res *= i;
			// while (base <= r && res % base == 0) {
			// res /= base;
			// base++;
			// }
		}
		for (int i = r; i >= 1; i--) {
			res /= i;
		}
		return res;
	}
}
