import java.util.Scanner;

public class Main {
	private static int[][] multiply = { { 0, 1, 2, 3, 4, 5, 6, 7 }, { 1, 4, 3, 6, 5, 0, 7, 2 },
			{ 2, 7, 4, 1, 6, 3, 0, 5 }, { 3, 2, 5, 4, 7, 6, 1, 0 }, { 4, 5, 6, 7, 0, 1, 2, 3 },
			{ 5, 0, 7, 2, 1, 4, 3, 6 }, { 6, 3, 0, 5, 2, 7, 4, 1 }, { 7, 6, 1, 0, 3, 2, 5, 4 } };

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			long L = sc.nextLong(), X = sc.nextLong();
			int result = 0;
			char[] str = sc.next().toCharArray();
			boolean i = false, j = false, k = false;
			for (int x = 0; x < Math.min(8, X); x++) {
				for (char c : str) {
					result = multiply[result][c - 'i' + 1];
					if (result == 1) {
						i = true;
					} else if (result == 3 && i) {
						j = true;
					}
				}
				if (x == 0) {
					k = result(result, X) == 4;
				}
			}
			System.out.println("Case #" + t + ": " + (j && k ? "YES" : "NO"));
		}
		sc.close();
	}

	private static int result(int base, long power) {
		if (power == 0) {
			return 0;
		} else {
			int result = result(base, power / 2);
			return multiply[multiply[result][result]][power % 2 == 0 ? 0 : base];
		}
	}
}