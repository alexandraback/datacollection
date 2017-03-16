using GoogleCodeJam.Common;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace CountingSheep
{
	class Program
	{
		static void Main(string[] args)
		{
			InputFile input = new InputFile("A-large.in");
			OutputFile output = new OutputFile("output.txt");

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
		private readonly BigInteger m_Number;

		public TestCase(InputFile input)
		{
			int[] parameters = input.ReadIntArray();
			m_Number = parameters[0];
		}

		public String Solution()
		{
			if (m_Number == 0)
				return "INSOMNIA";

			bool[] digitsSeen = new bool[10];
			BigInteger accum = 0;

			do
			{
				accum += m_Number;

				foreach (char c in accum.ToString())
					digitsSeen[c - '0'] = true;
			}
			while (!digitsSeen.All(bit => bit));

			return accum.ToString();
		}
	}
}
