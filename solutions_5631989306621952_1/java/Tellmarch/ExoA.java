package gcj2016.r1a;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ExoA {
	public static void main(final String[] args) {

		final String base = "/home/jfortin/workspace-gcj/Codejam2016/r1a/ExoA/";
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
			Logger.getLogger(ExoA.class.getName()).log(Level.SEVERE, null, ex);
		}

	}

	private static void test(final Scanner sc, final PrintWriter pw) {
		String S = sc.next();
		String r = "";
		for (int i = 0; i < S.length(); i++) {
			char c = S.charAt(i);
			String r1 = c + r;
			String r2 = r + c;
			if (r1.compareTo(r2) > 0) {
				r = r1;
			} else {
				r = r2;
			}
		}

		pw.print(r);

	}

}
