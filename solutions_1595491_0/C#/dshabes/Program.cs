using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _2012Q2
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
				var dancerCount = int.Parse(elements[0]);
				var surpriseCount = int.Parse(elements[1]);
				var goal = int.Parse(elements[2]);
				var result = 0;
				var usedSurprises = 0;
				for (var i = 0; i < dancerCount; i++)
				{
					var total = int.Parse(elements[3+i]);
					switch (total)
					{
						case 0:
							if (goal == 0)
								result++;
							break;
						case 1:
							if (goal <= 1)
								result++;
							break;
						case 29:
						case 30:
							result++;
							break;
						default:
							if (((total - 1) / 3) + 1 >= goal)
								result++;
							else if (((total + 1) / 3) + 1 >= goal && usedSurprises < surpriseCount)
							{
								result++;
								usedSurprises++;
							}
							break;
					}
				}
				Console.WriteLine("Case #{0}: {1}", testNumber, result);
			}
		}
	}
}
