import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Cbits {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner scan = new Scanner(new File("C-large.in"));
		System.setOut(new PrintStream("C-large.out"));

		int t = scan.nextInt();
		for (int c = 0; c < t; c++) {
			int a = scan.nextInt();
			int b = scan.nextInt();
			int ans = 0;
			int bDigits = digits(b);

			for (int n = a; n < b; n++) {
				int nDigits = digits(n);
				int nDigitCount = numDigits(n);
				Set<Integer> done = new HashSet<Integer>();
				for (int i = 1; i < nDigitCount; i++) {
					int mDigits = rotate(nDigits, nDigitCount, i);
					if (nDigits < mDigits && mDigits <= bDigits
					        && !done.contains(mDigits)) {
						ans++;
						done.add(mDigits);
					}
				}
			}

			System.out.printf("Case #%d: %d%n", c + 1, ans);
		}
	}

	private static int numDigits(int n) {
		int num = 0;
		int temp = n;
		while (temp > 0) {
			num++;
			temp /= 10;
		}
		return num;
	}

	private static int digits(int n) {
		int num = numDigits(n);

		int digits = 0;
		int temp = n;
		for (int i = 0; i < num; i++) {
			digits |= (temp % 10) << i * 4;
			temp /= 10;
		}
		return digits;
	}

	private static int rotate(int nDigits, int digitCount, int r) {
		int rotPartMask = (1 << r * 4) - 1;
		int rotPart = nDigits & rotPartMask;

		int ans = nDigits;
		ans >>>= r * 4;
		ans |= rotPart << (digitCount - r) * 4;

		return ans;
	}

	private static int normal(int n, int digitCount) {
		int base = 1;
		int ans = 0;
		for (int i = 0; i < digitCount; i++) {
			int mask = 0b1111 << i * 4;
			int digit = (n & mask) >>> i * 4;
			ans += digit * base;
			base *= 10;
		}
		return ans;
	}
}