package cj;

import java.util.Scanner;

public class OminousOmino {

	static boolean isPossible(int X, int R, int C) {
		if (X >= 7)
			return false;
		if (R * C % X > 0) {
			return false;
		}
		int max = R > C ? R : C;
		int min = R > C ? C : R;
		if (X > max) {
			return false;
		}
		if (min < (X / 2) + 1) {
			return false;
		}

		return true;
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		int count = 0;
		while (T-- > 0) {
			count++;
			int X = scan.nextInt();
			int R = scan.nextInt();
			int C = scan.nextInt();

			boolean res = isPossible(X, R, C);
			String result = res ? "GABRIEL" : "RICHARD";
			System.out.println("Case #" + count + ": " + result);
		}
	}
}
