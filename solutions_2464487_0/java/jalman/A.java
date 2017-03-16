import java.io.*;
import java.util.*;
import java.math.BigInteger;


public class A{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("in.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("out.txt"));

		int T = Integer.parseInt(br.readLine());

		for(int i = 1; i <= T; i++) {
			String[] s = br.readLine().split(" ");


			BigInteger big = new BigInteger(s[0]);
			//System.out.println(big);
			big = big.multiply(new BigInteger("2"));
			//System.out.println(big);
			big = big.subtract(new BigInteger("1"));
			//System.out.println(big);
			big = big.multiply(big);
			//System.out.println(big);
			big = big.add((new BigInteger(s[1])).multiply(new BigInteger("8")));

			//System.out.println(big);

			big = bigIntSqRootFloor(big);
			//System.out.println(big);

			BigInteger tmp = (new BigInteger(s[0])).multiply(new BigInteger("2"));
			//System.out.println(tmp);

			big = big.subtract(tmp);
			//System.out.println(big);

			big = big.add(new BigInteger("1"));

			big = big.divide(new BigInteger("4"));


			pw.println("Case #" + i + ": " + big);
			//System.out.println("-----");
		}


		pw.flush();
		pw.close();
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
}