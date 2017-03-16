//C# Console Application, .NET v4.6.1

using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
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
				var parameters = input[i].Split(new [] {' '}, StringSplitOptions.RemoveEmptyEntries);
				var originalTileCount = int.Parse(parameters[0], NumberStyles.Integer, NumberFormatInfo.InvariantInfo); //K
				var complexity = int.Parse(parameters[1], NumberStyles.Integer, NumberFormatInfo.InvariantInfo);
				var numberOfStudents = int.Parse(parameters[2], NumberStyles.Integer, NumberFormatInfo.InvariantInfo);

				var solution = new List<long>();
				if (complexity == 1)
				{
					if (numberOfStudents >= originalTileCount) //otherwise - no solution
						solution.AddRange(Enumerable.Range(0, originalTileCount).Select(el => (long)el));
				}
				else if (numberOfStudents >= (originalTileCount + 1)/2) //otherwise - no solution
				{
					long groupSize = originalTileCount;
					for (var power = 2; power < complexity; power++)
						groupSize *= originalTileCount;

					for (var originalTile = 0; originalTile < originalTileCount; originalTile += 2)
					{
						var finalTile = originalTile*groupSize + (originalTile + 1 < originalTileCount ? originalTile + 1 : 0);
						solution.Add(finalTile);
					}
				}

				var line = "Case #" + (i + 1).ToString(NumberFormatInfo.InvariantInfo) + ": " + 
					(solution.Count == 0 
					 ? "IMPOSSIBLE"
					 : string.Join(" ", solution.Select(s => (s + 1).ToString(NumberFormatInfo.InvariantInfo))));

				result.AppendLine(line);
				Console.WriteLine(line);
			}

			File.WriteAllText(Path.ChangeExtension(inputFile, ".out"), result.ToString());

#if DEBUG
			Console.WriteLine("Done");
			Console.ReadKey();
#endif
		}
	}
}
