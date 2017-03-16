package round1A;

import java.io.BufferedOutputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;


public class A {

	public static void main(String args[]) {

		PrintStream printStream = null;
		try {
			printStream = new PrintStream(new BufferedOutputStream(new FileOutputStream("result/A-large.out")));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		System.setOut(printStream);

		Scanner scInput = new Scanner(System.in);
		solve(scInput);
		scInput.close();

		printStream.close();

	}

	private static void solve(Scanner scInput) {
		int T = scInput.nextInt() + 1;
		for(int i = 1 ; i < T ; i++) {
			String S = scInput.next();
			StringBuilder sb = new StringBuilder();
			sb.append(S.charAt(0));
			for (int j = 1 ; j < S.length() ; j++) {
				char current = S.charAt(j);
				if (sb.charAt(0) <= current) {
					sb.insert(0, current);
				} else {
					sb.append(current);
				}
			}

			System.out.format("Case #%d: %s\n", i, sb.toString());
		}
	}

}
