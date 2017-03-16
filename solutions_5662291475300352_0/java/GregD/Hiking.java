/*
 * Google Code Challenge Java
 * 
 * Code written for the Google Code Challenge by Greg Dougherty
 * Created: April 17, 2015
 * 
 * Copyright 2015 by Greg Dougherty
 */

package com.google.GregTD.CodeJam2015.Round1B.Problem3;

import java.util.ArrayList;
import java.util.List;
import java.io.*;

/**
 * @author Greg Dougherty
 *
 */
public class Hiking
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
			
			// Run each test case
			for (int i = 0; i < numCases; ++i)
			{
				line = dataReader.readLine ();
				int	numGroups = Integer.parseInt (line);
				
				List<int[]>	hikers = new ArrayList<int[]> ();
				
				for (int j = 0; j < numGroups; ++j)
				{
					line = dataReader.readLine ();
					String[]	values = line.split (" ");
					int			start, count, speed;
					
					start = Integer.parseInt (values[0]);
					count = Integer.parseInt (values[1]);
					speed = Integer.parseInt (values[2]);
					
					for (int k = 0; k < count; ++k)
					{
						int[]	hiker = new int[2];
						
						hiker[0] = start;
						hiker[1] = speed;
						hikers.add (hiker);
						++speed;
					}
				}
				
				boolean	willCross = false;
				if (hikers.size () == 2)
				{
					int[]	first = hikers.get (0);
					int[]	second = hikers.get (1);
					
					if (first[1] > second[1])	// Order by speed, fast to slow
					{
						first = hikers.get (1);
						second = hikers.get (0);
					}
					
					long	time1 = first[1];
					long	time2 = second[1];
					if (time1 != time2)	// Same speed, no cross
					{
						long	pos1 = 360 - first[0];
						long	pos2 = 360 - second[0];
						long	endTime1 = (pos1 * time1) + (time1 * 360L);	// Time for faster to get around twice
						long	endTime2 = pos2 * time2;	// Time for slower to get around once
						
						willCross = endTime1 <= endTime2;
					}
				}
				
				results.delete (0, results.length ());
				results.append ("Case #");
				results.append (i + 1);
				results.append (": ");
				if (willCross)
					results.append ("1");
				else
					results.append ("0");
				dataWriter.write (results.toString ());
				dataWriter.newLine ();
				dataWriter.flush ();
				System.out.println (results.toString ());
			}
			
			dataReader.close ();
			dataWriter.close ();
		}
		catch (IOException ioE)
		{
			ioE.printStackTrace ();
		}
	}
	
}
