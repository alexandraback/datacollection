using GoogleCodeJam.Common;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Slides
{
	class Program
	{
		static void Main(string[] args)
		{
			InputFile input = new InputFile("B-small-attempt1.in");
			OutputFile output = new OutputFile("output-small1.txt");

			int[] values = input.ReadIntArray();
			int TEST_COUNT = values[0];

			for (int i = 0; i < TEST_COUNT; i++)
			{
				TestCase testCase = new TestCase(input);
				output.WriteCase(i + 1, testCase.GetSolution());
			}

			output.Close();
		}
	}

	class TestCase
	{
		private readonly int B;
		private readonly int M;

		public TestCase(InputFile input)
		{
			int[] inputs = input.ReadIntArray();
			B = inputs[0];
			M = inputs[1];
		}

		internal string GetSolution()
		{
			byte[,] slides = new byte[B, B];

			if (M > Math.Pow(2, B - 2))
				return "IMPOSSIBLE";

			if (!IsPowerOfTwo((uint)M))
				return "IMPOSSIBLE";

			int nodesToRemove = (int)Math.Log(Math.Pow(2, B - 2) / M, 2);

			int firstNodeToRemove = 0;
			int lastNodeToRemove = 0;

			if (nodesToRemove != 0)
			{
				firstNodeToRemove = 1;
				lastNodeToRemove = 0 + nodesToRemove;
			}

			for (int i = 0; i < B; i++)
			{
				for (int j = i + 1; j < B; j++)
				{
					if (firstNodeToRemove != 0 && ((i >= firstNodeToRemove && i <= lastNodeToRemove) || (j >= firstNodeToRemove && j <= lastNodeToRemove)))
						continue;

					slides[i, j] = 1;
				}
			}

			return "POSSIBLE" + "\r\n" + MatrixToString(slides);
		}

		private string MatrixToString(byte[,] slides)
		{
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < B; i++)
			{
				for (int j = 0; j < B; j++)
				{
					sb.Append((slides[i, j] == 1 ? "1" : "0"));
				}
				sb.AppendLine();
			}

			return sb.ToString();
		}

		bool IsPowerOfTwo(uint x)
		{
			return (x & (x - 1)) == 0;
		}
	}
}
