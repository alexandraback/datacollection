using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace TvShow
{
	class TvShow
	{
		static void Main(string[] args)
		{
			Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
			Thread.CurrentThread.CurrentUICulture = CultureInfo.InvariantCulture;

			using (var input = new StreamReader(args[0]))
			using (var output = new StreamWriter(args[1])) {
				int caseCount = int.Parse(input.ReadLine());
				foreach (var caseN in Enumerable.Range(1, caseCount)) {
					output.Write("Case #{0}:", caseN);
					SolveCase(input, output);
				}

				input.Close();
				output.Close();
			}
		}

		static void SolveCase(StreamReader input, StreamWriter output)
		{
			var ints = input.ReadLine().Split(' ')
				.Select(int.Parse).Skip(1).ToArray();
			var result = FindMinimumFractions(ints);
			foreach (double v in result) {
				output.Write(' ');
				output.Write(v);
			}
			output.WriteLine();
		}

		static double[] FindMinimumFractions(int[] J)
		{
			int totalJudgePoints = J.Sum();

			double needed = (2.0 * totalJudgePoints) / J.Length;
			var decreasing = Enumerable.Range(0, J.Length)
				.OrderByDescending(i => J[i]);
			var result = new double[J.Length];
			int passed = 0;
			foreach (var i in decreasing) {
				if (J[i] > needed) {
					result[i] = 0;
					needed = (needed * J.Length - J[i] - needed * passed)
						/ (J.Length - 1 - passed);
				} else {
					result[i] = 100 * (needed - J[i]) / totalJudgePoints;
				}

				passed++;
			}
			return result;
		}
	}
}
