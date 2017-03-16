import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.InputStreamReader;


public class Dance { 
	
	int[] maxNormal = new int[31];
	
	int[] maxSurprise = new int[31];
	
	public int maxNormal( int t ) {
		int r = t % 3;
		
		int x = t / 3;
		
		if ( r == 0 ) {
			 //  x + x + x 
			return ( x );		
		}
		
		if ( r == 1 ) {
			// ( x + 1) + x + x  
			return ( x + 1 );
		}
		
		// if ( r == 2 ) {
			// ( x + 1) + (x + 1) + x
			// ( x + 2 ) + x + x
		return ( x + 1 );
	}
	
	
	public int maxSuprise( int t ) {
		
		if ( t == 0 ) return 0;

		if ( t == 1 ) return 1;
		
		if ( t == 2 ) return 2;
		
		int r = t % 3;
		
		int x = t / 3;
		
		if ( r == 0 ) { 
			 // ( x + 1 ) + x + ( x -1 ) *** 

			return ( x + 1 ) ;
		}
		
		if ( r == 1 ) { 
			// No surpising because max range 2 ***  
			return 0;
		}
		
		//if ( r == 2 )   ( x + 2 ) + x + x
		return ( x + 2 );
	}
	
	public void init() {
		
		for( int t = 0; t <= 30; ++t ) {
			
			maxNormal[ t ] = maxNormal( t );
			
			maxSurprise[ t ] = maxSuprise( t );
		}
	} 
	
	
	public int run ( int S, int p, int[] G ) {
		
		int results = 0; 
		
		for( int i = G.length -1; i >= 0; --i ) {
			
			int t = G[ i ]; 
			
			if ( maxNormal[ t ] >= p ) {
					
				++results;
 
				continue;
			}

			if ( S > 0 && maxSurprise[ t ] >= p ) {
				 	
					++results;
					
					--S;
					
					continue;
			}
			break;
		}
		
		return results;		
	} 
	
	
	public Dance( String input ) throws Exception {
			
		init();
		
		FileInputStream fstream = new FileInputStream(input);
		
		DataInputStream in = new DataInputStream(fstream);
		
		BufferedReader br = new BufferedReader(new InputStreamReader(in)); 
		
		int t = Integer.parseInt( br.readLine() ); 
		
		for( int i = 1; i <= t; i++ ) {
	
			String test = br.readLine(); 
			
			String[] tokens = test.split( " " );
			
			int N = Integer.parseInt( tokens[0] );
			
			int S = Integer.parseInt( tokens[1] );
			
			int p = Integer.parseInt( tokens[2] );
			
			int[] G = new int[N];
			
			for( int j = 0; j < N; ++j ) {
				
				G[ j ] = Integer.parseInt( tokens[ 3 + j ] ); 
			} 
			
			java.util.Arrays.sort( G );
			
			System.out.print( "Case #" );
			
			System.out.print( i ); 
			
			System.out.print( ": " );
			
			System.out.println( run( S, p, G ) );
		}  
	
		in.close(); 
	}
	
	
	public static void main( String[] args ) throws Exception {
		
		new Dance( "dance-test.in" );
	}
}
