import java.io.*;
import java.util.*;
import java.math.*;

public class Lottery implements Runnable {
	public static void main(String[] args) {
		new Thread(new Lottery()).start();
	}

	void transfer(long[][] dp, long[][] next, int bitA, int bitB, int bitK, int freeA, int freeB) {
		//a_i = 0, b_i = 0
		if (bitK == 0) {
			int nextFA = bitA == 1 ? 1 : freeA;
			int nextFB = bitB == 1 ? 1 : freeB;
			next[nextFA][nextFB] += dp[freeA][freeB];
		}

		//a_i = 0, b_i = 1
		if ((bitB == 1 || freeB == 1) && bitK == 0) {
			int nextFA = bitA == 1 ? 1 : freeA;
			int nextFB = freeB;
			next[nextFA][nextFB] += dp[freeA][freeB];
		}

		//a_i = 1, b_i = 0
		if ((bitA == 1 || freeA == 1) && bitK == 0) {
			int nextFA = freeA;
			int nextFB = bitB == 1 ? 1 : freeB;
			next[nextFA][nextFB] += dp[freeA][freeB];
		}

		//a_i = 1, b_i = 1
		if ((bitA == 1 || freeA == 1) && (bitB == 1 || freeB == 1) && bitK == 1) {
			int nextFA = freeA;
			int nextFB = freeB;
			next[nextFA][nextFB] += dp[freeA][freeB];
		}
	}

	public void run() {
		InputReader in = new InputReader(System.in);
		PrintWriter out = new PrintWriter(System.out);

		int task = in.nextInt();
		for (int taskIndex = 1; taskIndex <= task; ++taskIndex) {
			long ret = 0;
			int a = in.nextInt(), b = in.nextInt(), k = in.nextInt();
			int mask = 1, len = 0;
			while (mask <= Math.max(Math.max(a, b), k)) {
				mask <<= 1;
				++len;
			}
			long[][] dp = new long[2][2];
			dp[0][0] = 1;
			while (mask > 1) {
				mask >>= 1; --len;
				int bitA = a >> len & 1;
				int bitB = b >> len & 1;
				int bitK = k >> len & 1;
				long[][] next = new long[2][2];
				for (int freeA = 0; freeA < 2; ++freeA) {
					for (int freeB = 0; freeB < 2; ++freeB) {
						transfer(dp, next, bitA, bitB, bitK, freeA, freeB);
					}
				}
				if (bitK == 1) {
					long[][] mem = new long[2][2];
					for (int freeA = 0; freeA < 2; ++freeA) {
						for (int freeB = 0; freeB < 2; ++freeB) {
							transfer(dp, mem, bitA, bitB, 0, freeA, freeB);
						}
					}
					for (int freeA = 0; freeA < 2; ++freeA) {
						for (int freeB = 0; freeB < 2; ++freeB) {
							int wayA = freeA == 0 ? (a & mask - 1) : mask;
							int wayB = freeB == 0 ? (b & mask - 1) : mask;
							ret += (long)wayA * wayB * mem[freeA][freeB];
						}
					}
				}
				dp = next;
			}
			out.println("Case #" + taskIndex + ": " + ret);
		}

		out.close();
	}
}

class InputReader {
	BufferedReader buff;
	StringTokenizer tokenizer;

	InputReader(InputStream stream) {
		buff = new BufferedReader(new InputStreamReader(stream));
		tokenizer = null;
	}
	boolean hasNext() {
		while (tokenizer == null || !tokenizer.hasMoreTokens())
			try {
				tokenizer = new StringTokenizer(buff.readLine());
			}
			catch (Exception e) {
				return false;
			}
		return true;
	}
	String next() {
		if (!hasNext())
			throw new RuntimeException();
		return tokenizer.nextToken();
	}
	int nextInt() { return Integer.parseInt(next()); }
	long nextLong() { return Long.parseLong(next()); }
}

