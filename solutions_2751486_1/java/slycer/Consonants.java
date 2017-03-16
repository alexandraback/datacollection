package pack1;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class Consonants {
	public static boolean [] isv = new boolean [ 255 ];
	public static void main ( String [] arg ) throws FileNotFoundException{
		//a, e, i, o, and u 
		isv['a']=true;
		isv['e']=true; 
		isv['i']=true;
		isv['o']=true;
		isv['u']=true;
		Scanner s = new Scanner ( new File( "large.in" ) );
		System.setErr( new PrintStream ( new File("output" )));
		int cases = s.nextInt(); 
		for ( int c=1; c<=cases; c++ ){
			char [] L = s.next().toCharArray(); 
			int n = s.nextInt();
			int [] consecutive = new int[L.length];
			int [] start = new int[L.length];
			
			long [] dp = new long[L.length];
			
			if ( !isv[ L[0] ])
			   consecutive[0] = 1; 

			if ( consecutive[0] >= n ) { dp[0] = consecutive[0]; }

			
			for ( int i=1; i<L.length; i++ ){
				if ( !isv[L[i]] ){
					consecutive[i] = consecutive[i-1]+1;
				} else{
					consecutive[i] = 0;
				}
			}
			
		
			for ( int i=0; i<L.length-n+1; i++ ){
				if ( consecutive[i+n-1]>=n ){
					start[i] = 1; 
				} else {
					start[i] = 0; 
				}
			}
			
			if ( n == 1 ) {
				dp[0] = consecutive[0];
			}
			
			int lastStart = -1;
			long sol = dp[0]; 
			if ( dp[0] == 1 ) lastStart = 0; 
			
			for ( int i=1; i<L.length; i++ ){
				int back = i-n+1;
				
				if ( back >= 0){
					if ( start[back] == 1 ) {
						lastStart = back; 
					}
					dp[i] = ( lastStart + 1 ) ;
				}
     			sol += dp[i];
			}
				
//			System.out.println( new String(L) );
//			for ( int i=0; i<L.length; i++ ){
//				System.out.print( consecutive[i] + " " );
//			}
//			System.out.println();
//			for ( int i=0; i<L.length; i++ ){
//				System.out.print( start[i] + " " );
//			}
//			System.out.println();
//			for ( int i=0; i<L.length; i++ ){
//				System.out.print( dp[i] + " " );
//			}
//			System.out.println(); 
			
			System.out.println( "Case #"+c+": " + sol );
			
			System.err.println( "Case #"+c+": " + sol );
		}
	}
	
}
