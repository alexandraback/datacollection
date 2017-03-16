using System.Globalization;
using System.IO;
using System.Linq;

namespace Impl.Round1A
{
	public class ProblemB : ProblemBase
	{
		private const int Maxn = 2000;
		private readonly decimal[][] p = new decimal[Maxn][];
		private readonly decimal[][] q = new decimal[Maxn][];

		public ProblemB()
		{
			p[0] = new decimal[] { 1 };
			for (int i = 1; i < Maxn; i++)
			{
				p[i] = new decimal[i + 1];
				p[i][0] = p[i - 1][0]/2;
				for (int k = 1; k < i; k++)
					p[i][k] = (p[i - 1][k - 1] + p[i - 1][k])/2;
				p[i][i] = p[i - 1][i - 1]/2;
			}

			q[0] = new decimal[] { 1 };
			for (int i = 1; i < Maxn; i++)
			{
				q[i] = new decimal[i + 1];
				q[i][i] = p[i][i];
				for (int k = i - 1; k >= 0; k--)
					q[i][k] = q[i][k + 1] + p[i][k];
			}
		}

		protected override bool SolveOne(TextReader input, TextWriter output, int testNumber)
		{
			var a = ReadIntsLine(input);
			int n = a[0], x = a[1], y = a[2];
			int i = 1;
			while (i*(i + 1)/2 <= n)
				i += 2;
			i -= 2;
			if (x < 0)
				x = -x;
			decimal res;
			if (x + y < i + 1)
				res = 1;
			else if (x + y > i + 1)
				res = 0;
			else if (x == 0)
				res = 0;
			else if (n - i*(i + 1)/2 < y + 1)
				res = 0;
			else
				res = q[n - i*(i + 1)/2][y + 1];
			return Write(output, testNumber, string.Format(CultureInfo.InvariantCulture, "{0:0.0#########}", res));
		}

		private static int[] ReadIntsLine(TextReader input)
		{
			var readLine = input.ReadLine();
			return readLine.Split(' ').Select(int.Parse).ToArray();
		}
	}
}