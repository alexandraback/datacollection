import java.util.*;
import java.lang.*;
import java.math.*;
public class Bulls{
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int T=in.nextInt();
		for(int c=1;c<=T;c++)
		{
			String s1=in.next(),s2=in.next();
			//long r=in.nextLong(),t=in.nextLong();
			BigInteger r=new BigInteger(s1);
			BigInteger t=new BigInteger(s2);
			BigInteger two=new BigInteger("2");
			BigInteger t1=r.multiply(two).subtract(BigInteger.ONE);
		//	long t1=2*r-1;
			BigInteger high=new BigInteger("100000000000000000000");
			BigInteger low=new BigInteger("0");
			BigInteger mid=high.add(low).divide(two);
			BigInteger mid1=mid.add(BigInteger.ONE);
			while(low.add(BigInteger.ONE).compareTo(high)<0){
				BigInteger temp=mid.multiply(mid.multiply(two).add(t1));
				if(temp.compareTo(t)<=0){
					low=mid;
					mid=high.add(low).divide(two);
				}else{
					high=mid;
					mid=high.add(low).divide(two);
				}
			}
				
			System.out.println("Case #"+c+": "+mid.longValue());
		}
	}
}
