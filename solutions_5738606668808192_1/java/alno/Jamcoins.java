package codejam16q;

import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Jamcoins {

	private static final boolean recheck = true;

	public static void main(String[] args) throws IOException {
		String problem = "jamcoins";
		String example = "C-large";

		File inFile = new File("data/" + problem + "/" + example + ".in");
		File outFile = new File("data/" + problem + "/" + example + ".out");

		try (Scanner in = new Scanner(inFile); PrintStream out = new PrintStream(outFile)) {
			int T = Integer.parseInt(in.nextLine());

			for (int t = 0; t < T; ++t) {
				int sz = in.nextInt();
				int cnt = in.nextInt();
				int rep = 1;

				if (sz > 16 && sz % 2 == 0) {
					sz /= 2;
					rep = 2;
				}

				out.println("Case #" + (t + 1) + ":");

				mineJamcoins(sz, cnt, out, rep);
			}
		}
	}

	private static int[] preparePrimes(int max) {
		boolean[] sieve = new boolean[max + 1];

		Arrays.fill(sieve, true);

		sieve[0] = false;
		sieve[1] = false;

		int pc = 0;
		for (int n = 0; n <= max; ++n)
			if (sieve[n]) {
				pc++;

				for (long k = ((long) n) * n; k <= max; k += n)
					sieve[(int) k] = false;
			}

		int[] res = new int[pc];
		pc = 0;
		for (int n = 0; n <= max; ++n)
			if (sieve[n])
				res[pc++] = n;

		return res;
	}

	private static void mineJamcoins(int sz, int max, PrintStream out, int rep) {
		int[] primes = preparePrimes(100000000);
		int[] proof = new int[9];
		int cnt = 0;

		for (int s = 0; cnt < max && s < (1 << (sz - 2)); ++s) {
			String coin = Integer.toBinaryString(s * 2 + 1 + (1 << (sz - 1)));
			boolean ok = true;

			for (int b = 2; ok && b <= 10; ++b) {
				int p = findProof(Long.valueOf(coin, b), primes);

				if (p > 0)
					proof[b - 2] = p;
				else
					ok = false;
			}

			if (ok) {
				StringBuilder b = new StringBuilder();
				for (int i = 0; i < rep; ++i)
					b.append(coin);

				if (recheck)
					for (int base = 2; base <= 10; ++base)
						if (!new BigInteger(b.toString(), base).mod(BigInteger.valueOf(proof[base - 2])).equals(BigInteger.ZERO))
							throw new Error("Wrong jamcoin: " + b);

				for (int i = 0; i < proof.length; ++i) {
					b.append(' ');
					b.append(proof[i]);
				}

				out.println(b.toString());
				cnt++;
			}
		}
	}

	private static int findProof(long n, int[] primes) {
		int sq = (int) Math.sqrt(n + 1);
		for (int p : primes)
			if (p > sq)
				return 0;
			else if (n % p == 0)
				return p;

		return 0;
	}

}
