import java.io.FileReader;
import java.io.BufferedReader;
// import static java.lang.Math;

class A {

	public static void main( String[] args ) throws Exception {
		// Read input
		BufferedReader br = new BufferedReader( new FileReader( args[0] ) );

		// Get the first line - number of tests
		int numTests = Integer.parseInt( br.readLine() );

		// Loop
		for ( int testNo = 1; testNo <= numTests; testNo++ ) {
			System.out.print( "Case #" + testNo + ": " );

			int res = getResult( br );
			if ( res == -1 ) {
				System.out.println( "impossible" );
			} else {
				System.out.println( res );
			}
		}

		//Close br
		br.close();
	}

	public static int getResult( BufferedReader br ) throws Exception {
		String[] values = br.readLine().split("/");
		int a = Integer.parseInt( values[0] );
		int b = Integer.parseInt( values[1] );
		int counter = 0;

		return getGen( a, b, 0 );
	}

	public static int getGen( int a, int b, int counter ) {
		while ( counter < 40 ) {
			if ( a == b ) {
				return counter;
			} else if ( a < b ) {
				a = a*2;
				counter++;
			} else {
				int r = a - b;
				if ( b % 2 == 0 ) {
					int common = gcd( b, r );
					b = b/common;
					r = r/common;
					if ( getGen( r, b, counter ) != -1 ) {
						return counter;
					} else {
						return -1;
					}
				} else {
					return -1;
				}
			}
		}

		return -1;
	}

	// a is the larger number
	public static int gcd( int a, int b ) {
		if ( a % b == 0 ) {
			return b;
		} else {
			return gcd( b, a % b );
		}
	}
}