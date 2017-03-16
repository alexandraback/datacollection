	import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;
/* 
 * Problem A. 
 */
public class C {
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
	
	public static void main(String[] args) throws Exception {
		precomp();

		nextLine();
		int Cases = nextInt();
		for (int Case=0; Case<Cases; Case++) {

			nextLine();
			long A = nextLong();
			long B = nextLong();
			
			long rootA = (long)Math.ceil(Math.sqrt(A));
			long rootB = (long)Math.floor(Math.sqrt(B));
			
			long ans=0;
			for (long x = rootA; x <= rootB; x++) {
				if (check(x) && check(x*x)) {
					ans++;
				}
			}
			
			System.out.print("Case #" + (Case+1) + ": " + ans);
			System.out.println();

		} // end for each case

	} // end main

	static boolean check(long x) {
		String s = String.valueOf(x);
		int n = s.length();
		for (int i=0; i<n/2; i++) {
			if (s.charAt(i) != s.charAt(n-i-1)) return false;
		}
		return true;
	}

}
