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
				int n = Convert.ToInt32(input.ReadLine());
				string[] data1 = input.ReadLine().Split(' ');
				string[] data2 = input.ReadLine().Split(' ');

				var a = new List<double>();
				var b = new List<double>();

				for (int i = 0; i < n; i++)
				{
					a.Add(Convert.ToDouble(data1[i], CultureInfo.InvariantCulture));
					b.Add(Convert.ToDouble(data2[i], CultureInfo.InvariantCulture));
				}

				a.Sort();
				b.Sort();
				int k = 0;
				int m = 0;
				int p = 0;

				for (int i = 0; i < n; i++)
				{
					if (a[i] > b[m])
						m++;

					while ((p < n) && (a[i] > b[p]))
						p++;

					if (p < n)
					{
						k++;
						p++;
					}
				}

				output.WriteLine("Case #{0}: {1} {2}", z, m, n - k);
			}
		}
	}
}