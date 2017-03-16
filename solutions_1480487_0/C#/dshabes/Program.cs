using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;

namespace _1BA
{
	class Program
	{
		class Contestant
		{
			public int Order;
			public int JudgePoints;
			public double Answer;
		}

		static void Main(string[] args)
		{
			var line = Console.ReadLine();
			var testCount = int.Parse(line);
			for (var testNumber = 1; testNumber <= testCount; testNumber++)
			{
				var elements = Console.ReadLine().Split();
				var N = int.Parse(elements[0]);
				var contestants = new List<Contestant>(N);
				var sum = 0;
				for (var i = 0; i < N; i++)
				{
					var c = new Contestant {Order = i, JudgePoints = int.Parse(elements[i + 1])};
					contestants.Add(c);
					sum += c.JudgePoints;
				}
				var sorted = contestants.OrderBy(c => c.JudgePoints).ToList();
				var previousSum = 0;
				for (var i = 0; i < N; previousSum += sorted[i++].JudgePoints)
				{
					var chaseTotal = sorted[i].JudgePoints * i - previousSum;
					var chaserCount = i + 1;
					while (chaserCount < N)
					{
						var newTotal = chaseTotal + chaserCount * (sorted[chaserCount].JudgePoints - sorted[chaserCount - 1].JudgePoints);
						if (newTotal > sum)
							break;
						chaseTotal = newTotal;
						chaserCount++;
					}
					var delta = (sum - chaseTotal) / (double)chaserCount + sorted[chaserCount - 1].JudgePoints - sorted[i].JudgePoints;
					contestants[sorted[i].Order].Answer = delta > 0 ? delta / sum * 100d : 0d;
				}

				Console.WriteLine("Case #{0}: {1}", testNumber, string.Join(" ", contestants.Select(c => c.Answer.ToString(CultureInfo.InvariantCulture))));
			}
		}
	}
}
