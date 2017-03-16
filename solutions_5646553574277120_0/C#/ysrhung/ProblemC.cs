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
	static bool isValid(long C, List<long> denoms, long target)
	{
		long t = target;
		for (int i = denoms.Count - 1; i >= 0; --i)
		{		
			if (denoms[i] * C > t)
			{
				t = t % denoms[i];
			}
			else
			{
				t = t - denoms[i] * C;
			}
			
		}
//		log(C + " " + target + " " + t);
		return t == 0;
	}

	static string solveProblem(string line1, string line2)
	{
		List<long> nums = new List<long>(line1.Split().Select(token => long.Parse(token)).ToArray());
		long C = nums[0];
		long D = nums[1];
		long V = nums[2];
		long count = 0;
		List<long> denoms = new List<long>(line2.Split().Select(token => long.Parse(token)).ToArray());
//		log("Start " + C + " " + D + " " + V);
		for (long i = 1; i <= V; ++i)
		if (!isValid(C, denoms, i))
		{
			count++;
			denoms.Add(i);
			denoms.Sort();
		}

		
		return count.ToString();
		


	}

        static void Main(string[] args)
        {
		//preCompute();
		//using (StreamReader reader = new StreamReader("A-large (1).in"))
		using (StreamReader reader = new StreamReader("C-small-attempt1.in"))
		//using (StreamReader reader = new StreamReader("A-small-attempt0.in"))
		//using (StreamReader reader = new StreamReader("sample.in"))
		{
			using (StreamWriter writer = new StreamWriter("output.txt"))
			{
				string line = reader.ReadLine();
				int total = int.Parse(line);
				StringBuilder results = new StringBuilder();
				

				for (int i = 1; i <= total; ++i)
				{
					string tempResult = "Case #" + i.ToString() + ": " + solveProblem(reader.ReadLine(), reader.ReadLine());
	//				Console.WriteLine(tempResult);
					results.AppendLine(tempResult);
					
				}
				writer.WriteLine(results.ToString());

			}
		}
	}
    }
}
