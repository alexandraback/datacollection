
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;

public class C {
	public static HashMap<Integer, ArrayList<Integer>> recycledNumbers = new HashMap<Integer, ArrayList<Integer>>( );

	public ArrayList<Integer> getRecycledNumbers( Integer n, Integer a, Integer b ) {
		if ( n < 10 || ( n < 100 && n % 10 == 0 ) )
			return null;

		ArrayList<Integer> aList = recycledNumbers.get( n );
		if ( aList == null ) {
			aList = new ArrayList<Integer>( );
			
			String s = n.toString( );
			int len = s.length( );
			for ( int i = 1; i < len; i++ ){
				Integer m = new Integer( s.substring( len-i ) + s.substring( 0, len-i) );
				if ( m > n && m.toString( ).length( ) == s.length( ) ) {
					if ( !aList.contains( m ) ) {
						aList.add( m );
					}
				}
			}
			recycledNumbers.put( n, aList );
		}
		return filterRecycledNumbers( aList, a, b );
	}
	
	public ArrayList filterRecycledNumbers( ArrayList<Integer> list, Integer a, Integer b ) {
		ArrayList<Integer> retList = new ArrayList<Integer>( );
		Iterator<Integer> iterator =list.iterator( );
		while ( iterator.hasNext( ) ) {
			Integer i = iterator.next( );
			if ( ( a <= i && i <= b ) ) {
				retList.add( i );
			}
		}
		return retList;
	}

	public void solve( Scanner sc, PrintWriter pw ) {
		int tests = sc.nextInt( ); sc.nextLine( );
		for ( int i = 0 ; i < tests; i++ ) {
			int a = sc.nextInt( );
			int b = sc.nextInt( );

			ArrayList<Integer> recycledNumbers = new ArrayList<Integer>( );
			for ( int j = a; j <= b; j++ ) {
				ArrayList<Integer> lst = getRecycledNumbers( j, a, b );
				if ( lst != null && lst.size( ) > 0 ) {
					recycledNumbers.addAll( lst );
				}
			}
			
			pw.print( "Case #" + (i+1) + ": " + recycledNumbers.size( ) );
			pw.println( );
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