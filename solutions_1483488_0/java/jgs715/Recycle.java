import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.InputStreamReader;


public class Recycle {
	
	int decimals[];
	int powerOf10[];
	
	int decimals( int n ) {
		if ( n < 10 )          return 1;
		if ( n < 100 )         return 2;
		if ( n < 1000 )        return 3;
		if ( n < 10000 )       return 4;
		if ( n < 100000 )      return 5;
		if ( n < 1000000 )     return 6;
		if ( n < 10000000 )    return 7;
		if ( n < 100000000 )   return 8;
		return 9;
	}
	
	void init() {
		
		decimals = new int[2000001]; 
		
		for( int i = 1; i <= 2000000; i++ ) { 

			decimals[i] = decimals(i);
		}
		
		powerOf10 = new int[10];
		
		powerOf10[0] = 1;
		
		for( int i = 1; i < 10; i ++ ) {
		
			powerOf10[i] = powerOf10[i-1]*10;
		}
	} 
	
	
	int run( int lower, int upper ) {
		
		int results = 0;  
		
		int[] temp = new int[6];
		
		int index = -1;

		for( int n = lower; n < upper; n++ ) { 
			
			index = -1;
			
			SHFT:
			for( int shft = 1; shft < decimals[n]; ++shft ) {
				
				int test = rotateRight( n, shft );
				
				if ( test > upper )  continue;
				
				if ( decimals[n] != decimals[test] ) continue;
				
				if ( test <= n ) continue; 
				
				for( int i = index; i >=0; i-- ) {
					
					if ( temp[i] == test ) 
						continue SHFT;
				}
				
				temp[ ++index ] = test;
				
				results++; 
			} 
		}
		
		return results;
	}
	
	
	public void run( String input ) throws Exception {
		
		FileInputStream fstream = new FileInputStream(input);
		
		DataInputStream in = new DataInputStream(fstream);
		
		BufferedReader br = new BufferedReader(new InputStreamReader(in)); 
		
		int t = Integer.parseInt( br.readLine() ); 
		
		for( int i = 1; i <= t; i++ ) {
	
			String test = br.readLine(); 
			
			String[] tokens = test.split( " " );
			
			int a = Integer.parseInt( tokens[0] );
			
			int b = Integer.parseInt( tokens[1] ); 
			
			System.out.print( "Case #" );
			
			System.out.print( i ); 
			
			System.out.print( ": " );
			
			System.out.println( run( a, b ) );
		}  
	
		in.close(); 
	}  
	
	
	int rotateRight( int n, int shft ) {  
		
		int dec = powerOf10[ shft ];
		
		int mult = decimals[ n ] - shft;
		
		int right = n % dec;
		
		int left = n / dec;
		
		return right * powerOf10[ mult ] + left; 
	}
	
	
	void test( int n ) {
		
		for( int shft = 1; shft < decimals[n]; ++shft ) {
	
			System.out.print( n );
			
			System.out.print( " -> ( " );
			
			System.out.print( shft );
			
			System.out.print( " )-> " ); 
			
			System.out.println( rotateRight( n, shft ) ); 
		} 
	}
	

	public Recycle( )  {
		
		init();  
	}
	
	
	public static void main( String[] args ) throws Exception {
		
		Recycle app = new Recycle();
		
		app.run( "recycle-test.in" );
	}
}
