using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _1AA
{
	class Program
	{
		static void Main(string[] args)
		{
			var line = Console.ReadLine();
			var testCount = int.Parse(line);
			for (var testNumber = 1; testNumber <= testCount; testNumber++)
			{
				var parameters = Console.ReadLine().Split();
				var A = int.Parse(parameters[0]);
				var B = int.Parse(parameters[1]);
				var ps = Console.ReadLine().Split().Select(double.Parse).ToArray();
				var rightSoFar = new double[A];
				rightSoFar[0] = ps[0];
				for (var i = 1; i < A; i++)
					rightSoFar[i] = rightSoFar[i - 1] * ps[i];
				double result = B + 2;
				for (var bspCount = 0; bspCount < A; bspCount++)
				{
					var ifRightCount = bspCount * 2 + (B - A) + 1;
					if (ifRightCount >= result)
						break;
					var ifWrongCount = ifRightCount + B + 1;
					var p = rightSoFar[A - bspCount - 1] * ifRightCount + (1d - rightSoFar[A - bspCount - 1]) * ifWrongCount;
					if (p < result)
						result = p;
				}
				Console.WriteLine("Case #{0}: {1:F6}", testNumber, result);
			}
		}
	}
}
