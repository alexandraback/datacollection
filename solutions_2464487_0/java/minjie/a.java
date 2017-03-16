import java.util.*;
import java.math.*;

public class a{

	static BigInteger r, t;
	static BigInteger f(BigInteger n){
		return (BigInteger.valueOf(2).multiply(n).multiply(n)).add(BigInteger.valueOf(2).multiply(n).multiply(r)).subtract(n);
	}
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int cas = in.nextInt();
		for(int it = 1;it <= cas; ++it){
			r = in.nextBigInteger();
			t = in.nextBigInteger();
			BigInteger s = BigInteger.valueOf(0);
			BigInteger e = t.add(s);
			BigInteger mid, two = BigInteger.valueOf(2);
			while(e.compareTo(s) >= 0){
				mid = (s.add(e)).divide(two);
				if(f(mid).compareTo(t) > 0) e = mid.subtract(BigInteger.ONE);
				else s = mid.add(BigInteger.ONE);
			}
			System.out.println("Case #" + it + ": " + e);
		}
	}
}
