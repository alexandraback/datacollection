//C# Console Application, .NET v4.6.1

using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;

namespace Gcj
{
	class Program
	{
		static void Main(string[] args)
		{
			var inputFile = args[0];

			var input = File.ReadAllLines(inputFile).Where(l => !string.IsNullOrWhiteSpace(l)).Select(l => l.Trim()).ToArray();
			var count = int.Parse(input.First(), NumberFormatInfo.InvariantInfo);
			input = input.Skip(1).ToArray();
			if (count != input.Length)
				throw new ArgumentException();

			var result = new StringBuilder();

			for (var i = 0; i < count; i++)
			{
				var inputParameters = input[i].Trim().Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(s => long.Parse(s, NumberStyles.Integer, NumberFormatInfo.InvariantInfo)).ToArray();
				var b = (int)inputParameters[0];
				var m = inputParameters[1];

				if (1L << (b - 2) < m)
					result.AppendLine("Case #" + (i + 1).ToString(NumberFormatInfo.InvariantInfo) + ": IMPOSSIBLE");
				else
				{
					result.AppendLine("Case #" + (i + 1).ToString(NumberFormatInfo.InvariantInfo) + ": POSSIBLE");

					var solution = new List<string>();

					for (var row = 0; row < b; row++)
					{
						var line = "";

						var lineValue = (1L << (b - 2 - row));
						var isZeroLine = lineValue/2 >= m;
						var isBinaryLine = (!isZeroLine) && (lineValue >= m);

						System.Diagnostics.Debug.WriteLine(row + " " + isZeroLine + " " + isBinaryLine);

						//for (var col = 0; col < b; col++)
						//{
						//	if (col <= row)
						//		line += "0";
						//	else if (isZeroLine)
						//		line += (col == row + 1 ? "1" : "0");
						//	else if (!isBinaryLine)
						//		line += "1";
						//	else if (col == b - 1)
						//		line += (m % 2 == 0 ? "1" : "0");
						//	else
						//		line += ((((m % 2 != 0 ? m : (m - 1)) & (1L << (b - 2 - col))) != 0) ? "1" : "0");
						//}
						for (var col = 0; col < b; col++)
						{
							if (col <= row)
								line += "0";
							else if (isZeroLine)
								line += (col == row + 1 ? "1" : "0");
							else if (!isBinaryLine)
								line += "1";
							else if (col == b - 1)
								line += ((m == lineValue) || (m % 2 == 0) ? "1" : "0");
							else
								line += ((((m % 2 != 0 ? m : (m - 1)) & (1L << (b - 2 - col))) != 0) ? "1" : "0");
						}
						solution.Add(line);
					}

					foreach (var line in solution)
						result.AppendLine(line);
				}
			}

			File.WriteAllText(Path.ChangeExtension(inputFile, ".out"), result.ToString());

#if DEBUG
			Console.WriteLine("Done");
			Console.ReadKey();
#endif
		}
	}
}
