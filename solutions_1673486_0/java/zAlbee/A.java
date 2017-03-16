import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;
/* 
 * Problem A. 
 */
public class A {
	static BufferedReader _in = new BufferedReader(new InputStreamReader(System.in));
	static String _string;
	static StringTokenizer _stok;
	static String nextLine() throws IOException {
		_string = _in.readLine();
		_stok = new StringTokenizer(_string);
		return _string;}
	static String nextWord()	{return _stok.nextToken();}
	static int nextInt()		{return Integer.parseInt(nextWord());} // 2.1 x 10^9, 
	static long nextLong()		{return Long.parseLong(nextWord());}   // 9.2 x 10^18, 
	static double nextDouble() 	{return Double.parseDouble(nextWord());}
	static BigInteger nextBig()	{return new BigInteger(nextWord());}
	static void Dprintln(Object s) 	{if(debug) System.out.println(s);}
	static void Dprintln() 	{if(debug) System.out.println();}
	static void Dprint(Object s) 	{if(debug) System.out.print(s);}
	static void Dprintf(String s, Object... args) 	{if(debug) System.out.printf(s, args);}
	static void print(Object s) {System.out.print(s);}
	static void println(Object s) {System.out.println(s);}
	static void println() 	{System.out.println();}
	static void printf(String s, Object... args) {System.out.printf(s, args);}
	
	static boolean debug = false;
	
	static void precomp() {
	}
	
	static int rstrokes(int a, int b, int d) {
		return d + (b - a + d) + 1;
	}
	static int wstrokes(int a, int b, int d) {
		return rstrokes(a,b,d) + b + 1;
	}
	static int estrokes(int b) {
		return b+2;
	}
	
	public static void main(String[] args) throws Exception {
		precomp();

		nextLine();
		int Cases = nextInt();
		for (int Case=0; Case<Cases; Case++) {
			nextLine();
			int a = nextInt();
			int b = nextInt();
			nextLine();
			double[] p = new double[a];
			for (int i=0; i<a; i++) {
				p[i] = nextDouble();
			}
			double best = b+2; // enter right away
			for (int d=0; d<=a; d++) {
				double pr = 1;
				for (int i=0; i<a-d; i++) {
					pr = pr * (p[i]);
				}
				double s = pr*rstrokes(a,b,d) + (1-pr)*wstrokes(a,b,d);
				Dprintf("right = %f*%d, wrong=%f*%d, total %f\n", pr, rstrokes(a,b,d), 1-pr, wstrokes(a,b,d), s);
				if (s < best) best = s;
			}
			System.out.println("Case #" + (Case+1) + ": " + (best));

		} // end for each case

	} // end main

	static long gcd(long a, long b) {
		if (b > a) return gcd(b,a);
		if (b == 0) return a;
		return gcd(b, a % b);
	}

}
