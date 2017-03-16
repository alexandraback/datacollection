import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

// https://code.google.com/codejam/contest/6254486/dashboard#s=p2

// not very optimised

public class JamCoin {
	private static final BigInteger TWO = BigInteger.valueOf( 2 );

	private static BigInteger findFactor( final BigInteger value ) {
		// thanks, http://stackoverflow.com/a/16804552/1180785
		if( value.mod( TWO ).equals( BigInteger.ZERO ) ) {
			return TWO;
		}
		BigInteger f = BigInteger.valueOf( 3 );
		while( f.multiply( f ).compareTo( value ) <= 0 ) {
			if( value.mod( f ).equals( BigInteger.ZERO ) ) {
				return f;
			}
			f = f.add( TWO );
		}
		return null;
	}

	private static boolean testJamcoin( final String jamcoin, final int maxBase ) {
		for( int base = 2; base <= maxBase; ++ base ) {
			final BigInteger value = new BigInteger( jamcoin, base );
			if( value.isProbablePrime( 5 ) ) {
				if( findFactor( value ) == null ) {
					return false;
				}
			}
		}
		return true;
	}

	private static List<String> mineJamcoins( final int N, final int maxBase, final int limit ) {
		if( N < 2 || limit <= 0 ) {
			return Collections.emptyList( );
		}
		final int fill = N - 2;
		final List<String> jamcoins = new ArrayList<>( limit );

		char[] builder = new char[N];
		builder[0] = '1';
		for( int i = 0; i < fill; ++ i ) {
			builder[i+1] = '0';
		}
		builder[N-1] = '1';

		while( true ) {
			// test current value
			final String value = new String( builder );
			if( testJamcoin( value, maxBase ) ) {
				jamcoins.add( value );
				if( jamcoins.size( ) >= limit ) {
					return jamcoins; // limit reached
				}
			}

			// step to next test value
			int p = 1;
			while( builder[p] == '1' ) {
				builder[p] = '0';
				if( (++ p) > fill ) {
					return jamcoins; // no more values to test
				}
			}
			builder[p] = '1';
		}
	}

	public static void main( final String[] args ) {
		final int maxBase = 10;
		final Scanner input = new Scanner( System.in );
		final int totalTests = input.nextInt( );
		for( int n = 0; n < totalTests; ++ n ) {
			final int N = input.nextInt( );
			final int J = input.nextInt( );
			final List<String> jamcoins = mineJamcoins( N, maxBase, J );
			System.out.println( "Case #" + (n + 1) + ":" );
			for( final String jamcoin : jamcoins ) {
				System.out.print( jamcoin );
				for( int base = 2; base <= maxBase; ++ base ) {
					System.out.print( " " + findFactor( new BigInteger( jamcoin, base ) ) );
				}
				System.out.println( );
			}
		}
	}
}
