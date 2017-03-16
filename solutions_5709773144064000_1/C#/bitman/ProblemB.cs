using System;
using System.Globalization;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam
{
	class ProblemB
	{
		static void Main(string[] args)
		{
			//string inFilePath = Environment.GetFolderPath(Environment.SpecialFolder.Desktop) + "\\input.txt";

			Console.Out.Write("Enter input file path:");
			string inFilePath = Console.In.ReadLine();

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
			double[] inp = input.ReadLine().Split(' ').Select(num => double.Parse(num, CultureInfo.InvariantCulture)).ToArray();
			double farmCost = inp[0], farmProd = inp[1], goal = inp[2];

			double production = 2;
			double timeToBuyFarms = 0;
			double estimatedTime = timeToBuyFarms + goal / production;
			
			for (;;) {
				timeToBuyFarms += farmCost / production;
				production += farmProd;
				double newEstimatedTime = timeToBuyFarms + goal / production;
				if (newEstimatedTime > estimatedTime) return estimatedTime.ToString("F7", CultureInfo.InvariantCulture);
				estimatedTime = newEstimatedTime;
			}
		}
	}
}
