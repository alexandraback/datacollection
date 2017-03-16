import java.util.*;
import java.io.*;
import java.math.*;

class A{

	public static void main (String [] args) throws IOException 
	{
		Scanner sc = new Scanner(new File("A-large.in"));
		PrintWriter out = new PrintWriter(new FileWriter("A-large.out"));



		int t;
		t = sc.nextInt();

		for (int _t=0;_t<t;_t++){
		
			//System.out.println(  BigInteger.ONE.subtract( BigInteger.TEN).multiply(BigInteger.TEN) );
			
			BigInteger r = new BigInteger(sc.next());
			BigInteger p = new BigInteger (sc.next());
			BigInteger rm = r; //rm is r-1
			r=r.add(BigInteger.ONE);
		
			BigInteger c = (r.multiply(r)).subtract(rm.multiply(rm));
			

			BigInteger disc, n;
			
			n = BigInteger.ONE;

			//quadratic formula where disc is the discriminant
			
			disc = (   (c.add(BigInteger.valueOf(2))).multiply( c.add(BigInteger.valueOf(2)) )    ).subtract( (c.subtract(p)).multiply(BigInteger.valueOf(8)));
			disc = sqrt(disc);
			n = c.multiply(BigInteger.valueOf(-1)).subtract(BigInteger.valueOf(2)).add(disc).divide(BigInteger.valueOf(4));
			//disc = (c+2)*(c+2) - (c-pp)*4*2;

			//n = ((c*-1 - 2) + sqrt(disc))/4;





			out.println("Case #"+ (_t+1) + ": " + (n.add(BigInteger.ONE)).toString() );
		}



		sc.close();
		out.close();
	}
	
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
}

