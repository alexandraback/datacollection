/*
 * Google Code Challenge Java
 * 
 * Code written for the Google Code Challenge by Greg Dougherty
 * Created: April 12, 2013
 * 
 * Copyright 2013 by Greg Dougherty
 */

package com.google.GregTD.CodeJam2014.Quals.ProbD;

import java.io.*;
import java.util.Arrays;

/**
 * @author Greg Dougherty
 *
 */
public class DeceitfulWar
{
	
	private static final String	kInSuffix = ".in";
	private static final String	kOutSuffix = ".out";
	
	
	/**
	 * @param args
	 */
	public static void main (String[] args)
	{
		String	inName = args[0];
		int		nameLen = inName.indexOf (kInSuffix);
		String	outName = inName.substring (0, nameLen) + kOutSuffix;
		File	dataFile = new File (args[0]);
		File	resultFile = new File (outName);
		
		try
		{
			BufferedReader	dataReader = new BufferedReader (new FileReader (dataFile));
			BufferedWriter	dataWriter = new BufferedWriter (new FileWriter (resultFile));
			String			line = dataReader.readLine ();	// Get first line
			int				numCases = Integer.parseInt (line);
			
			// Run each test case
			for (int i = 0; i < numCases; ++i)
			{
				line = dataReader.readLine ();
				
				int			numBlocks = Integer.parseInt (line);
				double[]	naomiBlocks = new double[numBlocks];
				double[]	kenBlocks = new double[numBlocks];
				
				line = dataReader.readLine ();
				String[]	values = line.split (" ");
				
				for (int j = 0; j < numBlocks; ++j)
					naomiBlocks[j] = Double.parseDouble (values[j]);
				
				line = dataReader.readLine ();
				values = line.split (" ");
				
				for (int j = 0; j < numBlocks; ++j)
					kenBlocks[j] = Double.parseDouble (values[j]);
				
				Arrays.sort (naomiBlocks);
				Arrays.sort (kenBlocks);
				
				double[]	useKen = Arrays.copyOf (kenBlocks, numBlocks);
				double[]	useNaomi = Arrays.copyOf (naomiBlocks, numBlocks);
				int	cheatWins = getCheatWins (numBlocks, useNaomi, useKen);
				int	fairWins = getFairWins (numBlocks, naomiBlocks, kenBlocks);
				
				dataWriter.write ("Case #" + (i + 1) + ": ");
				dataWriter.write ("" + cheatWins + " " + fairWins);
				dataWriter.newLine ();
				dataWriter.flush ();
			}
			
			dataReader.close ();
			dataWriter.close ();
		}
		catch (IOException ioE)
		{
			ioE.printStackTrace ();
		}
	}
	
	
	/**
	 * Computer naomi's wins if she doesn't cheat
	 * 
	 * @param numBlocks		Number of blocks
	 * @param naomiBlocks	Naomi's blocks, in sorted increasing order
	 * @param kenBlocks		Ken's blocks, in sorted increasing order
	 * @return	Number of her wins
	 */
	private static int getFairWins (int numBlocks, double[] naomiBlocks, double[] kenBlocks)
	{
		int	numWins = 0;
		
		for (double curBlock : naomiBlocks)
		{
			boolean	won = true;
			
			for (int i = 0; i < numBlocks; ++i)
			{
				if (kenBlocks[i] > curBlock)
				{
					won = false;
					kenBlocks[i] = 0;
					break;
				}
			}
			
			if (won)
			{
				++numWins;
				blankMin (numBlocks, kenBlocks);
			}
		}
		
		return numWins;
	}
	
	
	/**
	 * Find the smallest non-zero cell, and make it zero
	 * 
	 * @param numBlocks	Number of blocks
	 * @param blocks	Array of blocks to work on
	 */
	private static final void blankMin (int numBlocks, double[] blocks)
	{
		for (int i = 0; i < numBlocks; ++i)
		{
			if (blocks[i] > 0.0)
			{
				blocks[i] = 0;
				return;
			}
		}
	}
	
	
	/**
	 * Find the largest non-zero cell, and make it zero
	 * 
	 * @param numBlocks	Number of blocks
	 * @param blocks	Array of blocks to work on
	 */
	private static final void blankMax (int numBlocks, double[] blocks)
	{
		for (int i = numBlocks - 1; i >= 0; --i)
		{
			if (blocks[i] > 0.0)
			{
				blocks[i] = 0;
				return;
			}
		}
	}
	
	
	/**
	 * Find the smallest non-zero cell, and make it zero
	 * 
	 * @param numBlocks	Number of blocks
	 * @param blocks	Array of blocks to work on
	 */
	private static final double getMin (int numBlocks, double[] blocks)
	{
		for (int i = 0; i < numBlocks; ++i)
		{
			if (blocks[i] > 0.0)
				return blocks[i];
		}
		
		return 0.0;
	}
	
	
	/**
	 * Find the largest non-zero cell, and make it zero
	 * 
	 * @param numBlocks	Number of blocks
	 * @param blocks	Array of blocks to work on
	 */
	private static final double getMax (int numBlocks, double[] blocks)
	{
		for (int i = numBlocks - 1; i >= 0; --i)
		{
			if (blocks[i] > 0.0)
				return blocks[i];
		}
		
		return 0.0;
	}
	
	
	/**
	 * Computer naomi's wins if she doesn't cheat
	 * 
	 * @param numBlocks		Number of blocks
	 * @param naomiBlocks	Naomi's blocks, in sorted increasing order
	 * @param kenBlocks		Ken's blocks, in sorted increasing order
	 * @return	Number of her wins
	 */
	private static int getCheatWins (int numBlocks, double[] naomiBlocks, double[] kenBlocks)
	{
		int	numWins = 0;
		
		for (int i = 0; i < numBlocks; ++i)
		{
			double	naomi = naomiBlocks[i];
			double	kenMax = getMax (numBlocks, kenBlocks);
			
			if (kenMax < naomi)
				return (numBlocks - i) + numWins;
			
			double	kenMin = getMin (numBlocks, kenBlocks);
			if (kenMin < naomi)
			{
				++numWins;
				blankMin (numBlocks, kenBlocks);
			}
			else
				blankMax (numBlocks, kenBlocks);
		}
		
		return numWins;
	}
	
}
