import java.io.*;
import java.util.*;
public class Solve1b {



	public static void main ( String args[] ) throws FileNotFoundException, IOException {
		BufferedReader in = new BufferedReader( new FileReader ( args[0] ) );
		BufferedWriter out = new BufferedWriter( new FileWriter ( "outfile.txt" ) );
		int cases = Integer.parseInt( in.readLine() );
		String[] tmp;
		int levels, currentStars, count;
		int [] oneStar, twoStars;
		String result;
		for ( int i = 1; i <= cases; i++ ) {
			result = "Too Bad";
			levels = Integer.parseInt( in.readLine() );
			currentStars = 0;
			count = 0;
			oneStar = new int[ levels ];
			twoStars = new int[ levels ];
			for ( int j =0; j < levels; j++ ) {
				tmp = in.readLine().split( " " );
				oneStar[j] = Integer.parseInt( tmp[0] );
				twoStars[j] = Integer.parseInt( tmp[1] );
			}
			Arrays.sort( oneStar );
			Arrays.sort( twoStars );
			int pointerOne = 0;
			for ( int pointerTwo = 0; pointerTwo < levels && pointerOne < levels ; pointerTwo++ ) {
				if ( currentStars >= twoStars[pointerTwo] ) {
					currentStars += 2;
					count++;
					if ( pointerTwo == levels - 1 ) {
						result = count + "";
					}
				}
				else {
					if ( currentStars >= oneStar[pointerOne] ) {
						currentStars++;
						count++;
						pointerTwo--;
						pointerOne++;
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


}
