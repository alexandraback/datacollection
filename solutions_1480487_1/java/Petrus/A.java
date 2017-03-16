
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class A {
	public void solve( Scanner sc, PrintWriter pw ) {
		int tests = sc.nextInt( ); sc.nextLine( );
		for ( int i = 0 ; i < tests; i++ ) {
			pw.print( "Case #" + (i+1) + ": " );
			//System.out.println( "Case #" + (i+1) + ": " );
			int contestants = sc.nextInt( );
			int[] contestantPoints = new int[contestants];
			double[] percentages = new double[contestants];
			int sum = 0;
			
			for ( int j=0; j < contestants; j++ ) {
				contestantPoints[j] = sc.nextInt( );
				sum+=contestantPoints[j];
			}
			int sumWithAudience = sum * 2;
			double required = ((double)sumWithAudience)/contestants;
			//System.out.println( sum );
			//System.out.println( required );
			int exceptions = 0;
			double exceptionDiff = 0;
			
			for ( int j = 0 ; j < contestants; j++ ) {
				int score = contestantPoints[j];
				if ( score > required ) {
					exceptions++;
					exceptionDiff += ( contestantPoints[j] - required ); 
				}
			}
			
			required -= ( exceptionDiff / (contestants-exceptions) );
			//System.out.println( exceptions + " - " + exceptionDiff );
			//System.out.println( required );
			for ( int j = 0 ; j < contestants; j++ ) {
				int score = contestantPoints[j];
				if ( score > required ) {
					percentages[j] = 0;
				} else {
					percentages[j] = ((double)(required-score)*100)/sum;
				}
				pw.print( percentages[j] );
				if ( j != contestants-1 ) {
					pw.print( " " );
				}
			}
			
			pw.println( );
			pw.flush( );
		}
	}

	public static void main ( String[] args ) throws IOException {
		Scanner sc = new Scanner(new FileReader("A-large.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("A-large.out"));
		new A( ).solve( sc, pw );
		pw.close( );
		sc.close( );
	}
}