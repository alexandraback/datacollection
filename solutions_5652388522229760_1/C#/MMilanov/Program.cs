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
				var number = int.Parse(input[i], NumberStyles.Integer, NumberFormatInfo.InvariantInfo);
				var multiplier = 0;
				if (number != 0)
				{
					var digitsSeen = new bool[10];
					var numberOfDigitsSeen = 0;
					while (true)
					{
						multiplier++;
						var temp = multiplier*number;

						while (temp != 0)
						{
							var lastDigit = temp%10;
							temp = temp/10;
							if (digitsSeen[lastDigit])
								continue;

							digitsSeen[lastDigit] = true;
							numberOfDigitsSeen++;
						}

						if (numberOfDigitsSeen >= 10)
							break;
					}
				}

				var line = "Case #" + (i + 1).ToString(NumberFormatInfo.InvariantInfo) + ": " + (number == 0 ? "INSOMNIA" : (number*multiplier).ToString(NumberFormatInfo.InvariantInfo));

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
