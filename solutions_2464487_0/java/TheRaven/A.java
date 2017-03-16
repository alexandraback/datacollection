import java.util.*;
import java.math.*;
public class A {
	public static void main (String [] arg) {
		Scanner sc = new Scanner(System.in);
		int T = Integer.parseInt(sc.nextLine());
		int ptr = 0;
		
		
		
		for (int ii = 1; ii<=T; ++ii) {
			long R = sc.nextLong();
			long A = sc.nextLong();
			BigInteger B = BigInteger.valueOf(A);
			long min = 0;
			long max = (long)(Math.sqrt(A) + 10);
			while (min < max) {
				//System.err.println("Min =  " + min + " , max = " + max);
				long piv = (min+max+1) / 2;
				BigInteger val = getVal(piv, R);
				if (val.compareTo(B) <= 0)
					min = piv;
				else
					max = piv-1;
				
				//System.err.println("At piv " + piv + " with " + min + " , " + max);
			}
			long ans = min;
			System.out.printf("Case #%d: %s\n",ii,ans);
		}
	}
	static BigInteger getVal(long piv, long R) {
		if (piv == 0) return BigInteger.ZERO;
		long tmp = R;
		BigInteger ans = (R % 2 == 0) ? form(R/2, R/2 + piv - 1).shiftLeft(2).add(BigInteger.valueOf(piv))
								: form((R+1)/2, (R+1)/2 + piv - 1).shiftLeft(2).subtract(BigInteger.valueOf(piv));

		//System.err.println("Value for " + piv + " after " + R + " is " + ans);
		return ans;
	}
	static BigInteger form (long from , long to) {
		return f(to).subtract(f(from-1));
	}
	static BigInteger f (long to) {
		return BigInteger.valueOf(to).multiply(BigInteger.valueOf(to).add(BigInteger.ONE)).shiftRight(1);
	}
}