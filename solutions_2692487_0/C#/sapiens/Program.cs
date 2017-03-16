using System;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam2013Round_1B
{
	class Program
	{
		static void Main(string[] args)
		{
			(new Problem_A_Osmos()).SolveTest("A-small-attempt1.in");
		}
	}

	internal class Problem_A_Osmos
	{
		private byte nCount;

		public void SolveTest(string inFileName)
		{
			var input = File.ReadAllText(inFileName);
			var sr = new StringReader(input);
			var caseCount = int.Parse(sr.ReadLine());
			var res = new StringBuilder();
			for (int i = 1; i <= caseCount; i++)
			{
				var t = sr.ReadLine().Split(' ').Select(ulong.Parse).ToArray();
				var a = t[0];
				nCount = (byte)t[1];
				var ni = sr.ReadLine().Split(' ').Select(ulong.Parse).ToArray();
				Array.Sort(ni);
				res.AppendFormat("Case #{0}: {1}\n", i, SolveCase(a, ni));
			}
			var outFileName = inFileName.Split('.')[0] + ".out";
			File.WriteAllText(outFileName, res.ToString());
		}

		private int SolveCase(ulong a, ulong[] ni)
		{
			byte operations = 0;
			var nLeft = (byte)(ni.Count() + 1);
			foreach (var k in ni)
			{
				nLeft--;
				operations += GetOperationsCount(ref a, k, nLeft);
				if (operations >= nCount)
					return nCount;
			}
			return operations;
		}

		private byte GetOperationsCount(ref ulong a, ulong k, byte nLeft)
		{
			byte operations = 0;
			while (a <= k && operations < nLeft)
			{
				a += a - 1;
				operations++;
			}
			a += k;
			return operations;
		}
	}
}
