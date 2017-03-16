import java.math.BigInteger;
import java.util.Scanner;


public class A_GCJ {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		BigInteger TWO = new BigInteger("2");
		int C = 1;
		while(T-- > 0){
			BigInteger r = sc.nextBigInteger();
			BigInteger t = sc.nextBigInteger();
			long max =  10000000000L; 
			long min =  1L;
			BigInteger mid;
			while(max - min > 1){
				mid = new BigInteger(""+max).add(new BigInteger(""+min));
				mid = mid.divide(TWO);
				BigInteger a = TWO.multiply(r).multiply(mid);
				BigInteger b = TWO.multiply(mid).multiply(mid);
				BigInteger c = a.add(b).subtract(mid);
				if(c.compareTo(t)>0) max = mid.longValue();
				else min = mid.longValue();
			}
			System.out.println("Case #"+C+": "+min);
			C++;
		}
	}

}
