package round1a.p3;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.text.DecimalFormat;

public class P3
{
	private static void calculate( int A, int B, double[] chances, BufferedWriter bw, int n ) throws Exception
	{
		double[] correctStart = new double[ chances.length+1 ];
		correctStart[0] = 1;
		for ( int j = 1; j <= chances.length; j++ )
			correctStart[j] = correctStart[j-1]*( chances[j-1] );
		
		double minAverage = B+2;
		
		for ( int i = 0; i < correctStart.length; i++ )
		{
			double average = ( (A-i)*2+B-A+1 ) + ( 1-correctStart[i] ) * (B+1);
			minAverage = Math.min( minAverage, average );
		}
		
		DecimalFormat df = new DecimalFormat( "#.##########" );
		bw.append( "Case #"+n+": "+df.format( minAverage ).replace( ',', '.' )+"\n" );
	}

	public static void main( String[] args ) throws Exception
	{
		File inputFile = new File( "inputfiles/round1a/p3/input.txt" );
		FileReader fr = new FileReader( inputFile );
		BufferedReader br = new BufferedReader( fr );
		
		int numOfTestCases = Integer.parseInt( br.readLine() );
		
		File outputFile = new File( "inputfiles/round1a/p3/output.txt" );
		outputFile.delete();
		outputFile.createNewFile();
		FileWriter fw = new FileWriter( outputFile );
		BufferedWriter bw = new BufferedWriter( fw );
		
		for ( int i = 0; i < numOfTestCases; i++ )
		{
			String[] AB = br.readLine().split( " " );
			int A = Integer.parseInt( AB[0] );
			int B = Integer.parseInt( AB[1] );
			
			String[] cs = br.readLine().split( " " );
			double[] chances = new double[A];
			for ( int j = 0; j < cs.length; j++ )
				chances[j] = Double.parseDouble( cs[j] );
			
			calculate( A, B, chances, bw, i+1 );
		}
		
		bw.flush();
		fw.flush();
		
		bw.close();
		fw.close();
	}
}
