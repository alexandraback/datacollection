using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Numerics;

namespace Qualification2016
{
	class Program
	{
		static int ReadIntLine()
		{
			string line = Console.ReadLine();
			return int.Parse(line);
		}

		static int[] ReadIntsLine()
		{
			string line = Console.ReadLine();
			return line.Trim().Split(' ').Select(x => int.Parse(x)).ToArray();
		}

		static long FindDivisor(BigInteger n)
		{
			for(long i = 3; i * i < n && i < 100000; i += 2)
			{
				if (n % i == 0)
					return i;
			}

			return 0;
		}

		static void Main()
		{
			int T = ReadIntLine();

			for(int t = 1; t <= T; t++) { 
				Console.WriteLine("Case #" + t + ":");
				int[] NJ = ReadIntsLine();
				int N = NJ[0];
				int J = NJ[1];

				int mMax = 1 << (N - 2);
				bool[] coin = new bool[N];
				coin[0] = true;
				coin[N - 1] = true;
				int numFound = 0;
				for (int m = 0; m < mMax && numFound < J; m++)
				{
					int x = m;
					for(int i = 1; i < N - 1; i++)
					{
						coin[N - 1 - i] = ((x & 1) != 0);
						x >>= 1;
					}

					long[] divisors = new long[9];
					bool ok = true;
					for(int b = 2; b <= 10; b++)
					{
						BigInteger n = 0;
						foreach(bool d in coin)
						{
							n = n * b + (d ? 1 : 0);
						}
						long div = FindDivisor(n);
						if (div == 0)
						{
							ok = false;
							break;
						}
						else
							divisors[b - 2] = div;
					}
					if (ok) { 
						Console.Write(new String(coin.Select(d => d ? '1' : '0').ToArray()));
						foreach(var div in divisors)
						{
							Console.Write(" " + div);
						}
						Console.WriteLine();

						numFound++;
               }
				}
			}
		}
	}
}
