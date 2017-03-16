using System;
using System.IO;
using System.Linq;

namespace Impl.Round1A
{
	public class ProblemA : ProblemBase
	{
		protected override bool SolveOne(TextReader input, TextWriter output, int testNumber)
		{
			var a = ReadIntsLine(input);
			int c = a[0], n = a[1];
			a = ReadIntsLine(input);
			Array.Sort(a);
			int b = 0, res = n;
			if (c == 1)
			{
				return Write(output, testNumber, String.Format("{0}", res));
			}
			for (int i = 0; i < n; i++)
			{
				while (c <= a[i])
				{
					c += c - 1;
					++b;
				}
				c += a[i];
				if (res == -1 || res > n - 1 - i + b)
					res = n - 1 - i + b;
			}
			return Write(output, testNumber, String.Format("{0}", res));
		}

		private static int[] ReadIntsLine(TextReader input)
		{
			var readLine = input.ReadLine();
			return readLine.Split(' ').Select(int.Parse).ToArray();
		}
	}
}