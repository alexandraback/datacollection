package qualif2013;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class CMain {

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new FileInputStream(new File("in.txt")));
		PrintWriter out = new PrintWriter(new BufferedOutputStream(
				new FileOutputStream(new File("out.txt"))), false);
		solve(in, out);
		out.flush();
		out.close();
	}

	public static boolean isPalindrom(String str) {
		for (int j = 0; j < str.length() / 2; j++) {
			if (str.charAt(j) != str.charAt(str.length() - j - 1)) {
				return false;
			}
		}
		return true;
	}

	static void solve(Scanner in, PrintWriter out) throws Exception {

		final int MAX = 10000000;
		long[] fairs = new long[MAX];
		int len = 0;

		for (long i = 1; i < MAX; i++) {
			if (i % 10 == 0)
				continue;
			if (isPalindrom(String.valueOf(i))
					&& isPalindrom(String.valueOf(i * i))) {
				fairs[len++] = i * i;
			}
		}

//		for (int i = 0; i < len; i++) {
//			System.out.println(((long) Math.sqrt(fairs[i])) + " --> " + fairs[i]);
//		}

		int cases = in.nextInt();
		for (int k = 1; k <= cases; k++) {
			long from = in.nextLong();
			long to = in.nextLong();

			int count = 0;
			for (int i = 0; i < len; i++) {
				if (from <= fairs[i] && fairs[i] <= to) {
					count++;
				}
			}
			out.println(String.format("Case #%d: %d", k, count));
		}
	}
}
