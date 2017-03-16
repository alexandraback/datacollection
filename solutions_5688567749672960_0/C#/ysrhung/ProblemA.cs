using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Round1B
{


	class Round1B
	{
	
	const long target = 1000001;
	//const long target = 100000000000001;
	static long[] numbers = new long[target]; 
	
	static long getReverse(long input)
	{
		long answer = input % 10;
		input /= 10;
		while (input > 0)
		{
			answer *= 10;
			answer += input % 10;
			input /= 10;
		}
		return answer;
	}
	
	static void preCompute()
	{
		numbers[0] = 0;
		numbers[1] = 1;
		for (long i = 2; i < target; ++i)
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

	static void log(string log)
	{
		using (StreamWriter writer = new StreamWriter("log.txt"))
		{
			writer.WriteLine(log);
		}
	}
	
	static string solveProblem(string line)
	{
		//List<int> nums = new List<int>(line.Split().Select(token => int.Parse(token)).ToArray());
		long N = long.Parse(line);
		return numbers[N].ToString();
		


	}

        static void Main(string[] args)
        {
		using (StreamReader reader = new StreamReader("A-small-attempt1.in"))
		//using (StreamReader reader = new StreamReader("C-small-practice.in"))
		//using (StreamReader reader = new StreamReader("C-large-practice.in"))
		//using (StreamReader reader = new StreamReader("sample.in"))
		{
			using (StreamWriter writer = new StreamWriter("output.txt"))
			{
				string line = reader.ReadLine();
				int total = int.Parse(line);
				StringBuilder results = new StringBuilder();
				preCompute();

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
