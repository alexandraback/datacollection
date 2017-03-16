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

		public static void Solve(TextReader input, TextWriter output)
		{
			int t = Convert.ToInt32(input.ReadLine());

			for (int z = 1; z <= t; z++)
			{
				string[] data = input.ReadLine().Split(' ');
				double c = Convert.ToDouble(data[0], CultureInfo.InvariantCulture);
				double f = Convert.ToDouble(data[1], CultureInfo.InvariantCulture);
				double x = Convert.ToDouble(data[2], CultureInfo.InvariantCulture);

				double r = x / 2d;
				double w = 0d;
				double ff = 2d;
				double p = r + 1;

				while (r < p)
				{
					p = r;
					w += c / ff;
					ff += f;
					r = w + x / ff;
				}

				output.WriteLine("Case #{0}: {1}", z, p.ToString("F7", CultureInfo.InvariantCulture));
			}
		}
	}
}