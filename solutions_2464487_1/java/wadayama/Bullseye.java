import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class Bullseye {

	public static void main(String[] args) {
		Scanner sc = null;
		PrintWriter fout = null;
		int T = 0;

		try {
			sc = new Scanner(new File(args[0]));
			fout = new PrintWriter(new BufferedWriter(new FileWriter("result.txt")));
			T = sc.nextInt();
		}
		catch( Exception e ) {
			System.out.println(e);
		}

		for( int a = 1; a <= T; a++ ) {
			long r = sc.nextLong();
			long t = sc.nextLong();
			long n2 = Math.min( t / ( 2 * r ) + 1L, 1000000000L );
			long res = doit( r, t, 1, n2 );
			
//			System.out.println("Case #" + a + ": " + res );
			fout.println("Case #" + a + ": " + res );
		}

		fout.close();
		sc.close();
	}
	
	static long doit( long r, long t, long n1, long n2 ) {
		long n = ( n1 + n2 ) / 2;
		if( n2 - n1 ==1 || n1 == n2 ) return n1;
		if( 2 * n * n + (2*r-1) * n - t > 0 ) {
			return doit( r, t, n1, n );
		}
		else {
			return doit( r, t, n, n2 );
		}
	}

}
