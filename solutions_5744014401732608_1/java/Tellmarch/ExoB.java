package gcj2016.r1c;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ExoB {
	private static final BigInteger TWO = BigInteger.valueOf(2);

	public static void main(final String[] args) {

		final String base = "/home/jfortin/workspace-gcj/Codejam2016/r1c/ExoB/";
		final String input = base + "b1.in";
		final String output = base + "b1.out";

		try {
			final Scanner sc = new Scanner(new FileReader(input));
			final PrintWriter pw = new PrintWriter(output);

			final int n = sc.nextInt();
			sc.nextLine();
			for (int c = 0; c < n; c++) {
				System.out.println("Test case " + (c + 1) + "...");
				pw.print("Case #" + (c + 1) + ": ");
				test(sc, pw);
				pw.println();
			}
			pw.println();
			pw.flush();
			pw.close();
			sc.close();
		} catch (final FileNotFoundException ex) {
			Logger.getLogger(ExoB.class.getName()).log(Level.SEVERE, null, ex);
		}

	}

	private static void test(final Scanner sc, final PrintWriter pw) {
		int B = sc.nextInt();
		BigInteger M = new BigInteger(sc.next());

		BigInteger max = BigInteger.ONE;
		BigInteger p = BigInteger.ONE;
		BigInteger k = BigInteger.ONE;
		for (int i = B - 2; i > 0; i--) {
			p = p.multiply(BigInteger.valueOf(i)).divide(k);
			max = max.add(p);
			k = k.add(BigInteger.ONE);
		}

		System.out.println(max.toString());

		if (M.compareTo(TWO.pow(B - 2)) > 0) {
			pw.print("IMPOSSIBLE");
			return;
		}

		int[][] mat = new int[B][B];
		for (int i = 0; i < B; i++) {
			for (int j = 0; j < B; j++) {
				if (i < j) {
					mat[i][j] = 1;
				}
			}
		}

		String string = M.subtract(BigInteger.ONE).toString(2);
		System.out.println(string);

		while (string.length() < B - 1) {
			string = "0" + string;
		}

		if (M.mod(TWO).equals(BigInteger.ZERO) || M.equals(BigInteger.ONE)) {
			string = string + "1";
		} else {
			string = string + "1";
		}

		pw.println("POSSIBLE");

		pw.println(string);

		for (int i = 1; i < B; i++) {
			for (int j = 0; j < B; j++) {
				pw.print(Character.valueOf((char) ('0' + mat[i][j])));
			}
			if (i < B - 1) {
				pw.println();
			}
		}

	}

}
