using GoogleCodeJam.Common;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CloseMatch
{
	class Program
	{
		static void Main(string[] args)
		{
			InputFile input = new InputFile("B-small-attempt2.in");
			OutputFile output = new OutputFile("output-small.txt");

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
		private readonly string m_FirstScore;
		private readonly string m_SecondScore;

		public TestCase(InputFile input)
		{
			string[] line = input.ReadStringArray();
			m_FirstScore = line[0];
			m_SecondScore = line[1];
		}

		const int EQUAL_SO_FAR = 0;
		const int LEFT_WINNING = 1;
		const int RIGHT_WINNING = 2;

		public string GetSolution()
		{
			char[] leftChars = m_FirstScore.ToCharArray();
			char[] rightChars = m_SecondScore.ToCharArray();

			// Flags
			int state = EQUAL_SO_FAR;

			for (int i = 0; i < leftChars.Length; i++)
			{
				char c = leftChars[i];
				char j = rightChars[i];

				if (c == '?' && j != '?')
				{
					if (state == EQUAL_SO_FAR)
					{
						// Find first
						if (i < leftChars.Length - 1 && leftChars[i + 1] != '?' && rightChars[i + 1] != '?')
						{
							int nextDigitDifference = leftChars[i + 1] - rightChars[i + 1];
							if (nextDigitDifference < -5)
							{
								if (rightChars[i] < '9')
									leftChars[i] = (char)(rightChars[i] + 1);
								else
									leftChars[i] = rightChars[i];
							}
							else if (nextDigitDifference >= 5)
							{
								if (rightChars[i] > '0')
									leftChars[i] = (char)(rightChars[i] - 1);
								else
									leftChars[i] = rightChars[i];
							}
							else
							{
								leftChars[i] = rightChars[i];
							}
						}
						else
						{
							leftChars[i] = rightChars[i];
						}
					}
					else if (state == LEFT_WINNING)
						leftChars[i] = '0';
					else if (state == RIGHT_WINNING)
						leftChars[i] = '9';
				}
				else if (c != '?' && j == '?')
				{
					if (state == EQUAL_SO_FAR)
					{
						// Find first
						if (i < leftChars.Length - 1 && leftChars[i + 1] != '?' && rightChars[i + 1] != '?')
						{
							int nextDigitDifference = leftChars[i + 1] - rightChars[i + 1];
							if (nextDigitDifference > 5)
							{
								if (leftChars[i] < '9')
									rightChars[i] = (char)(leftChars[i] + 1);
								else
									rightChars[i] = leftChars[i];
							}
							else if (nextDigitDifference <= -5)
							{
								if (leftChars[i] > '0')
									rightChars[i] = (char)(leftChars[i] - 1);
								else
									rightChars[i] = leftChars[i];
							}
							else
							{
								rightChars[i] = leftChars[i];
							}
						}
						else
						{
							rightChars[i] = leftChars[i];
						}
					}
					else if (state == LEFT_WINNING)
						rightChars[i] = '9';
					else if (state == RIGHT_WINNING)
						rightChars[i] = '0';
				}
				else if (c == '?' && j == '?')
				{
					if (state == EQUAL_SO_FAR)
					{
						// Find first
						if (i < leftChars.Length - 1 && leftChars[i + 1] != '?' && rightChars[i + 1] != '?')
						{
							int nextDigitDifference = leftChars[i + 1] - rightChars[i + 1];
							if (nextDigitDifference < -5)
							{
								leftChars[i] = '1';
								rightChars[i] = '0';
							}
							else if (nextDigitDifference > 5)
							{
								leftChars[i] = '0';
								rightChars[i] = '1';
							}
							else
							{
								leftChars[i] = '0';
								rightChars[i] = '0';
							}
						}
						else
						{
							leftChars[i] = '0';
							rightChars[i] = '0';
						}
					}
					else if (state == LEFT_WINNING)
					{
						leftChars[i] = '0';
						rightChars[i] = '9'; 
					}
					else if (state == RIGHT_WINNING)
					{
						leftChars[i] = '9';
						rightChars[i] = '0'; 
					}
				}

				if (leftChars[i] == '?' || rightChars[i] == '?')
					throw new InvalidOperationException();

				// update flags for following digits.
				if (state == EQUAL_SO_FAR)
				{
					if (leftChars[i] > rightChars[i])
						state = LEFT_WINNING;
					else if (leftChars[i] < rightChars[i])
						state = RIGHT_WINNING;
				}
			}

			return String.Join("", leftChars) + " " + String.Join("", rightChars);
		}
	}
}
