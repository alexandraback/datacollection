import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.StringTokenizer;


public class Template {

	public static void main ( String [] arg ) throws IOException{
		BufferedReader reader = new BufferedReader ( new FileReader( new File( "input.txt" ))); 
		PrintWriter output = new PrintWriter ( new File( "output.txt" )); 
		int cases = Integer.valueOf( reader.readLine() );
			
		for ( int c=1; c<=cases; c++ ){
			StringTokenizer tkn = new StringTokenizer( reader.readLine() ); 
			int n = Integer.valueOf( tkn.nextToken() ); 
			double [] data = new double[ n ]; 
			double sum =0; 
			for ( int i=0; i<n; i++ ){
				data[i] = Integer.valueOf( tkn.nextToken() ); 
				System.out.print( data[i] + " " ); 
				sum += data[i]; 
			}
			output.print( "Case #"+c+": " );
			Scanner s = new Scanner ( System.in ); 
		/*	while ( true ){
				int target = s.nextInt(); 
				double percent = s.nextDouble(); 
				if ( target == - 1){
					break; 
				}
				System.out.println( ok( sum,data,target,percent ) ); 
			} */
			for ( int target=0; target<n; target++ ){
				double stanga  = 0; 
				double dreapta = 1; 
				while ( Math.abs( stanga -dreapta ) >0.00000000001 )
				//for ( int itr=0; itr<=2000; itr++)
				{
					double PERCENT = ( stanga + dreapta )/2.0; 
					System.out.println( stanga + " " + dreapta + " " +  PERCENT ); 
					boolean eval = ok ( sum, data, target, PERCENT ); 
					if ( eval ){
						stanga = PERCENT; 
					} else {
						dreapta = PERCENT; 
					}
				}
				output.print( String.format("%.7f", dreapta*100.0 ) + " " ); 
			}
			output.println(); 
		}
		
		output.close(); 
	}
	
	/**
	 * TRUE DACA este eliminat
	 * @param sum
	 * @param data
	 * @param target
	 * @param percent
	 * @return
	 */
	public static boolean ok( double sum, double [] data, int target, double percent ){
		double targetScore = data[target] + percent * sum; 
		System.out.println( sum + " " + targetScore + " " + percent ); 
		double acc = 0; 
		for ( int i=0; i<data.length; i++ ){
			if ( i != target ){
				double current = ( targetScore - data[i] )/(double)sum;
				if ( current > 0 ){
					acc+= current; 
				}
			}
		}
		if ( percent + acc >= 1.0 ){
			return false; 
		}
		return true; 
	}
	
}
