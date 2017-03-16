using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Qualification
{
	class RecycledNums
	{
		static void Main(string[] args)
		{
			var fileContent = File.ReadAllLines(@"C:\Z\Projects\CodeJam2012\Qualification\bin\Debug\C-large.in");
			var numTests = int.Parse(fileContent[0]);

			for (int i = 0; i < numTests; i++)
			{
				var data = fileContent[i + 1].Split(" ".ToCharArray()).Select(n => int.Parse(n)).ToArray();
				var len = fileContent[i + 1].Split(" ".ToCharArray()).Select(n => n.Length).First();
				Console.WriteLine(Solve(i + 1, len, data[0], data[1]));
			}
			//Console.ReadKey();
		}

		private static string Solve(int testNum, int numLength, int min, int max)
		{
			int result = 0;

			//for (int i = min; i <= max; i++)
			//{
			//    result += GetDistinctRecycleCount(i, numLength, min, max);
			//}
			Parallel.For(min, max, i => Interlocked.Add(ref result, GetDistinctRecycleCount(i, numLength, min, max)));

			return "Case #" + testNum + ": " + result;
		}

		private static int GetDistinctRecycleCount(int number, int numLength, int min, int max)
		{
			var result = new HashSet<int>();
			int minCutOff = min / (int)Math.Pow(10, numLength - 1);
			int maxCutOff = max / (int)Math.Pow(10, numLength - 1);
			int numCutOff = number / (int)Math.Pow(10, numLength - 1);
			//count recpairs which are bigger than number between min and max
			for (int i = 1; i < numLength; i++)
			{
				var curr = (number / (int)Math.Pow(10, i - 1)) % 10;
				int shiftedNum;
				if (curr >= minCutOff
					&& curr <= maxCutOff
					&& curr >= numCutOff
					&& (shiftedNum = Shift(number, numLength, i)) > number
					&& shiftedNum >= min
					&& shiftedNum <= max)
				{
					result.Add(shiftedNum);
				}
			}
			return result.Count;
		}

		private static int Shift(int orig, int length, int numToShift)
		{
			int div = (int)Math.Pow(10, numToShift);
			int mul = (int)Math.Pow(10, length - numToShift);
			return (orig % div) * mul + (orig / div);
		}
	}
}
