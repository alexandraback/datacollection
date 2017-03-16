import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;

public class KingdomRush {

	public static void main( final String[] args ) throws Exception {
		final BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		final int T = toi( br.readLine() );
		for ( int ii = 0; ii < T; ++ii ) {
			final int N = toi( br.readLine() );
			final int[] a = new int[N];
			final int[] b = new int[N];
			for ( int i = 0; i < N; ++i ) {
				final int[] t = toi( br.readLine().split( " " ) );
				a[ i ] = t[ 0 ];
				b[ i ] = t[ 1 ];
			}
			System.out.printf( "Case #%s: %s\n", ii + 1, solve( N, a, b ) );
		}
	}

	public static String solve( final int n, final int[] a, final int[] b ) {
		final PriorityQueue<Level> aq = new PriorityQueue<Level>();
		final PriorityQueue<Level> bq = new PriorityQueue<Level>( b.length, bcomp );
		for ( int i = 0; i < n; ++i ) {
			aq.add( new Level( i, a[ i ], b[ i ] ) );
			bq.add( new Level( i, a[ i ], b[ i ] ) );
		}
		final boolean[] ab = new boolean[n];
		final boolean[] bb = new boolean[n];
		for ( int i = 0; i < n; ++i ) {
			ab[ i ] = false; // not played
			bb[ i ] = false;
		}

		int cnt = 0;
		int ap = 0;
		while ( !bq.isEmpty() ) {
			final Level blev = bq.poll();
			final int minB = blev.minStarsB;
			if ( ap >= minB ) {
				if ( ab[ blev.idx ] )
					++ap;
				else
					ap += 2;
				bb[ blev.idx ] = true;
				++cnt;
			} else {
				bq.add( blev ); // return not used
				if ( aq.isEmpty() ) return "Too Bad";
				while ( !aq.isEmpty() ) {
					final Level alev = aq.poll();
					final int minA = alev.minStarsA;
					if ( bb[ alev.idx ] ) continue;//skip 
					if ( minA <= ap ) {
						ab[ alev.idx ] = true;
						ap += 1;
						++cnt;
					} else {
						return "Too Bad";
					}
					if ( ap >= minB ) break;
				}
			}
		}
		return Integer.toString( cnt );
	}

	private static Comparator<Level> bcomp = new Comparator<Level>() {

		@Override
		public int compare( final Level l1, final Level l2 ) {
			return Integer.valueOf( l1.minStarsB ).compareTo( l2.minStarsB );
		}
	};

	static class Level implements Comparable<Level> {

		int idx;
		int minStarsA;
		int minStarsB;

		public Level( final int idx, final int minStarsA, final int minStarsB ) {
			super();
			this.idx = idx;
			this.minStarsA = minStarsA;
			this.minStarsB = minStarsB;
		}

		@Override
		public int compareTo( final Level l ) {
			if ( this.minStarsA == l.minStarsA ) return -Integer.valueOf( this.minStarsB ).compareTo( l.minStarsB );
			return Integer.valueOf( this.minStarsA ).compareTo( l.minStarsA );
		}
	}

	private static int toi( final String s ) {
		return Integer.parseInt( s );
	}

	private static int[] toi( final String... s ) {
		final int[] res = new int[s.length];
		for ( int i = 0; i < res.length; ++i ) {
			res[ i ] = toi( s[ i ] );
		}
		return res;
	}

}
