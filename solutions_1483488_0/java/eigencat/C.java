import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class C {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner scan = new Scanner(new File("C-small-attempt0.in"));
		System.setOut(new PrintStream("C-small-attempt0.out"));

		int t = scan.nextInt();
		for (int c = 0; c < t; c++) {
			int a = scan.nextInt();
			int b = scan.nextInt();
			int ans = 0;
			int[] bDigits = digits(b);

			for (int n = a; n < b; n++) {
				int[] nDigits = digits(n);
				int digitCount = nDigits.length;
				Set<Integer> done = new HashSet<Integer>();
				for (int i = 1; i < digitCount; i++) {
					int[] mDigits = rotate(nDigits, i);
					int m = normal(mDigits);
					if (isLess(nDigits, mDigits) && isLessEq(mDigits, bDigits)
					        && !done.contains(m)) {
						ans++;
						done.add(m);
						/*
						 * if (c == 3) { if (normal(nDigits) != n) throw new
						 * AssertionError(); System.out.println(n + " " + m); if
						 * (n < a || n >= m || m > b) throw new
						 * AssertionError(); }
						 */
					}
				}
			}

			System.out.printf("Case #%d: %d%n", c + 1, ans);
		}
	}

	private static int[] digits(int n) {
		int num = 0;
		int temp = n;
		while (temp > 0) {
			num++;
			temp /= 10;
		}

		int[] dig = new int[num];
		temp = n;
		for (int i = 0; i < num; i++) {
			dig[num - i - 1] = temp % 10;
			temp /= 10;
		}
		return dig;
	}

	private static int[] rotate(int[] num, int r) {
		int n = num.length;
		int[] ans = new int[n];
		for (int i = 0; i < r; i++) {
			ans[i] = num[n - r + i];
		}
		for (int i = 0; i < n - r; i++) {
			ans[r + i] = num[i];
		}
		return ans;
	}

	private static int normal(int[] num) {
		int base = 1;
		int ans = 0;
		for (int i = 0; i < num.length; i++) {
			ans += num[num.length - 1 - i] * base;
			base *= 10;
		}
		return ans;
	}

	private static boolean isLess(int[] a, int[] b) {
		for (int i = 0; i < a.length; i++) {
			if (a[i] < b[i])
				return true;
			if (a[i] > b[i])
				return false;
		}
		return false;
	}

	private static boolean isLessEq(int[] a, int[] b) {
		for (int i = 0; i < a.length; i++) {
			if (a[i] < b[i])
				return true;
			if (a[i] > b[i])
				return false;
		}
		return true;
	}
}