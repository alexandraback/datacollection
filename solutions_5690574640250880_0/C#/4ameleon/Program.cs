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
				int r = Convert.ToInt32(data[0]);
				int c = Convert.ToInt32(data[1]);
				int m = Convert.ToInt32(data[2]);
				int e = r * c - m;

				int[] w = new int[r + 1];
				bool possible = true;

				if ((r == 1) || (e == 1))
				{
					w[1] = e;
				}
				else if (c == 1)
				{
					for (int i = 1; i <= e; i++)
						w[i] = 1;
				}
				else if ((e < 4) || (e == 5) || (e == 7))
				{
					possible = false;
				}
				else if (r == 2)
				{
					possible = e % 2 == 0;

					if (possible)
						w[1] = w[2] = e / 2;
				}
				else if (c == 2)
				{
					possible = e % 2 == 0;

					if (possible)
					{
						for (int i = 1; i <= e / 2; i++)
							w[i] = 2;
					}
				}
				else
				{
					if (e <= c * 2 + 1)
					{
						if (e % 2 == 1)
						{
							w[1] = w[2] = e / 2 - 1;
							w[3] = 3;
						}
						else
						{
							w[1] = w[2] = e / 2;
						}
					}
					else
					{
						int k = e / c;

						for (int i = 1; i <= k; i++)
							w[i] = c;

						if (e % c > 0)
						{
							if (e % c > 1)
							{
								w[k + 1] = e % c;
							}
							else
							{
								w[k + 1] = 2;
								w[k]--;
							}
						}
					}
				}

				output.WriteLine("Case #{0}:", z);

				if (possible)
				{
					for (int i = 1; i <= r; i++)
					{
						for (int j = 1; j <= w[i]; j++)
							output.Write((i == 1) && (j == 1) ? 'c' : '.');

						for (int j = w[i] + 1; j <= c; j++)
							output.Write('*');

						output.WriteLine();
					}
				}
				else
				{
					output.WriteLine("Impossible");
				}
			}
		}
	}
}