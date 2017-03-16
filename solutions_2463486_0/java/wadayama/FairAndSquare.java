import java.io.*;
import java.util.*;

public class FairAndSquare {

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
			long A = sc.nextLong();
			long B = sc.nextLong();
			long ret = 0;
			
			long n = 1;
			while( true ) {
				long[] mm = genpalin( n );
				if( mm[0] > Integer.MAX_VALUE ) break;
				
				long m0 = mm[0] * mm[0];
				long m1 = mm[1] * mm[1];
				
				if( m1 > B ) break;
				if( ispalin(m0) ) {
					if( m0 >= A && m0 <= B ) ret++;
				}
				if( ispalin(m1) ) {
					if( m1 >= A && m1 <= B ) ret++;
				}
				n++;
			}
			
//			System.out.println("Case #" + a + ": " + ret );
			fout.println("Case #" + a + ": " + ret );
		}

		fout.close();
		sc.close();
	}

	static long[] genpalin( long a ) {
		long ret1 = a, ret2 = a;
		ret1 = ret1 * 10 + ( a % 10 );
		a /= 10;

		while( a > 0 ) {
			long b = a % 10;
			ret1 = ret1 * 10 + b;
			ret2 = ret2 * 10 + b;
			a /= 10;
		}
		return new long[]{ ret1, ret2 };
	}
	
	static boolean ispalin( long a ) {
		long b = a, c = 0;
		while( b > 0 ) {
			c = c * 10 + ( b % 10 );
			b /= 10;
		}
		if( a == c ) return true;
		return false;
	}
}

