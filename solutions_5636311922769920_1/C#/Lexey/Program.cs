using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using NUnit.Framework;

namespace task4
{
	[TestFixture]
	public class Program
	{
		static void Main(string[] args)
		{
			using (var reader = new StreamReader(args[0], Encoding.ASCII))
			using (var writer = new StreamWriter(args[0] + ".out", false, Encoding.ASCII))
			{
				var cases = int.Parse(reader.ReadLine());
				Console.WriteLine("Cases {0}", cases);
				for (var i = 1; i <= cases; ++i)
				{
					var parameters = reader.ReadLine().Split(new[] { ' ' });
					var K = int.Parse(parameters[0]);
					var C = int.Parse(parameters[1]);
					var S = int.Parse(parameters[2]);
					var result = Solve(K, C, S);
					writer.WriteLine("Case #{0}: {1}", i
						, result.Count > 0 ? string.Join(" ", result) : "IMPOSSIBLE");
				}
			}
		}

		private static IReadOnlyList<long> Solve(int K, int C, int S)
		{
			var result = new List<long>();
			if (C * S < K)
			{
				return result; // no solution
			}
			// distribute K indices in the original string among <= S indices in the final string
			// original indices are coefficients in the K-based representation of the final string index
			var currentIndex = 0;
			for (var i = 0; i < S && currentIndex != K; ++i)
			{
				var v = 1L; // 1-based
				var power = 1L;
				for (var j = 0; j < C && currentIndex != K; ++j)
				{
					v += currentIndex * power;
					++currentIndex;
					power *= K;
				}
				result.Add(v);
			}
			return result;
		}

		private static IReadOnlyList<long> SolveSmall(int K, int C, int S)
		{
			if (S != K)
			{
				throw new NotImplementedException();
			}
			var blockLength = (long)BigInteger.Pow(K, C - 1);
			return Enumerable.Range(0, S).Select(_ => _ * blockLength + 1).ToList();
		}
	}
}
