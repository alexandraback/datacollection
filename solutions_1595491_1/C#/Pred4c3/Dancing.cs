using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

namespace Qualification
{
	class Dancing
	{
		static void Main(string[] args)
		{
			var fileContent = File.ReadAllLines(@"C:\Z\Projects\CodeJam2012\Qualification\bin\Debug\B-large.in");
			var numTests = int.Parse(fileContent[0]);

			for (int i = 0; i < numTests; i++)
			{
				var data = fileContent[i + 1].Split(" ".ToCharArray()).Select(n => int.Parse(n)).ToArray();

				Console.WriteLine(Solve(i + 1, data[0], data[1], data[2], data.Skip(3).ToList()));
			}
			//Console.ReadKey();
		}

		private static string Solve(int testNum, int numDance, int surprise, int bestResult, List<int> totals)
		{
			Debug.Assert(numDance == totals.Count);
			int result = 0;
			int remainS = surprise;
			int normTotal = 3 * bestResult - 2;
			int surpTotal = 3 * bestResult - 4;
			foreach (var total in totals)
			{
				if (total >= normTotal)
				{
					result++;
				}
				else if (total >= bestResult && total >= surpTotal && --remainS >= 0)
				{
					result++;
				}
			}

			return "Case #" + testNum + ": " + result;
		}
	}
}
