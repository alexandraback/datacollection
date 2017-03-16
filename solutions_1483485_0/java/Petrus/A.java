
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Scanner;

public class A {
	public void solve( Scanner sc, PrintWriter pw ) {
		HashMap dictionary = new HashMap<Character, Character>( );
		dictionary.put( 'a', 'y' );
		dictionary.put( 'b', 'h' );
		dictionary.put( 'c', 'e' );
		dictionary.put( 'd', 's' );
		dictionary.put( 'e', 'o' );
		dictionary.put( 'f', 'c' );
		dictionary.put( 'g', 'v' );
		dictionary.put( 'h', 'x' );
		dictionary.put( 'i', 'd' );
		dictionary.put( 'j', 'u' );
		dictionary.put( 'k', 'i' );
		dictionary.put( 'l', 'g' );
		dictionary.put( 'm', 'l' );
		dictionary.put( 'n', 'b' );
		dictionary.put( 'o', 'k' );
		dictionary.put( 'p', 'r' );
		dictionary.put( 'q', 'z' );
		dictionary.put( 'r', 't' );
		dictionary.put( 's', 'n' );
		dictionary.put( 't', 'w' );
		dictionary.put( 'u', 'j' );
		dictionary.put( 'v', 'p' );
		dictionary.put( 'w', 'f' );
		dictionary.put( 'x', 'm' );
		dictionary.put( 'y', 'a' );
		dictionary.put( 'z', 'q' );
		
		int tests = sc.nextInt( ); sc.nextLine( );
		for ( int i = 0 ; i < tests; i++ ) {
			pw.print( "Case #" + (i+1) + ": " );
			String line = sc.nextLine( );
			for ( int j = 0; j < line.length( ); j++ ) {
				Character input = line.charAt( j );
				
				Character output = (Character) dictionary.get( input );
				if ( output == null ) {
					output = input;
				}
				pw.print( output.toString( ) );
			}
			pw.println( );
			pw.flush( );
		}
	}

	public static void main ( String[] args ) throws IOException {
		Scanner sc = new Scanner(new FileReader("A-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("A-small-attempt0.out"));
		new A( ).solve( sc, pw );
		pw.close( );
		sc.close( );
	}
}