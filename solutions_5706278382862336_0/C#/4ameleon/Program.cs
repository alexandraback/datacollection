using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;

namespace Test
{
	public class Program
	{
		private static void Main()
		{
			Solve(Console.In, Console.Out);
		}

		private static long FindNod(long a, long b)
		{
			while (b > 0)
			{
				long c = a % b;
				a = b;
				b = c;
			}

			return a;
		}

		public static void Solve(TextReader input, TextWriter output)
		{
			int t = Convert.ToInt32(input.ReadLine());

			for (int z = 1; z <= t; z++)
			{
				string[] data = input.ReadLine().Split('/');
				long p = Int64.Parse(data[0]);
				long q = Int64.Parse(data[1]);
				long nod = FindNod(q, p);

				p /= nod;
				q /= nod;

				int g = -1;
				int k = -1;
				long e = 1;

				for (int i = 0; i < 80; i++)
				{
					if (e == q) g = i;
					e <<= 1;

					if (p == 1) k = i;
					p >>= 1;
				}

				if (g > 0)
				{
					output.WriteLine("Case #{0}: {1}", z, g - k);
				}
				else
				{
					output.WriteLine("Case #{0}: impossible", z);
				}
			}
		}
	}
}