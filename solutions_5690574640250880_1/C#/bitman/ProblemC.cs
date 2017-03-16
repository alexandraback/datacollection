using System;
using System.Globalization;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam
{
	class ProblemC
	{
		static void Main(string[] args)
		{
			string inFilePath = Environment.GetFolderPath(Environment.SpecialFolder.Desktop) + "\\C-large.in";

			//Console.Out.Write("Enter input file path:");
			//string inFilePath = Console.In.ReadLine();

			string outFilePath = Path.Combine(Path.GetDirectoryName(inFilePath),
			Path.GetFileNameWithoutExtension(inFilePath) + "_out");
			outFilePath = Path.ChangeExtension(outFilePath, Path.GetExtension(inFilePath));
			Console.Out.Write("Input file: " + inFilePath + "\nOutput file: " + outFilePath + "\n");
			StreamReader inputFile = new StreamReader(inFilePath, Encoding.ASCII);
			StreamWriter outputFile = new StreamWriter(outFilePath, false, Encoding.ASCII);
			string line = inputFile.ReadLine();
			uint caseCount = uint.Parse(line);
			for(uint caseNumber = 1; caseNumber <= caseCount; ++caseNumber) {
				var result = ResolveCase(inputFile);
				string output = string.Format("Case #{0}: {1}", caseNumber, result);
				outputFile.WriteLine(output);
				Console.Out.WriteLine(output);
			}
			inputFile.Close();
			outputFile.Close();
		}

		//-------------------------------------------------------------------------------------------------
		static string ResolveCase(StreamReader input)
		{
			// Reading input
			int[] inp = input.ReadLine().Split(' ').Select(num => int.Parse(num, CultureInfo.InvariantCulture)).ToArray();
			int rows = inp[0], columns = inp[1], mines = inp[2], noMineCells = rows * columns - mines;

			if (noMineCells == 1)
				return "\r\nc" + new string('*', columns - 1) + StringByRepeating("\r\n" + new string('*', columns), rows - 1);
			if (rows == 1) 
				return "\r\nc" + new string('.', noMineCells - 1) + new string('*', mines);
			if (columns == 1) 
				return "\r\nc" + StringByRepeating("\r\n.", noMineCells - 1) + StringByRepeating("\r\n*", mines);
			if (noMineCells != 2 && !((rows == 2 || columns == 2 || noMineCells < 9) && noMineCells % 2 == 1)) {
				StringBuilder sb = new StringBuilder("\r\nc");
				int noMineRows = noMineCells / columns;
				if (noMineRows < 2) {
					int noMineCellsPerRow = noMineCells / 2 - noMineCells % 2;
					sb.Append(new string('.', noMineCellsPerRow - 1));
					sb.Append(new string('*', columns - noMineCellsPerRow)).Append("\r\n");
					sb.Append(new string('.', noMineCellsPerRow));
					sb.Append(new string('*', columns - noMineCellsPerRow));
					int mineRows = rows - 2;
					if (noMineCells % 2 == 1) {
						sb.Append("\r\n").Append(new string('.', 3));
						sb.Append(new string('*', columns - 3));
						mineRows--;
					}
					sb.Append(StringByRepeating("\r\n" + new string('*', columns), mineRows));
					return sb.ToString();
				}
				int reminder = noMineCells % columns;
				if (reminder == 1) {
					if (noMineRows == 2) {
						sb.Append(new string('.', columns - 2)).Append("*").Append("\r\n");
						sb.Append(new string('.', columns - 1)).Append("*").Append("\r\n");
						sb.Append(new string('.', 3));
						sb.Append(new string('*', columns - 3));
						sb.Append(StringByRepeating("\r\n" + new string('*', columns), rows - 3));
						return sb.ToString();
					}
					sb.Append(new string('.', columns - 1));
					sb.Append(StringByRepeating("\r\n" + new string('.', columns), noMineRows - 2)).Append("\r\n");
					sb.Append(new string('.', columns - 1)).Append("*\r\n");
					sb.Append(new string('.', 2));
					sb.Append(new string('*', columns - 2));
					sb.Append(StringByRepeating("\r\n" + new string('*', columns), rows - noMineRows - 1));
					return sb.ToString();
				}
				sb.Append(new string('.', columns - 1));
				sb.Append(StringByRepeating("\r\n" + new string('.', columns), noMineRows - 1));
				if (rows - noMineRows > 0) {
					sb.Append("\r\n").Append(new string('.', reminder));
					sb.Append(new string('*', columns - reminder));
					sb.Append(StringByRepeating("\r\n" + new string('*', columns), rows - noMineRows - 1));
				}
				return sb.ToString();
			}
			return "\r\nImpossible";
		}

		static string StringByRepeating(string str, int count) {
			//if(str.Length == 0 || count <= 0) return "";
			StringBuilder sb = new StringBuilder(str.Length * count);
			for (int i = 0; i < count; i++) {
				sb.Append(str);
			}
			return sb.ToString();
		}

	}
}
