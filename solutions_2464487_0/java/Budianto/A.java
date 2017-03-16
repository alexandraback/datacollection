import java.util.*;
import java.io.*;
import java.math.*;

public class A{
	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(System.in);
		
		int Tes = in.nextInt();
		
		for(int caseNo=1;caseNo<=Tes;caseNo++){
			BigInteger R = in.nextBigInteger();
			BigInteger T = in.nextBigInteger();
			
			BigInteger left = new BigInteger("1");
			BigInteger right = new BigInteger("1000000000000");
			BigInteger last = new BigInteger("-1");
			BigInteger TWO = new BigInteger("2");
			BigInteger THREE = new BigInteger("3");
			BigInteger FOUR= new BigInteger("4");
			BigInteger FIVE = new BigInteger("5");
			BigInteger start = null;
			
			if (R.longValue() % 2 == 1) { // odd
				start = THREE.add(R.add(BigInteger.ONE).divide(TWO).subtract(BigInteger.ONE).multiply(FOUR));
			} else {
				start = FIVE.add(R.divide(TWO).subtract(BigInteger.ONE).multiply(FOUR));
			}
			
			//System.out.println(R+" "+start);
			
			
			while(left.compareTo(right) < 0) {
				BigInteger mid  = left.add(right).divide(TWO);
				if (mid.equals(last)) break;
				last = mid;
				
				BigInteger sum =mid.multiply(TWO.multiply(start).add(mid.subtract(BigInteger.ONE).multiply(FOUR))).divide(TWO);
				if (sum.compareTo(T) < 0) {
					left = mid;
				} else if (sum.compareTo(T) > 0) {
					right = mid;
				} else break;
				//System.out.println(left+" "+right+" "+mid+" "+sum);
			}
			
			BigInteger ans = left.add(right).divide(TWO);
			
			System.out.println("Case #"+caseNo+": "+ans);
						
		}
	}
}