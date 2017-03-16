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
				int n = Int32.Parse(data[0]);
				int m = Int32.Parse(data[1]);
				int k = Int32.Parse(data[2]);
				int min = k;

				for (int ni = 3; ni <= n; ni++)
				{
					for (int mi = 3; mi <= m; mi++)
					{
						int r = (ni - 2) * 2 + (mi - 2) * 2;

						if (ni * mi - 4 < k)
							r += k - (ni * mi - 4);

						if (r < min)
							min = r;
					}
				}

				output.WriteLine("Case #{0}: {1}", z, min);
			}
		}
	}
}