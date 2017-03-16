package codejam2015.roud1b;

import java.io.FileOutputStream;
import java.io.PrintStream;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;
import java.util.regex.Pattern;

public class A {

	Scanner sc = new Scanner(getClass().getResourceAsStream(IN));
	static final String FILENAME = "A-small-attempt0";
	// static final String FILENAME = "A-small-attempt0";
	static final String IN = FILENAME + ".in";
	static final String OUT = FILENAME + ".out";
	PrintStream out;

	private void solve() {
		long s = sc.nextLong();
		String sString = s + "";
		long res = 1;
		long ans = 0;
		long ans5 = 0;
		int pow = 0;
		long sprime = s;
		while (res < s) {
			res *= 10;
			pow++;
		}

		if (s % 10 == 0) {
			ans5++;
			sprime--;
		}
		pow--;
		int mid = pow  / 2;
		res = res / 10;
		long ans1 = reverse(res + get(sprime, mid));
		long ans2 = get(sprime, mid) + (sprime - ans1) + 1 + ans5;
		if (s - res < ans2) {
			ans = s - res;
		} else {
			ans = ans2;
		}
		while (res > 10) {
			 mid = pow  / 2;
			if (pow % 2 == 0) {
				ans = ans + 2 * pow(mid) - 1;
			} else {
				ans = ans + pow(mid) + pow((mid + 1)) - 1;
			}

			res = res / 10;
			pow--;
		}
		ans += res;
		out.print(ans);
	}

	long reverse(long s) {
		String sString = s + "";
		String res = "";
		for (int i = sString.length() - 1; i >= 0; i--) {
			res += sString.charAt(i);
		}
		return Long.valueOf(res);
	}

	long pow(int pow) {
		long res = 1;
		for (int i = 0; i < pow; i++) {
			res *= 10;
		}
		return Long.valueOf(res);
	}

	long get(long s, int mid) {
		String sString = s + "";
		String res = "";
		for (int i = mid; i >= 0; i--) {
			res += sString.charAt(i);
		}
		if (res.equals(""))
			return 0;
		return Long.valueOf(res);
	}

	long getLast(long s, int mid) {
		String sString = s + "";
		String res = "";
		for (int i = mid + 1; i < sString.length(); i++) {
			res += sString.charAt(i);
		}
		if (res.equals(""))
			return 0;
		return Long.valueOf(res);
	}

	private void run() throws Exception {
		sc.useLocale(Locale.US);
		out = new PrintStream(new FileOutputStream(OUT));
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			sc.nextLine();
			out.print("Case #" + i + ": ");
			solve();
			out.println();
		}
		sc.close();
		out.close();
	}

	public static void main(String args[]) throws Exception {
		new A().run();
	}

}