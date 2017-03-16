using GoogleCodeJam.Common;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace First
{
	class Program
	{
		static void Main(string[] args)
		{
			InputFile input = new InputFile("A-large.in");
			OutputFile output = new OutputFile("output-large.txt");

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
		private readonly string m_OriginalString;

		public TestCase(InputFile input)
		{
			m_OriginalString = input.ReadLine();
		}

		public string GetSolution()
		{
			List<char> remaining = m_OriginalString.ToCharArray().ToList();
			List<int> numbers = new List<int>();

			while (remaining.IndexOf('Z') != -1)
			{
				numbers.Add(0);
				RemoveLetters(remaining, "ZERO");
			}

			while (remaining.IndexOf('W') != -1)
			{
				numbers.Add(2);
				RemoveLetters(remaining, "TWO");
			}

			while (remaining.IndexOf('X') != -1)
			{
				numbers.Add(6);
				RemoveLetters(remaining, "SIX");
			}

			// Remove obvious ones.
			while (remaining.IndexOf('U') != -1)
			{
				numbers.Add(4);
				RemoveLetters(remaining, "FOUR");
			}

			while (remaining.IndexOf('F') != -1)
			{
				numbers.Add(5);
				RemoveLetters(remaining, "FIVE");
			}

			while (remaining.IndexOf('V') != -1)
			{
				numbers.Add(7);
				RemoveLetters(remaining, "SEVEN");
			}

			while (remaining.IndexOf('O') != -1)
			{
				numbers.Add(1);
				RemoveLetters(remaining, "ONE");
			}

			while (remaining.IndexOf('G') != -1)
			{
				numbers.Add(8);
				RemoveLetters(remaining, "EIGHT");
			}

			while (remaining.IndexOf('T') != -1)
			{
				numbers.Add(3);
				RemoveLetters(remaining, "THREE");
			}

			while (remaining.IndexOf('N') != -1)
			{
				numbers.Add(9);
				RemoveLetters(remaining, "NINE");
			}

			if (remaining.Count != 0)
				throw new InvalidOperationException();

			numbers.Sort();
			return String.Join("", numbers.ToArray());
		}

		private void RemoveLetters(List<char> remaining, string toRemove)
		{
			foreach (char c in toRemove)
			{
				if (!remaining.Remove(c))
					throw new InvalidOperationException();
			}
		}
	}



}
