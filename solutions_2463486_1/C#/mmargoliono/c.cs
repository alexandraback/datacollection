using System;
using System.Collections.Generic;

public class q
{
	public static void Main()
	{
		ulong maxNotBaseNumber = (ulong) Math.Pow(10,7);
		HashSet<string> fairAndSquare = new HashSet<string>();

		for (ulong i=0; i<=maxNotBaseNumber; i++)
		{
			if (isFairAndSquareBase(i))
			{
				ulong fairAndSquareNumber = i * i;
				fairAndSquare.Add(fairAndSquareNumber  + "");
			}
		}
		
		int n;
		n = Int32.Parse(Console.ReadLine());
				
		for (int i=1; i<=n; i++)
		{
			int counter = 0;
			
			ulong start;
			ulong end;

			string[] line = Console.ReadLine().Split(' ');
			
			start = UInt64.Parse(line[0]);
			end = UInt64.Parse(line[1]);
			
			foreach (string xx in fairAndSquare)
			{
				ulong x = UInt64.Parse(xx);
				if (x >= start && x<= end)
				{
					counter++;
				}
			}

			Console.WriteLine(String.Format("Case #{0}: {1}", i, counter));
		}
	}
	
	public static bool isFairAndSquareBase(ulong number)
	{
		string numberString = number + "";
		
		//check palindrome
		
		for (int i=0; i< numberString.Length/2; i++)
		{
			if(numberString[i] != numberString[numberString.Length - i - 1])
				return false;
		}
		
		int counter = 0;

		for (int i=0; i< numberString.Length; i++)
		{
			int digit = Int32.Parse(numberString[i] + "");
			counter += digit * digit;
			
			if (counter >= 10)
			{
				return false;
			}
		}
		
		return true;
	}
}