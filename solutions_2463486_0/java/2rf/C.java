import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class C {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	enum InputType {
		EXAMPLE, SMALL, LARGE
	}

	static final InputType INPUT_TYPE = InputType.SMALL;
	static final int ATTEMPT_NUMBER = 0;

	BigInteger root(BigInteger x) {
		int len = x.bitLength();
		// floor((len - 1) / 2)
		// ceil(len / 2)
		BigInteger low = BigInteger.ONE.shiftLeft((len - 1) / 2); // low^2 <= x
		BigInteger high = BigInteger.ONE.shiftLeft((len + 1) / 2); // high^2 > x
		while (high.subtract(low).compareTo(BigInteger.ONE) > 0) {
			BigInteger mid = low.add(high).shiftRight(1);
			if (mid.multiply(mid).compareTo(x) <= 0)
				low = mid;
			else
				high = mid;
		}
		return low;
	}

	long solve(BigInteger a) {
		
		if (a.signum() == 0)
			return 0;	
		
		// number of good shit on [1; a]
		a = root(a).add(BigInteger.ONE);

		// number of roots of good shit on [1; a)
		String s = a.toString();

		long ans = 0;
		for (int len = 1; len < s.length(); len++) {
			char[] cur = new char[len];
			for (cur[0] = '1'; cur[0] <= '3'; cur[0]++) {
				ans += solve(cur, 1);
			}
		}

		char[] cur = s.toCharArray();
		for (int i = cur.length - 1; i >= 0; i--) {
			char low = (i == 0 ? '1' : '0');
			while (cur[i] > low) {
				cur[i]--;
				ans += solve(cur, i + 1);
			}
		}

		return ans;

	}

	// MAYBE biginteger
	long solve(char[] s, int fix) {
		
//		System.err.println("!" + s.length + " " + new String(Arrays.copyOf(s, fix)));
		
		int n = s.length;
		int sumSq = 0;
		int freePair = 0;
		int freeOne = 0;
		for (int l = 0, r = n - 1; l <= r; l++, r--) {
			if (r < fix && s[l] != s[r]) {
				return 0;
			}
			if (l >= fix) {
				if (l == r)
					freePair++;
				else
					freeOne++;
			} else {
				int val = (s[l] - '0');
				if (l == r) {
					sumSq += val * val;
				} else {
					sumSq += 2 * val * val;
				}
			}
		}
		if (sumSq >= 10)
			return 0;
		return dp[9 - sumSq][freePair][freeOne];
	}

	static final int MAX_PAIR = 25;
	static final long[][][] dp = new long[10][MAX_PAIR + 1][2];
	// sum of squares, number of pairs, number of singles
	static {
		dp[0][0][0] = 1;
		for (int sum = 0; sum < 10; sum++) {
			for (int pair = 0; pair <= MAX_PAIR; pair++) {
				for (int put = 0; put <= 2; put++) {
					int add = 2 * put * put;
					if (sum + add < 10 && pair + 1 <= MAX_PAIR)
						dp[sum + add][pair + 1][0] += dp[sum][pair][0];
				}

				for (int put = 0; put <= 3; put++) {
					int add = put * put;
					if (sum + add < 10)
						dp[sum + add][pair][1] += dp[sum][pair][0];
				}
			}
		}

		for (int sum = 1; sum < 10; sum++) {
			for (int pair = 0; pair <= MAX_PAIR; pair++) {
				for (int sing = 0; sing < 2; sing++) {
					dp[sum][pair][sing] += dp[sum - 1][pair][sing];
				}
			}
		}
	}

	void solve() throws IOException {
		BigInteger a = new BigInteger(nextToken()).subtract(BigInteger.ONE);
		BigInteger b = new BigInteger(nextToken());
		out.println(solve(b) - solve(a));
	}

	C() throws IOException {
		switch (INPUT_TYPE) {
		case EXAMPLE: {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			break;
		}
		case SMALL: {
			br = new BufferedReader(new FileReader("C-small-attempt"
					+ ATTEMPT_NUMBER + ".in"));
			out = new PrintWriter("C-small-attempt" + ATTEMPT_NUMBER + ".out");
			break;
		}
		case LARGE: {
			br = new BufferedReader(new FileReader("C-large.in"));
			out = new PrintWriter("C-large.out");
			break;
		}
		}
		int t = nextInt();
		for (int i = 1; i <= t; i++) {
			System.err.println("Test " + i);
			out.print("Case #" + i + ": ");
			solve();
		}
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new C();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}