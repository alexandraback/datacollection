
public class C {
	static boolean isJamCoin(long x, int width, int[] d) {
		for (int base = 2; base <= 10; base++) {
			long y = rebase(x, width, base);
			if( ( d[base-2] = findDivisor(y)) == -1)
				return false;
		}
		return true;
	}

	static long rebase(long x, int width, int base) {
		long y = 0;
		long m = 1;
		for (int i = 0; i < width; i++) {
			if ((x & (1L << i)) != 0)
				y += m;
			m *= base;
		}
		return y;
	}

	static int findDivisor(long num) {
		if(num < 3)
			throw new AssertionError();
		if (num % 2 == 0)
			return 2;
		for (int i = 3; ((long)i) * i <= num; i += 2)
			if (num % i == 0)
				return i;
		return -1;
	}
	
	public static void main(String[] args) {
//		int N = 32;
//		int J = 500;
//		int N = 6;
//		int J = 3;
		int N = 16;
		int J = 50;
		int c = 0;
		System.out.println("Case #1:");
		int[] d = new int[9];
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
