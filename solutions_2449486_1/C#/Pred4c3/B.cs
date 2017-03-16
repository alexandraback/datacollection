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
	class B : ICodeJamSolver
	{
		int testNum;
		int[,] map;

		public void ReadCase(int caseNumber, StreamReader reader)
		{
			testNum = caseNumber;

			var size = reader.ReadLineAsIntArray();
			map = new int[size[0], size[1]];

			for (int i = 0; i < size[0]; i++)
			{
				var line = reader.ReadLineAsIntArray();
				for (int j = 0; j < line.Length; j++)
				{
					map[i, j] = line[j];
				}
			}
		}

		public string SolveCase()
		{
			var result = IsValid() ? "YES" : "NO";

			return "Case #" + testNum + ": " + result.ToString(CultureInfo.InvariantCulture);
		}

		private bool IsValid()
		{
			for (int i = 0; i < map.GetLength(0); i++)
			{
				for (int j = 0; j < map.GetLength(1); j++)
				{
					if (!IsValid(i, j)) return false;
				}
			}
			return true;
		}

		private bool IsValid(int ii, int jj)
		{
			var curr = map[ii, jj];
			var allOk = true;
			for (int i = 0; i < map.GetLength(0); i++)
			{
				allOk &= map[i, jj] <= curr;
			}
			if (allOk) return true;
			allOk = true;
			for (int j = 0; j < map.GetLength(1); j++)
			{
				allOk &= map[ii, j] <= curr;
			}
			return allOk;
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
