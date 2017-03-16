using GoogleCodeJam.Common;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CounterCulture
{
	class Program
	{
		static void Main(string[] args)
		{
			InputFile input = new InputFile("A-small-attempt0.in");
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
		private readonly long m_Target;

		public TestCase(InputFile input)
		{
			m_Target = input.ReadLongArray()[0];
		}

		public long GetSolution()
		{
			if (m_Target == 1)
				return 1;

			List<HashSet<long>> obtainedPerStep = new List<HashSet<long>>();
			HashSet<long> allObtained = new HashSet<long>();

			allObtained.Add(1);
			obtainedPerStep.Add(new HashSet<long>() { 1 });
			int lastStep = 0;

			while (true)
			{
				HashSet<long> previousSet = obtainedPerStep[lastStep];
				HashSet<long> nextSet = new HashSet<long>();

				foreach (long number in previousSet)
				{
					long afterInc = number + 1;
					long afterRev = Reverse(number);

					if (afterInc == m_Target || afterRev == m_Target)
						return lastStep + 2;

					if (!allObtained.Contains(afterInc))
					{
						allObtained.Add(afterInc);
						nextSet.Add(afterInc);
					}

					if (!allObtained.Contains(afterRev))
					{
						nextSet.Add(afterRev);
						allObtained.Add(afterRev);
					}
				}

				obtainedPerStep.Add(nextSet);
				lastStep++;
			}
		}

		public static long Distance(long start, long end)
		{
			if (start > end)
				return Int32.MinValue;

			if (start == end)
				return 1;

			long distanceAfterInc = Distance(start + 1, end);
			long distanceAfterRev = Distance(Reverse(start), end);

			if (distanceAfterInc == Int32.MinValue)
				return 1 + distanceAfterRev;
			else if (distanceAfterRev == Int32.MinValue)
				return 1 + distanceAfterInc;
			else
				return 1 + Math.Min(distanceAfterInc, distanceAfterRev);
		}

		public static long Reverse(long number)
		{
			return long.Parse(new String(number.ToString().Reverse().ToArray()).TrimStart('0'));
		}
	}
}
