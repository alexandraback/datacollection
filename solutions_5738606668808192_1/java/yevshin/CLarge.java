import java.math.BigInteger;

public class CLarge {
	static boolean isJamCoin(long x, int width, long[] d) {
		for (int base = 2; base <= 10; base++) {
			BigInteger y = rebase(x, width, base);
			if( ( d[base-2] = findDivisor(y)) == -1)
				return false;
		}
		return true;
	}

	static BigInteger rebase(long x, int width, int base) {
		BigInteger y = BigInteger.ZERO;
		BigInteger m = BigInteger.ONE;
		for (int i = 0; i < width; i++) {
			if ((x & (1L << i)) != 0)
				y = y.add(m);
			m = m.multiply(BigInteger.valueOf(base));
		}
		return y;
	}

	static long findDivisor(BigInteger num) {
		if(num.compareTo(BigInteger.valueOf(3)) < 0)
			throw new AssertionError();
		if( num.mod(BigInteger.valueOf(2)).equals(BigInteger.ZERO))
			return 2;
		for (int i = 3; i < 100 && BigInteger.valueOf(i*i).compareTo(num) <= 0; i += 2)
			if (num.mod(BigInteger.valueOf(i)).equals(BigInteger.ZERO))
				return i;
		return -1;
	}
	
	public static void main(String[] args) {
		int N = 32;
		int J = 500;
//		int N = 6;
//		int J = 3;
//		int N = 16;
//		int J = 50;
		int c = 0;
		System.out.println("Case #1:");
		long[] d = new long[9];
		for(long i = 0; i < 1L<<(N-1); i++)
		{
			long n = 1L | (i << 1) | (1L << (N-1));
			if(isJamCoin(n, N, d)) {
				System.out.print(Long.toBinaryString(n));
				for(int j = 0; j < d.length; j++)
					System.out.print(" "+d[j]);
				System.out.println();
				c++;
				if(c == J)
					return;
			}
		}
		throw new AssertionError();
	}
}
