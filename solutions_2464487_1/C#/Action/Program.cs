using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;

namespace ProblemA
{
	class Program
	{
		static void Main(string[] args)
		{
			using (var inFile = new FileStream("A.in", FileMode.Open, FileAccess.Read))
			{
				using (var reader = new StreamReader(inFile))
				{
					using (var outFile = new FileStream("A.out", FileMode.Create, FileAccess.Write))
					{
						using (var writer = new StreamWriter(outFile))
						{
							var line = reader.ReadLine();
							var testCount = int.Parse(line);
							for (int testIndex = 1; testIndex <= testCount; testIndex++)
							{
								line = reader.ReadLine();
								var parts = line.Split(' ');
								var r = BigInteger.Parse(parts[0]);
								var t = BigInteger.Parse(parts[1]);
								var n = FindAnswer(r, t);
								writer.WriteLine("Case #{0}: {1}", testIndex, n);
							}
						}
					}
				}
			}
		}

		//Avoid floating point calculations!!!
		private static BigInteger FindAnswer(BigInteger r, BigInteger t)
		{
			BigInteger low = 0;
			BigInteger hi = t;
			while (low < hi - 1)
			{
				var med = (low + hi) / 2;
				var ink = 2 * med * r + 2 * med * med - med;
				if (ink == t) return med;
				if (ink < t)
				{
					low = med;
				}
				else
				{
					hi = med;
				}
			}
			if (low == hi) return low;
			var m = hi;
			var i = 2 * m * r + 2 * m * m - m;
			if (i <= t) return hi;
			return low;
		}
	}
}
