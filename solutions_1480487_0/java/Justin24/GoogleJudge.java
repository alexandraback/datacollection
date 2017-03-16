package googleJam;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class GoogleJudge
{

	public static void main(String[] args)
	{
		Scanner scan = null;
		try
		{
			scan = new Scanner(new File(args[0]));
		}
		catch (FileNotFoundException e)
		{
			System.err.println("File not found!");
			return;
		}
		if (!scan.hasNext())
		{
			System.err.println("Nothing in File!");
			return;
		}
		double testCases = Double.parseDouble(scan.nextLine());
		String[] line;
		int number = 1;
		while (scan.hasNext())
		{
			String str = scan.nextLine();
			line = str.split(" ");
			double totalPoints = 0;
			double minPoints = 0;
			double[] arr = new double[(line.length - 1)];
			for (int x = 1; x < line.length; x++)
			{
				totalPoints = totalPoints + Double.parseDouble(line[x]);			
			}
			totalPoints = totalPoints * 2;
			arr = getPercentages(line, totalPoints);
			System.out.print("Case #" + number + ": ");
			for (int x = 0; x < (arr.length - 1); x++)
			{
				System.out.print((arr[x]*100) + " ");
			}

			if (number != testCases)
			{
				System.out.println(100*arr[arr.length-1]);
			}
			else
			{
				System.out.print(100*arr[arr.length-1]);
			}
			number++;
		}

	}
	public static double[] getPercentages(String[] line, double totalPoints)
	{
		double minPoints = 0;
		double realTotal = totalPoints;
		double[] arr = new double[line.length - 1];
		int countBigs = 0;
		for (int x = 1; x < line.length; x++)
		{
			minPoints = totalPoints / (line.length - 1);
			minPoints = (minPoints - Double.parseDouble(line[x]));
			if(minPoints <= 0)
			{
				countBigs++;
				realTotal = realTotal - Double.parseDouble(line[x]);
			}
		}
		for (int x = 1; x < line.length; x++)
		{
			minPoints = realTotal / (line.length - (1 + countBigs));
			minPoints = (minPoints - Double.parseDouble(line[x]));
			if(minPoints <= 0)
			{
				arr[x-1] = 0;
			}
			else
			{
				arr[x - 1] = minPoints / (totalPoints/2.0);
			}
		}
		return arr;
	}
}
