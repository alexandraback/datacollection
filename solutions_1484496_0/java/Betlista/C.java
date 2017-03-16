import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class C {

	public static void main( final String[] args ) throws Exception {
		final BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		final int T = toi( br.readLine() );
		for ( int ii = 0; ii < T; ++ii ) {
			final int t[] = toi( br.readLine().split( " " ) );
			final int[] s = new int[t[ 0 ]];
			for ( int i = 0; i < s.length; ++i ) {
				s[ i ] = t[ i + 1 ];
			}
			System.out.printf( "Case #%d:\n%s\n", ii + 1, solve( s ) );
		}
	}

	public static String solve( final int[] s ) {
		final int n = s.length;
		final Map<Long, Integer> map = new HashMap<Long, Integer>();
		for ( int i = 0; i < 1 << n; ++i ) {
			long sum = 0;
			for ( int j = 0; j < n; ++j ) {
				if ( ( i & ( 1 << j ) ) > 0 ) {
					sum += s[ j ];
				}
			}
			final Integer val = map.get( sum );
			if ( val == null )
				map.put( sum, i );
			else {
				return print( val, i, s );
			}
		}
		return "Impossible";
	}

	private static String print( final int i1, final int i2, final int[] s ) {
		return map( i1, s ) + "\n" + map( i2, s );
	}

	private static String map( final int n, final int[] s ) {
		final StringBuilder buff = new StringBuilder();
		for ( int i = 0; i < s.length; ++i ) {
			if ( ( n & ( 1 << i ) ) > 0 ) {
				buff.append( ' ' ).append( s[ i ] );
			}
		}
		return buff.delete( 0, 1 ).toString();
	}

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
