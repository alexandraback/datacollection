import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class A {

	public static void main( final String[] args ) throws Exception {
		final BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		final int T = toi( br.readLine() );
		for ( int ii = 0; ii < T; ++ii ) {
			final int[] t = toi( br.readLine().split( " " ) );
			final int N = t[ 0 ];
			final int[] s = new int[N];
			for ( int i = 0; i < N; ++i ) {
				s[ i ] = t[ i + 1 ];
			}
			System.out.println( print( solve( N, s ), ii + 1 ) );
		}
	}

	private static String print( final Double[] res, final int i ) {
		final StringBuilder buff = new StringBuilder();
		for ( int j = 0; j < res.length; ++j ) {
			buff.append( ' ' ).append( 100 * res[ j ] );
		}
		return String.format( "Case #%d:%s", i, buff.toString() );
	}

	public static Double[] solve( final int N, final int[] s ) {
		final Double[] res = new Double[N];
		Arrays.fill( res, null );
		//		final int[] sc = Arrays.copyOf( s, s.length );
		//		Arrays.sort( sc );
		//		final int max = sc[ N - 1 ];
		//		final int max2 = sc[ N - 2 ];
		int X = 0;
		for ( int i = 0; i < N; ++i ) {
			X += s[ i ];
		}

		final double mean = 2D * X / N;
		int cnt = 0; // < mean
		int sum = 0;
		for ( int i = N - 1; i >= 0; --i ) {
			if ( s[ i ] >= mean )
				res[ i ] = 0D;
			else {
				++cnt;
				sum += s[ i ];
			}
		}
		for ( int i = 0; i < N; ++i ) {
			if ( res[ i ] == null ) {
				res[ i ] = solve2( s[ i ], X, sum, cnt );
			}
		}
		return res;
	}

	private static double solve2( final double si, final double x, final double sum, final double n ) {
		final double mean = ( x + sum ) / n;
		if ( si >= mean ) return 0;
		return ( mean - si ) / x;
	}

	//	// sact + X * y >= smax + X * (1-y)
	//	private static double eqSolve( final double sact, final double x, final double smax ) {
	//		// sact + X * y >= smax + X * (1-y)
	//		// sact + X * y >= smax + X - X * y
	//		// 2 * X*y >= smax + X - sact
	//		// y >= (smax + X -sact ) / 2*X
	//		return ( smax + x - sact ) / ( 2 * x );
	//	}

	// *** helper methods ***

	public static int toi( final String s ) {
		return Integer.parseInt( s );
	}

	public static int[] toi( final String[] sa ) {
		final int[] res = new int[sa.length];
		for ( int i = 0; i < res.length; ++i ) {
			res[ i ] = toi( sa[ i ] );
		}
		return res;
	}

	public static long tol( final String s ) {
		return Long.parseLong( s );
	}

	public static long[] tol( final String[] sa ) {
		final long[] res = new long[sa.length];
		for ( int i = 0; i < res.length; ++i ) {
			res[ i ] = tol( sa[ i ] );
		}
		return res;
	}

	public static double tod( final String s ) {
		return Long.parseLong( s );
	}

	public static double[] tod( final String[] sa ) {
		final double[] res = new double[sa.length];
		for ( int i = 0; i < res.length; ++i ) {
			res[ i ] = tod( sa[ i ] );
		}
		return res;
	}

}
