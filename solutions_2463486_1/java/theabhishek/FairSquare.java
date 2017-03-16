import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.StringTokenizer;

public class FairSquare{

	static BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
	static BigInteger palSquare[] = new BigInteger[ 10000000 + 10 ];
	static BigInteger A[] = new BigInteger[ 10000000 + 10 ], SA[] = new BigInteger[ 10000000 + 10 ];
	static int counts = 0, head = 0, seeds[] = { 0, 1, 3, 7 };
	public static void main( String args[] ) throws IOException{
		preprocess();
		A[head++] = palSquare[0];
		for( int i=1; i<counts; i++ ){
			if( A[head - 1].compareTo( palSquare[i] ) != 0 )
				A[head++] = palSquare[i];
		}
		for( int i=0; i<head; i++ ){
			SA[i] = A[i].multiply( A[i] );
		}

		String line;
		StringTokenizer strTokenizer;
		BigInteger X, Y;
		int T = Integer.parseInt( br.readLine() );
		for( int i=1; i<=T; i++ ){
			line = br.readLine();
			strTokenizer = new StringTokenizer( line );
			X = new BigInteger( strTokenizer.nextToken() );
			X = X.subtract( BigInteger.ONE );
			Y = new BigInteger( strTokenizer.nextToken() );

			System.out.println( "Case #" + i + ": " + ( getIndex( Y ) - getIndex( X ) ) );
		}
	}

	private static int getIndex( BigInteger X ){
		if( X.compareTo( BigInteger.ZERO ) == 0 )
			return -1;
		int low = 0, high = head - 1, mid;
		while( low < high ){
			mid = ( low + high + 1 )/2;
			if( SA[mid].compareTo( X ) > 0 )
				high = mid - 1;
			else
				low = mid;
		}
		assert( low == high );
		return low;
	}

	private static void preprocess() {
		palSquare[counts++] = new BigInteger( "1" );
		palSquare[counts++] = new BigInteger( "2" );
		palSquare[counts++] = new BigInteger( "3" );

		//Case 1 : Binary Root
		palSquare[ counts++ ] = new BigInteger( "11" );
		for( int i=0; i<4; i++ ){
			int seed = seeds[i];
			while( Integer.toBinaryString( seed ).length() < 27 ){
				for( int L=Integer.toBinaryString( seed ).length(); L<27; L++ ){
					String pattern = Integer.toBinaryString( ( 1<<L ) + seed );
					palSquare[ counts++ ] = new BigInteger( pattern + reverse( pattern ) );
				}
				seed = next( seed );
			}
		}

		//Case 2 : Ternary Root
		palSquare[ counts++ ] = new BigInteger( "101" );
		palSquare[ counts++ ] = new BigInteger( "111" );
		palSquare[ counts++ ] = new BigInteger( "121" );
		for( int i=0; i<4; i++ ){
			int seed = seeds[i];
			while( Integer.toBinaryString( seed ).length() < 27 ){
				for( int L=Integer.toBinaryString( seed ).length(); L < 27; L++ ){
					String pattern = Integer.toBinaryString( (1<<L) + seed );
					palSquare[ counts++ ] = new BigInteger( pattern + "0" + reverse( pattern ) );
					palSquare[ counts++ ] = new BigInteger( pattern + "1" + reverse( pattern ) );
					if( i < 2 )
						palSquare[ counts++ ] = new BigInteger( pattern + "2" + reverse( pattern ) );
				}
				seed = next( seed );
			}
		}

		//Case 3 :
		for( int L=0; L<27; L++ ){
			String pattern = "";
			for( int i=0; i<L; i++ )
				pattern += "0";
			palSquare[ counts++ ] = new BigInteger( "2" + pattern + reverse( pattern ) + "2" );
			palSquare[ counts++ ] = new BigInteger( "2" + pattern + "0" + reverse( pattern ) + "2" );
			palSquare[ counts++ ] = new BigInteger( "2" + pattern + "1" + reverse( pattern ) + "2" );
		}
		counts -= 2;

		Arrays.sort( palSquare, 0, counts );
	}

	static int next( int seed ){
		if( seed == 0 )
			return 1<<30;
		int one = ( seed )&( ~seed + 1 );
		if( ( seed & ( one<<1 ) ) != 0 && ( seed & ( one<<2 ) ) != 0 )
			return (one<<3) + 3;
		if( ( seed & ( one<<1 ) ) != 0 )
			return ( ( seed + ( one<<1 ) ) & ( ~one ) ) + 1;
		return seed + one;
	}

	static String reverse(String s){
	    return new StringBuffer(s).reverse().toString();
	}
}
