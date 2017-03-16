import java.util.Scanner;

public class Enclosure {
	public int getMin(int m, int n, int k) {
		if (m <= 2 || n <= 2) return k;
		if (m > n) {
			int temp = m;
			m = n;
			n = temp;
		}
		int min = k;
		if (n == 3) {
			min -= k / 4;
		} else {
			if (k >= 4) min--;
			if (k >= 8) min--;
			if (k >= 10) min--;
			if (k >= 12) min--;
			if (k >= 14) min--;
			if (k >= 16) min--;
		}
		return min;
	}
	public static void main(String[] args) {
		try (final Scanner in = new Scanner(System.in)) {
			final int t = Integer.parseInt(in.nextLine());
			for (int i = 1; i <= t; i++) {
				System.out.printf("Case #%s: %s%n", i, new Enclosure().getMin(in.nextInt(), in.nextInt(), in.nextInt()));
			}
		}
	}
}
