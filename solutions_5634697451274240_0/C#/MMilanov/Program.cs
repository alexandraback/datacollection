//C# Console Application, .NET v4.6.1

using System;
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
				var s = input[i] + "+";

				var flips = 0;
				for (var j = 0; j < s.Length - 1; j++)
				{
					if (s[j] != s[j + 1])
						flips++;
				}

				var line = "Case #" + (i + 1).ToString(NumberFormatInfo.InvariantInfo) + ": " + flips.ToString(NumberFormatInfo.InvariantInfo);

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
