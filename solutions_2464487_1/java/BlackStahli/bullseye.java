import java.util.*;
import java.io.*;
import java.math.BigInteger;
public class bullseye {
	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader (new FileReader ("A-large (1).in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("bull.out")));
		int n = Integer.parseInt(in.readLine());
		for(int i = 0; i<n;i++) {
			//solve here
			StringTokenizer s = new StringTokenizer(in.readLine());
//			long r = Long.parseLong(s.nextToken());
//			long t = Long.parseLong(s.nextToken());
			BigInteger r_b = new BigInteger(s.nextToken(),10);
			BigInteger t_b = new BigInteger(s.nextToken(),10);
			BigInteger sqr = bigIntSqRootFloor((r_b.multiply(BigInteger.valueOf(2)).subtract(BigInteger.ONE).pow(2).add(BigInteger.valueOf(8).multiply(t_b))));
			BigInteger total = sqr.subtract(r_b.multiply(BigInteger.valueOf(2))).add(BigInteger.ONE).divide(BigInteger.valueOf(4));
			out.println("Case #" + (i+1) + ": " + total);
		}
		out.close();
		in.close();
	}
	
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

	public static BigInteger bigIntSqRootCeil(BigInteger x)
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
	    if (x.compareTo(y.multiply(y)) == 0) {
	        return y;
	    } else {
	        return y.add(BigInteger.ONE);
	    }
	}
}
