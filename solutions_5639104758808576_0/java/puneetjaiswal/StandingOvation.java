package cj;

import java.util.Scanner;

public class StandingOvation {

	static int minRequired(String shynessness) {
		int total = 0;
		int sumTillI = 0;

		for (int i = 0; i < shynessness.length(); i++) {
			int ch = shynessness.charAt(i) - '0';
			if (ch > 0) {
				if (sumTillI < i) {
					int delta = i - sumTillI;
					total += delta;
					sumTillI += delta;
				}
			}
			sumTillI += ch;
		}
		return total;
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		int count = 0;
		while (T-- > 0) {
			count++;
			int useless = scan.nextInt();
			String useful = scan.next();
			System.out.println("Case #" + count + ": " + minRequired(useful));
		}
		System.out.println();
	}
}
