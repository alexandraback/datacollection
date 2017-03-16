import java.io.BufferedReader; 
import java.io.DataInputStream; 
import java.io.FileInputStream; 
import java.io.InputStreamReader; 


public class tongues { 
	
	char[] map = new char[256];
	
	void buildMap() {	
		buildMap( "yeqz ", "aozq " );
		buildMap( "ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand" );
		buildMap( "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities" );
		buildMap( "de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up" );
	}
	
	
	void buildMap(String input, String output ) {
		
		for( int i = 0; i < input.length(); ++i ) {
			
			map[ input.charAt(i) ] = output.charAt(i);
		}
	}
	
	
	String parse( String input ) {
		
		StringBuilder sb = new StringBuilder();
		
		for( int i = 0; i < input.length(); ++i ) {
			
			sb.append( map[ input.charAt( i ) ] );
		}
		
		return sb.toString();
	}
	
	
	public tongues( String input ) throws Exception {
		
		buildMap(); 
		
		FileInputStream fstream = new FileInputStream(input);
		
		DataInputStream in = new DataInputStream(fstream);
		
		BufferedReader br = new BufferedReader(new InputStreamReader(in)); 
		
		int t = Integer.parseInt( br.readLine() ); 
		
		for( int i = 1; i <= t; i++ ) {

			String test = br.readLine(); 
			
			System.out.print( "Case #" );
			
			System.out.print( i ); 
			
			System.out.print( ": " );
			
			String result = parse( test ); 
			
			System.out.println( result );
		}  
		
		in.close(); 
	}
	
	static public void main( String[] args ) throws Exception {
		
		new tongues( "tongues-data.txt" );
		
	}
}
