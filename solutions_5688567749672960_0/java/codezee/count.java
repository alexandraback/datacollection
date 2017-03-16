import java.io.*;
class count {
	static int[] table;
	public static void main( String[] args ) throws IOException {
		BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
		PrintWriter pw = new PrintWriter( System.out );
		int z = 1;
		int t = Integer.parseInt( br.readLine() );
		table = new int[1000001];
		while ( t > 0 ) {
			int N = Integer.parseInt( br.readLine() );
			int ans = getMinCount( N );
			System.out.println( "Case #"+z+": "+ ans);
			z++;
			t--;
		}
	}
	public static int getRev( int n ) {
		int tmp = 0;
		int k = n;
		int f = 0;
		while( k > 0 ) {
			int r = k%10;
			if( r == 0 && f == 0 ) {
				k = k/10;
				continue;
			} else {
				f = 1;
			}
			k = k/10;
			tmp = tmp*10 + r;
		}
		return tmp;
	}
	public static int getMinCount( int n ) {
		if ( table[n] != 0 ) {
			return table[n];
		}
		if( n < 10 ) {
			table[n] = n;
			return n;
		}
		// cannot be reversed
		if( n%10 == 0 ) {
			table[n] = 1 + getMinCount( n-1 );
			return table[n];
		} else {
			int rev = getRev( n );
			//System.out.println( rev );
			if( rev >= n ) {
				table[n] = 1 + getMinCount( n-1 );
				return table[n];
			} else {

				int gmcrev = getMinCount( rev );
				int gmc = getMinCount( n-1 );
				table[n] = gmcrev<gmc?1+gmcrev:1+gmc;
				return table[n];
			}
		}
	}
}
