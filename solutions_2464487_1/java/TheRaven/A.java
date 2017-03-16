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
			BigInteger min = BigInteger.valueOf(0);
			BigInteger max = BigInteger.valueOf(A);
			while (min.compareTo(max) < 0) {
				//System.err.println("Min =  " + min + " , max = " + max);
				BigInteger piv = min.add(max).add(BigInteger.ONE).shiftRight(1);
				BigInteger val = getVal(piv, R);
				if (val.compareTo(B) <= 0)
					min = piv;
				else
					max = piv.subtract(BigInteger.ONE);
				
				//System.err.println("At piv " + piv + " with " + min + " , " + max);
			}
			String ans = min.toString();
			System.out.printf("Case #%d: %s\n",ii,ans);
		}
	}
	static BigInteger getVal(BigInteger piv, long R) {
		if (piv.equals(BigInteger.ZERO)) return BigInteger.ZERO;
		BigInteger tmp = (R % 2 == 0) ? BigInteger.valueOf(R/2) : BigInteger.valueOf((R+1)/2);
		BigInteger ans = (R % 2 == 0) ? form(tmp, tmp.add(piv).subtract(BigInteger.ONE)).shiftLeft(2).add(piv)
								: form(tmp, tmp.add(piv).subtract(BigInteger.ONE)).shiftLeft(2).subtract(piv);

		//System.err.println("Value for " + piv + " after " + R + " is " + ans);
		return ans;
	}
	static BigInteger form (BigInteger from , BigInteger to) {
		return f(to).subtract(f(from.subtract(BigInteger.ONE)));
	}
	static BigInteger f (BigInteger to) {
		return to.multiply(to.add(BigInteger.ONE)).shiftRight(1);
	}
}