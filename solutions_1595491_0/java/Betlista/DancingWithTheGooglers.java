import java.io.BufferedReader;
import java.io.InputStreamReader;

import org.junit.Assert;

public class DancingWithTheGooglers {

	public static void main( final String[] args ) throws Exception {
		final BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		final int T = Integer.parseInt( br.readLine() );
		for ( int ii = 0; ii < T; ++ii ) {
			final String[] parts = br.readLine().split( " " );
			final int N = Integer.parseInt( parts[ 0 ] );
			final int S = Integer.parseInt( parts[ 1 ] );
			final int p = Integer.parseInt( parts[ 2 ] );
			final int[] t = new int[N];
			for ( int i = 0; i < N; ++i ) {
				t[ i ] = Integer.parseInt( parts[ i + 3 ] );
			}
			System.out.printf( "Case #%d: %d\n", ii + 1, solve( N, S, p, t ) );
		}
	}

	private static int solve( final int n, int s, final int p, final int[] t ) {
		int cnt = 0;
		for ( int i = 0; i < t.length; ++i ) {
			final int k = t[ i ] / 3;
			final int mod = t[ i ] % 3;
			if ( k + ( mod > 0 ? 1 : 0 ) >= p ) {
				++cnt;
			} else if ( s > 0 ) {
				// k + k + k -> k+1 + k + k-1
				if ( mod == 0 && k - 1 >= 0 && k + 1 >= p ) {
					++cnt;
					--s;
				}

				// k+1 + k + k -> k+1 + k+1 + k-1 (not enough) || k+2 + k + k-1 (not ok)

				// k+1 + k+1 + k -> k+2 + k + k
				if ( mod == 2 && k + 2 >= p ) {
					++cnt;
					--s;
				}
			}
		}
		return cnt;
	}

	@org.junit.Test
	public void statement1() {
		final int[] t = { 15, 13, 11 };
		Assert.assertEquals( 3, solve( 3, 1, 5, t ) );
	}

	@org.junit.Test
	public void statement2() {
		final int[] t = { 23, 22, 21 };
		Assert.assertEquals( 2, solve( 3, 0, 8, t ) );
	}

	@org.junit.Test
	public void statement3() {
		final int[] t = { 8, 0 };
		Assert.assertEquals( 1, solve( 2, 1, 1, t ) );
	}

	@org.junit.Test
	public void statement4() {
		final int[] t = { 29, 20, 8, 18, 18, 21 };
		Assert.assertEquals( 3, solve( 6, 2, 8, t ) );
	}

}
