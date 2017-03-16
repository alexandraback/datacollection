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
					writer.WriteLine("Case #{0}: {1}", i, string.Join(" ", result));
				}
			}
		}

		private static IReadOnlyList<long> Solve(int K, int C, int S)
		{
			if (S == K) // small set
			{
				var step = (long)BigInteger.Pow(K, C - 1);
				return Enumerable.Range(0, S).Select(_ => _ * step + 1).ToList();
			}
			var result = new List<long>();
			throw new NotImplementedException();
		}
	}
}
