import java.io.*;
import java.util.*;
public class Solve {

	public static void main ( String[] args ) throws FileNotFoundException, IOException {
		BufferedReader in = new BufferedReader( new FileReader ( args[0] ) );
		BufferedWriter out = new BufferedWriter( new FileWriter ( "outfile.txt" ) );
		int cases = Integer.parseInt( in.readLine() );
		String[] tmp;
		int number, surprising, minimum, count, allMax, result;
		int[] scores;
		for ( int i = 1; i <= cases; i++ ) {
			tmp = in.readLine().split( " " );
			result = 0;
			number = Integer.parseInt( tmp[0] );
			surprising = Integer.parseInt( tmp[1] );
			minimum = Integer.parseInt( tmp[2] );
			scores = new int[ number ];
			allMax = minimum * 3;
			for ( int j = 0; j < number; j++ ) {
				scores[j] = Integer.parseInt( tmp[ j + 3 ] );
			}
			for ( int j = number - 1; j >= 0; j-- ) {
				if ( scores[j] > allMax - 3 ) {
					result ++;
				}
				else {
					if ( scores[j] >= allMax - 4 && minimum -2 >= 0) {
						if ( surprising > 0 ) {
							result++;
							surprising--;
						}
					}
				}
			}
			out.write( "Case #" + i + ": " + result );
			out.newLine();
			out.flush();
		}
		in.close();
		out.close();
	}
	public static String replace( String first, String second, char target, char replacement ) {
		String ret = "";
		for ( int i = 0; i < first.length(); i++ ) {
			if ( first.charAt( i ) == target ) {
				ret = ret + replacement;
			}
			else {
				ret = ret + second.charAt( i );
			}
		}
		return ret;		
	} 

}
