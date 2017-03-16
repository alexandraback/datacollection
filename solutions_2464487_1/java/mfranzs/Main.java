import java.io.*;
import java.util.*;
import java.math.BigDecimal;

public class Main {
	static BufferedReader f;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws Exception {

		// Use BufferedReader rather than RandomAccessFile; it's much faster
		f = new BufferedReader(new java.io.InputStreamReader(System.in));

		out = new PrintWriter(new BufferedWriter(new FileWriter("out.out")));

		long unixTime = System.currentTimeMillis();

		int Tests = nextInt();
		for (int test = 0; test < Tests; test++) {
			long radius = new Long(next());
			BigDecimal paint = new BigDecimal(next());
			System.err.println(radius + " " + paint);
			long n = (radius - 1) / 2;
			if(radius%2==0){
				n=radius/2;
			}
			BigDecimal bdn=new BigDecimal(n);
			System.err.println(bdn.toString());
			BigDecimal usedbycurrentradius = bdn.multiply(bdn).multiply(new BigDecimal("2")).add(bdn);
			if(radius%2==0){
				usedbycurrentradius=usedbycurrentradius.subtract(bdn).subtract(bdn);
			}
			paint=paint.add(usedbycurrentradius);
			BigDecimal sqrtOf=paint.multiply(new BigDecimal("8")).add(new BigDecimal("1"));
			System.out.println(sqrtOf.toString());
			long sqrt=sqrt(sqrtOf).longValue();//Math.sqrt(1 + 8 * paint)
			System.out.println(sqrt);
			long rings = (-1 + sqrt) / 4;
			if(radius%2==0)rings=(1+sqrt)/4;
			System.err.println(n + " " + usedbycurrentradius + " " + paint
					+ " " + rings);
			out.println("Case #" + (test + 1) + ": " + (int) (rings - n));
		}

		out.close();
		System.out.println("Time elapsed (ms): "
				+ (System.currentTimeMillis() - unixTime));

		System.exit(0); // don't omit this!
	}

	/*
	 * Find Square Root of BigInteger Example This Java example shows how to
	 * find square root of BigInteger using NEWTON's method.
	 */

	public static BigDecimal sqrt(BigDecimal myNumber) {

		BigDecimal g = new BigDecimal("1");
		BigDecimal my2 = new BigDecimal("2");
		BigDecimal epsilon = new BigDecimal("0.0000000001");

		BigDecimal nByg = myNumber.divide(g, 9, BigDecimal.ROUND_FLOOR);

		// Get the value of n/g
		BigDecimal nBygPlusg = nByg.add(g);

		// Get the value of "n/g + g
		BigDecimal nBygPlusgHalf = nBygPlusg.divide(my2, 9,
				BigDecimal.ROUND_FLOOR);

		// Get the value of (n/g + g)/2
		BigDecimal saveg = nBygPlusgHalf;
		int firsttime = 99;

		do {			
			g = nBygPlusgHalf;
			nByg = myNumber.divide(g, 9, BigDecimal.ROUND_FLOOR);
			nBygPlusg = nByg.add(g);
			nBygPlusgHalf = nBygPlusg.divide(my2, 9, BigDecimal.ROUND_FLOOR);
			BigDecimal savegdiff = saveg.subtract(nBygPlusgHalf);

			if (savegdiff.compareTo(epsilon) == -1) {
				firsttime = 0;
			} else {
				saveg = nBygPlusgHalf;
			}

		} while (firsttime > 1);
		return saveg;

	}

	// Library

	static int nextInt() throws Exception {
		return Integer.parseInt(next());
	}

	static String next() throws Exception {
		while (st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(f.readLine());
		}
		return st.nextToken();
	}

}

class ii {
	int a;
	int b;

	public ii(int a, int b) {
		this.a = a;
		this.b = b;
	}
}