/*
 * Google Code Challenge Java
 * 
 * Code written for the Google Code Challenge by Greg Dougherty
 * Created: April 17, 2015
 * 
 * Copyright 2015 by Greg Dougherty
 */

package com.google.GregTD.CodeJam2016.Round1C.Problem2;

import java.io.*;

/**
 * @author Greg Dougherty
 *
 */
public class Fashion
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
			StringBuilder	results = new StringBuilder (200);
			StringBuilder	out = new StringBuilder (20000);
			
			// Run each test case
			for (int i = 0; i < numCases; ++i)
			{
				line = dataReader.readLine ();
				
				int	numDays = calcDays (line, out);
				
				results.delete (0, results.length ());
				results.append ("Case #");
				results.append (i + 1);
				results.append (": ");
				results.append (numDays);
				results.append ("\n");
				results.append (out);
				dataWriter.write (results.toString ());
				dataWriter.flush ();
				System.out.print (results.toString ());
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
	 * 
	 * @param line
	 * @param out
	 * @return
	 */
	private static int calcDays (String line, StringBuilder out)
	{
		out.delete (0, out.length ());
		
		String[]	nums = line.split (" ");
		int	jackets = Integer.valueOf (nums[0]);
		int	pants = Integer.valueOf (nums[1]);
		int	shirts = Integer.valueOf (nums[2]);
		int	maxPair = Integer.valueOf (nums[3]);
		
		if (maxPair >= shirts)
			return dump (jackets, pants, shirts, out);
		
		int		numDays = 0;
		int[][]	js = new int[jackets][];
		int[][]	ps = new int[pants][];
		
		for (int j = 0; j < jackets; ++j)
			js[j] = new int[shirts];
		for (int j = 0; j < pants; ++j)
			ps[j] = new int[shirts];
		
		for (int j = 0; j < jackets; ++j)
		{
			int[]	jacks = js[j];
			
			for (int k = 0; k < pants; ++k)
			{
				int[]	pant = ps[k];
				int		pCount = 0;
				int		start = 0;
				
				for (int l = 0; l < shirts; ++l)
				{
					if (pCount >= maxPair)
						break;
					int	which = getSmallest (start, jacks, pant, shirts);
					int	test = jacks[which];
					
					start = which + 1;
					if (test < maxPair)
					{
						int	tester = pant[which];
						if (tester < maxPair)
						{
							++numDays;
							++pCount;
							start = 0;
							jacks[which] = test + 1;
							pant[which] = tester + 1;
							out.append (j + 1);
							out.append (' ');
							out.append (k + 1);
							out.append (' ');
							out.append (which + 1);
							out.append ("\n");
						}
					}
				}
				
			}
		}
		
		return numDays;
	}


	/**
	 * 
	 * @param jacks
	 * @param pant
	 * @param shirts
	 * @return
	 */
	private static int getSmallest (int start, int[] jacks, int[] pant, int shirts)
	{
		int	which = start;
		int	min = jacks[start] + pant[start];
		int	diff = jacks[start] - pant[start];
		
		if (diff < 0)
			diff = -diff;
		
		for (int i = start + 1; i < shirts; ++i)
		{
			int	score = jacks[i] + pant[i];
			if (score < min)
			{
				min = score;
				which = i;
				diff = jacks[i] - pant[i];
				if (diff < 0)
					diff = -diff;
			}
			else if (score == min)
			{
				int	curDiff = jacks[i] - pant[i];
				if (curDiff < 0)
					curDiff = -curDiff;
				
				if (curDiff < diff)
				{
					diff = curDiff;
					which = i;
				}
			}
		}
		
		return which;
	}


	/**
	 * 
	 * @param jackets
	 * @param pants
	 * @param shirts
	 * @return
	 */
	private static int dump (int jackets, int pants, int shirts, StringBuilder out)
	{
		int	numDays = 0;
		for (int j = 0; j < jackets; ++j)
		{
			for (int k = 0; k < pants; ++k)
			{
				for (int l = 0; l < shirts; ++l)
				{
					++numDays;
					out.append (j + 1);
					out.append (' ');
					out.append (k + 1);
					out.append (' ');
					out.append (l + 1);
					out.append ("\n");
				}
				
			}
		}
		return numDays;
	}
	
}
