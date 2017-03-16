using GoogleCodeJam.Common;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Brattleship
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
				output.WriteCase(i + 1, testCase.GetSolution().ToString());
			}

			output.Close();
		}
	}

	class TestCase
	{
		private readonly int m_Rows;
		private readonly int m_RowSize;
		private readonly int m_ShipSize;

		public TestCase(InputFile input)
		{
			int[] parameters = input.ReadIntArray();
			m_Rows = parameters[0];
			m_RowSize = parameters[1];
			m_ShipSize = parameters[2];
		}

		public int GetSolution()
		{
			// Just calculate for one row, then multiply.
			return GetSolutionPerRow() * m_Rows;

		}

		private int GetSolutionPerRow()
		{
			if (m_ShipSize == m_RowSize)
				return m_RowSize; // Includes special case where shipsize == 1.

			// Ship is smaller than row.
			int numberOfAttemptsForFirstHit = (m_RowSize / m_ShipSize);

			// We have a guaranteed hit. Now need to check the hits to finish up. Depends on last hit and row size.
			int remainingSpaces = m_RowSize - (numberOfAttemptsForFirstHit - 1) * m_ShipSize;

			int finalShots = m_ShipSize;
			if (remainingSpaces == m_ShipSize)
				finalShots--;

			return numberOfAttemptsForFirstHit + finalShots;
		}
	}
}
