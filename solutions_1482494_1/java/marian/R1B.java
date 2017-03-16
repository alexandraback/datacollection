package jam2012;
import java.io.*;
import java.util.*;

// Marian G Olteanu
public class R1B
{
	public static void main(String[] args)
	throws Exception
	{
		BufferedReader inputFile = new BufferedReader(new InputStreamReader(new FileInputStream(args[0])));
		int cases = Integer.parseInt(inputFile.readLine());
		
		PrintStream outFile = new PrintStream(new FileOutputStream(args[1]));
		for (int i = 1; i <= cases; i++)
		{
			int n = Integer.parseInt(inputFile.readLine());
			int[][] cost = new int[n][2];
			for (int j = 0; j < n; j++)
			{
				String lineT[] = tokenize(inputFile.readLine());
				cost[j][0] = Integer.parseInt(lineT[0]);
				cost[j][1] = Integer.parseInt(lineT[1]);
			}
			
			int[] collectedStars = new int[n];
			int totalCollectedStars = 0;
			int gamesPlayed = 0;
			boolean failure = false;
			
			X: while (totalCollectedStars < n + n)
			{
				// search for a level 2 game, any of them is fine
				for (int j = 0; j < n; j++)
					if (collectedStars[j] < 2 && cost[j][1] <= totalCollectedStars)
					{
						totalCollectedStars += 2 - collectedStars[j];
						collectedStars[j] = 2;
						gamesPlayed++;
						continue X;
					}
				
				// search for a level 1 game, goal is that cost for level 2 is maximum, so that it's pushed as far as possible
				int idxMaxL2 = -1;
				int maxL2 = -1;
				
				for (int j = 0; j < n; j++)
					if (collectedStars[j] == 0 && cost[j][0] <= totalCollectedStars)
					{
						int cL2 = cost[j][1];
						if (idxMaxL2 == -1 || cL2 > maxL2)
						{
							idxMaxL2 = j;
							maxL2 = cL2;
						}
					}
				
				if (idxMaxL2 == -1)
				{
					failure = true;
					break X;
				}
				
				totalCollectedStars++;
				collectedStars[idxMaxL2] = 1;
				gamesPlayed++;
			}
			
			String out;
			if (failure)
				out = "Too Bad";
			else
				out = "" + gamesPlayed;
			
			outFile.println("Case #" + i + ": " + out);
		}
		
		
		outFile.close();
		inputFile.close();
	}
	
	
	
	
	public static String[] tokenize(String input)
	{
		StringTokenizer st = new StringTokenizer(input);
		String[] k = new String[st.countTokens()];
		for (int i = 0; i < k.length; i++)
			k[i] = st.nextToken();
		return k;
	}
	public static String[] tokenize(String input, String sep)
	{
		StringTokenizer st = new StringTokenizer(input , sep);
		String[] k = new String[st.countTokens()];
		for (int i = 0; i < k.length; i++)
			k[i] = st.nextToken();
		return k;
	}
	
}

