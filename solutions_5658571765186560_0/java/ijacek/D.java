package R0;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Locale;
import java.util.Scanner;

// Ominous Omino
public class D {

	private static Scanner sc;
	private static PrintStream out;

	private static boolean check(int a, int b, int ma, int mb) {
		return a >= ma && b >= mb;
	}

	private static boolean sol(int X, int R, int C) {
		int a = Math.max(R, C);
		int b = Math.min(R, C);
		if ( (R * C) % X > 0 )
			return false;
		if ( X < 3 )
			return true;

		return check(a, b, X, X - 1);
	}

	public static void main(String[] args) throws FileNotFoundException {
		Locale.setDefault(Locale.ROOT);

		String file = "src/R0/D.sm";
		sc = new Scanner(new FileInputStream(file + ".in"));
		out = new PrintStream(file + ".out");

		int TC = ni();
		for (int i = 1; i <= TC; i++)
			out.println(String.format("Case #%d: %s", i, sol(ni(), ni(), ni()) ? "GABRIEL" : "RICHARD"));
	}

	private static int ni() {
		return sc.nextInt();
	}
}
