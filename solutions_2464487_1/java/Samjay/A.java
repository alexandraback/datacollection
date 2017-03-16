package con2013R1A;

import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class A {

	private static final String islarge = "-large";
	private static final String fileName = "results/con2013R1A/"+A.class.getSimpleName().toLowerCase()+islarge;
	private static final String inputFileName = fileName + ".in";
	private static final String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;
	
	static final int MAX = 2000000000;
	static final BigInteger MAX_LONG = BigInteger.valueOf(Long.MAX_VALUE);
	static final BigInteger TWO = BigInteger.valueOf(2);
	static BigInteger start;
	private void solve() {
		BigInteger r = BigInteger.valueOf(in.nextLong()),
				t = BigInteger.valueOf(in.nextLong());
		BigInteger rdiv = BigInteger.valueOf(r.longValue()/2);
		boolean isEven = r.mod(TWO).intValue()==0;
		start = BigInteger.ZERO;
		start = calculateScore(rdiv, BigInteger.ZERO, !isEven);
		int low=1, high=MAX,mid=0;
		int best = 0;
		while (low <= high) {
			mid = (low + high) / 2;
			BigInteger res = calculateScore(BigInteger.valueOf(mid),rdiv,!isEven);
			if (res.compareTo(t) > 0) {
				high = mid - 1;
			} else {
				best = Math.max(mid, best);
				low = mid + 1;
			}
		}
		out.println(best);
		System.out.println(best);
	}

	BigInteger calculateScore(BigInteger x, BigInteger r, boolean even){
		x = x.add(r);
		// x*((2*x)-1)
		if(even)
			return x.multiply(TWO.multiply(x).add(BigInteger.ONE)).subtract(start);
		// (x)*((2*x)+1)
		return x.multiply(TWO.multiply(x).subtract(BigInteger.ONE)).subtract(start);

	}
	
	public static int find(int[] a, int key) {
		int low=0,high=a.length-1,mid=0;
		while (low <= high) {
			mid = (low + high) / 2;
			if (a[mid] > key) {
				high = mid - 1;
			} else if (a[mid] < key) {
				low = mid + 1;
			} else {
				return mid;
			}
		}
		return -1;
	}
	
	public static void main(String[] args) throws IOException {
		long start = System.currentTimeMillis();
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			new A().solve();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
		long stop = System.currentTimeMillis();
		System.out.println(stop-start+" ms");
	}
}
