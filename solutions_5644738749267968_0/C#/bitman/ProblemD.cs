using System;
using System.Globalization;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam
{
	class ProblemD
	{
		static void Main(string[] args)
		{
			string inFilePath = Environment.GetFolderPath(Environment.SpecialFolder.Desktop) + "\\D-small-attempt0.in";

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
			input.ReadLine();
			double[] blocks1 = input.ReadLine().Split(' ')
				.Select(num => double.Parse(num, CultureInfo.InvariantCulture)).ToArray();
			double[] blocks2 = input.ReadLine().Split(' ')
				.Select(num => double.Parse(num, CultureInfo.InvariantCulture)).ToArray();
			
			Array.Sort(blocks1);
			Array.Sort(blocks2);
			int length = blocks1.Length;
			int unfairResult = 0;
			for(int i = 0, j = i; i < length; i++, j++) {
				if(blocks1[i] < blocks2[j]) {
					int newi = ~Array.BinarySearch(blocks1, blocks2[j]);
					i = newi;
					if (newi >= length) break;
				}
				unfairResult++;
			}
			int fairResult = 0;
			for (int i = length - 1, j = i; i >= 0; i--, j--) {
				if (blocks1[i] > blocks2[j]) {
					int newi = ~Array.BinarySearch(blocks1, blocks2[j]) - 1;
					fairResult += i - newi;
					i = newi;
				}
			}
			return String.Format("{0} {1}", unfairResult, fairResult);
		}

	}
}
