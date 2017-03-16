import java.io.File;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Locale;
import java.util.Scanner;
import java.util.Set;

public class B {

	private static boolean sameChar(String s, char c) {
		for (int j = 0; j < s.length(); j++)
			if (s.charAt(j) != c)
				return false;
		return true;
	}

	private static boolean checkStr(String str) {
		int i = 0;
		Set<Character> used = new HashSet<>();

		while (i < str.length()) {
			char c = str.charAt(i);
			if (used.contains(c)) {
				return false;
			}
			used.add(c);
			i++;
			while (i < str.length() && str.charAt(i) == c) {
				i++;
			}
		}
		return true;

	}

	private static long findSame(String[] cars, char c, boolean[] used) {
		long count = 0;

		for (int i = 0; i < cars.length; i++)

			if (!used[i] && sameChar(cars[i], c)) {
				used[i] = true;
				count++;
			}
		return count;
	}

	private static String findStartsWith(String[] cars, char c, boolean[] used) {

		for (int i = 0; i < cars.length; i++)
			if (!used[i] && cars[i].charAt(0) == c) {
				used[i] = true;
				return cars[i];
			}
		return null;
	}

	private static String findEndsWith(String[] cars, char c, boolean[] used) {

		for (int i = 0; i < cars.length; i++)
			if (!used[i] && cars[i].endsWith(String.valueOf(c))) {
				used[i] = true;
				return cars[i];
			}
		return null;
	}

	private static long factorial(long n) {
		long res = 1;
		for (long i = 2; i <= n; i++)
			res = (res * i) % 1000000007;
		return res;
	}

	private static String str;

	private static long calc(String[] cars, boolean[] used, boolean left,
			boolean right) {
		if (!left && !right)
			return 1;

		char c = str.charAt(0);
		char cn = str.charAt(str.length() - 1);

		long countSame1 = 0;
		long countSame2 = 0;
		String aLeft = null;
		String aRight = null;

		if (left) {
			countSame1 = findSame(cars, c, used);
			aLeft = findEndsWith(cars, c, used);
			if (sameChar(str, c))
				countSame1++;

			if (aLeft != null) {
				str = aLeft + str;
			}
		}

		if (right) {
			countSame2 = findSame(cars, cn, used);
			aRight = findStartsWith(cars, cn, used);

			if (aRight != null) {
				str = str + aRight;
			}
		}

		long res1 = (factorial(countSame1) * factorial(countSame2)) % 1000000007;

		return res1 * calc(cars, used, aLeft != null, aRight != null);
	}

	public static void main(String[] args) throws Exception {
		Locale.setDefault(Locale.US);

		Scanner in = new Scanner(new File("problem.in"));
		PrintStream out = new PrintStream(new File("problem.out"));

		int T = in.nextInt();
		

		for (int test = 1; test <= T; test++) {
			int n = in.nextInt();
			String[] cars = new String[n];
			for (int i = 0; i < n; i++)
				cars[i] = in.next();

			boolean[] used = new boolean[n];

			long res = 1;
			String totalStr = "";
			long totalCount = 0;
			
			
			for (int i = 0; i < cars.length; i++)
				if (!used[i]) {
					String car = cars[i];
					used[i] = true;

					str = car;
					res = (res * calc(cars, used, true, true)) % 1000000007;

					totalStr += str;
					totalCount++;
				}
			res = (res * factorial(totalCount)) % 1000000007;

			if (!checkStr(totalStr)) {
				res = 0;
			}
			out.println("Case #" + test + ": " + res);

		}

	}
}
