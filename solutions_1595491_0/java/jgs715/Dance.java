import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.InputStreamReader;


public class Dance {

	public int run ( int N, int S, int p, int[] G ) {
		
		int results = 0;
		
		java.util.Arrays.sort( G );
		
		for( int i = G.length -1; i >= 0; --i ) {
			
			int t = G[ i ];
			
			int r = t % 3;
			
			int x = t / 3;
			
			if ( r == 0 ) {
				 //  x + x + x 
				 // ( x + 1 ) + x + ( x -1 ) ***
				if ( x >= p ) {
					
					++results;
 
					continue;
				}

				if ( t > 0 && x + 1 >= p && S > 0) {
					
					--S;
					
					++results;
					
					continue;
				}
				
				break;
			}
			
			if ( r == 1 ) {
				// ( x + 1) + x + x
				// No surpising because max range 2 ***  
				if ( x + 1 >= p ) {
					
					++results;
					
					continue;
				}

				break;
			}
			
			if ( r == 2 ) {
				// ( x + 1) + (x + 1) + x
				// ( x + 2 ) + x + x
				if ( x + 1 >= p ) {
					
					++results;
					
					continue;
				}

				if ( x + 2 >= p && S > 0) {
					
					--S;
					
					++results;
					
					continue;
				}
				
				break;
			}
		}
		
		return results;		
	}
	
	public Dance( String input ) throws Exception {
			
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
			
			System.out.print( "Case #" );
			
			System.out.print( i ); 
			
			System.out.print( ": " );
			
			System.out.println( run( N, S, p, G ) );
		}  
	
		in.close(); 
	}
	
	
	public static void main( String[] args ) throws Exception {
		
		new Dance( "dance-test.in" );
	}
}
