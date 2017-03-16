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
			int found = 0;
			StringBuilder output = new StringBuilder();

			foreach (BigInteger number in GetPossibleBitSequences())
			{
				List<BigInteger> values = GetValueInBases(number);
				List<BigInteger> divisors = new List<BigInteger>();

				foreach (BigInteger interpretation in values)
				{
					BigInteger divisor = PrimeChecker.GetDivisorWithFalseNegatives(interpretation);
					if (divisor != PrimeChecker.NOT_FOUND)
						divisors.Add(divisor);
					else
						break;
				}

				if (divisors.Count == values.Count)
				{
					string outputLine = ToBinaryString(number) + " " + String.Join(" ", divisors.ToArray());
					Console.WriteLine(outputLine);

					output.AppendLine(outputLine);
					found++;
				}

				if (found == DESIRED_COIN_COUNT)
					break;
			}

			return output.ToString();
		}

		private IEnumerable<BigInteger> GetPossibleBitSequences()
		{
			// From 1<bit_count-2 zeroes>1 to 1<bit_count-2 ones>1
			BigInteger first = BigInteger.Pow(2, BIT_COUNT - 1) + 1;
			BigInteger last = BigInteger.Pow(2, BIT_COUNT) - 1;

			for (BigInteger n = first; n <= last; n += 2)
				yield return n;
		}


		private static List<BigInteger> GetValueInBases(BigInteger bits)
		{
			List<BigInteger> interpretations = new List<BigInteger>();
			foreach (int theBase in new List<int>() { 2, 3, 4, 5, 6, 7, 8, 9, 10 })
				interpretations.Add(GetValueInBase(bits, theBase));

			return interpretations;
		}

		private static BigInteger GetValueInBase(BigInteger bits, int theBase)
		{
			BigInteger result = 0;
			BigInteger positionValue = 1;
			while (bits != 0)
			{
				if (bits % 2 == 1)
					result += positionValue;

				positionValue *= theBase;
				bits = bits / 2;
			}

			return result;
		}

		private static string ToBinaryString(BigInteger bigint)
		{
			var bytes = bigint.ToByteArray();
			var idx = bytes.Length - 1;

			// Create a StringBuilder having appropriate capacity.
			var base2 = new StringBuilder(bytes.Length * 8);

			// Convert first byte to binary.
			var binary = Convert.ToString(bytes[idx], 2);

			// Append binary string to StringBuilder.
			base2.Append(binary);

			// Convert remaining bytes adding leading zeros.
			for (idx--; idx >= 0; idx--)
			{
				base2.Append(Convert.ToString(bytes[idx], 2).PadLeft(8, '0'));
			}

			string result = base2.ToString();
			if (result.StartsWith("0"))
				result = result.Substring(1);

			return result;
		}
	}
}
