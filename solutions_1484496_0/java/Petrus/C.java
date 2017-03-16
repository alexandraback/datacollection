
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

public class C {

	public String checkOrStore( HashMap<BigInteger,String> map, BigInteger bigInt ) {
		if ( map.containsKey( bigInt ) ) {
			return map.get( bigInt )+","+bigInt;
		} else {
			map.put( bigInt, "" + bigInt );

			Set<BigInteger> keyset = map.keySet();
			Iterator<BigInteger> iterator = keyset.iterator( );
			HashMap<BigInteger,String> tempMap = new HashMap<BigInteger, String>();
			while ( iterator.hasNext( ) ) {
				BigInteger key = iterator.next( );
				if ( !key.equals( bigInt ) ) {
					BigInteger added = key.add( bigInt );
					if ( map.containsKey( added ) ) {
						return map.get( key ) + " " + bigInt+","+ map.get( added );
					} else {
						tempMap.put( added, map.get( key ) + " " + bigInt );
					}
				}
			}
			map.putAll(tempMap);
			tempMap = null;
		}
		return null;
	}
	public void solve( Scanner sc, PrintWriter pw ) {
		int tests = sc.nextInt( ); sc.nextLine( );
		for ( int i = 0 ; i < tests; i++ ) {
			int cardinality = sc.nextInt( );
			ArrayList<BigInteger> setS = new ArrayList<BigInteger>( );
			HashMap<BigInteger, String> map = new HashMap<BigInteger, String>( );
			String s = null;
			for ( int j=0; j < cardinality; j++ ) {
				BigInteger bi = sc.nextBigInteger( );
				setS.add( bi );
				
				if ( s == null ) {
					s = checkOrStore( map, bi );
				}
			}
			pw.println( "Case #" + (i+1) +":");
			if ( s == null ) {
				pw.println( "Impossible" );
			} else {
				String[] arr = s.split(",");
				pw.println( arr[0] );
				pw.println( arr[1] );
			}
			
			pw.flush( );
		}
	}

	public static void main ( String[] args ) throws IOException {
		Scanner sc = new Scanner(new FileReader("C-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("C-small-attempt0.out"));
		new C( ).solve( sc, pw );
		pw.close( );
		sc.close( );
	}
}