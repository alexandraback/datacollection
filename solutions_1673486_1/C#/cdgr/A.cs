using System.IO;
using System.Linq;
using System;

namespace RAVE
{
	class TestCase
	{
		int A;
		int B;
		double[] P;
		double[] PC;

		public TestCase(TextReader input)
		{
			var r = input.ReadInts();
			A = r[0]; B = r[1];
			P = input.ReadDoubles();
		}

		public string GetResult()
		{
			PC = new double[P.Length + 1];
			PC[0] = 1; // chance that first 0 are correct (100%)
			P.ForEach((p, i) => PC[i + 1] = PC[i] * p);

			double e = Enumerable.Range(0, A).Select(i => EBackspace(i)).Concat(new [] { EStartOver() }).Min();
			return e.ToString("F8");
		}

		double EBackspace(int i)
		{
			int correct = i + i + B - A + 1;         // backspace i, type i, type B - A, enter
			int mistake = i + i + B - A + 1 + B + 1; // backspace i, type i, type B - A, enter, type B, enter
			double chanceCorrect = ChanceCorrect(A - i);
			return chanceCorrect * correct + (1 - chanceCorrect) * mistake;
		}

		double ChanceCorrect(int i)
		{
			return PC[i];
			//return P.Take(i).Aggregate(1.0, (r, p) => r * p, r => r);
		}

		double EStartOver()
		{
			return A == B
				? EBackspace(0)
				: 1 + B + 1; // enter, type B, enter 
		}
	}
}