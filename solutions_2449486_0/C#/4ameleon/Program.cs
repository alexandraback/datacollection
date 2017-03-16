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
				int n = Convert.ToInt32(data[0]);
				int m = Convert.ToInt32(data[1]);
				byte[,] a = new byte[n, m];
				bool[] r = new bool[n];
				bool[] c = new bool[m];

				for (int i = 0; i < n; i++)
				{
					data = input.ReadLine().Split(' ');

					for (int j = 0; j < m; j++)
						a[i, j] = Convert.ToByte(data[j]);
				}

				int count = n + m;
				int previous = -1;

				while (count != previous)
				{
					previous = count;

					// try horizontal cuts
					for (int i = 0; i < n; i++)
					{
						if (!r[i])
						{
							byte h = 255;
							byte max = 0;
							r[i] = true;

							for (int j = 0; j < m; j++)
							{
								if (c[j])
								{
									// find max height for possible vertical cuts
									if (a[i, j] > max) max = a[i, j];
								}
								else
								{
									// check that height is the same in row if no vertical cut yet
									if (h == 255) h = a[i, j];
									r[i] = r[i] && (a[i, j] == h);
								}
							}

							r[i] = r[i] && (max <= h);

							if (r[i]) count--;
						}
					}

					// try vertical cuts
					for (int j = 0; j < m; j++)
					{
						if (!c[j])
						{
							byte h = 255;
							byte max = 0;
							c[j] = true;

							for (int i = 0; i < n; i++)
							{
								if (r[i])
								{
									// find max height for possible horizontal cuts
									if (a[i, j] > max) max = a[i, j];
								}
								else
								{
									// check that height is the same in column if no horizontal cut yet
									if (h == 255) h = a[i, j];
									c[j] = c[j] && (a[i, j] == h);
								}
							}

							c[j] = c[j] && (max <= h);

							if (c[j]) count--;
						}
					}
				}

				output.WriteLine("Case #{0}: {1}", z, count > 0 ? "NO" : "YES");
			}
		}
    }
}