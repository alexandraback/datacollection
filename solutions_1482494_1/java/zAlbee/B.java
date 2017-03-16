import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;
/* 
 * Problem A. 
 */
public class B {
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
	
	static boolean debug = true;
	
	static void precomp() {
	}
	
	public static void main(String[] args) throws Exception {
		precomp();

		nextLine();
		int Cases = nextInt();
		for (int Case=0; Case<Cases; Case++) {
			nextLine();
			int n = nextInt();
			/*int req1[] = new int[n];
			int req2[] = new int[n];
			int done[] = new int[n];*/
			
			//List<T> ts = new ArrayList<T>();
			T[] ts = new T[n];
			for (int i=0;i<n;i++) {
				nextLine();
				T t = new T(nextInt(), nextInt(), i);
				ts[i] = t;
				//ts.add(t);
			}
			int count = 0, stars = 0;
			boolean fail = false; 
			while (true) {
				boolean mod = false;
				for (T t : ts) {
					if (t.done < 2 && t.req2 <= stars) {
						int diff = 2 - t.done;
						t.done = 2;
						stars += diff;
						count++;
						mod = true;
					}
				}
				if (mod) continue;
				
				// No more 2-star possible
				int best = 0;
				int besti = -1;
				for (T t : ts) {
					if (t.done < 1 && t.req1 <= stars) {
						int k = t.req2; // - t.req1;
						if (k > best) {
							besti = t.id;
							best = k;
						}
						mod = true;
					}
				}
				if (mod) {
					ts[besti].done = 1;
					count++;
					stars++;
					continue;
				}
				// No more 1-star possible
				for (T t : ts) {
					if (t.done < 2) {
						fail = true;
						break;
					}
				}
				break;
			}
			
			System.out.println("Case #" + (Case+1) + ": " + (fail ? "Too Bad" : count));

		} // end for each case

	} // end main
	
	static class T {
		int req1, req2, done=0, id;
		T(int a, int b, int c) {
			req1=a; req2=b; id=c;
		}
	}

}
