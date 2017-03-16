import java.io.*;
import java.util.*;

public class TicTacToeTomek {

	public static void main(String[] args) {
		Scanner sc = null;
		PrintWriter fout = null;
		int T = 0;

		try {
			sc = new Scanner(new File(args[0]));
			fout = new PrintWriter(new BufferedWriter(new FileWriter("result.txt")));
			T = sc.nextInt();
		}
		catch( Exception e ) {
			System.out.println(e);
		}

		for( int a = 1; a <= T; a++ ) {
			String[] str = new String[4];
			for( int i = 0; i < 4; i++ ) {
				str[i] = sc.next();
			}

			if( check( str, 'X') ) {
//				System.out.println("Case #" + a + ": X won" );
				fout.println("Case #" + a + ": X won" );
			}
			else if( check( str, 'O') ) {
//				System.out.println("Case #" + a + ": O won" );
				fout.println("Case #" + a + ": O won" );
			}
			else if( !contains( str, '.') ) {
//				System.out.println("Case #" + a + ": Draw" );
				fout.println("Case #" + a + ": Draw" );
			}
			else {
//				System.out.println("Case #" + a + ": Game has not completed" );
				fout.println("Case #" + a + ": Game has not completed" );				
			}
		}

		fout.close();
		sc.close();
	}
	
	static boolean check( String[] str, char C ) {
		for( int i = 0; i < 4; i++ ) {
			for( int j = 0; j < 4; j++ ) {
				char c = str[i].charAt( j );
				if( !( c == C || c == 'T' ) ) {
					break;
				}
				if( j == 3 ) return true;
			}
			for( int j = 0; j < 4; j++ ) {
				char c = str[j].charAt( i );
				if( !( c == C || c == 'T' ) ) {
					break;
				}
				if( j == 3 ) return true;
			}
		}
		for( int i = 0; i < 4; i++ ) {
			char c = str[i].charAt( i );
			if( !( c == C || c == 'T' ) ) {
				break;
			}			
			if( i == 3 ) return true;
		}
		for( int i = 0; i < 4; i++ ) {
			char c = str[i].charAt( 3 - i );
			if( !( c == C || c == 'T' ) ) {
				break;
			}			
			if( i == 3 ) return true;
		}

		return false;
	}
	
	static boolean contains( String[] str, char C ) {
		for( int i = 0; i < 4; i++ ) {
			if( str[i].indexOf( '.' ) >= 0 ) {
				return true;
			}
		}
		return false;
	}

}
