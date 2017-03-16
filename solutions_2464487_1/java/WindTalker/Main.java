import java.math.BigInteger;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;


public class Main {
	public static BigInteger bigIntSqRootFloor(BigInteger x)
	        throws IllegalArgumentException {
	    if (x.compareTo(BigInteger.ZERO) < 0) {
	        throw new IllegalArgumentException("Negative argument.");
	    }
	    // square roots of 0 and 1 are trivial and
	    // y == 0 will cause a divide-by-zero exception
	    if (x == BigInteger.ZERO || x == BigInteger.ONE) {
	        return x;
	    } // end if
	    BigInteger two = BigInteger.valueOf(2L);
	    BigInteger y;
	    // starting with y = x / 2 avoids magnitude issues with x squared
	    for (y = x.divide(two);
	            y.compareTo(x.divide(y)) > 0;
	            y = ((x.divide(y)).add(y)).divide(two));
	    return y;
	} // end bigIntSqRootFloor
	
	
	public static void main(String args[])
	{
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		int i = 1;
		
		
		while( i <= T)
		{
			BigInteger r = in.nextBigInteger();
			BigInteger t = in.nextBigInteger();

			BigInteger two_r_minus_1 = r.add(r).subtract(BigInteger.ONE);
			
			BigInteger n = bigIntSqRootFloor(  two_r_minus_1.multiply(two_r_minus_1).add(t.multiply(new BigInteger("8") )  ) ).subtract(two_r_minus_1).divide(new BigInteger("4"));

			System.out.println("Case #" + i + ": " + n.toString());
			
			i++;
		}

		
	}
	
}

