using System;
using System.Globalization;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam
{
	class ProblemA
	{

		static void Main(string[] args)
		{
			string inFilePath = "D:\\Downloads\\A-small-attempt0.in";

			string outFilePath = Path.ChangeExtension(inFilePath, "out") + ".txt";
			Console.Out.Write("Input file: " + inFilePath + "\nOutput file: " + outFilePath + "\n");
			StreamReader inputFile = new StreamReader(inFilePath, Encoding.ASCII);
			StreamWriter outputFile = new StreamWriter(outFilePath, false, Encoding.ASCII);
			uint caseCount = uint.Parse(inputFile.ReadLine());
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
			long[] inp = input.ReadLine().Split('/').Select(num => long.Parse(num)).ToArray();
			long p = inp[0], q = inp[1];
			if (p == 0) return "impossible";
			bool generationEvaluated = false;
			int generation = 1;
			while (p != 0 && q % 2 == 0) {
				q /= 2;
				if (p >= q) {
					generationEvaluated = true;
					p -= q;
				}
				if (!generationEvaluated) generation++;
			}
			if(p == 0) return generation.ToString();
			return "impossible";
		}
	}
}
