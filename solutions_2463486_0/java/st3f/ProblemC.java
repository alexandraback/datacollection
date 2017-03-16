import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;

public class ProblemC {
	static Scanner sc;
	static PrintStream ps;
	static BigInteger fsCount;

	static void nextCase() {
		BigInteger a = new BigInteger(sc.next());
		BigInteger b = new BigInteger(sc.next());

		fsCount = BigInteger.ZERO;
		BigInteger x = firstPalindrome(sqrt(a));
		BigInteger xSq = x.multiply(x);
		while (xSq.compareTo(b) <= 0) {
			if (isPalindrome(xSq))
				fsCount = fsCount.add(BigInteger.ONE);
			x = nextPalindrome(x);
			xSq = x.multiply(x);
		}
	}

	static void printSol() {
		ps.println(fsCount);
	}

	public static BigInteger sqrt(BigInteger n) {
		BigInteger xOld;
		BigInteger xNew = n;

		do {
			xOld = xNew;
			xNew = (xOld.multiply(xOld).add(n).divide(xOld.shiftLeft(1)));
		} while (xOld.subtract(xNew).compareTo(BigInteger.ONE) > 0);

		while (xNew.multiply(xNew).compareTo(n) > 0)
			xNew = xNew.subtract(BigInteger.ONE);
		while (xNew.multiply(xNew).compareTo(n) < 0)
			xNew = xNew.add(BigInteger.ONE);
		return xNew;
	}

	public static boolean isPalindrome(BigInteger n) {
		String s = n.toString();
		int i = 0;
		int j = s.length() - 1;
		while (i < j) {
			if (s.charAt(i) != s.charAt(j))
				return false;
			i++;
			j--;
		}
		return true;
	}

	public static BigInteger nextPalindrome(BigInteger n) {
		String s = n.toString();
		int l = s.length();

		boolean only9 = true;
		for (int i = 0; i < l / 2 + 1; i++)
			if (s.charAt(i) != '9') {
				only9 = false;
				break;
			}
		if (only9) {
			String r = "1";
			for (int i = 0; i < l - 1; i++)
				r += "0";
			r += "1";
			return new BigInteger(r);
		}

		s = s.substring(0, l / 2 + l % 2);
		s = new BigInteger(s).add(BigInteger.ONE).toString();
		for (int i = l / 2 - 1; i >= 0; i--)
			s += s.charAt(i);
		return new BigInteger(s);
	}

	static BigInteger firstPalindrome(BigInteger n) {
		if (isPalindrome(n))
			return n;
		String s = n.toString();
		int l = s.length();
		s = s.substring(0, l / 2 + l % 2);
		for (int i = l / 2 - 1; i >= 0; i--)
			s += s.charAt(i);
		BigInteger b = new BigInteger(s);
		if (b.compareTo(n) < 0)
			b = nextPalindrome(b);
		return b;
	}

	public static void main(String[] args) throws FileNotFoundException {
		sc = new Scanner(new File(args[0] + ".in"));
		ps = new PrintStream(args[0] + ".out");
		int t = sc.nextInt();
		sc.nextLine();

		for (int c = 1; c <= t; c++) {
			nextCase();
			ps.printf("Case #%d: ", c);
			printSol();
		}
	}
}
