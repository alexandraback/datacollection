import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class C {
	public static void main(String args[]) throws Exception {
		Scanner in = new Scanner(new File("in.txt"));
		BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));
		int T = in.nextInt();

		for (int X = 1; X <= T; X++) {
			String A = in.next();
			String B = in.next();

			BigInteger AA = new BigInteger(A);
			BigInteger BB = new BigInteger(B);

			String low = "1";
			for (int n = 0; n < (A.length() + 1) / 2 - 1; n++) {
				low += "0";
			}
			low = low.substring(0, low.length() - 1) + "1";
			int count = 0;
			if (AA.compareTo(new BigInteger("9")) <= 0
					&& BB.compareTo(new BigInteger("9")) >= 0) {
				count++;
			}
			while (true) {
				BigInteger b = new BigInteger(low);
				b = b.pow(2);
				if (b.compareTo(AA) < 0) {
					low = nextPal(low);
					continue;
				}
				if (b.compareTo(BB) > 0) {
					break;
				}
				String s = b.toString();
				if (isPal(s)) {
					count++;
				}
				low = nextPal(low);
			}

			out.write("Case #" + X + ": " + count + "\n");
		}

		in.close();
		out.close();
	}

	public static boolean isPal(String s) {
		while (s.length() > 1) {
			if (s.charAt(0) != s.charAt(s.length() - 1)) {
				return false;
			}
			s = s.substring(1, s.length() - 1);
		}
		return true;
	}

	public static String nextPal(String s) {
		int len = s.length();
		if (len % 2 == 0) {
			s = s.substring(0, s.length() / 2);
		} else {
			s = s.substring(0, s.length() / 2 + 1);
		}
		int len2 = s.length();
		BigInteger b = new BigInteger(s).add(BigInteger.ONE);
		while(b.toString().matches("[3-9]")) {
			b = b.add(BigInteger.ONE);
		}
		s = b.toString();
		int len3 = s.length();

		if (len3 > len2) {
			if (len % 2 == 0) {
				s = s + reverse(s.substring(0, s.length() - 1));
			} else {
				s = s.substring(0, s.length() - 1)
						+ reverse(s.substring(0, s.length() - 1));
			}
		} else {
			if (len % 2 == 0) {
				s = s + reverse(s);
			} else {
				s = s + reverse(s.substring(0, s.length() - 1));
			}
		}

		return s;
	}

	public static String reverse(String s) {
		// System.out.println(3);
		String r = "";
		for (int n = 0; n < s.length(); n++) {
			r = s.charAt(n) + r;
		}
		return r;
	}

}