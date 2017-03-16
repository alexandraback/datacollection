import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class SpeakingInTongues {

	private static final boolean DEBUG = false;

	private static boolean[] avail = new boolean['z' - 'a' + 1];
	private static char[] trans = new char['z' - 'a' + 1];
	private static final String[] from = {
			"ejp mysljylc kd kxveddknmc re jsicpdrysi",
			"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
			"de kr kd eoya kw aej tysr re ujdr lkgc jv",
			"y qee"
		};
	private static final String[] to = {
			"our language is impossible to understand",
			"there are twenty six factorial possibilities",
			"so it is okay if you want to just give up",
			"a zoo"
		};
	static {
		Arrays.fill( avail, false );
		Arrays.fill( trans, '.' );
		for ( int i = 0; i < from.length; ++i ) {
			final char[] fa = from[ i ].toCharArray();
			final char[] ta = to[ i ].toCharArray();
			for ( int j = 0; j < fa.length; ++j ) {
				final char cf = fa[ j ];
				if ( cf == ' ' ) continue;
				final char ct = ta[ j ];
				assert ( trans[ cf - 'a' ] == '.' || trans[ cf - 'a' ] == ct );
				trans[ cf - 'a' ] = ct;
				avail[ ct - 'a' ] = true;
			}
		}
		for ( char c = 'a'; c <= 'z'; ++c ) {
			if ( !avail[ c - 'a' ] )
				trans[ 'z' - 'a' ] = c;
		}
		if ( DEBUG ) {
			System.out.print( "[a" );
			for ( char c = 'b'; c <= 'z'; ++c ) {
				System.out.print( ", " + c );
			}
			System.out.println( "]" );
			System.out.println( Arrays.toString( trans ) );
		}
	}

	public static void main( final String[] args ) throws Exception {
		final BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		final int t = Integer.parseInt( br.readLine() );
		for ( int ii = 0; ii < t; ++ii ) {
			System.out.println( solve( ii + 1, br.readLine() ) );
		}
	}

	private static String solve( final int idx, final String line ) {
		final char[] la = line.toCharArray();
		final char[] res = new char[line.length()];
		for ( int i = 0; i < res.length; ++i ) {
			final char c = la[ i ];
			if ( c == ' ' )
				res[ i ] = ' ';
			else
				res[ i ] = trans[ c - 'a' ];
		}
		return String.format( "Case #%d: %s", idx, new String( res ) );
	}

	@org.junit.Test
	public void statement1() {
		final int idx = 0;
		org.junit.Assert.assertEquals( String.format( "Case #%d: %s", idx + 1, to[ idx ] ),
				solve( idx + 1, from[ idx ] ) );
	}

	@org.junit.Test
	public void statement2() {
		final int idx = 1;
		org.junit.Assert.assertEquals( String.format( "Case #%d: %s", idx + 1, to[ idx ] ),
				solve( idx + 1, from[ idx ] ) );
	}

	@org.junit.Test
	public void statement3() {
		final int idx = 2;
		org.junit.Assert.assertEquals( String.format( "Case #%d: %s", idx + 1, to[ idx ] ),
				solve( idx + 1, from[ idx ] ) );
	}

	@org.junit.Test
	public void statement0() {
		final int idx = 3;
		org.junit.Assert.assertEquals( String.format( "Case #%d: %s", idx + 1, to[ idx ] ),
				solve( idx + 1, from[ idx ] ) );
	}

}
