using GoogleCodeJam.Common;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fractiles
{
	class Program
	{
		static void Main(string[] args)
		{
			InputFile input = new InputFile("D-small-attempt0.in");
			OutputFile output = new OutputFile("output-small.txt");

			int[] values = input.ReadIntArray();
			int TEST_COUNT = values[0];

			for (int i = 0; i < TEST_COUNT; i++)
			{
				TestCaseCheat testCase = new TestCaseCheat(input);
				output.WriteCase(i + 1, testCase.Solution());
			}

			output.Close();
		}
	}

	class TestCaseCheat
	{
		private readonly int K; // original sequence length
		private readonly int C; // complexity, number of times rule applied.
		private readonly int S; // number of tiles to check

		public TestCaseCheat(InputFile input)
		{
			int[] parameters = input.ReadIntArray();
			K = parameters[0];
			C = parameters[1];
			S = parameters[2];
		}

		public string Solution()
		{
			if (K != S)
				throw new InvalidOperationException();

			string[] positions = new string[S];
			for (int i = 1; i <= S; i++)
				positions[i - 1] = i.ToString();

			return String.Join(" ", positions);
		}
	}
}
