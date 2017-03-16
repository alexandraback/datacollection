/*
 * Google Code Jam 2014 - Problem D
 * 
 * Jae Yoon Chong (jychong1@gmail.com)
 * 
 * DeceitfulWarMain
 */

import java.io.*;
import java.util.*;

public class DeceitfulWarMain {

	final static int DECEITFUL_WAR_READLINE_INDEX_BLOCK_COUNT  = 0;
	final static int DECEITFUL_WAR_READLINE_INDEX_WEIGHT_NAOMI = 1;
	final static int DECEITFUL_WAR_READLINE_INDEX_WEIGHT_KEN   = 2;
	
	public static void main(String[] args)
	{
		String filename = args[0];

		FileReader fr = null;
		BufferedReader br = null;
		
		try {
			fr = new FileReader (filename);
			br = new BufferedReader(fr);

			int indexCurrTrial = 1;
			int indexCurrRow = 0;
			
			int countBlocks = 0;
			float[] blockWeightNaomi = null;
			float[] blockWeightKen = null;
			
			String line = br.readLine();
            while ((line = br.readLine()) != null)
    		{	
            	switch (indexCurrRow)
            	{
            	case DECEITFUL_WAR_READLINE_INDEX_BLOCK_COUNT:
            	{
            		countBlocks = Integer.parseInt(line);
            		blockWeightNaomi = new float[countBlocks];
            		blockWeightKen = new float[countBlocks];
            		break;
            	}

            	case DECEITFUL_WAR_READLINE_INDEX_WEIGHT_NAOMI:
            		blockWeightNaomi = createSortedBlockWeightsFromString(line, countBlocks);
            		break;

            	case DECEITFUL_WAR_READLINE_INDEX_WEIGHT_KEN:
            		blockWeightKen = createSortedBlockWeightsFromString(line, countBlocks);
            		break;
            	}

            	if (indexCurrRow == DECEITFUL_WAR_READLINE_INDEX_WEIGHT_KEN)
            	{
            		// play game here
            		
            		// 1) base case
            		if (countBlocks == 1)
            		{
            			float weightNaomi = blockWeightNaomi[0];
            			float weightKey   = blockWeightKen[0];
            			
            			if (weightNaomi > weightKey)
            				System.out.println("Case #" + indexCurrTrial++ + ": 1 1");
            			else
            				System.out.println("Case #" + indexCurrTrial++ + ": 0 0");
            		}
            		
            		// 2) non-base cases
            		else
            		{
            			int countNaomiWinDeceitfulWar = playDeceitfulWar(blockWeightNaomi, blockWeightKen, countBlocks);
            			int countNaomiWinNormalWar = playNormalWar(blockWeightNaomi, blockWeightKen, countBlocks);
            			System.out.println("Case #" + indexCurrTrial++ + ": " + countNaomiWinDeceitfulWar + " " + countNaomiWinNormalWar);
            		}
            		
            		// clear states
            		countBlocks = 0;
            		blockWeightNaomi = null;
            		blockWeightKen = null;
            		
            		// clear readline index
            		indexCurrRow = 0;
            	}
            	else
            		// increment readline index
            		indexCurrRow++;
    		}
			
		} catch (FileNotFoundException ex) {
			// exception handling
		} catch (IOException ex) {
			// exception handling
		} finally {
			try {
				br.close();
				fr.close();
			} catch (IOException ex) {
				// exception handling
			}
		}
	}

	public static int playDeceitfulWar(float[] blockWeightNaomi, float[] blockWeightKen, int count)
	{
		// in-order for Naomi to win, she needs higher values than Ken
		
		int countNaomiWin = 0;
		int indexNaomi = 0;
		int indexKen   = 0;

		while (indexNaomi < count && indexKen < count)
		{
			float currWeightNaomi = blockWeightNaomi[indexNaomi];
			float currWeightKen   = blockWeightKen[indexKen];
			boolean isNaomiValueGreater = currWeightNaomi > currWeightKen;
			if (isNaomiValueGreater)
			{
				indexKen++;
				indexNaomi++;
				countNaomiWin++;
			}
			else
				indexNaomi++;

		}
		return countNaomiWin;
		
//		int countNaomiWin = 0;
//		int indexNaomi = 0;
//		int indexKen   = 0;
//		int indexNaomiEnd = count - 1;
//		int indexKenEnd   = count - 1;
//		
//		while (indexNaomi <= indexNaomiEnd && indexKen <= indexKenEnd)
//		{
//			float currWeightNaomi = blockWeightNaomi[indexNaomi];
//			float currWeightKen   = blockWeightKen[indexKen];
//			boolean isNaomiValueGreater = currWeightNaomi > currWeightKen;
//			if (isNaomiValueGreater)
//			{
//				indexKen++;
//				indexNaomi++;
//				countNaomiWin++;
//			}
//			else
//			{
//				indexNaomi++;
//				indexKenEnd--;
//			}
//
//		}
//		return countNaomiWin;
	}
	
	public static int playNormalWar(float[] blockWeightNaomi, float[] blockWeightKen, int count)
	{
		// keep track of number of transitions of value at each indices, local min from Naomi to Ken -> this gives you # of win for Ken 
		// lastly, subtract that number from count -> this gives you win for Naomi	
		int indexNaomi  = 0;
		int indexKen    = 0;

		while (indexNaomi < count && indexKen < count)
		{
			float currWeightNaomi = blockWeightNaomi[indexNaomi];
			float currWeightKen   = blockWeightKen[indexKen];
			boolean isNaomiValueGreater = currWeightNaomi > currWeightKen;
			if (isNaomiValueGreater)
				indexKen++;
			else
			{
				indexKen++;
				indexNaomi++;
			}
		}
		return count - indexNaomi;
	}
	
	public static float[] createSortedBlockWeightsFromString(String weightString, int count)
	{
		float[] newBlockWeights = new float[count];
		int index = 0;
		
		StringTokenizer st = new StringTokenizer(weightString, " ");
		while (st.hasMoreTokens())
		{
			newBlockWeights[index++] = Float.parseFloat(st.nextToken());
		}
		Arrays.sort(newBlockWeights);
		return newBlockWeights;
	}
}
