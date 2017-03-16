	import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;
/* 
 * Problem A. 
 */
public class C2 {
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
	
	static List<Long> fairs = new ArrayList<Long>();
	
	static void precomp() {
		long maxRoot = (long)Math.pow(10,7);
		for (long x = 1; x <= maxRoot; x++) {
			if (check(x) && check(x*x)) {
				fairs.add(x);
				//Dprintf("%d %d\n", x, x*x);
			}
		}
		
		//makeTest();
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
			
			long i = Collections.binarySearch(fairs, rootA);
			long j = Collections.binarySearch(fairs, rootB);
			if (i < 0) {
				i = -i-1;
			}
			if (j < 0) {
				j = -j-1-1;
			}
			ans = j - i + 1;
			
			
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
	
	static void makeTest() {
		long last;
		println(fairs.size());
		for (int i=0; i<fairs.size()-1; i++) {
			long a = fairs.get(i);
			long b = fairs.get(i+1);
			printf("%d %d\n", a*a+1, b*b);
		}
		long a = fairs.get(0);
		long b = fairs.get(fairs.size()-1);
		printf("%d %d\n", a*a+1, b*b);
	}
}
