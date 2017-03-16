import java.util.*;
import java.io.*;
import static java.lang.Math.*;

class Main {

    public static void main( final String[] args ) {

		final Scanner stdin = new Scanner( System.in );
		final int T = stdin.nextInt();
		for ( int t = 1; t <= T; t++ ){
			solveSmall( stdin, t );
		}		
    }
	static void solveSmall( Scanner stdin, int t ) {
		final int a = stdin.nextInt();
		final int b = stdin.nextInt();
		final int k = stdin.nextInt();
			
		int count = 0;
		for ( int i = 0; i < a; i++ ) {
			for ( int j = 0; j < b; j++ ) {
				if ( ( i & j ) < k ) {
					count++;
				}
			}
		}
		System.out.printf( "Case #%d: %d\n", t, count );
	}
}
