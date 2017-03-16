package qualification.p3;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashSet;

public class RecycledNumbers
{
	private static void calculate( String testCase, BufferedWriter bw, int n ) throws Exception
	{
		String[] tcData = testCase.split( " " );
		
		int A = Integer.parseInt( tcData[0] );
		int B = Integer.parseInt( tcData[1] );
		
		int c = 0;
		
		HashSet<Long> was = new HashSet<Long>();
		for ( int i = A; i <= B; i++ )
		{
			int l = Integer.toString( i ).length();
			int p = (int)Math.pow( 10, l-1 );
			int ii = i;
			for ( int d = 1; d < l; d++ )
			{
				ii = p*( ii % 10 ) + ( ii / 10 );
				if ( ( ii > i && ii >= A && ii <= B ) && was.add( 1000000000l*i + ii ) )
					c++;
			}
		}
		
		bw.append( "Case #"+n+": "+c+"\n" );
	}

	public static void main( String[] args ) throws Exception
	{
		File inputFile = new File( "inputfiles/qualification/p3/input.txt" );
		FileReader fr = new FileReader( inputFile );
		BufferedReader br = new BufferedReader( fr );
		
		int numOfTestCases = Integer.parseInt( br.readLine() );
		
		File outputFile = new File( "inputfiles/qualification/p3/output.txt" );
		outputFile.delete();
		outputFile.createNewFile();
		FileWriter fw = new FileWriter( outputFile );
		BufferedWriter bw = new BufferedWriter( fw );
		
		for ( int i = 0; i < numOfTestCases; i++ )
		{
			String testCase = br.readLine();
			calculate( testCase, bw, i+1 );
		}
		
		bw.flush();
		fw.flush();
		
		bw.close();
		fw.close();
	}
}
