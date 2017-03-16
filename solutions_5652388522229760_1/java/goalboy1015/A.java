import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			System.out.print("Case #" + tc + ": ");

			long N = sc.nextLong();
			if (N == 0) {
				System.out.println("INSOMNIA");
			} else {
				System.out.println(solve(N));
			}
		}

		sc.close();
	}

	static long solve(long N) {
		boolean[] seens = new boolean[10];
		int seenNum = 0;

		long number = 0;
		while (seenNum < seens.length) {
			number += N;
			for (char ch : String.valueOf(number).toCharArray()) {
				int digit = ch - '0';
				if (!seens[digit]) {
					seens[digit] = true;
					seenNum++;
				}
			}
		}
		return number;
	}
}
