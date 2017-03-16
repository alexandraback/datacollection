/*
 * Google Code Challenge Java
 * 
 * Code written for the Google Code Challenge by Greg Dougherty
 * Created: May 20, 2011
 * 
 * Copyright 2011 by Greg Dougherty
 */

package com.google.GregTD.CodeJam2013.Round1C.Problem3;

import java.io.*;
import java.text.NumberFormat;
import java.util.*;

/**
 * Class that lets you pass in a double value to a routine that can then modify it, 
 * i.e. pass the double by reference
 * @author Greg Dougherty
 */
class ModInt
{
	int	value;
}


/**
 * Class that lets you pass in a double value to a routine that can then modify it, 
 * i.e. pass the double by reference
 * @author Greg Dougherty
 */
class ModLong
{
	long	value;
}


/**
 * Class that lets you pass in a double value to a routine that can then modify it, 
 * i.e. pass the double by reference
 * @author Greg Dougherty
 */
class ModDouble
{
	double	value;
}

/**
 * @author Greg Dougherty
 *
 */
public class Wall implements Runnable
{
	private int[][]	results;
	private int[][]	values;
	private int		numFactors;
	private int		maxFactor;
	private int		numOutputs;
	private int		first;
	private int		last;
	
	static PrintStream		out;
	static BufferedReader	dataReader;
	static Deque<String>	lineStack = new ArrayDeque<String> ();
	static Deque<String>	wordStack = new ArrayDeque<String> ();
	static NumberFormat		format;
	static boolean			debugging = true;
	
	private static final int	kNumThreads = 20;
	
	
	/**
	 * @param results
	 * @param values
	 * @param numFactors
	 * @param maxFactor
	 * @param numOutputs
	 * @param first
	 * @param last
	 */
	public Wall (int[][] results, int[][] values, int numFactors, int maxFactor, int numOutputs, int first, int last)
	{
		this.results = results;
		this.values = values;
		this.numFactors = numFactors;
		this.maxFactor = maxFactor;
		this.numOutputs = numOutputs;
		this.first = first;
		this.last = last;
	}
	
	
	private static final int	kAttackDay = 0;
	private static final int	kAttackCount = kAttackDay + 1;
	private static final int	kAttackStart = kAttackCount + 1;
	private static final int	kAttackEnd = kAttackStart + 1;
	private static final int	kAttackStrength = kAttackEnd + 1;
	private static final int	kDaysBetweenAttacks = kAttackStrength + 1;
	private static final int	kAttackDistance = kDaysBetweenAttacks + 1;
	private static final int	kStrengthDelta = kAttackDistance + 1;
	private static final int	kTribeData = kStrengthDelta + 1;
	
	/**
	 * @param args
	 */
	public static void main (String[] args)
	{
		getDataReader (args);
		
		try
		{
			String		line = readLine ();	// Get the number of test cases
			String[]	numbers;
			int			numCases = Integer.parseInt (line);
			
			for (int i = 0; i < numCases; ++i)
			{
				line = readLine ();
				int				numTribes = Integer.parseInt (line);
				List<long[]>	tribes = new ArrayList<long[]> ();
				Map<Long, Long>	theWall = new HashMap<Long, Long> ();
				Map<Long, Long>	newWall = new HashMap<Long, Long> ();
				
				for (int j = 0; j < numTribes; ++j)
				{
					line = readLine ();
					numbers = line.split (" ");
					long[]	row = new long[8];
					for (int k = 0; k < kTribeData; ++k)
						row[k] = Long.parseLong (numbers[k]);
					tribes.add (row);
				}
				
				int		count = 0;
				
				while (!tribes.isEmpty ())
				{
					Iterator<long[]>	iter = tribes.iterator ();
					while (iter.hasNext ())
					{
						long[]	tribe = iter.next ();
						
						if (tribe[kAttackDay] > 0)
						{
							--(tribe[kAttackDay]);
							continue;
						}
						
						tribe[kAttackDay] = tribe[kDaysBetweenAttacks] - 1;
						count += doAttack (tribe, theWall, newWall);
						long	attacksLeft = tribe[kAttackCount] - 1;
						if (attacksLeft <= 0)
						{
							iter.remove ();
							continue;
						}
						
						tribe[kAttackCount] = attacksLeft;
						long	dist = tribe[kAttackDistance];
						tribe[kAttackStart] += dist;
						tribe[kAttackEnd] += dist;
						tribe[kAttackStrength] += tribe[kStrengthDelta];
					}
					
					theWall.putAll (newWall);
					newWall.clear ();
				}
				
//				Thread[]	threads = new Thread[kNumThreads];
//				int			block = numCases / kNumThreads;
//				int			min = 0;
//				int			max = block;
				
//				for (int j = 0; j < kNumThreads; ++j)
//				{
//				}
				
//				try
//				{
//					for (int j = 0; j < kNumThreads; ++j)
//						threads[i].join ();
//				}
//				catch (InterruptedException oops)
//				{
//					oops.printStackTrace ();
//				}
				
				println ("Case #" + (i + 1) + ": " + count);
				
//				println ("Case #1:");
//				for (int i = 0; i < numLines; ++i)
//				{
//					int[]	row = results[i];
//					for (int k = 0; k < numOutputs; ++k)
//						print ("" + row[k]);
//					println ("");
//				}
			}
			close ();
		}
		catch (IOException ioE)
		{
			ioE.printStackTrace ();
		}
	}
	
	
	/**
	 * 
	 * @param tribe
	 * @param theWall
	 * @param newWall
	 * @return
	 */
	private static int doAttack (long[] tribe, Map<Long, Long> theWall, Map<Long, Long> newWall)
	{
		long	strength = tribe[kAttackStrength];
		long	start = tribe[kAttackStart] * 2;
		long	end = tribe[kAttackEnd] * 2;
		boolean	success = false;
		
		for (long pos = start; pos <= end; ++pos)
		{
			Long	key = Long.valueOf (pos);
			Long	value = theWall.get (key);
			long	height = 0;
			if (value != null)
				height = value.longValue ();
			if (height < strength)
			{
				success = true;
				value = newWall.get (key);
				if (value != null)
					height = value.longValue ();
				if (height < strength)
					newWall.put (key, Long.valueOf (strength));
			}
		}
		
		if (success)
			return 1;
		
		return 0;
	}


	/* (non-Javadoc)
	 * @see java.lang.Runnable#run()
	 */
	public void run ()
	{
		// Run its cases
		for (int i = first; i < last; ++i)
		{
			int[]	products = values[i];
			int[]	result = new int[numOutputs];
			
			results[i] = result;
		}
	}
	

	/**
	 * Print a String to System.out, and to the output file, if it exists
	 * @param outString	String to print
	 */
	protected static final void print (String outString)
	{
		if (debugging)
			System.out.print (outString);
		
		if (out != null)
			out.print (outString);
	}
	
	
	/**
	 * Println a String to System.out, and to the output file, if it exists
	 * @param outString	String to print
	 */
	protected static final void println (String outString)
	{
		if (debugging)
			System.out.println (outString);
		
		if (out != null)
			out.println (outString);
	}
	
	
	/**
	 * Take a line that had been read, and put it back for the next call to get
	 * @param line	line that caller doesn't need after all.
	 */
	static void unreadLine (String line)
	{
		lineStack.addFirst (line);
	}
	
	
	/**
	 * Get the most recently unread line.  If there are no lines that have been read from
	 * the data file and then "unread", get the next lien from the data file
	 * Note; This ignores the contents of the Word Stack.  Perhaps it shouldn't?  in any case,
	 * when using both readLine and readWord, be aware of the potential for issues to crop up
	 * @return	the next line of text
	 * @throws IOException
	 */
	static String readLine () throws IOException
	{
		if (!lineStack.isEmpty ())
			return lineStack.removeFirst ();
		
		if (dataReader == null)
			return null;
		
		return dataReader.readLine ();
	}
	
	
	/**
	 * Take a word that had been read, and puts it back on the stack to be read again.
	 * Major use is when there are multiple tokens in one "word"
	 * @param word	The String caller wants to leave for the next caller of readWord
	 */
	static void unreadWord (String word)
	{
		wordStack.addFirst (word);
	}
	
	
	/**
	 * Gets the next word from the Word Stack, or from the data file / Line Stack if the
	 * Word Stack is empty.  Note that once their are words in the Word Stack, they are decoupled
	 * from the line reading.  This might be a bad thing.  As a minimum, callers should be aware of
	 * the potential for trouble.
	 * @return	The next word
	 * @throws IOException
	 */
	static String readWord () throws IOException
	{
		while (wordStack.isEmpty ())
		{
			String	line = readLine ();
			
			if (line == null)
				return null;
			
			String[]	splits = line.split ("\\s");
			
			if ((splits != null) && (splits.length > 0))
			{
				for (int i = splits.length - 1; i >= 0; --i)
				{
					if (splits[i].length () > 0)
						wordStack.addFirst (splits[i]);
				}
			}
		}
		
		return wordStack.removeFirst ();
	}
	
	
	/**
	 * Routine that gets the data reader we will use to get all our data
	 * @param args	Arguments passed in by caller. First arg should be name
	 * of input data file
	 * result:	BufferedReader for the data file, or for stdin if no data file name given or
	 * the file doesn't exist.  Note it is not returned to the caller, because callers should only
	 * access this through readLine and readWord.
	 */
	private static void getDataReader (String[] args)
	{
		File	dataFile = null;
		
		dataReader = null;
		if (args.length > 0)
			dataFile = new File (args[0]);
		
		try
		{
			// If have a data file, try to open it 
			if (dataFile != null)
				dataReader = new BufferedReader (new FileReader (dataFile));
		}
		catch (IOException ioE)
		{
			ioE.printStackTrace ();
			dataReader = null;
		}
		
		// If couldn't open a data file, get data from stdin
		if (dataReader == null)
		{
			dataReader = new BufferedReader (new InputStreamReader (System.in));
			out = null;
			debugging = true;	// Have to write to System.out
		}
		else
		{
			String[]	nameComponents = args[0].split ("\\.");
			int			numComponents = nameComponents.length;
			
			if (nameComponents[numComponents - 1].equalsIgnoreCase ("in"))
				--numComponents;
			
			StringBuilder	name = new StringBuilder ();
			
			for (int i = 0; i < numComponents; ++i)
				name.append (nameComponents[i] + ".");
			
			name.append ("out");
			
			try
			{
				out = new PrintStream (new File (name.toString ()));
			}
			catch (FileNotFoundException ioE)
			{
				out = null;
				debugging = true;	// Have to write to System.out
			}
		}
	}
	
	
	/**
	 * Close everything we opened
	 */
	private static void close ()
	{
		try
		{
			if (dataReader != null)
				dataReader.close ();
			if (out != null)
				out.close ();
		}
		catch (IOException oops)
		{
			// Ignore
		}
		dataReader = null;
		out = null;
	}
}
