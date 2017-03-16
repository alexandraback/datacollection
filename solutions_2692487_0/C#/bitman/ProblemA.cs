using System;
using System.Globalization;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;

namespace GoogleCodeJam
{
	class ProblemA
	{
		static void Main(string[] args)
		{
			StreamReader inputFile = new StreamReader("input.txt", Encoding.ASCII);
			StreamWriter outputFile = new StreamWriter("output.txt", false, Encoding.ASCII);
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
			// Reading input.
			uint[] firstLine =  input.ReadLine().Split(' ').Select(str => uint.Parse(str)).ToArray();
			//if (firstLine[0] == 1) {
			//    return firstLine[1].ToString();
			//}
			uint mote = firstLine[0];
			uint[] motes = input.ReadLine().Split(' ').Select(str => uint.Parse(str)).OrderBy(num => num).ToArray();
			if (mote == 1) {
				return motes.Length.ToString();
			}

			uint[] insertsNeeded = new uint[motes.Length];
			for (uint i = 0; i < motes.Length; ++i) {
				while (mote <= motes[i]) {
					mote += mote - 1;
					++insertsNeeded[i];
				}
				mote += motes[i];
			}

			uint totalInsertsNeeded = 0;
			uint result = (uint)motes.Length;
			for (uint i = 0; i < motes.Length; ++i) {
				totalInsertsNeeded += insertsNeeded[i];
				result = Math.Min((uint)(totalInsertsNeeded + motes.Length - i - 1), result);
			}

			return result.ToString();
		}

	}
}
