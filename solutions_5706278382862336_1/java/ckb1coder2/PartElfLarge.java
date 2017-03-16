import java.util.Scanner;

public class PartElfLarge {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		long P, Q;
		int i, j, k;
		String str[];
		boolean isPossible;
		int ans;
		long num;
		long value;
		int arr[];
		int index;
		long gcd;

		for (k = 0; k < T; k++) {
			str = scanner.next().split("/");
			P = Long.parseLong(str[0]);
			Q = Long.parseLong(str[1]);
			arr = new int[64];

			gcd = GCD(Math.max(P, Q), Math.min(P, Q));

			P /= gcd;
			Q /= gcd;

			isPossible = false;
			ans = 0;
			value = 1;
			index = 0;
			while (value <= Q) {
				if (value == Q) {
					isPossible = true;
					break;
				}
				value *= 2;
				index++;
			}

			if (isPossible == true) {
				num = P;
				for (i = 0; i < 64; i++) {
					arr[i] = 0;
				}
				for (i = index; i >= 0; i--) {
					arr[i] = (int) ((num >> i) & 1);
					if (arr[i] == 1) {
						ans = index - i;
						break;
					}
				}

				System.out.println("Case #" + (k + 1) + ": " + ans);
			} else {
				System.out.println("Case #" + (k + 1) + ": impossible");
			}
		}
	}

	public static long GCD(long a, long b) {
		if (b == 0)
			return a;
		return GCD(b, a % b);
	}
}

// To submit