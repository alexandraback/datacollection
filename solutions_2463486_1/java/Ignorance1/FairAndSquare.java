import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class FairAndSquare {

	static Set<BigInteger> set = new HashSet<BigInteger>();

	public static void main(String[] args) throws FileNotFoundException {
		precalc();
		Scanner sc = new Scanner(new File("input.txt"));
		int T = sc.nextInt();
		PrintWriter out = new PrintWriter(new File("output.txt"));
		for (int i = 0; i < T; i++) {
			String A = sc.next();
			String B = sc.next();
			BigInteger a = new BigInteger(A);
			BigInteger b = new BigInteger(B);
			long cnt = 0;
			for (BigInteger x : set) {
				BigInteger xx = x.multiply(x);
				if (xx.compareTo(a) >= 0 && xx.compareTo(b) <= 0) {
					cnt++;
				}
			}
			out.println("Case #" + (i + 1) + ": " + cnt);
		}
		out.close();
	}

	private static void precalc() {
		int n = 50;
		for (int digits = 1; digits <= n; digits++) {
			char[] num = new char[digits];
			if (digits == 1) {
				set.add(new BigInteger("1"));
				set.add(new BigInteger("2"));
				set.add(new BigInteger("3"));
			} else {
				int mid = digits / 2;
				for (int k = 0; k < (1 << mid); k++) {
					for (int j = 0; j < mid; j++) {
						if ((k & (1 << j)) > 0 || j == 0) {
							num[j] = '1';
							num[digits - j - 1] = '1';
						} else {
							num[j] = '0';
							num[digits - j - 1] = '0';
						}
					}
					for (char first = '1'; first <= '2'; first++) {
						num[0] = first;
						num[digits - 1] = first;
						if (digits % 2 != 0) {
							num[mid] = '0';
							check(first, num);
							num[mid] = '1';
							check(first, num);
							num[mid] = '2';
							check(first, num);
						} else {
							check(first, num);
						}
					}
				}
			}
		}
	}
	
	private static void check(char f, char[] num) {
		if (f == '2') {
			for (int k = 1; k < num.length / 2; k++) {
				if (num[k] != '0') {
					return;
				}
			}
		}else if (num.length >= 18) {
			int cnt1 = 0;
			for (int k = 0; k < num.length; k++) {
				if (num[k] == '1') {
					cnt1++;
				}
			}
			if (num.length > 18 && cnt1 > 12) {
				return;
			}
		}
		String s = new String(num);
		BigInteger b = new BigInteger(s);
		BigInteger bb = b.multiply(b);
		if (isPalindrome(bb.toString())) {
			set.add(b);
		}
	}

	private static boolean isPalindrome(String s) {
		for (int k = 0; k < s.length() / 2; k++) {
			if (s.charAt(k) != s.charAt(s.length() - k - 1)) {
				return false;
			}
		}
		return true;
	}

}
