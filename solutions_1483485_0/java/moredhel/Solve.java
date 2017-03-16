import java.io.*;
import java.util.*;
public class Solve {

	public static void oldMain ( String[] args ) throws FileNotFoundException, IOException {
		BufferedReader in = new BufferedReader( new FileReader ( args[0] ) );
		BufferedReader lineIn = new BufferedReader( new InputStreamReader (System.in ) );
		BufferedWriter out = new BufferedWriter( new FileWriter ( "outfile.txt" ) );
		int cases = Integer.parseInt( in.readLine() );
		String tmp, input, help;
		int[] scores;
		for ( int i = 1; i <= cases; i++ ) {
			tmp = in.readLine();
			input = tmp;
			help = "00";
			while ( help.length() == 2 ) {
				if ( help.equals ("00" ) ) {
					tmp = input;
					System.out.println( tmp );
					tmp = replace( input, tmp, 'y', 'a' );
					System.out.println( tmp );
					tmp = replace( input, tmp, 'e', 'o' );
					System.out.println( tmp );
					tmp = replace( input, tmp, 'q', 'z' );
					System.out.println( tmp );
				}
				else {
					tmp = replace( input, tmp, help.charAt( 0 ), help.charAt( 1 ) );
					System.out.println( tmp );
				}
				help = lineIn.readLine();
			}
			out.write( "Case #" + i + ": " + tmp );
			out.newLine();
			out.flush();
		}
		in.close();
		out.close();
	}


	public static void main ( String args[] ) throws FileNotFoundException, IOException {
		BufferedReader in = new BufferedReader( new FileReader ( args[0] ) );
		BufferedReader lineIn = new BufferedReader( new InputStreamReader (System.in ) );
		BufferedWriter out = new BufferedWriter( new FileWriter ( "outfile.txt" ) );
		int cases = Integer.parseInt( in.readLine() );
		String tmp, input;
		int[] scores;
		for ( int i = 1; i <= cases; i++ ) {
			tmp = in.readLine();
			input = tmp;
			tmp = replace( input, tmp, 'y', 'a' );
			tmp = replace( input, tmp, 'n', 'b' );
			tmp = replace( input, tmp, 'f', 'c' );
			tmp = replace( input, tmp, 'i', 'd' );
			tmp = replace( input, tmp, 'c', 'e' );
			tmp = replace( input, tmp, 'w', 'f' );
			tmp = replace( input, tmp, 'l', 'g' );
			tmp = replace( input, tmp, 'b', 'h' );
			tmp = replace( input, tmp, 'k', 'i' );
			tmp = replace( input, tmp, 'u', 'j' );
			tmp = replace( input, tmp, 'o', 'k' );
			tmp = replace( input, tmp, 'm', 'l' );
			tmp = replace( input, tmp, 'x', 'm' );
			tmp = replace( input, tmp, 's', 'n' );
			tmp = replace( input, tmp, 'e', 'o' );
			tmp = replace( input, tmp, 'v', 'p' );
			tmp = replace( input, tmp, 'z', 'q' );
			tmp = replace( input, tmp, 'p', 'r' );
			tmp = replace( input, tmp, 'd', 's' );
			tmp = replace( input, tmp, 'r', 't' );
			tmp = replace( input, tmp, 'j', 'u' );
			tmp = replace( input, tmp, 'g', 'v' );
			tmp = replace( input, tmp, 't', 'w' );
			tmp = replace( input, tmp, 'h', 'x' );
			tmp = replace( input, tmp, 'a', 'y' );
			tmp = replace( input, tmp, 'q', 'z' );
			out.write( "Case #" + i + ": " + tmp );
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
