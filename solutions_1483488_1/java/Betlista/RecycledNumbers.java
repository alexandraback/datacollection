import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;

public class RecycledNumbers {

	private static final boolean DEBUG = false;

	public static void main( final String[] args ) throws Exception {
		final BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		final int t = Integer.parseInt( br.readLine() );
		for ( int ii = 0; ii < t; ++ii ) {
			final String parts[] = br.readLine().split( " " );
			final int from = Integer.parseInt( parts[ 0 ] );
			final int to = Integer.parseInt( parts[ 1 ] );
			System.out.println( solve( ii + 1, from, to ) );
			if ( DEBUG ) System.out.println( "=== === === === ===" );
		}
	}

	private static String solve( final int idx, final int from, final int to ) {
		final HashSet<Long> set = new HashSet<Long>();
		for ( int i = from; i <= to; ++i ) {
			add( set, i, from, to );
		}
		return String.format( "Case #%d: %d", idx, set.size() );
	}

	private static void add( final HashSet<Long> set, final long n, final int from, final int to ) {
		final String ns = Long.toString( n );
		for ( int i = 1; i < ns.length(); ++i ) {
			final String f = ns.substring( 0, i );
			final String t = ns.substring( i );
			final long pair = getN( t, f );
			final long min = Math.min( n, pair );
			final long max = Math.max( n, pair );
			if ( from <= pair && pair <= to && pair != n )
				set.add( min * 3000000 + max );
		}
	}

	private static long getN( final String s1, final String s2 ) {
		long res = 0;
		for ( int i = 0; i < s1.length(); ++i ) {
			res += s1.charAt( i ) - '0';
			res *= 10;
		}
		for ( int i = 0; i < s2.length(); ++i ) {
			res += s2.charAt( i ) - '0';
			res *= 10;
		}
		if ( DEBUG ) System.out.printf( "DEBUG: s1='%s', s2='%s', res=%d\n", s1, s2, res / 10 );
		return res / 10;
	}

	@org.junit.Test
	public void statement1() {
		org.junit.Assert.assertEquals( String.format( "Case #%d: %d", 1, 0 ), solve( 1, 1, 9 ) );
	}

	@org.junit.Test
	public void statement2() {
		org.junit.Assert.assertEquals( String.format( "Case #%d: %d", 2, 3 ), solve( 2, 10, 40 ) );
	}

	@org.junit.Test
	public void statement3() {
		org.junit.Assert.assertEquals( String.format( "Case #%d: %d", 3, 156 ), solve( 3, 100, 500 ) );
	}

	@org.junit.Test
	public void statement4() {
		org.junit.Assert.assertEquals( String.format( "Case #%d: %d", 4, 287 ), solve( 4, 1111, 2222 ) );
	}

	@org.junit.Test(timeout = 10000)
	public void my1() {
		org.junit.Assert.assertEquals( String.format( "Case #%d: %d", 5, 299997 ), solve( 5, 1000000, 2000000 ) );
	}

}
