import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class c {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int t = in.nextInt();
		for(int caseN = 1; caseN <= t; caseN++) {
			int n = in.nextInt();
			int j = in.nextInt();

			long start = (1L << (n - 1)) + 1L;
			long end = 1L << n;

			System.out.println("Case #" + caseN + ":");
			for(long val = start; val < end && j > 0; val += 2L) {
				String str = Long.toBinaryString(val);
				long[] divs = new long[11];
				divs[0] = divs[1] = 1;

				boolean good = true;
				for(int base = 2; base <= 10; base++) {
					divs[base] = getDiv(convert(str, base));
					if(divs[base] == 0)
						good = false;
				}

				if(!good) continue;

				System.out.print(str);
				for(int base = 2; base <= 10; base++) {
					System.out.print(" " + divs[base]);
				}
				System.out.println();
				j--;			
			}
		}

	}

	public static BigInteger convert(String str, int base) {
		BigInteger ans = BigInteger.ZERO;
		BigInteger b = BigInteger.valueOf((long) base);
		for(int i = 0; i < str.length(); i++) {
			ans = ans.multiply(b);
			ans = ans.add(BigInteger.valueOf((long) (str.charAt(i) - '0')));
		}
		return ans;
	}

	public static long getDiv(BigInteger num) {
		for(long a = 2; a <= 100; a++) {
			if(num.mod(BigInteger.valueOf(a)).equals(BigInteger.ZERO))
				return a;
		}
		return 0;
	}

}