using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace RAVE
{
	class TestCase
	{
		int A; // 1 ≤ A ≤ 100|10^6.
		int N; // 1 ≤ N ≤ 10|100
		int[] Other; // 1 ≤ all mote sizes ≤ 100|10^6.

		public TestCase(TextReader input)
		{
			var x = input.ReadInts(); A = x[0]; N = x[1];
			Other = input.ReadInts();
		}

		public int GetResult()
		{
			return Solve(A, Other.OrderBy(x => x).ToArray(), 0);
		}

		static int Solve(int a, int[] other, int i)
		{
			while (i != other.Length && a > other[i])
				a += other[i++];

			if (i == other.Length)
				return 0;
			if (a == 1)
				return other.Length - i;

			int addOne = 1 + Solve(a + a - 1, other, i);
			int deleteAll = other.Length - i;
			return Math.Min(addOne, deleteAll);
		}
	}
}