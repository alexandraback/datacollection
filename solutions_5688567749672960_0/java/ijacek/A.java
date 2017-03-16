package R1B;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.*;

//
public class A {

	private static Scanner sc;
	private static PrintStream out;

	static Map<Long, Long> map = new HashMap<>();
	static Set<Long> sol = new HashSet<>();

	static long[] ar = new long[1_000_009];

	static long swap(long n) {
		long ret = 0;
		while (n > 0) {
			long a = n % 10;
			ret *= 10;
			ret += a;
			n /= 10;
		}
		return ret;
	}

	static {
		for (int i = 1; i < 20; i++)
			ar[i] = i;
		for (int i = 9; i < ar.length - 1; i++) {
			if ( ar[i + 1] == 0 || ar[i + 1] > ar[i] + 1 )
				ar[i + 1] = ar[i] + 1;
			long k = swap(i);
			if ( k > i && k < ar.length )
				ar[(int)k] = ar[i] + 1;
		}
	}

	static long cnt(long n) {
		if ( n <= 20 )
			return n;
		if ( map.containsKey(n) )
			return map.get(n);
		if ( !sol.add(n) )
			return -1;
		long a1 = cnt(n - 1) + 1;
		if ( a1 == 0 )
			a1 = Long.MAX_VALUE;
		long a2 = cnt(swap(n)) + 1;
		if ( a2 == 0 )
			a2 = Long.MAX_VALUE;
		long m = Math.min(a1, a2);
		sol.remove(n);
		if ( m == Long.MAX_VALUE )
			return -1;
		map.put(n, m);
		return m;
	}

	private static void solve(int TC) {
		long n = sc.nextLong();

		long ret = ar[(int)n];
		out.println(String.format("Case #%d: %d", TC, ret));
	}

	public static void main(String[] args) throws FileNotFoundException {
		Locale.setDefault(Locale.ROOT);

		String file = "src/R1B/A.sm";
		sc = new Scanner(new FileInputStream(file + ".in"));
		out = new PrintStream(file + ".out");

		int TC = ni();
		for (int i = 1; i <= TC; i++)
			solve(i);
	}

	private static int ni() {
		return sc.nextInt();
	}
}
