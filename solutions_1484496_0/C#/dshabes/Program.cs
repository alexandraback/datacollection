using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _1BC
{
	class Program
	{
		static void Main(string[] args)
		{
			var line = Console.ReadLine();
			var testCount = int.Parse(line);
			for (var testNumber = 1; testNumber <= testCount; testNumber++)
			{
				var elements = Console.ReadLine().Split();
				var N = int.Parse(elements[0]);
				var numbers = new int[N];
				for (var i = 0; i < N; i++)
					numbers[i] = int.Parse(elements[i + 1]);

				var subsetCount = 1;
				for (var i = 0; i < N; i++)
					subsetCount *= 2;
				var sums = new int[subsetCount];
				for (var i = 1; i < subsetCount; i++)
				{
					var sum = 0;
					for (int mask = 1, j = 0; j < N; mask *= 2, j++)
						if ((i & mask) != 0)
							sum += numbers[j];
					sums[i] = sum;
				}

				var sorted = sums.Select((s, i) => new { Index = i, Sum = s }).OrderBy(e => e.Sum).ToList();
				var found = false;
				var result = new int[2];
				for (var i = 1; i < subsetCount; i++)
					if (sorted[i].Sum == sorted[i - 1].Sum)
					{
						found = true;
						result[0] = sorted[i - 1].Index;
						result[1] = sorted[i].Index;
						break;
					}
				Console.WriteLine("Case #{0}:", testNumber);
				if (found)
					foreach (var i in result)
					{
						var setMembers = new List<int>();
						for (int mask = 1, j = 0; j < N; mask *= 2, j++)
							if ((i & mask) != 0)
								setMembers.Add(numbers[j]);
						Console.WriteLine(string.Join(" ", setMembers));
					}
				else
					Console.WriteLine("Impossible");
			}
		}
	}
}
