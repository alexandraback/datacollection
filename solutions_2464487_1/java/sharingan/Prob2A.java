import java.math.BigInteger;
import java.util.Scanner;

public class Prob2A {

	
	static BigInteger sqrt(BigInteger n) {
		  BigInteger a = BigInteger.ONE;
		  BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
		  while(b.compareTo(a) >= 0) {
		    BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
		    if(mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
		    else a = mid.add(BigInteger.ONE);
		  }
		  return a.subtract(BigInteger.ONE);
		}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		int T =scan.nextInt();
		for(int tt=0;tt<T;tt++)
		{
			long r= scan.nextLong();
			long t =scan.nextLong();
			long b= 2*r+1-2;
			long a =2 ;
			long c=t;
			BigInteger bb = new BigInteger(Long.toString(b));
			bb=bb.multiply(bb);
			BigInteger cc = new BigInteger(Long.toString(c));
			cc=cc.multiply(new BigInteger("8"));
			bb=bb.add(cc);
			bb =sqrt(bb);
			BigInteger bbb = new BigInteger(Long.toString(b));
			bb=bb.subtract(bbb);
			bb=bb.divide(new BigInteger("4"));
			long q = 0;
			q= Long.parseLong( bb.toString());
			q=(long)(Math.floor(q));
			System.out.println("Case #"+tt+": "+q);
			
			
		}
		scan.close();

	}

}
