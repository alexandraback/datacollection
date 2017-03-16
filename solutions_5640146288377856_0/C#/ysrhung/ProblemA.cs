using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Round1C
{


	class Round1C
	{
	
	
	
	static void log(string log)
	{
		using (StreamWriter writer = new StreamWriter("log.txt", true))
		{
			writer.WriteLine(log);
		}
	}
	
	static int numOfDigits(long input)
	{
		int count = 0;
		while (input > 0)
		{
			input /= 10;
			count++;
		}
		return count;

	}
	
	static long powerOf(int power)
	{
		long j = 1;
		for (int i = 0; i < power; ++i)
		{
			j *= 10;
		}
		return j;
	}
	static long[] numbers = new long[100]; 
	
	/*
	static void preCompute()
	{
		numbers[0] = 0;
		numbers[1] = 1;
		for (long i = 2; i < 100; ++i)
		{
//			Console.WriteLine(i + " " + reverse(i));
			numbers[i] = numbers[i-1] + 1;
			if (i % 10 != 0)
			{
				long reverse = getReverse(i);
				if (reverse < i && numbers[i] > numbers[reverse])
				{
					numbers[i] = numbers[reverse] + 1;
				}
			}
		}
	}
*/
	
	static int guessPerRow(int C, int W)
	{
		return C / W;
	}
	
	static int additionalGuesses(int C, int W)
	{
		int remain = C % W;
		if (remain == 0) return W - 1;
		else return W;
	
	
	}

	static string solveProblem(string line)
	{
		List<int> nums = new List<int>(line.Split().Select(token => int.Parse(token)).ToArray());
		int R = nums[0];
		int C = nums[1];
		int W = nums[2];
		int numOfGuess = guessPerRow(C, W) * R;
		numOfGuess += additionalGuesses(C, W);
		
		return numOfGuess.ToString();
		


	}

        static void Main(string[] args)
        {
		//preCompute();
		//using (StreamReader reader = new StreamReader("A-large.in"))
		//using (StreamReader reader = new StreamReader("C-small-practice.in"))
		using (StreamReader reader = new StreamReader("A-small-attempt0.in"))
		//using (StreamReader reader = new StreamReader("sample.in"))
		{
			using (StreamWriter writer = new StreamWriter("output.txt"))
			{
				string line = reader.ReadLine();
				int total = int.Parse(line);
				StringBuilder results = new StringBuilder();
				

				for (int i = 1; i <= total; ++i)
				{
					string tempResult = "Case #" + i.ToString() + ": " + solveProblem(reader.ReadLine());
	//				Console.WriteLine(tempResult);
					results.AppendLine(tempResult);
					
				}
				writer.WriteLine(results.ToString());

			}
		}
	}
    }
}
