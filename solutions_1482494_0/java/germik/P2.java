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
		if ( n < 12 )
			return;
					
		try {
			System.out.println( "Case #"+n+": "+calc( N, sr, 0, new int[N] )+"\n" );
		} catch ( Exception e ) {
			System.out.println( "Case #"+n+": Too Bad\n" );
		}
	}
	
	private static int calc( int N, int[][] sr, int stars, int[] sgs ) throws Exception
	{
		if ( stars == 2*N )
			return 0;
		
		int min = Integer.MAX_VALUE;
		for ( int i = 0; i < N; i++ )
		{
			if ( stars >= sr[i][1] && sgs[i] < 2 )
			{
				int[] newSgs = new int[N];
				System.arraycopy( sgs, 0, newSgs, 0, N );
				newSgs[i] = 2;
				int newMin = calc( N, sr, stars+( 2-sgs[i] ), newSgs );
				if ( newMin < min )
					min = newMin;
			} else
				if ( stars >= sr[i][0] && sgs[i] < 1 )
				{
					int[] newSgs = new int[N];
					System.arraycopy( sgs, 0, newSgs, 0, N );
					newSgs[i] = 1;
					int newMin = calc( N, sr, stars+1, newSgs );
					if ( newMin < min )
						min = newMin;
				}
		}
		
		if ( min == Integer.MAX_VALUE )
			throw new Exception();
		
		return min+1;
	}

	private static void calculate2( int N, int[][] sr, BufferedWriter bw, int n ) throws Exception
	{
		/*if ( n < 12 )
			return;*/

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
			
			calculate2( N, sr, bw, i+1 );
		}
		
		bw.flush();
		fw.flush();
		
		bw.close();
		fw.close();
	}
}
