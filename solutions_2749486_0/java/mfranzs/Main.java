///REMOVE ALL OUTPUT AND USE STRINGTOKENIZER!

/*
 ID: mfranzs1
 LANG: JAVA
 TASK: template
 */
import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader f;
	static StringTokenizer st;
	static PrintWriter out;
	static long unixTime;

	public static void main(String[] args) throws Exception {
		unixTime = System.currentTimeMillis();
		// Use BufferedReader rather than RandomAccessFile; it's much faster
		f = new BufferedReader(new java.io.InputStreamReader(System.in));

		// input file name goes above
		out = new PrintWriter(
				new BufferedWriter(new FileWriter("out.out")));

		int Tests = nextInt();
		for (int test = 0; test < Tests; test++) {
			int x=nextInt();
			int y= nextInt();
			out.print("Case #"+(test+1)+": ");
			if(x<0){
				for(int i=0;i<Math.abs(x);i++){
					out.print("EW");
				}
			}else{
				for(int i=0;i<Math.abs(x);i++){
					out.print("WE");
				}
			}
			if(y<0){
				for(int i=0;i<Math.abs(y);i++){
					out.print("NS");
				}
			}else{
				for(int i=0;i<Math.abs(y);i++){
					out.print("SN");
				}
			}
			out.println();
		}
		out.close(); // close the output file

		System.out.println("Time elapsed (ms): "
				+ (System.currentTimeMillis() - unixTime));

		System.exit(0); // don't omit this!
	}

	// Library
	static void finish() {
		out.close(); // close the output file

		System.out.println("Time elapsed (ms): "
				+ (System.currentTimeMillis() - unixTime));

		System.exit(0); // don't omit this!
	}
	
	static void d(String s){
		System.out.println(s);
	}

	static int nextInt() throws Exception {
		return Integer.parseInt(next());
	}

	static String next() throws Exception {
		while (st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(f.readLine());
		}
		return st.nextToken();
	}

	private static long gcd(long a, long b) {
		while (b > 0) {
			long temp = b;
			b = a % b; // % is remainder
			a = temp;
		}
		return a;
	}

	private static long gcd(long[] input) {
		long result = input[0];
		for (int i = 1; i < input.length; i++)
			result = gcd(result, input[i]);
		return result;
	}

	private static long lcm(long a, long b) {
		return a * (b / gcd(a, b));
	}

	private static long lcm(long[] input) {
		long result = input[0];
		for (int i = 1; i < input.length; i++)
			result = lcm(result, input[i]);
		return result;
	}

	private static boolean isAPalindrome(String s) {// Running Time: Linear,
													// s.length()/2
		for (int i = 0; i < s.length() / 2 + 1; i++) {
			if (!(s.charAt(i) == s.charAt(s.length() - i - 1))) {
				return false;
			}
		}
		return true;
	}

	private static boolean isPrime(int finalnum) {// Running tmime: Sqrt,
													// sqrt(finalnum)/2
		if (finalnum % 2 == 0)
			return false;
		for (int i = 3; i <= Math.sqrt(finalnum); i += 2) {
			if (finalnum % i == 0) {
				return false;
			}
		}
		return true;
	}

	public static boolean lineSegmentsIntersect(double l1x1, double l1y1,
			double l1x2, double l1y2, double l2x1, double l2y1, double l2x2,
			double l2y2) {
		// need to check this
		double m1 = (l1y1 - l1y2) / (l1x1 - l1x2);
		double m2 = (l2y1 - l2y2) / (l2x1 - l2x2);

		double b1 = l1y1 - m1 * l1x1;
		double b2 = l2y1 - m2 * l2x1;

		if (m1 == m2)// Parallel
		{
			return b1 == b2;
		} else {// Intersect somewhere
				// Intersection point:
			double ix, iy;
			if (Double.isInfinite(m1)) {
				ix = l1x1;
				iy = m2 * ix + b2;
			} else if (Double.isInfinite(m2)) {
				ix = l1x2;
				iy = m1 * ix + b1;
			} else {
				ix = (b2 - b1) / (m1 - m2);
				iy = m1 * ix + b1;
			}

			if ((iy <= l1y1 && iy >= l1y2) || (iy >= l1y1 && iy <= l1y2)) {// Inside
																			// y's
																			// of
																			// first
																			// line
				if ((ix <= l1x1 && ix >= l1x2) || (ix >= l1x1 && ix <= l1x2)) {// Inside
																				// x's
																				// of
																				// first
																				// line
					if ((iy <= l2y1 && iy >= l2y2)
							|| (iy >= l2y1 && iy <= l2y2)) {// Inside y's of 2nd
															// line
						if ((ix <= l2x1 && ix >= l2x2)
								|| (ix >= l2x1 && ix <= l2x2)) {// Inside x's of
																// 2nd line
							return true;
						}
					}
				}
			}
		}

		return false;
	}
	private static int combination(int n, int k){
		int r=1;
		for(int i=n;i>k;i--){
			r*=i;
		}
		for(int i=n-k;i>1;i--){
			r/=i;
		}
		return r;
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