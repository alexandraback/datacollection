import java.util.*;
import java.io.*;
import java.math.*;
public class main {
	static BigInteger calc(long r,long n)
	{
		BigInteger res;
		res=BigInteger.valueOf(r).multiply(BigInteger.valueOf(2)).add(BigInteger.ONE).multiply(BigInteger.valueOf(n)).add(BigInteger.valueOf(n).subtract(BigInteger.ONE).multiply(BigInteger.valueOf(n)).multiply(BigInteger.valueOf(2)));
		return res;
	}
	public static void main(String args[]) throws IOException{
		int t,tt=0;
	    long r,s,upper,lower,mid=0;
	    System.setIn(new FileInputStream(new File("src/A-small-attempt0.in")));
	    System.setOut(new PrintStream(new File("src/A-small-attempt0.out")));
	    Scanner cin=new Scanner(System.in);
	    t=cin.nextInt();
	    while(t!=0)
	    {
	    	t--;
	        tt++;
	        r=cin.nextLong();
	        s=cin.nextLong();
	        lower=0;upper=1000000000000000000L;
	        while(lower<=upper)
	        {
	            mid=(upper+lower)/2;
	            if(calc(r,mid).equals(BigInteger.valueOf(s)))break;
	            else if(calc(r,mid).compareTo(BigInteger.valueOf(s))>0)upper=mid-1;
	            else lower=mid+1;
	        }
	        if(calc(r,mid+2).compareTo(BigInteger.valueOf(s))<=0)System.out.println("Case #"+tt+": "+(mid+2));
	        else if(calc(r,mid+1).compareTo(BigInteger.valueOf(s))<=0)System.out.println("Case #"+tt+": "+(mid+1));
	        else if(calc(r,mid).compareTo(BigInteger.valueOf(s))<=0)System.out.println("Case #"+tt+": "+(mid));
	        else System.out.println("Case #"+tt+": "+(mid-1));
	    }
	}
}
