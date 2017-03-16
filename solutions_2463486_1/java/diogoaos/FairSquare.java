import java.util.Collections;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;
import java.util.Vector;

public class FairSquare {

	private static String reverse(String s) {
		char[] c = s.toCharArray();
		int len = s.length();
		for (int i = 0; i < len / 2; i++) {
			char tmp = c[i];
			c[i] = c[len - i - 1];
			c[len - i - 1] = tmp;
		}
		return new String(c);
	}

	public static void main(String[] args) {
		Set<Long> palindromes = new TreeSet<Long>();
		
		for (int j = 1; j < 10; j++) {
			palindromes.add((long) j);
		}
		
		for (int i = 1; i < 10000; i++) {
			String s = String.valueOf(i);
			String r = reverse(s);

			palindromes.add(Long.parseLong(s + r));
			if ((s + r).length() < 8) {
				for (int j = 0; j < 10; j++) {
					palindromes.add(Long.parseLong(s + j + r));
				}
			}
		}

		Vector<Long> squares = new Vector<Long>();

		for (long l : palindromes) {
			long square = l * l;

			if (isPalindrome(String.valueOf(square))) {
				squares.add(square);
			}
		}

		Scanner sc = new Scanner(System.in);
		int ntests = sc.nextInt();

		for (int test = 1; test <= ntests; test++) {
			long A = sc.nextLong();
			long B = sc.nextLong();

			int la = lessThan(A, squares, false);
			int lb = lessThan(B, squares, true);

			System.out.println("Case #" + test + ": " + (lb - la));
		}
	}

	private static int lessThan(long key, Vector<Long> squares,
			boolean toInclude) {
		int pos = Collections.binarySearch(squares, key);

		if (pos < 0)
			return (-pos) - 1;
		else if (toInclude)
			return pos + 1;
		else
			return pos;
	}

	private static boolean isPalindrome(String str) {
		if (str.length() == 1) return true;
		return str.endsWith(reverse(str.substring(0, str.length() / 2)));
	}

}
