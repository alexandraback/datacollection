using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Round1CB
{
	class Program
	{
		public static int[] ReadInts(string line)
		{
			string[] strNumbers = line.Split(new char[] { ' ' });
			int[] numbers = new int[strNumbers.Length];

			for (int i = 0; i < strNumbers.Length; i++)
			{
				numbers[i] = int.Parse(strNumbers[i]);
			}

			return numbers;
		}

		public static long[] ReadLongs(string line)
		{
			string[] strNumbers = line.Split(new char[] { ' ' });
			long[] numbers = new long[strNumbers.Length];

			for (int i = 0; i < strNumbers.Length; i++)
			{
				numbers[i] = long.Parse(strNumbers[i]);
			}

			return numbers;
		}

		public static string[] ReadStrings(string line)
		{
			return line.Split(new char[] { ' ' });
		}

		static void Main(string[] args)
		{
			int tcCount = int.Parse(Console.ReadLine());
			for (int tcIndex = 1; tcIndex <= tcCount; tcIndex++)
			{
				int[] xy = ReadInts(Console.ReadLine());
				int x = xy[0];
				int y = xy[1];

				char xpd = 'E';
				char xnd = 'W';

				if (x < 0)
				{
					xpd = 'W';
					xnd = 'E';
					x = -x;
				}

				char ypd = 'N';
				char ynd = 'S';

				if (y < 0)
				{
					ypd = 'S';
					ynd = 'N';
					y = -y;
				}

				StringBuilder sb = new StringBuilder();
				int step = 1;

				step = Go(sb, x, step, xpd, xnd);
				step = Go(sb, y, step, ypd, ynd);

				// Output
				Console.WriteLine("Case #{0}: {1}", tcIndex, sb.ToString());
			}
		}

		static int Go(StringBuilder sb, int dest, int step, char pd, char nd)
		{
			int t = 0;

			while (t != dest)
			{
				if (dest >= t + step)
				{
					sb.Append(pd);
					t += step;
				}
				else
				{
					sb.Append(nd);
					t -= step;
				}
				step++;
			}

			return step;
		}
	}
}
