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
	
	static boolean debug = false;
	
	static void precomp() {
	}
	
	public static void main(String[] args) throws Exception {
		precomp();

		nextLine();
		int Cases = nextInt();
		for (int Case=0; Case<Cases; Case++) {
			
			nextLine();
			int N = nextInt();
			int M = nextInt();
			int[][] grid = new int[N][M];
			
			for (int i=0; i<N; i++) {
				nextLine();
				for (int j=0; j<M; j++) {
					grid[i][j] = nextInt();
				}
			}
			int[] rowmax = new int[N];
			int[] colmax = new int[M];
			for (int i=0; i<N; i++) {
				for (int j=0; j<M; j++) {
					if (grid[i][j] > rowmax[i]) rowmax[i] = grid[i][j];
					if (grid[i][j] > colmax[j]) colmax[j] = grid[i][j];
				}
			}
			boolean ans = true;
			outer:
			for (int i=0; i<N; i++) {
				for (int j=0; j<M; j++) {
					if (grid[i][j] < rowmax[i] && grid[i][j] < colmax[j]) {
						ans = false;
						break outer;
					}
				}
			}

			for (int i=0; i<N; i++) {
				for (int j=0; j<M; j++) {
					Dprintf("%d ", grid[i][j]);
				}
				Dprintf("<%d> \n", rowmax[i]);
			}
			Dprintln("------");
			for (int j=0; j<M; j++) {
				Dprintf("%d ", colmax[j]);
			}
			Dprintln();
			

			System.out.println("Case #" + (Case+1) + ": " + (ans ? "YES":"NO"));

		} // end for each case

	} // end main

}
