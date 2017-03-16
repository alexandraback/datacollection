import java.util.*;
import java.math.*;
public class A{
	public static void main(String[] argv){
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int kase = 1; kase <= T; ++kase){
			BigInteger r = in.nextBigInteger(), t= in.nextBigInteger();
			r = r.multiply(BigInteger.valueOf(2));

			BigInteger left, right = BigInteger.ONE, ans;
			left = BigInteger.ZERO;
			right = right.shiftLeft(63);
			ans = BigInteger.ZERO;
			while(left.compareTo(right)<0){
				BigInteger mid = left.add(right).divide(BigInteger.valueOf((long)2));

				BigInteger tmp = mid.add(mid).subtract(BigInteger.ONE).add(r);
				tmp = tmp.multiply(mid);

//				System.out.println("testing " + mid + " " + tmp + " " + t);
				
				if(tmp.compareTo(t) <= 0){ans = mid; left = mid.add(BigInteger.ONE);}
				else{right = mid;}
			}
			System.out.println("Case #" + kase + ": " + ans);
		}
	}
}
