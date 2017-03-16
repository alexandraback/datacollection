package Qualification2014;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;

/**
 * Open an input file called "input.txt", output file "output.txt" The file
 * begins with n,the number of lines, followed by n lines each line of the n
 * lines has two numbers writes all the number separated be a space in the
 * output file
 * 
 */
public class D
{

	public static void main(String[] args) throws IOException
	{
		// For the Input file
		BufferedReader in = new BufferedReader(new FileReader("input.txt"));

		// For the output file
		BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));

		// Read the number from the input file and write them to the output file
		int nCases = Integer.parseInt(in.readLine());
		for (int i = 0; i < nCases; i++)
		{
			int n = Integer.parseInt(in.readLine());
			ArrayList<Double> xBlocks = new ArrayList<>();
			ArrayList<Double> yBlocks = new ArrayList<>();

			String[] strs1 = in.readLine().split(" ");
			for (String string : strs1)
				xBlocks.add(Double.parseDouble(string));

			String[] strs2 = in.readLine().split(" ");
			for (String string : strs2)
				yBlocks.add(Double.parseDouble(string));

			out.write("Case #" + (i + 1) + ": ");
			out.write(solveOptimal(n, xBlocks, yBlocks) + " ");
			out.write(solveNotOptimal(n, xBlocks, yBlocks) + "\n");
			
		}
		out.flush();

		// Close the streams
		in.close();
		out.close();
	}

	private static String solveOptimal(int n, ArrayList<Double> xBlocks, ArrayList<Double> yBlocks)
	{
		// Sort both
		Collections.sort(xBlocks);
		Collections.sort(yBlocks);
			
		int xIndex = 0;
		int yStart = 0;
		int yEnd = n-1;
		int score = 0;
		while (xIndex < n)
		{
			if (xBlocks.get(xIndex) < yBlocks.get(yStart))
			{
				yEnd --;
				xIndex ++;
			}
			else
			{
				yStart ++;
				xIndex ++;
				score ++;
			}
		}
		
		return "" + score;
	}

	private static String solveNotOptimal(int n, ArrayList<Double> xBlocks, ArrayList<Double> yBlocks)
	{
		// Sort both
		Collections.sort(xBlocks);
		Collections.sort(yBlocks);
		
		System.out.println(xBlocks);
		System.out.println(yBlocks);
		
		// Find till when he'll win
		int hisIndex = 0;
		int hisScore = 0;
		
		for (int i = 0; i < n; i++)
		{
			Double  myBlock = xBlocks.get(i);

			// he'll look for the next larger block
			boolean foundHigher = false;
			for (int j = hisIndex; j < n; j++)
			{
				if (yBlocks.get(j) > myBlock)
				{
					foundHigher = true;
					hisIndex ++;
					break;
				}
				hisIndex ++ ;
			}
			
			if (foundHigher)
				hisScore ++;
			else
				break;
			
		}
		

		return "" + (n - hisScore);

	}
}