using System.IO;
using System.Linq;

// ReSharper disable AssignNullToNotNullAttribute
// ReSharper disable PossibleNullReferenceException

namespace ConsoleApplication2
{
	class D
	{
		public void Solve()
		{
			using (var sr = new StreamReader("D.in"))
			using (var sw = new StreamWriter("D.out"))
			{
				var t = int.Parse(sr.ReadLine());
				for (var testCase = 1; testCase <= t; ++testCase)
				{
					var input = sr.ReadLine().Split(' ').Select(long.Parse).ToList();
					sw.Write("Case #{0}:", testCase);
					Solve(sw, input[0], input[1], input[2]);
					sw.WriteLine();
				}
			}
		}

		private void Solve(StreamWriter sw, long k, long c, long s)
		{
			var necessaryCheck = k/c + (k%c == 0 ? 0 : 1);
			if (necessaryCheck > s)
			{
				sw.Write(" IMPOSSIBLE");
				return;
			}
			for (long p = 0; p < k; p += c)
				sw.Write(" {0}", GeneratePosition(k, c, p) + 1);
		}

		private long GeneratePosition(long k, long c, long p)
		{
			if (c == 1)
				return p%k;
			return (p%k)*BinPow(k, c - 1) + GeneratePosition(k, c - 1, p + 1);
		}

		private long BinPow(long value, long pow)
		{
			if (pow == 0)
				return 1;
			var temp = BinPow(value, pow/2);
			var res = temp*temp;
			if (pow%2 == 1)
				res = res*value;
			return res;
		}
	}
}
