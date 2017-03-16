import java.io.*;
import java.util.*;
public class Solve {



	public static void main ( String args[] ) throws FileNotFoundException, IOException {
		BufferedReader in = new BufferedReader( new FileReader ( args[0] ) );
		BufferedWriter out = new BufferedWriter( new FileWriter ( "outfile.txt" ) );
		int cases = Integer.parseInt( in.readLine() );
		String[] tmp;
		int low, high, multiplier, shift, rest, pairs;
		HashSet<Integer> used;
		for ( int i = 1; i <= cases; i++ ) {
			pairs = 0;
			tmp = in.readLine().split( " " );
			low = Integer.parseInt( tmp[0] );
			high = Integer.parseInt( tmp[1] );
			multiplier = 1;
			for ( int j = 1; j < tmp[0].length(); j++ ) {
				multiplier *= 10;
			}
			for ( int j = low; j < high; j++ ) {
				shift = j;
				used = new HashSet<Integer>();
				for ( int k = 0; k < tmp[0].length(); k++ ) {
					rest = shift % 10;
					shift /= 10;
					shift += rest * multiplier;			
					if ( j < shift && shift <= high ) {
						if ( !used.contains( shift ) ) {
							pairs++;
							used.add( shift );
						}
					}
				}
			}
			out.write( "Case #" + i + ": " + pairs );
			out.newLine();
			out.flush();
		}
		in.close();
		out.close();
	}	


}
