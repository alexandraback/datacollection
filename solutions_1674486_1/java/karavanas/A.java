import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;

public class A {
	static int n;
	static boolean[][] c;
	static boolean[] v;
	/**
	 * @param args
	 */
	public static void main( String[] args ) {
		try {
			String fileName = "A-large";// "A-small-attempt1";// "A-test";// 
			BufferedReader inFile = new BufferedReader( new FileReader(
					new File( fileName+".in" ) ) );
			PrintStream outFile = new PrintStream(
					new FileOutputStream( fileName+".out" ));

			String line = inFile.readLine();
			int tests = Integer.parseInt( line );
			for (int test = 0; test < tests; test++) {
				line = inFile.readLine();
				String[] ss = line.split( " " );
				n = Integer.parseInt( ss[0] );
				c = new boolean[n][];
				
				ArrayList<Integer> r = new ArrayList<Integer>();
				for ( int i = 0; i < n; i++ ) {
					c[i] = new boolean[n];
					line = inFile.readLine();
					ss = line.split( " " );
					int m = Integer.parseInt( ss[0] );
					for ( int j = 0; j < m; j++ ) {
						int a = Integer.parseInt( ss[j+1] );
						c[i][a-1] = true;
					}
					if ( m == 0 ) r.add( i );
				}
				boolean ans = false;
				for ( Integer i : r ) {
					v = new boolean[n];
					if ( go(i) ){
						ans = true;
						break;
					}
				}
				outFile.println( "Case #" + (test+1) + ": " + (ans?"Yes":"No") );
			}
			inFile.close();
			outFile.close();

		} catch ( IOException e ) {
			e.printStackTrace();
		}
	}
	
	static boolean go( int r ){
		if ( v[r] ) return true;
		v[r] = true;
		for ( int i = 0; i < n; i++ ) {
			if ( c[i][r] ){
				if ( go( i ) ){
					return true;
				}
			}
		}
		return false;
	}

}


