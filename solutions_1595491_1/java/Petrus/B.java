
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	public void solve( Scanner sc, PrintWriter pw ) {
		int tests = sc.nextInt( ); sc.nextLine( );
		for ( int i = 0 ; i < tests; i++ ) {
			int googlers = sc.nextInt( );
			int suprises = sc.nextInt( );
			int minScore = sc.nextInt( );
			
			int minimumNsFoundIn = (((3*minScore)-2) > 0 ) ? ((3*minScore)-2) : 0;
			int minimumSFoundIn = (((3*minScore)-4) > 0 ) ? ((3*minScore)-4) : 2;
			int out = 0;
			
			int[]scores = new int[googlers];
			for ( int j = 0 ; j < googlers; j++ ) {
				scores[j] = sc.nextInt( );
			}
			Arrays.sort( scores );
			for ( int j = 0 ; j < scores.length; j++ ) {
				int score = scores[j];
				if ( score >= minimumNsFoundIn ) {
					out++;
				} else if ( suprises > 0 && score >= minimumSFoundIn ) {
					out++;
					suprises--;
				}
			}
			pw.println( "Case #" + (i+1) + ": " + out );
			pw.flush( );
		}
	}

	public static void main ( String[] args ) throws IOException {
		Scanner sc = new Scanner(new FileReader("B-large.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("B-large.out"));
		new B( ).solve( sc, pw );
		pw.close( );
		sc.close( );
	}

//	public final static HashMap<Integer, String> NON_SUPRISING = new HashMap<Integer, String>( );
//	public final static HashMap<Integer, String> SUPRISING = new HashMap<Integer, String>( );
//	static {
//		//target = ( 3k-2 > 0 ) ? 3k-2 : 0;
//		//0 = 
//		//0 = 0
//		//1 = 1
//		//2 = 4
//		//3 = 7
//		//4 = 10
//		//5 = 13
//		//6 = 16
//		//7 = 19
//		//8 = 22
//		//9 = 25
//		//10 = 28
//		NON_SUPRISING.put( 0, "0 0 0" );
//		NON_SUPRISING.put( 1, "0 0 1" );
//		NON_SUPRISING.put( 2, "0 1 1" );
//		NON_SUPRISING.put( 3, "1 1 1" );
//		NON_SUPRISING.put( 4, "1 1 2" );
//		NON_SUPRISING.put( 5, "1 2 2" );
//		NON_SUPRISING.put( 6, "2 2 2" );
//		NON_SUPRISING.put( 7, "2 2 3" );
//		NON_SUPRISING.put( 8, "2 3 3" );
//		NON_SUPRISING.put( 9, "3 3 3" );
//		NON_SUPRISING.put( 10, "3 3 4" );
//		NON_SUPRISING.put( 11, "3 4 4" );
//		NON_SUPRISING.put( 12, "4 4 4" );
//		NON_SUPRISING.put( 13, "4 4 5" );
//		NON_SUPRISING.put( 14, "4 5 5" );
//		NON_SUPRISING.put( 15, "5 5 5" );
//		NON_SUPRISING.put( 16, "5 5 6" );
//		NON_SUPRISING.put( 17, "5 6 6" );
//		NON_SUPRISING.put( 18, "6 6 6" );
//		NON_SUPRISING.put( 19, "6 6 7" );
//		NON_SUPRISING.put( 20, "6 7 7" );
//		NON_SUPRISING.put( 21, "7 7 7" );
//		NON_SUPRISING.put( 22, "7 7 8" );
//		NON_SUPRISING.put( 23, "7 8 8" );
//		NON_SUPRISING.put( 24, "8 8 8" );
//		NON_SUPRISING.put( 25, "8 8 9" );
//		NON_SUPRISING.put( 26, "8 9 9" );
//		NON_SUPRISING.put( 27, "9 9 9" );
//		NON_SUPRISING.put( 28, "9 9 10" );
//		NON_SUPRISING.put( 29, "9 10 10" );
//		NON_SUPRISING.put( 30, "10 10 10" );
//		
//		//target = 
//		//target = (3k - 4) > 0 ? 3k - 4 : 2
//		//0 = 2
//		//1 = 2
//		//2 = 2
//		//3 = 5
//		//4 = 8
//		//5 = 11
//		//6 = 14
//		//7 = 17
//		//8 = 20
//		//9 = 23
//		//10 = 26
//		SUPRISING.put( 2, "0 0 2" );
//		SUPRISING.put( 3, "0 1 2" );
//		SUPRISING.put( 4, "0 2 2" );
//		SUPRISING.put( 5, "1 1 3" );
//		SUPRISING.put( 6, "1 2 3" );
//		SUPRISING.put( 7, "1 3 3" );
//		SUPRISING.put( 8, "2 2 4" );
//		SUPRISING.put( 9, "2 3 4" );
//		SUPRISING.put( 10, "2 4 4" );
//		SUPRISING.put( 11, "3 3 5" );
//		SUPRISING.put( 12, "3 4 5" );
//		SUPRISING.put( 13, "3 5 5" );
//		SUPRISING.put( 14, "4 4 6" );
//		SUPRISING.put( 15, "4 5 6" );
//		SUPRISING.put( 16, "4 6 6" );
//		SUPRISING.put( 17, "5 5 7" );
//		SUPRISING.put( 18, "5 6 7" );
//		SUPRISING.put( 19, "5 7 7" );
//		SUPRISING.put( 20, "6 6 8" );
//		SUPRISING.put( 21, "6 7 8" );
//		SUPRISING.put( 22, "6 8 8" );
//		SUPRISING.put( 23, "7 7 9" );
//		SUPRISING.put( 24, "7 8 9" );
//		SUPRISING.put( 25, "7 9 9" );
//		SUPRISING.put( 26, "8 8 10" );
//		SUPRISING.put( 27, "8 9 10" );
//		SUPRISING.put( 28, "8 10 10" );
//	}
}