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

		public static void Solve(TextReader input, TextWriter output)
		{
			int t = Convert.ToInt32(input.ReadLine());

			for (int z = 1; z <= t; z++)
			{
				string[] data = input.ReadLine().Split(' ');
				long r = Convert.ToInt64(data[0]);
				long p = Convert.ToInt64(data[1]);

				long a1 = 2 * r + 1;
				long left = 1;
				long right = p;

				while (left < right)
				{
					long middle = left / 2 + right / 2 + (left % 2 + right % 2 + 1) / 2;

					if (p / middle < a1 + 2 * middle - 2)
					{
						right = middle - 1;
					}
					else
					{
						left = middle;
					}
				}

				output.WriteLine("Case #{0}: {1}", z, left);
			}
		}
    }
}