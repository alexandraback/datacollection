using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;

namespace Round1A
{
	class Password
	{
		static void Main(string[] args)
		{
			var inFileName = args.Length == 0 ? "A-small-attempt0.in" : args[0];
			var outFileName = inFileName.Replace(".in", "") + ".out";
			using (var reader = new StreamReader(inFileName))
			using (var writer = new StreamWriter(outFileName))
			{
				int numTests = reader.ReadLineAsInt();

				for (int i = 0; i < numTests; i++)
				{
					var pass = reader.ReadLineAsIntArray();
					var prob = reader.ReadLine().Split(new[] { ' ' }).Select(n => double.Parse(n, CultureInfo.InvariantCulture)).ToArray();
					var result = Solve(i + 1, pass[0], pass[1], prob);
					writer.WriteLine(result);
					Console.WriteLine(result);
				}
			}
			Console.WriteLine("Done.");
			Console.ReadKey();
		}


		private static string Solve(int testNum, int typed, int len, double[] prob)
		{
			var min = double.MaxValue;
			for (int i = -1; i <= typed; i++)
			{
				var curr = GetExpectedValue(i, typed, len, prob);
				if (curr < min)
				{
					min = curr;
				}
			}

			return "Case #" + testNum + ": " + min.ToString("0.000000", CultureInfo.InvariantCulture);
		}

		private static double GetExpectedValue(int action, int typed, int len, double[] prob)
		{
			if (action == -1) //keep typing
			{
				var right = prob.Aggregate((n1, n2) => n1 * n2);
				var wrong = 1 - right;
				var rightKeys = len - typed + 1;
				var wrongKeys = rightKeys + len + 1;
				return rightKeys * right + wrongKeys * wrong;
			}
			else if (action == 0) //hit enter
			{
				return 1 + len + 1;
			}
			else //press backspace action num times
			{
				var right = (double)1;
				for (int i = 0; i < typed - action; i++)
				{
					right *= prob[i];
				}
				var wrong = 1 - right;
				var rightKeys = len - typed + 1 + 2 * action;
				var wrongKeys = rightKeys + len + 1;
				return rightKeys * right + wrongKeys * wrong;
			}
		}
	}
}
