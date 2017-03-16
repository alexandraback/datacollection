/**
 * TODO
 * 
 * @version 1.0.0 2013 May 12, 2013<br>
 * @author Fan Liang <br>
 */
package jam;

import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class Consonants {
	private static boolean isVowle(char c) {
		switch (c) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return true;
		default:
			return false;
		}
	}

	static int factorial(int n) {
		if (n == 1) {
			return n;
		}
		return factorial(n - 1) * n;
	}

	private static int getOperN2(String s, Integer n) {
		ArrayList<Integer> lens = new ArrayList<Integer>();
		int t;
		int i, orig;
		for (i = 0, orig = 0; i < s.length(); i++) {
			if (isVowle(s.charAt(i))) {
				t = i - orig;
				if (t >= n) {
					lens.add(t - n + 1);
				}
				orig = i;
			}
		}
		t = i - orig - 1;
		if (t >= n) {
			lens.add(t - n + 1);
		}
		int sum = 0;
		for (Integer len : lens) {
			sum += factorial(len);
		}
		return sum;
	}

	static boolean isContain(String s, int n) {
		int t, i, orig;
		for (i = 0, orig = 0; i < s.length(); i++) {
			if (isVowle(s.charAt(i))) {
				t = i - orig;
				if (t >= n) {
					return true;
				}
				orig = i + 1;
			}
		}
		t = i - orig;
		if (t >= n) {
			return true;
		}
		return false;
	}

	private static int getOperN(String s, Integer n) {
		int sum = 0;
		for (int i = 0; i < s.length(); i++) {
			if (i + n > s.length()) {
				break;
			}
			for (int j = i + n; j <= s.length(); j++) {
				String subs = s.substring(i, j);
				if (isContain(subs, n)) {
					sum++;
				}
			}
		}
		return sum;
	}

	public static void main(String[] args) throws IOException {
		int case_num = 0, cnt = 1;
		Scanner scn = new Scanner(System.in);
		String str;
		Integer n;
		case_num = scn.nextInt();
		FileOutputStream fos = new FileOutputStream("out");
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(fos));
		while (cnt <= case_num) {
			str = scn.next();
			n = scn.nextInt();
			bw.write(String.format("Case #%d: %d\n", cnt++, getOperN(str, n)));
			// System.out.println(String.format("Case #%d: %d\n", cnt++,
			// getOperN(str, n)));
		}
		bw.close();
		fos.close();
	}
}
