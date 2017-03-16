using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _1AB
{
	class Program
	{
		class Reqs
		{
			public int L1, L2, AcquiredStars;
		}

		static void Main(string[] args)
		{
			var line = Console.ReadLine();
			var testCount = int.Parse(line);
			for (var testNumber = 1; testNumber <= testCount; testNumber++)
			{
				var N = int.Parse(Console.ReadLine());
				var reqs = new Reqs[N];
				for (var i = 0; i < N; i++)
				{
					var parameters = Console.ReadLine().Split();
					reqs[i] = new Reqs { L1 = int.Parse(parameters[0]), L2 = int.Parse(parameters[1]) };
				}
				var l2 = reqs.OrderBy(i => i.L2).ToList();
				var l1 = reqs.OrderBy(i => i.L1).ToList();

				var stars = 0;
				var result = 0;
				while (l2.Count > 0)
				{
					if (stars >= l2[0].L2)
					{
						stars += 2 - l2[0].AcquiredStars;
						result++;
						l2.RemoveAt(0);
						continue;
					}
					Reqs best = null;
					var bestIndex = 0;
					for (var i = 0; i < l1.Count && l1[i].L1 <= stars; i++)
						if (best == null || best.L2 < l1[i].L2)
						{
							best = l1[i];
							bestIndex = i;
						}
					if (best == null)
						break;
					stars++;
					best.AcquiredStars++;
					result++;
					l1.RemoveAt(bestIndex);
				}
				Console.WriteLine("Case #{0}: {1}", testNumber, (stars * 2 < N) ? "Too Bad" : result.ToString());
			}
		}
	}
}
