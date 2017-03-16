package Quali;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Locale;
import java.util.Scanner;

public class ProblemD {

	static final String rich = "RICHARD";
	static final String gab = "GABRIEL";

	public static void solve(Scanner sc) {
		int X = sc.nextInt();
		int R = sc.nextInt();
		int C = sc.nextInt();
		if (R < C) {
			int tmp = R;
			R = C;
			C = tmp;
		}
		// pick one with a hole
		if (X > 6) {
			System.out.println(rich);
			return;
		}
		if (R * C % X != 0) {
			System.out.println(rich);
			return;
		}
		// always win
		if (X < 3) {
			System.out.println(gab);
			return;
		}
		// build one that does not fit
		for (int x = 1; x <= X; x++) {
			if ((x > R || (X + 1 - x) > C) && (x > C || (X + 1 - x) > R)) {
				System.out.println(rich);
				return;
			}
		}
		if (X == 3) {
			System.out.println(gab);
		}
		if (X == 4) {
			if (C == 2) {
				System.out.println(rich);
			} else {
				System.out.println(gab);
			}
		}
		if (X == 5) {
			if (C == 2 && R == 5) {
				System.out.println(rich);
			} else {
				System.out.println(gab);
			}
		}
		if (X == 6) {
			if (C < 4) {
				System.out.println(rich);
			} else {
				System.out.println(gab);
			}
		}
	}

	public static void main(String[] args) throws FileNotFoundException {
		// Scanner sc = new Scanner(new File("D-practice.in"));
		Scanner sc = new Scanner(new File("D-small-attempt1.in"));
		// Scanner sc = new Scanner(new File("D-large.in"));
		sc.useLocale(Locale.US);
		int cases = sc.nextInt();

		for (int i = 1; i <= cases; i++) {
			System.out.format(Locale.US, "Case #%d: ", i);
			solve(sc);
		}
		sc.close();
	}
}
