using System;
using System.ComponentModel.Design;
using System.IO;
using System.Linq;

namespace GCJ.Impl._2016_Qual
{
	public class ProblemC : ProblemBase
	{
		protected override bool SolveOne(StreamReader reader, StreamWriter writer, int testNumber)
		{
			int n, j;
			ReadInts(reader, out n, out j);
			WriteHeader(writer, testNumber);
			for (int i = 0; i < j; i++)
			{
				long a = 1;
				a <<= n;
				a -= 1;
				a -= i << 1;
				a -= i << (n/2);
				Check(Convert.ToString(a, 2));
				writer.Write(Convert.ToString(a, 2));
				for (int k = 3; k < 12; k++)
					writer.Write($" {k}");
				writer.WriteLine();
			}
			return true;
		}

		private void Check(string s)
		{
			for (int i = 2; i < 11; i++)
			{
				long a = 0;
				foreach (var c in s)
				{
					a *= i;
					a += Convert.ToInt32(c);
					a %= i + 1;
				}
				if (a != 0)
					throw new Exception($"{s}({a}) % {i + 1} == {a%(i + 1)}");
			}
		}
	}
}