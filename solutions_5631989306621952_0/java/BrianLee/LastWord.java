
package codejam2016;

import java.io.File;
import java.util.Scanner;

import codejam2015.Haircut;


public class LastWord {

	private static boolean DEBUG = false;


	private String solve(String S) {

		int n = S.length();
		if (n == 1)
			return S;

		String ret = "";

		ret = ret + S.charAt(0);
		for (int i = 1; i < n; i++) {
			char c = S.charAt(i);

			char first = ret.charAt(0);

			if (first <= c)
				ret = c + ret;
			else
				ret = ret + c;
		}

		return ret;
	}

	private void solvePrint(String S) {

		String ret = solve(S);

		System.out.format("%s => %s\n", S, ret);
	}


	private void solve(Scanner sc) {
		int T = sc.nextInt();

		for (int i = 0; i < T; i++) {
			String s = sc.next();

			String ret = solve(s);

			System.out.format("Case #%d: %s\n", i+1, ret);
		}
	}


	public static void main(String[] args) throws Exception {

		Scanner sc = null;

		LastWord lw = new LastWord();

		if (args.length == 1) {
			sc = new Scanner(new File(args[0]));

			lw.solve(sc);
		}
		else {
			lw.solvePrint("CODE");
			lw.solvePrint("C");
			lw.solvePrint("ABCABCABC");
			lw.solvePrint("ZXCASDQWE");
			lw.solvePrint("CABCBBABC");
			lw.solvePrint("JAM");
		}
	}
}
