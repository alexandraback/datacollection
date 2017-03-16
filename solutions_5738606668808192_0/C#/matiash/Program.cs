using GoogleCodeJam.Common;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace JamCoin
{
	class Program
	{
		static void Main(string[] args)
		{
			InputFile input = new InputFile("test.txt");
			OutputFile output = new OutputFile("output.txt");

			int[] values = input.ReadIntArray();
			int TEST_COUNT = values[0];

			for (int i = 0; i < TEST_COUNT; i++)
			{
				TestCase testCase = new TestCase(input);
				output.WriteCase(i + 1, null);
				output.Write(testCase.Solution());
			}

			output.Close();
		}
	}

	class TestCase
	{
		private readonly int BIT_COUNT;
		private readonly int DESIRED_COIN_COUNT;

		public TestCase(InputFile input)
		{
			int[] parameters = input.ReadIntArray();
			BIT_COUNT = parameters[0];
			DESIRED_COIN_COUNT = parameters[1];
		}

		public string Solution()
		{
			long found = 0;
			StringBuilder output = new StringBuilder();

			foreach (long number in GetPossibleBitSequences())
			{
				List<long> values = GetValueInBases(number);
				List<long> divisors = new List<long>();

				foreach (long interpretation in values)
				{
					long divisor = PrimeChecker.GetDivisor(interpretation);
					if (divisor != PrimeChecker.NOT_FOUND)
						divisors.Add(PrimeChecker.GetDivisor(interpretation));
					else
						break;
				}

				if (divisors.Count == values.Count)
				{
					string outputLine = Convert.ToString(number, 2) + " " + String.Join(" ", divisors.ToArray());
					Console.WriteLine(outputLine);

					output.AppendLine(outputLine);
					found++;
				}

				if (found == DESIRED_COIN_COUNT)
					break;
			}

			return output.ToString();
		}

		private IEnumerable<long> GetPossibleBitSequences()
		{
			// From 1<bit_count-2 zeroes>1 to 1<bit_count-2 ones>1
			long first = (long)Math.Pow(2, BIT_COUNT - 1) + 1;
			long last = (long)Math.Pow(2, BIT_COUNT) - 1;

			for (long n = first; n <= last; n += 2)
				yield return n;
		}


		private static List<long> GetValueInBases(long bits)
		{
			List<long> interpretations = new List<long>();
			foreach (int theBase in new List<int>() { 2, 3, 4, 5, 6, 7, 8, 9, 10 })
				interpretations.Add(GetValueInBase(bits, theBase));

			return interpretations;
		}

		private static long GetValueInBase(long bits, int theBase)
		{
			long result = 0;
			long positionValue = 1;
			while (bits != 0)
			{
				if (bits % 2 == 1)
					result += positionValue;

				positionValue *= theBase;
				bits = bits / 2;
			}

			return result;
		}
	}
}
