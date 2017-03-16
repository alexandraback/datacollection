using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _2013QualifyC
{
	class Program
	{
		public static long[] ReadNumbers(string line)
		{
			string[] strNumbers = line.Split(new char[] { ' ' });
			long[] numbers = new long[strNumbers.Length];

			for (int i = 0; i < strNumbers.Length; i++)
			{
				numbers[i] = long.Parse(strNumbers[i]);
			}

			return numbers;
		}


		static void Main(string[] args)
		{
			long[] fairSqArray = BuildFairSqArray();

			int tcCount = int.Parse(Console.ReadLine());
			for (int tcIndex = 1; tcIndex <= tcCount; tcIndex++)
			{
				long[] numbers = ReadNumbers(Console.ReadLine());

				long a = numbers[0];
				long b = numbers[1];

				int count = 0;
				for (int i = 0; i<fairSqArray.Length;i++)
				{
					if (fairSqArray[i] >= a && fairSqArray[i] <= b)
						count++;
				}

				// Output
				Console.WriteLine("Case #{0}: {1}", tcIndex, count);
			}
		}

		static long[] BuildFairSqArray()
		{
			List<long> fairSqList = new List<long>();

			for (long n=1;n<10000000;n++)
			{
				if (IsPalindrome(n) && IsPalindrome(n * n))
					fairSqList.Add(n * n);
			}

			return fairSqList.ToArray();
		}

		static bool IsPalindrome(long num)
		{
			long n = num;
			long p = 0;
			while (n > 0)
			{
				long r = n % 10;
				n = n / 10;
				p = p * 10 + r;
			}
			return (num == p);
		}
	}
}
