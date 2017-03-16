import java.io.BufferedReader;
import java.io.FileReader;
import java.math.BigInteger;

public class FairAndSquare {

	public static void main(String[] args) throws Exception {
		/*
		 * Scanner s = new Scanner(System.in); while(true){ BigInteger b = new
		 * BigInteger(s.nextLine());
		 * System.out.println(minPalindrom(b).value());
		 * 
		 * if(s==null){ break; } }
		 */

		String filename = "C-large-1.in";
		BufferedReader in = new BufferedReader(new FileReader(filename));

		int T = Integer.parseInt(in.readLine());

		for (int test = 1; test <= T; test++) {
			String[] tokens = in.readLine().split(" ");
			BigInteger A = new BigInteger(tokens[0]);
			BigInteger B = new BigInteger(tokens[1]);
			System.out.println("Case #" + test + ": " + solve(A, B));
		}
		in.close();
	}

	private static long solve(BigInteger A, BigInteger B) {
		//System.out.println("Solving from "+A+" to "+B);
		BigInteger a = sqrt(A);
		BigInteger b = sqrt(B);
		if (a.multiply(a).compareTo(A) < 0) {
			a = a.add(BigInteger.ONE);
		}
		//System.out.println("Sqrt from "+a+" to "+b);
		Palindrome p = minPalindrom(a);
		a = p.value();
		long count = 0;
		while (a.compareTo(b) <= 0) {
			if (isPalindrome(a.multiply(a).toString())) {
				count++;
			}
			p.inc();
			a = p.value();
		}
		return count;
	}

	private static boolean isPalindrome(String str) {
		char[] c = str.toCharArray();
		for (int i = 0; i < c.length / 2; i++) {
			if (c[i] != c[c.length - 1 - i]) {
				return false;
			}
		}
		return true;
	}

	private static Palindrome minPalindrom(BigInteger a) {
		String str = a.toString();
		BigInteger base;
		boolean odd;
		if (str.length() % 2 == 0) {
			String str1 = str.substring(0, str.length() / 2);
			base = new BigInteger(str1);
			odd = false;
		} else {
			String str1 = str.substring(0, str.length() / 2 + 1);
			base = new BigInteger(str1);
			odd = true;
		}
		Palindrome p = new Palindrome(base, odd);

		if (p.value().compareTo(a) < 0) {
			p.inc();
		}

		return p;
	}

	private static class Palindrome {
		BigInteger base;
		String baseStr;
		boolean odd;

		public Palindrome(BigInteger base, boolean odd) {
			this.base = base;
			this.baseStr = base.toString();
			this.odd = odd;
		}

		public BigInteger value() {
			String str2 = reverse(baseStr);
			if (odd) {
				str2 = str2.substring(1);
			}
			return new BigInteger(baseStr + str2);
		}

		public void inc() {
			int oldLength = baseStr.length();
			base = base.add(BigInteger.ONE);
			baseStr = base.toString();
			if (baseStr.length() > oldLength) {
				if (odd) {
					base = base.divide(BigInteger.TEN);
					baseStr = base.toString();
					odd = false;
				} else {
					odd = true;
				}
			}
		}

		private String reverse(String str) {
			char[] c = str.toCharArray();
			for (int i = 0; i < c.length / 2; i++) {
				char temp = c[i];
				c[i] = c[c.length - 1 - i];
				c[c.length - 1 - i] = temp;
			}
			return new String(c);
		}
	}

	public static BigInteger sqrt(BigInteger num) {
		BigInteger min = BigInteger.ONE;
		BigInteger max = BigInteger.ONE;
		while (max.multiply(max).compareTo(num) <= 0) {
			max = max.shiftLeft(1);
		}

		BigInteger mid;
		BigInteger midSqr;

		while (max.subtract(min).compareTo(BigInteger.ONE) > 0) {
			mid = min.add(max).shiftRight(1);
			midSqr = mid.multiply(mid);
			switch (midSqr.compareTo(num)) {
			case 0:
				return mid;
			case 1:
				max = mid;
				break;
			case -1:
				min = mid;
				break;
			}
		}
		return min;
	}

}
