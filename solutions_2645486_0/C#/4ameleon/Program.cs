using System;
using System.Collections.Generic;
using System.IO;

namespace Test
{
    public class Program
    {
		private static void Main()
		{
			Solve(Console.In, Console.Out);
		}

		public static int FindMax(int e, int r, int[] v, int c, int step)
		{
			if (step == v.Length - 1)
				return c * v[step];

			int max = 0;

			for (int i = 0; i <= c; i++)
			{
				int value = FindMax(e, r, v, Math.Min(c - i + r, e), step + 1) + v[step] * i;

				if (value > max)
					max = value;
			}

			return max;
		}

		public static void Solve(TextReader input, TextWriter output)
		{
			int t = Convert.ToInt32(input.ReadLine());

			for (int z = 1; z <= t; z++)
			{
				string[] data = input.ReadLine().Split(' ');
				long e = Convert.ToInt64(data[0]);
				long r = Convert.ToInt64(data[1]);
				int n = Convert.ToInt32(data[2]);
				int[] v = new int[n];

				data = input.ReadLine().Split(' ');

				for (int i = 0; i < n; i++)
					v[i] = Convert.ToInt32(data[i]);

				long maxE = 0;

				if (r >= e)
				{
					for (int i = 0; i < n; i++)
						maxE += v[i] * e;
				}
				else
				{
					/*long maxR = 0;

					for (int i = n - 1; i >= 0; i--)
					{
						maxE = Math.Max(v[i] * e + maxR, v[i] * r + maxE);
						maxR += v[i] * r;
					}*/
					maxE = FindMax((int)e, (int)r, v, (int)e, 0);
				}

				output.WriteLine("Case #{0}: {1}", z, maxE);
			}
		}
    }
}