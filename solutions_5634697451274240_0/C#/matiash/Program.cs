using GoogleCodeJam.Common;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RevengeOfThePancakes
{
	class Program
	{
		static void Main(string[] args)
		{
			InputFile input = new InputFile("B-small-attempt0.in");
			OutputFile output = new OutputFile("output-small.txt");

			int[] values = input.ReadIntArray();
			int TEST_COUNT = values[0];

			for (int i = 0; i < TEST_COUNT; i++)
			{
				TestCase testCase = new TestCase(input);
				output.WriteCase(i + 1, testCase.Solution());
			}

			output.Close();
		}
	}

	class TestCase
	{
		private readonly string m_InitialStack;

		public TestCase(InputFile input)
		{
			m_InitialStack = input.ReadStringArray()[0];
		}

		public string Solution()
		{
			// We just need to count the number of places where there is a different orientation
			// between the pancake at i and the one at i+1. Make up a fake "+" pancake at the end 
			// to flip the whole stack if necessary.
			int neededFlips = 0;
			string stackPlusSentinel = m_InitialStack + "+";

			for (int i = 0; i < stackPlusSentinel.Length - 1; i++)
			{
				if (stackPlusSentinel[i] != stackPlusSentinel[i + 1])
					neededFlips++;
			}

			return neededFlips.ToString();
		}
	}

}
