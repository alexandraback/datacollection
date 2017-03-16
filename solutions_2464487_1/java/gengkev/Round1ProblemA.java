

import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Round1ProblemA {	// let's just read standard input guys
	private static final String outputFile = "round1problemA.out";
	
	private static boolean debug = false; // print log statements
	private static BufferedReader br;
	private static PrintWriter out;
	private static String nl;
	
	private static BigInteger bigIntegerTwo = new BigInteger("2");
	
	private static void readNextLine() throws IOException {
		if (debug) {
			System.out.print("INPUT: ");
		}
		nl = br.readLine();
	}
	
	private static void log(String bla) {
		if (debug) {
			System.out.println("LOG: " + bla);
		}
	}
	
	private static void printOutput(String line) {
		//if (debug) {
			System.out.println("OUTPUT: " + line);
		//}
		out.println(line);
	}
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader((System.in)));
		out = new PrintWriter(new BufferedWriter(new FileWriter(outputFile)));
		
		// begin program
		
		readNextLine();
		int T = Integer.parseInt(nl);
		
		log(T + " test cases");
		
		for (int i = 0; i < T; i++) {
			readNextLine();
			StringTokenizer st = new StringTokenizer(nl);
			
			BigInteger r = new BigInteger(st.nextToken());
			BigInteger t = new BigInteger(st.nextToken());
			
			String result = solve(r, t);
			
			printOutput("Case #" + (i + 1) + ": " + result.toString());
			
		}
		
		// end program
		
		out.close();
	}
	
	// r, t
	private static String solve(BigInteger r, BigInteger t) {
		BigInteger x = r.multiply(bigIntegerTwo).subtract(BigInteger.ONE); // 2r-1
		
		BigInteger guess = x.negate().divide(new BigInteger("4")).add(
				bigIntSqRootFloor(x.pow(2).add(t.multiply(new BigInteger("8"))).divide(new BigInteger("16")))
			);
		
		log(guess + "");
		
		BigInteger k = guess.subtract(new BigInteger("5"));
		if (k.compareTo(BigInteger.ONE) < 0) k = new BigInteger("1");
		
		while (yay(k, x, t)) { // less than result
			//log("Incrementing k:" + k.toString());
			k = k.add(BigInteger.ONE);
		}
		k = k.subtract(BigInteger.ONE);
		
		return k.toString() + "";
		
		/*
		BigInteger thingToSqrt = x.pow(2).add(t.multiply(new BigInteger("8"))).divide(new BigInteger("16"));
		BigInteger sqrtThing = bigIntSqRootFloor(thingToSqrt);
		log(sqrtThing + "");
		BigInteger result = x.negate().divide(new BigInteger("4")).add(thingToSqrt);
		
		return result.toString();
		*/
		
	}
	
	private static boolean yay(BigInteger k, BigInteger x, BigInteger t) {
		return k.pow(2).multiply(bigIntegerTwo).add(k.multiply(x)).compareTo(t) <= 0;
	}
	
	// Code from http://stackoverflow.com/a/11962756/689161
	
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