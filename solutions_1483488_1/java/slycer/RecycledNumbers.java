import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;


public class RecycledNumbers {

	public static void main ( String [] arg ) throws NumberFormatException, IOException{
		BufferedReader reader = new BufferedReader(new FileReader(new File("input")));
		PrintWriter output = new PrintWriter(new File("output"));
		
		int cases = Integer.valueOf( reader.readLine() ); 
		for ( int c=1; c<=cases; c++ ){
			StringTokenizer tkn = new StringTokenizer( reader.readLine() ); 
			int a = Integer.valueOf( tkn.nextToken() ); 
			int b = Integer.valueOf( tkn.nextToken() ); 
			int sol=0; 
			//Set<String> superMap = new HashSet(); 
			
			for ( int k=a; k<b; k++ ){
				Set<String> aux = new HashSet();
				String sr = k + ""; 
				for ( int i=1; i<sr.length(); i++ ){
					
					int next = Integer.valueOf( (String)sr.subSequence(i, sr.length()) + (String)sr.subSequence(0, i) );
					if ( k<next && next<=b ){
						//System.out.println( k + "," + next );//+ " " +)
						if ( !aux.contains( next + "") ){
							sol++; 
							aux.add( next + "");
						} else {
							System.out.println(  next );
						}
					}
				}
			}
			System.out.println("Case #"+c+": "+sol);
			output.println( "Case #"+c+": "+sol );
		}
		output.close(); 
	}
	
}
