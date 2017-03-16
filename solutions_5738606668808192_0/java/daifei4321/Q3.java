package r0;

import java.math.BigInteger;
import java.util.Scanner;

public class Q3 {
	public static void main(String... args) {
//		Prime prime = new Prime(1000000);
		try (Scanner in = new Scanner(System.in)) {
			int T = Integer.parseInt(in.nextLine());
			for (int caseI = 0; caseI < T; caseI++) {
				processCase(caseI + 1, in.nextInt(), in.nextInt());
			}
		}
	}
//	private static final class Prime {
//		public final boolean[] isPrime;
//		public final int[] primeList;
//		public Prime(int max) {
//			long timeStart = System.currentTimeMillis();
//			
//			System.err.println("Prime list used " + (System.currentTimeMillis() - timeStart) + " ms.");
//		}
//	}

	private static void processCase(int sn, int N, int J) {
		System.out.println("Case #" + sn + ":");
		int seqMin = (1 << (N - 1)) + 1;
		int seqMax = (1 << N) - 1;
		System.err.println("seqMin=" + Integer.toBinaryString(seqMin));
		System.err.println("seqMax=" + Integer.toBinaryString(seqMax));
		int[] masks = new int[N];
		for (int bit = 0; bit < N; bit++) {
			masks[bit] = 1 << bit;
		}
		BigInteger[][] powers = new BigInteger[11][N];
		for (int radix = 2; radix <= 10; radix++) {
			BigInteger base = BigInteger.valueOf(radix);
			for (int power = 0; power < N; power++) {
				powers[radix][power] = base.pow(power);
			}
		}
		int found = 0;
		BigInteger[] factors = new BigInteger[11];
		int seq = seqMin;
		for (;;) {
			if (isSeqValid(seq, N, masks, powers, factors)) {
				System.out.print(Integer.toBinaryString(seq));
				for (int radix = 2; radix <= 10; radix++) {
					System.out.print(" " + factors[radix].toString());
				}
				System.out.println();
				System.err.print("> ");
				for (int radix = 2; radix <= 10; radix++) {
					System.err.print(resolve(seq, N, masks, powers[radix]) + " ");
				}
				System.err.println();
				if (++found >= J) {
					break;
				}
			}
			if (seq == seqMax) {
				throw new AssertionError("Found only " + found);
			}
			seq += 2;
		}
	}
	private static BigInteger resolve(int seq, int N, int[] masks, BigInteger[] powerForBase) {
		BigInteger resolved = BigInteger.ZERO;
		for (int bit = 0; bit < N; bit++) {
			if (0 != (masks[bit] & seq)) {
				resolved = resolved.add(powerForBase[bit]);
			}
		}
		return resolved;
	}
	private static boolean isSeqValid(int seq, int N, int[] masks, BigInteger[][] powers, BigInteger[] factors) {
		for (int radix = 2; radix <= 10; radix++) {
			BigInteger[] powerForBase = powers[radix];
			BigInteger resolved = resolve(seq, N, masks, powerForBase);
			BigInteger nonTrivialDivisor = getNonTrivialDivisor(resolved);
			if (null == nonTrivialDivisor) {
				return false;
			}
			factors[radix] = nonTrivialDivisor;
		}
		return true;
	}
	private static final BigInteger TWO = BigInteger.ONE.add(BigInteger.ONE);
	private static final BigInteger WHAT = BigInteger.valueOf(1002);
	private static BigInteger getNonTrivialDivisor(BigInteger resolved) {
		for (BigInteger a = TWO; a.compareTo(WHAT) < 0; a = a.add(BigInteger.ONE)) {
			if (resolved.remainder(a).signum() == 0) {
				return a;
			}
		}
		return null;
	}
}
