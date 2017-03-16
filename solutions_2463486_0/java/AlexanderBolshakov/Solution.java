import java.util.*;
import java.io.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Solution implements Runnable {

	ArrayList<BigInteger> numbers = new ArrayList<BigInteger>();
	
	BigInteger[] pow10;
	
	boolean isPalindrome(BigInteger n) {
		String str = n.toString();
		for (int i = 0; i < str.length(); i++) {
			if (str.charAt(i) != str.charAt(str.length() - 1 - i)) {
				return false;
			}
		}
		return true;
	}
	
	void backtrack(int halflen, BigInteger num, boolean odd, int pos) {
		int len = halflen * 2;
		if (odd) {
			len--;
		}
		if (pos == halflen) {
			numbers.add(num);
		} else {
			for (int digit = 0; digit <= 9; digit++) {
				if (pos == 0 && digit == 0) {
					continue;
				}
				BigInteger d = BigInteger.valueOf(digit);
				BigInteger newnum = num.add(d.multiply(pow10[pos]));
				if (!odd || pos != halflen - 1) {
					newnum = newnum.add(d.multiply(pow10[len - 1 - pos]));
				}
				if (isPalindrome(newnum.multiply(newnum))) {
					backtrack(halflen, newnum, odd, pos + 1);
				}
			}
		}
	}
	
	int solve(BigInteger r) {
		int sl = -1, sr = numbers.size() + 1;
		while (sr - sl > 1) {
			int sm = (sl + sr) / 2;
			BigInteger num = numbers.get(sm).multiply(numbers.get(sm));
			if (num.compareTo(r) <= 0) {
				sl = sm;
			} else {
				sr = sm;
			}
		}
		return sl + 1;
	}
	
	public void solve() throws Exception {
		final int MAXN = 200;
		pow10 = new BigInteger[MAXN + 1];
		pow10[0] = BigInteger.ONE;
		for (int i = 1; i <= MAXN; i++) {
			pow10[i] = BigInteger.valueOf(10).multiply(pow10[i - 1]);
		}
		for (int halflen = 1; halflen <= 26; halflen++) {
			backtrack(halflen, BigInteger.ZERO, true, 0);
			backtrack(halflen, BigInteger.ZERO, false, 0);
			System.out.println(halflen);
		}
		int t = sc.nextInt();
	outer:
		for (int Case = 1; Case <= t; Case++) {
			out.print("Case #" + Case + ": ");
			BigInteger a = new BigInteger(sc.nextToken()), b = new BigInteger(sc.nextToken());
			out.println(solve(b) - solve(a.subtract(BigInteger.ONE)));
		}
	}

	static Throwable uncaught;

	BufferedReader in;
	FastScanner sc;
	PrintWriter out;

	@Override
	public void run() {
		try {
			in = new BufferedReader(new FileReader("C-small-attempt0.in"));
			out = new PrintWriter(new FileWriter("C-small.out"));
			sc = new FastScanner(in);
			solve();
		} catch (Throwable uncaught) {
			Solution.uncaught = uncaught;
		} finally {
			out.close();
		}
	}

	public static void main(String[] args) throws Throwable {
		Thread thread = new Thread(null, new Solution(), "", (1 << 26));
		thread.start();
		thread.join();
		if (Solution.uncaught != null) {
			throw Solution.uncaught;
		}
	}

}

class FastScanner {

	BufferedReader in;
	StringTokenizer st;

	public FastScanner(BufferedReader in) {
		this.in = in;
	}

	public String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		return st.nextToken();
	}

	public int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	public long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	public double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

}