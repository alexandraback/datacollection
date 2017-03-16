package round1a.p2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class P2
{
	private static void calculate( int N, int[][] sr, BufferedWriter bw, int n ) throws Exception
	{
		int stars = 0;
		int[] starsCollected = new int[N];
		
		int count = 0;
		while ( stars != 2*N )
		{
			int maxI = -1;
			int maxStars = 0;
			int minSec = 0;
			boolean sec = false;
			for ( int i = 0; i < N; i++ )
			{	
				int starsToGet = 0;
				if ( stars >= sr[i][1] )
					starsToGet = 2;
				else if ( stars >= sr[i][0] )
					starsToGet = 1;
				
				if ( starsCollected[i] == 1 )
					starsToGet -= 1;
				if ( starsCollected[i] == 2 )
					starsToGet -= 2;
				
				if ( starsToGet > 0 )
					if ( starsToGet > maxStars || ( starsToGet == maxStars && ( sr[i][1] > minSec && !sec || starsCollected[i] == 1 ) ) )
					{
						maxStars = starsToGet;
						maxI = i;
						minSec = sr[i][1];
						sec = starsCollected[i] == 1;
					}
			}
			
			if ( maxI == -1 )
			{
				bw.append( "Case #"+n+": Too Bad\n" );
				return;
			}
			
			stars += maxStars;
			starsCollected[maxI] += maxStars;
			count++;
		}
		
		bw.append( "Case #"+n+": "+count+"\n" );
	}

	public static void main( String[] args ) throws Exception
	{
		File inputFile = new File( "inputfiles/round1a/p2/input.txt" );
		FileReader fr = new FileReader( inputFile );
		BufferedReader br = new BufferedReader( fr );
		
		int numOfTestCases = Integer.parseInt( br.readLine() );
		
		File outputFile = new File( "inputfiles/round1a/p2/output.txt" );
		outputFile.delete();
		outputFile.createNewFile();
		FileWriter fw = new FileWriter( outputFile );
		BufferedWriter bw = new BufferedWriter( fw );
		
		for ( int i = 0; i < numOfTestCases; i++ )
		{
			int N = Integer.parseInt( br.readLine() );
			int[][] sr = new int[N][2];
			
			for ( int j = 0; j < N; j++ )
			{
				String[] sl = br.readLine().split( " " );
				sr[j][0] = Integer.parseInt( sl[0] );
				sr[j][1] = Integer.parseInt( sl[1] );
			}
			
			calculate( N, sr, bw, i+1 );
		}
		
		bw.flush();
		fw.flush();
		
		bw.close();
		fw.close();
	}
}
