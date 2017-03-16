import java.io.*;
import java.util.*;
public class Solve {



	public static void main ( String args[] ) throws FileNotFoundException, IOException {
		BufferedReader in = new BufferedReader( new FileReader ( args[0] ) );
		BufferedWriter out = new BufferedWriter( new FileWriter ( "outfile.txt" ) );
		int cases = Integer.parseInt( in.readLine() );
		String[] tmp;
		int length, typed;
		double[] prob;
		String input;
		double ret, type, back, help, optimum, optiback;
		for ( int i = 1; i <= cases; i++ ) {
			tmp = in.readLine().split( " " );
			typed = Integer.parseInt( tmp[0] );
			length = Integer.parseInt( tmp[1] );
			tmp = in.readLine().split( " " );
			prob = new double[ tmp.length ];
			for ( int j = 0; j < tmp.length; j++ ) {
				prob[j] = Double.parseDouble(tmp[j]);
			}
			ret = (double)length + 2.0;
			type = 1.0;
			back = 1.0;
			optimum = 0.0;
			help = 1.0;
			for ( int j = 0; j < typed; j++ ) {
				help *= prob[j];
			}
			type = ( length + 1.0 - typed ) * help + ( length + ret - typed ) * (1.0 - help );
			optiback = type;			
			for ( int count = 1; count <= typed; count++ ) {
				help /= prob[ typed - count ];
				back = ( length + 1.0 - typed + count * 2.0 ) * help + ( length + ret - typed + count * 2.0) * (1.0 - help );
				if ( back < optiback ) {
					optiback = back;
				}
			}
			if ( type < ret ) {
				optimum = type;
			}
			else {
				optimum = ret;
			}
			if ( optiback < optimum ) {
				optimum = optiback;
			}
			out.write( "Case #" + i + ": " + optimum );
			out.newLine();
			out.flush();
		}
		in.close();
		out.close();
	}	


}
