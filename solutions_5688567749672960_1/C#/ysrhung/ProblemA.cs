using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Round1B
{


	class Round1B
	{
	
	
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

	
	
	static long compute(long input)
	{
		if (input < 100)
			return numbers[input];
		long count = 0;
		while (input >= 100) 
		{
//			Console.WriteLine(input + " " + count);
			int digits = numOfDigits(input);
			long half = powerOf(digits / 2);
			if (digits % 2 == 1) half *= 10;
//			Console.WriteLine("digits: " + digits + " half = " + half);
			if (input % half > 0)
			{
				count += (input % half - 1);
				input = input - (input % half - 1);
//				Console.WriteLine(input + " " + count);
				long reverse = getReverse(input);
				if (reverse < input)
				{
					count++;
					input = reverse;
				}
				if (input < 100)
					return count + numbers[input];
				long temp = powerOf(digits - 1) - 1;
				count += (input - temp);
				input = temp;
			}
			else
			{
				count++;
				input--;
			}
//			Console.WriteLine(input + " " + count);
		}		
		return numbers[input] + count;
	}
	
	static string solveProblem(string line)
	{
		//List<int> nums = new List<int>(line.Split().Select(token => int.Parse(token)).ToArray());
		long N = long.Parse(line);
		return compute(N).ToString();
		


	}

        static void Main(string[] args)
        {
		preCompute();
		using (StreamReader reader = new StreamReader("A-large.in"))
		//using (StreamReader reader = new StreamReader("C-small-practice.in"))
		//using (StreamReader reader = new StreamReader("C-large-practice.in"))
		//using (StreamReader reader = new StreamReader("sample2.in"))
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
