using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Qualification2016
{
	class Program
	{
		static int ReadIntLine()
		{
			string line = Console.ReadLine();
			return int.Parse(line);
		}

		static long SolveA(int N)
		{
			long n = N;
			int seen = 1023;
			for (int m = 1; m < int.MaxValue; m++)
			{

				foreach (char c in n.ToString().ToCharArray())
				{
					int i = (c - '0');
					if(i >= 0 && i < 10) { 
						seen &= (~(1 << i));
					}
				}

				if(seen == 0)
				{
					return n;
				}

				n += N;
			}

			return 0;
		}

		static void ProblemA()
		{
			int T = ReadIntLine();
			for (int t = 1; t <= T; t++)
			{
				int N = ReadIntLine();

				string result = "INSOMNIA";
				if (N != 0)
				{
					result = SolveA(N).ToString();
				}

				Console.WriteLine("CASE #" + t + ": " + result);
         }
		}

		static void Main(string[] args)
		{
			ProblemA();			
		}
	}
}
