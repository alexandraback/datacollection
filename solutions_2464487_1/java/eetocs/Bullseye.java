import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;
import java.math.RoundingMode;
import java.util.Scanner;


public class Bullseye {
//	public  static long cal(BigInteger a,BigInteger b,BigInteger c)
//	{
//		BigInteger x1,x2;
//		BigInteger four=new BigInteger("4");
//		BigInteger two=new BigInteger("2");
//		BigInteger delta=b.multiply(b).subtract(a.multiply(c).multiply(four))
////				b*b-4*a*c;
////		x2 = (-b+Math.sqrt(delta))/(2*a);
//		x2=
//		return (long) Math.floor(x2);
//	}
	public static void main(String[] args)
	{
//		System.out.println(deidai(new BigDecimal("1"),new BigDecimal("-1"),new BigDecimal("-2")));
		Scanner reader = new Scanner(System.in);
		int T = reader.nextInt();
		for(int t = 1; t <= T; t++){
			String rr = reader.next();
			String tt = reader.next();
			
			BigDecimal a=new BigDecimal("2");
			BigDecimal b=new BigDecimal(rr).multiply(a).subtract(new BigDecimal("1"));
			BigDecimal c=new BigDecimal(tt).negate();
			
			System.out.println("Case #"+t+": "+deidai(a,b,c));
		}
	}
	  public static long deidai(BigDecimal a,BigDecimal b,BigDecimal c)  
	    {  
	        int count=0;  
	        BigDecimal x = new BigDecimal("0");;
	        BigDecimal zero=new BigDecimal("0.001");
	        BigDecimal two=new BigDecimal(2);
	        MathContext MathContextmc = new MathContext(3,RoundingMode.HALF_UP);  
	        while((a.multiply(x).multiply(x).add(b.multiply(x)).add(c)).abs().compareTo(zero)>0)  
	        {  
	        	BigDecimal top = a.multiply(x).multiply(x).add(b.multiply(x)).add(c);
	        	BigDecimal down =a.multiply(x).multiply(two).add(b);
	        	x=x.subtract(top.divide(down,MathContextmc));
//	            x=x-(8*x*x*x*x-7*x*x*x+2*x*x+3*x+6-number)/(double)(32*x*x*x-21*x*x+4*x+3);  
	        
	        }  
	        return x.longValue();  
	    } 
}
