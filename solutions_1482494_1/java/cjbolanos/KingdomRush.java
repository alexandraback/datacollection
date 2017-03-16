package test.googlejam.year2012.jam;

import java.io.IOException;

import test.googlejam.base.ProblemProcessor;

public class KingdomRush extends ProblemProcessor
{

	static java.util.Map<Integer, Integer> mapping = new java.util.TreeMap<Integer, Integer>();
	public static void main(String[] args) throws java.io.IOException
	{
		KingdomRush processor;

		final String FILE_BASE = "C:/Users/cjbolanos/workspace/Google Code Jam/src/"
				+ KingdomRush.class.getName().substring(0, 
						KingdomRush.class.getName().lastIndexOf('.')).replace('.', '/'); 
		final String FILE_NAME = KingdomRush.class.getName().substring(
				KingdomRush.class.getName().lastIndexOf('.') + 1); 
		final String CASE_NAME = "large"; 
		processor = new KingdomRush();
		processor.setInputFileName(FILE_BASE + "/" + FILE_NAME + "-" + CASE_NAME + ".in");
		processor.setOutputFileName(FILE_BASE + "/" + FILE_NAME + "-" + CASE_NAME + ".out");
		processor.start();
	}

	@Override
	public String processCase(int caseNumber) throws IOException
	{
		int levels = this.readInteger();
		int[][] reqLevelStars = new int[levels][];
		
		for ( int i = 0; i < levels; i++ )
			reqLevelStars[i] = this.readIntegerArray(" ");
		
		int[] levelStars = new int[levels];
		int totalStars = 0;

		int totalPlays = 0;
		start: while ( true )
		{
			// which levels with two stars can I play?
			for ( int i = 0; i < levels; i++ )
			{
				if ( reqLevelStars[i][1] <= totalStars )
				{
					if ( levelStars[i] == 2 ) continue;

					totalStars += 2 - levelStars[i];
					levelStars[i] = 2;
					totalPlays++;
					continue start;
				}
			}

			// Determine which first level to try
			int bestLevel = -1;
			int bestLevelReqStars = -1;
			for ( int i = 0; i < levels; i++ )
			{
				if ( levelStars[i] > 0 ) continue;
				if ( reqLevelStars[i][0] <= totalStars )
				{
					if ( reqLevelStars[i][1] > bestLevelReqStars )
					{
						bestLevel = i;
						bestLevelReqStars = reqLevelStars[i][1];
					}
				}
			}
			
			if ( -1 != bestLevel )
			{
				totalStars++;
				levelStars[bestLevel] = 1;
				totalPlays++;
				continue;
			}

			// Nothing to play. Are we done?
			for ( int i = 0; i < levels; i++ )
			{
				if ( levelStars[i] < 2 )
					return "Too Bad";
			}
			
			break;
		}

		return Integer.toString(totalPlays);
	}
}
