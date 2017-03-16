package gcj2014.round1C;

import java.io.BufferedReader;
import java.io.FileReader;

public class A {
	public static void main(String[] args) throws Exception {
		A main = new A("A_sample.txt");
		main.solve();
	}

	private final BufferedReader in;

	public A(String input) throws Exception {
		in = new BufferedReader(new FileReader(this.getClass().getResource(input).getFile()));
	}

	private void solve() throws Exception {
		int T = getInt();
		for (int c = 1; c <= T; c++) {
			String[] input = in.readLine().split("/");
			String ans = solveOne(Long.valueOf(input[0]), Long.valueOf(input[1]));
			System.out.println("Case #" + c + ": " + ans);
		}
	}

	private String solveOne(Long P, Long Q) {
		long gcd = findGCD(P, Q);
		long base = log(Q / gcd);
		if (base == -1) {
			return "impossible";
		}
		double top = P / gcd;
		long count = 0;
		while (top < Math.pow(2, base - count)) {
			count++;
		}
		return String.valueOf(count);
	}

	/*
	 * Misc functions
	 */
	private int getInt() throws Exception {
		return Integer.valueOf(in.readLine()).intValue();
	}

	private static long findGCD(long x, long y) {
		return y == 0 ? x : findGCD(y, x % y);
	}

	private int log(long i) {
		double log = Math.log(i) / Math.log(2);
		if (log % 1 > 0.00000001) {
			return -1;
		}
		return (int) log;
	}

	private int logcap(long i) {
		double log = Math.floor(Math.log(i) / Math.log(2));
		return (int) log;
	}

}
