package b;

import java.util.Scanner;

public class B {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		sc.nextLine();

		int nbr = 1;
		while (t-- > 0) {
			int n = sc.nextInt();
			int s = sc.nextInt();
			int p = sc.nextInt();

			int[] total = new int[n];

			int clear = (p - 1) * 2 + p;
			int specialClear = (p - 2) * 2 + p;

			int score = 0;

			for (int i = 0; i < total.length; i++) {
				int j = sc.nextInt();
				if (j < p) {
					continue;
				}
				if (j >= clear) {
					score++;
				} else if (j >= specialClear && s > 0) {
					score++;
					s--;
				}
			}

			System.out.printf("Case #%d: %d\n", nbr++, score);
		}
	}
}
