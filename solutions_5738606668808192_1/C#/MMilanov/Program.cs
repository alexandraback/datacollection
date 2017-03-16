//C# Console Application, .NET v4.6.1

using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;

namespace Gcj
{
	class Program
	{
		static void Main(string[] args)
		{
			var inputFile = args[0];

			var input = File.ReadAllLines(inputFile).Where(l => !string.IsNullOrWhiteSpace(l)).Select(l => l.Trim()).ToArray();
			var count = int.Parse(input.First(), NumberFormatInfo.InvariantInfo);
			input = input.Skip(1).ToArray();
			if (count != input.Length)
				throw new ArgumentException();

			var result = new StringBuilder();

			for (var i = 0; i < count; i++)
			{
				var parameters = input[i].Split(new [] {' '}, StringSplitOptions.RemoveEmptyEntries);
				var numberOfDigits = int.Parse(parameters[0], NumberStyles.Integer, NumberFormatInfo.InvariantInfo); //K
				var numberOfSolutions = int.Parse(parameters[1], NumberStyles.Integer, NumberFormatInfo.InvariantInfo);

				var solution = Solve(numberOfDigits, numberOfSolutions);

				result.AppendLine("Case #" + (i + 1).ToString(NumberFormatInfo.InvariantInfo) + ":");
				foreach(var line in solution)
					result.AppendLine(line);
			}

			File.WriteAllText(Path.ChangeExtension(inputFile, ".out"), result.ToString());

#if DEBUG
			Console.WriteLine("Done");
			Console.ReadKey();
#endif
		}

		private static readonly int[] TargetedDivisors =
		{
			0, //0
			0, //1
			3, //2
			2, //3
			3, //4
			2, //5
			7, //6
			2, //7
			3, //8
			2, //9
			3, //10
		};

		private static List<string> Solve(int numberOfDigits, int numberOfSolutions)
		{
			//algorithm based on the assumption that N is somewhat a large number (e.g. 16 or 32 :)) and only a small number of all solutions are needed.
			//we pick solutions that we know are going to be good without the need to check them and we do this using the following approach:
			//  1. sum of 1s should be divisible by 6 because:
			//		1a. sum of 1s should be even -> guarantees that numbers for the odd bases (3, 5, 7, 9) are divisible by 2
			//		1b. sum of 1s should be divisible by 3 -> guarantees that the numbers for bases 4 and 10 are divisible by 3
			//  2. (sum of 1s with odd indexes) + 2x(sum of 1s with even indexes) should be divisible by 3 -> guarantees that the numbers for bases 2 and 8 are divisible by 3
			//  3. (sum of 1s with odd indexes) and (sum of 1s with even indexes) should be the same -> guarantees that the base 6 number is divisible by 7

			var result = new List<string>();
			
			var middleBitsWith4Set = 0xFl; //+ first and last bits = 6 bits set total -> #1 is achieved!
			var middleBitsShouldBeLessThan = (((long)1) << (numberOfDigits - 2));
			var leftBit = (((long) 1) << (numberOfDigits - 1));

			int cnt = 0;
			while (result.Count < numberOfSolutions)
			{
				cnt++;

				var number =
					leftBit + 
					(middleBitsWith4Set << 1) + //middle bits
					1;

				//count the bits
				var evenBitsSet = 0;
				var oddBitsSet = 0;
				var tmp = number;
				var odd = true;
				while (tmp > 0)
				{
					if ((tmp & 1) == 1)
					{
						if (odd)
							oddBitsSet++;
						else
							evenBitsSet++;
					}

					tmp = tmp >> 1;
					odd = !odd;
				}
				var totalBitsSet = oddBitsSet + evenBitsSet;
				Debug.Assert(totalBitsSet == 6);

				if ((oddBitsSet + 2*evenBitsSet)%3 == 0)
				{
					if (oddBitsSet == evenBitsSet)
					{
						var solution = GetBinaryString(number, numberOfDigits);

#if DEBUG
						//verification - not needed (just a validation of our logic)
						for (var numberBase = 2; numberBase < TargetedDivisors.Length; numberBase++)
							Verify(solution, numberBase, TargetedDivisors[numberBase]);
#endif

						var solutionLine = solution + " " + string.Join(" ", TargetedDivisors.Skip(2).Select(d => d.ToString(NumberFormatInfo.InvariantInfo)));
						Console.WriteLine(cnt + " - " + solutionLine);

						result.Add(solutionLine);
					}
				}

				middleBitsWith4Set = GetNextCombination(middleBitsWith4Set); //prepare for next iteration
				if (middleBitsWith4Set >= middleBitsShouldBeLessThan)
				{
					//failure to generate needed number of solutions
					throw new Exception();
				}
			}

			return result;
		}

		private static string GetBinaryString(long number, int numberOfDigits)
		{
			return string.Join("", Enumerable.Range(0, numberOfDigits).Select(bix => (number & (((long) 1) << bix)) == 0 ? 0 : 1).Reverse().Select(b => b.ToString(NumberFormatInfo.InvariantInfo)));
		}

		private static long GetNextCombination(long x)
		{
			//adapted from here (tested - seems to work): http://www.geeksforgeeks.org/next-higher-number-with-same-number-of-set-bits/

			long next = 0;
			if (x > 0)
			{
				var rightOne = x & (-x);
				var nextHigherOneBit = x + rightOne;
				var rightOnesPattern = x ^ nextHigherOneBit;
				rightOnesPattern = (rightOnesPattern) / rightOne;
				rightOnesPattern >>= 2;
				next = nextHigherOneBit | rightOnesPattern;
			}

			return next;
		}

#if DEBUG
		//verification - not needed (just a validation of our logic)
		public static void Verify(string valueAsString, int numberBase, int divisor)
		{
			var number = new BigInteger(0);
			var digitValue = new BigInteger(1);
			for (var i = 0; i < valueAsString.Length; i++)
			{
				if (valueAsString[valueAsString.Length - 1 - i] == '1')
					number = number + digitValue;
				digitValue *= numberBase;
			}

			if (number % divisor != 0)
				throw new InvalidOperationException();
		}
#endif
	}
}
