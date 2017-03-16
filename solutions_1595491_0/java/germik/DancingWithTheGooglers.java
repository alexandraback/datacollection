package qualification.p2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class DancingWithTheGooglers
{
	private static void calculate( String testCase, BufferedWriter bw, int n ) throws Exception
	{
		String[] tcData = testCase.split( " " );
		
		int N = Integer.parseInt( tcData[0] );
		int S = Integer.parseInt( tcData[1] );
		int P = Integer.parseInt( tcData[2] );
		
		int[] sums = new int[N];
		for ( int i = 3; i <= 2+N; i++ )
			sums[i-3] = Integer.parseInt( tcData[i] );
		
		int c = 0;
		for ( int sum : sums )
		{
			if ( sum >= 3*P - 2 && sum >= P )
				c++;
			else if ( S > 0 && sum >= 3*P - 4 && sum >= P )
			{
				S--;
				c++;
			}
		}
		
		bw.append( "Case #"+n+": "+c+"\n" );
	}

	public static void main( String[] args ) throws Exception
	{
		File inputFile = new File( "inputfiles/qualification/p2/input.txt" );
		FileReader fr = new FileReader( inputFile );
		BufferedReader br = new BufferedReader( fr );
		
		int numOfTestCases = Integer.parseInt( br.readLine() );
		
		File outputFile = new File( "inputfiles/qualification/p2/output.txt" );
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
