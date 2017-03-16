using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;

namespace Qualification
{
	class C : ICodeJamSolver
	{
		int testNum;
		long min, max;
		static List<long> results = new List<long>();

		static C()
		{
			for (long i = 1; i <= (long)Math.Floor(Math.Sqrt(Math.Pow(10, 14))); i++)
			{
				if (IsPalindrome(i.ToString()) && IsPalindrome((i * i).ToString()))
				{
					results.Add(i * i);
				}
			}
		}

		public void ReadCase(int caseNumber, StreamReader reader)
		{
			testNum = caseNumber;
			var m = reader.ReadLineAsLongArray();
			min = m[0];
			max = m[1];
		}

		public string SolveCase()
		{
			var result = 0;

			result = results.SkipWhile(n => n < min).TakeWhile(n => n <= max).Count();

			//for (long i = (long)Math.Ceiling(Math.Sqrt(min)); i <= (long)Math.Floor(Math.Sqrt(max)); i++)
			//{
			//    if (IsPalindrome(i.ToString()) && IsPalindrome((i * i).ToString()))
			//    {
			//        Console.WriteLine(i * i);
			//        result++;
			//    }
			//}

			return "Case #" + testNum + ": " + result.ToString(CultureInfo.InvariantCulture);
		}

		static bool IsPalindrome(string str)
		{
			for (int i = 0; i < str.Length / 2; i++)
			{
				if (str[i] != str[str.Length - 1 - i]) return false;
			}
			return true;
		}


		///////////////////////
		static void MainZ(string[] args)
		{
			using (var reader = new StreamReader(args[0]))
			{
				int numTests = int.Parse(reader.ReadLine());

				for (int i = 0; i < numTests; i++)
				{
					var solver = (ICodeJamSolver)Activator.CreateInstance(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);
					solver.ReadCase(i + 1, reader);
					var result = solver.SolveCase();
					Console.WriteLine(result);
				}
			}
		}
	}
}
