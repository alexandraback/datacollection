import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

public class HappyEnergy {
	private static List<Integer> v = new ArrayList<>();
	private static int maxE;

	/**
	 * bruteforce lol
	 */
	public static void main(String[] args) {
		int t, n, r;
		Scanner sc = new Scanner(System.in);
		t = sc.nextInt();
		for (int _ = 1; _ <= t; _++) {
			maxE = sc.nextInt();
			r = sc.nextInt();
			n = sc.nextInt();
			v.clear();
			for (int i = 0; i < n; i++) {
				v.add(sc.nextInt());
			}
			System.out.println("Case #" + _ + ": " + getHappyPoints(0, n, maxE, maxE + (n - 1L) * r, r));
		}
	}

	private static long getHappyPoints(int l, int h, int e, long d, int r) {
		if (d <= 0 || l == h) {
			return 0;
		}
		int maxi = 0;
		long max = 0;
		for (int i = l; i < h; i++) {
			if (v.get(i) > max) {
				maxi = i;
				max = v.get(i);
			}
		}
		if (d > maxE) {
			return max * maxE + getHappyPoints(l, maxi, e, d - maxE, r) + getHappyPoints(maxi + 1, h, r, r + (h - (maxi + 1) - 1) * r, r);
		} else {
			return max * d;
		}
	}
}
