package pack1;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class Osmos {
	public static void main ( String [] arg ) throws FileNotFoundException{
		Scanner s = new Scanner ( System.in ); 
		System.setOut( new PrintStream( new File("output") ) ); 
		int cases = s.nextInt(); 
		for ( int c=1; c<=cases; c++ ){
			int A = s.nextInt(); 
			int n = s.nextInt(); 
			int [] d = new int[n]; 
			for ( int i=0; i<n; i++){
				d[i] = s.nextInt(); 
			}
			
			Arrays.sort( d );
			System.err.print( A + " - " ); 
			for ( int i=0; i<n; i++ ){
				System.err.print( d[i] + " " );
			}
			System.err.println(); 
			
			int adaugate = 0; 
			int sol = Integer.MAX_VALUE; 
			if ( A>1 ) {
				for ( int i=0; i<n; i++ ){
					int costOprire = ( n - i ) + adaugate;
					sol = Math.min( sol, costOprire);
					System.err.println( A + " " + sol + " " + costOprire );
					if ( d[i] < A ){
						A += d[i];
					} else {
						while ( A <= d[i] ){
							A += (A-1); // crestere exponentiala
							System.err.println( "Adding " + A );
							adaugate ++; 
						}
						A += d[i];
					}
				} 
				sol = Math.min( sol, adaugate);
			} else {
				sol = n; 
			}
			
			System.err.println("Case #" + c + ": " + sol  ); 
			System.out.println("Case #" + c + ": " + sol  ); 
			
		}
	}
}
