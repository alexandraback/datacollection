import java.util.*;
import java.math.*;

public class clarge {

	public static BigInteger[][] table;
	public static BigInteger[] digits;
	public static void main(String[] args) {

		digits = new BigInteger[11];
		for (int i=0; i<11; i++)
			digits[i] = new BigInteger(""+i);

		table = new BigInteger[11][32];
		for (int i=0; i<=10; i++)
			table[i][0] = new BigInteger("1");

		for (int i=2; i<=10; i++)
			for (int j=1; j<=31; j++)
				table[i][j] = table[i][j-1].multiply(digits[i]);

		Scanner stdin = new Scanner(System.in);
		int numCases = stdin.nextInt();
		int n = stdin.nextInt();
		int max = stdin.nextInt();
		int printed = 0;

		for (long i=(1L<<(n-1))+1; i<(1L<<n); i+=2) {

			if (printed == max) break;

			boolean isPrime = false;
			BigInteger[] list = new BigInteger[11];
			for (int base=2; base<=10; base++) {
				list[base] = getBigInt(i, n, base);
				if (list[base].isProbablePrime(100)) {
					isPrime = true;
					break;
				}
			}

			if (isPrime) continue;


			int[] factors = new int[11];
			boolean okay = true;
			for (int j=2; j<=10; j++) {
				factors[j] = getFactor(list[j]);
				if (factors[j] == -1) {

					okay = false;
					break;
				}
			}

			if (!okay) continue;

			System.out.print(Long.toBinaryString(i));

			for (int j=2; j<=10; j++) {
				System.out.print(" "+factors[j]);
			}
			System.out.println();
			printed++;
		}
	}

	public static BigInteger getBigInt(long val, int size, int base) {

		BigInteger res = new BigInteger("0");
		for (int i=0; i<size; i++) {
			if  ( ((val>>i)&1L) == 1L)
				res = res.add(table[base][i]);
		}
		return res;
	}

	public static int getFactor(BigInteger b) {


		for (int i=2; i<1000; i++)
			if (b.mod(new BigInteger(""+i)).equals(BigInteger.ZERO))
				return i;

		return -1;
	}
}
