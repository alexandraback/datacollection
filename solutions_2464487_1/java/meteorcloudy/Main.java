import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 */
	public static BigInteger r;
	public static BigInteger t;
	
	public static BigInteger get(BigInteger k)
	{
		BigInteger two = BigInteger.valueOf(2);
	    return (two.multiply(r).subtract(BigInteger.valueOf(3))).multiply(k).add(two.multiply(k).multiply(k.add(BigInteger.ONE)));
	}
	
	public static BigInteger  lower_bound(BigInteger l,BigInteger r,BigInteger x)
	{
		BigInteger m;
	    while (l.compareTo(r)<0)
	    {
	        m=l.add(r).divide(BigInteger.valueOf(2));
	        if (get(m).compareTo(x)>=0) r=m;
	        else l=m.add(BigInteger.ONE);
	    }
	    
	    if (get(l).compareTo(x)>0) l=l.subtract(BigInteger.ONE);
	    return l;
	}
	
	public static void main(String[] args) {

		Scanner in=new Scanner(System.in);
		
			int tt = in.nextInt();
			
			for (int id=1;id<=tt;id++)
			{
				r = in.nextBigInteger();
				t = in.nextBigInteger();
				BigInteger ans = lower_bound(BigInteger.ONE,t,t);
				System.out.println("Case #"+id+": "+ans);
			}			
		}		

}

