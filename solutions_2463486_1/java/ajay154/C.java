import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeMap;
// @ Author   : Ajay Yadav
// @ Program  : PALINDROME

public class C {

	private static final long max = 10000010;
	/**
	 * @param args
	 */
	static TreeMap<Long, Long> x = new TreeMap<Long, Long>();

	static boolean ispalindrome(long t) {
		long res, p;
		p = t;
		res = 0;
		while (p != 0) {
			res = 10 * res + p % 10;
			p = p / 10;
		}
		if (res == t)
			return true;
		else
			return false;
	}

	static void preprocessing() {
		long square;
		for (long i = 1; i <= max; i++) {
			square = i * i;
			boolean t = ispalindrome(square);
			boolean tw = ispalindrome(i);
			if (t && tw) {
				x.put(i, square);
			}

		}
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub

		preprocessing();
		int tests;
		long a, b;
		long i, j, k, l, c, g;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str1 = br.readLine();
		tests = Integer.parseInt(str1);
		for (i = 1; i <= tests; ++i) {
			String[] st = br.readLine().split(" ");
			a = Long.valueOf(st[0]);
			b = Long.valueOf(st[1]);
			// System.out.println(a+" "+b);
			c = 0;
			j = x.ceilingKey((long) Math.sqrt(a));
			l = x.ceilingKey((long) Math.sqrt(b));
			for (; j <= l; ++j) {
				if (x.containsKey(j)) {
					Long s = x.get(j);
					if (s >= a && s <= b)
						c++;
				//	 System.out.println(j);
				}
			}
			System.out.println("Case #" + i + ": " + c);
		}
	}

}
