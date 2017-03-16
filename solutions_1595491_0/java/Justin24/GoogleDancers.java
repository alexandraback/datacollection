package googleJam;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class GoogleDancers 
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
		int testCases = Integer.parseInt(scan.nextLine());
		String[] line;
		String str;
		int theFabulousGoogleDancers;
		int soManySurprises;
		int whoIsBetterThanMe;
		int itsAStretch;
		int noSurpriseNeeded;
		int iAmBetterThanYou;
		int canReachWithSurprise;
		int number = 1;
		int combined;
		while (scan.hasNext())
		{
			System.out.print("Case #" + number + ": ");
			iAmBetterThanYou = 0;
			itsAStretch = 0;
			str = scan.nextLine();
			line = str.split(" ");
			theFabulousGoogleDancers = Integer.parseInt(line[0]);
			soManySurprises = Integer.parseInt(line[1]);
			whoIsBetterThanMe = Integer.parseInt(line[2]);
			noSurpriseNeeded = (whoIsBetterThanMe + (whoIsBetterThanMe-1) + (whoIsBetterThanMe-1));
			canReachWithSurprise = (whoIsBetterThanMe + (whoIsBetterThanMe-2) + (whoIsBetterThanMe - 2));
			if (whoIsBetterThanMe == 1)
			{
				noSurpriseNeeded = 1;
				canReachWithSurprise = 1;
			}
			if (whoIsBetterThanMe == 0)
			{
				noSurpriseNeeded = 0;
				canReachWithSurprise = 0;
			}
			for (int score = 3; score < line.length; score++)
			{
				if ((Integer.parseInt(line[score])) >= canReachWithSurprise && Integer.parseInt(line[score]) < noSurpriseNeeded)
				{
					itsAStretch++;
				}
				else if (Integer.parseInt(line[score]) >= noSurpriseNeeded)
				{
					iAmBetterThanYou++;
				}
			}
			if (itsAStretch <= soManySurprises)
			{
				combined = iAmBetterThanYou + itsAStretch;
			}
			else
			{
				combined = iAmBetterThanYou + soManySurprises;
			}

			System.out.print(combined);
			if(scan.hasNext())
			{
				System.out.println();
			}
			number++;
		}
	}

}
