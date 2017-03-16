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
				int a = Convert.ToInt32(data[0]);
				int n = Convert.ToInt32(data[1]);
				int[] m = new int[n];

				data = input.ReadLine().Split(' ');

				for (int i = 0; i < n; i++)
					m[i] = Convert.ToInt32(data[i]);

				Array.Sort<int>(m);
				int pos = 0;

				while ((pos < n) && (a > m[pos]))
				{
					a += m[pos];
					pos++;
				}

				int count = 0;
				int min = n - pos;

				while ((pos < n) && (count < min))
				{
					count++;
					a = a * 2 - 1;

					while ((pos < n) && (a > m[pos]))
					{
						a += m[pos];
						pos++;
					}

					if (n - pos + count < min)
						min = n - pos + count;
				}

				output.WriteLine("Case #{0}: {1}", z, min);
			}
		}
	}
}