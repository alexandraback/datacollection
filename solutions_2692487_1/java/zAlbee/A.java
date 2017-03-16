import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;

public class A {
	static BufferedReader _in = new BufferedReader(new InputStreamReader(System.in));
	static String _string;
	static StringTokenizer _stok;
	static String nextLine() throws IOException {
		_string = _in.readLine();
		_stok = new StringTokenizer(_string);
		return _string;}
	static String nxT() {return _stok.nextToken();}
	static String nxW() {while (!_stok.hasMoreTokens())
		try {nextLine();} catch (IOException e) {e.printStackTrace();}
		return _stok.nextToken();}
	static int nxI()		{return Integer.parseInt(nxW());} // 2.1 x 10^9, 
	static long nxL()		{return Long.parseLong(nxW());}   // 9.2 x 10^18, 
	static float nxF()	{return Float.parseFloat(nxW());}
	static double nxD() 	{return Double.parseDouble(nxW());}
	static BigInteger nxB()	{return new BigInteger(nxW());}
	static void Dprint(Object s)   {if (debug) System.out.print(s);}
	static void Dprintln(Object s) {if (debug) System.out.println(s);}
	static void Dprintln()         {if (debug) System.out.println();}
	static void Dprintf(String s, Object... args) {if (debug) System.out.printf(s, args);}
	static void print(Object s)   {System.out.print(s);}
	static void println(Object s) {System.out.println(s);}
	static void println()         {System.out.println();}
	static void printf(String s, Object... args) {System.out.printf(s, args);}
	
	static boolean debug = false;
	static final int LASTPUSH = 0; // index of last push time
	static final int POS = 1; // index of last position

	public static void main(String[] args) throws Exception {

		nextLine();
		int Cases = nxI();
		for (int Case=0; Case<Cases; Case++) {

			int ans = 0;

			nextLine();
			int A = nxI();
			int N = nxI();
			int[] sizes = new int[N];
			
			nextLine();
			for (int i=0; i<N; i++) {
				sizes[i] = nxI();
			}
			
			Arrays.sort(sizes);
			
			int done = 0;
			
			for (int i=0; i<N; i++) {
				if (A > sizes[i]) {
					A += sizes[i];
					done = i+1;
					Dprintf("%d + %d = %d\n", A-sizes[i], sizes[i], A);
				} else {
					break;
				}
			}
			
			if (done == N) ans = 0;
			else {
				int best = N-done;
				int ascore = 0;
				for (int i=done; i<N; i++) {
					if (A <= 1) break;
					while (A <= sizes[i]) {
						Dprintf(" added %d\n", A-1);
						A += A - 1;
						Dprintf("%d + %d = %d\n", (A+1)/2, (A-1)/2, A);
						ascore++;
					}
					A += sizes[i];
					Dprintf("%d + %d = %d\n", A-sizes[i], sizes[i], A);
					int dscore = ascore + N-i-1; // deletes
					Dprintf("best: %d, d %d, a %d\n", best, dscore, ascore);
					if (dscore < best) best = dscore;
					if (ascore >= best) break;
				}
				ans = best;
			}
			System.out.println("Case #" + (Case+1) + ": " + ans);
			Dprintln();
			
		} // end for each case

	} // end main
	

}

