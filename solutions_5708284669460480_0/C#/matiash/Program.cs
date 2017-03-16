using GoogleCodeJam.Common;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TypewriterMonkey
{
	class Program
	{
		static void Main(string[] args)
		{
			InputFile input = new InputFile("B-small-attempt1.in");
			OutputFile output = new OutputFile("output.txt");

			int[] values = input.ReadIntArray();
			int TEST_COUNT = values[0];

			for (int i = 0; i < TEST_COUNT; i++)
			{
				TestCase testCase = new TestCase(input);
				output.WriteCase(i + 1, String.Format("{0:0.0000000}", testCase.GetSolutionExhaustive()));
			}

			output.Close();
		}
	}

	class TestCase
	{
		private readonly int m_OutputSize;
		private readonly string m_Keys;
		private readonly string m_TargetWord;

		public TestCase(InputFile input)
		{
			int[] parameters = input.ReadIntArray();
			m_OutputSize = parameters[2];
			m_Keys = input.ReadLine();
			m_TargetWord = input.ReadLine();
		}

		public double GetSolutionExhaustive()
		{
			const double THRESHOLD = 0.0000000000001f;

			// Special cases
			// 1) Have all necessary keys? If not, no need to bring bananas; none kept.
			List<char> distinctKeys = m_Keys.Distinct().ToList();
			List<char> neededKeys = m_TargetWord.Distinct().ToList();
			if (distinctKeys.Intersect(neededKeys).Count() != neededKeys.Count())
				return 0f; // 

			// 2) All keys are valid. All bananas are used.
			if (distinctKeys.Count() == 1)
				return 0f;

			// First step: See if words can overlap.
			int minOverlap = 0;
			int maxOverlap = 0;
			for (int i = 1; i < m_TargetWord.Length; i++)
			{
				if (m_TargetWord.EndsWith(m_TargetWord.Substring(0, i)))
				{
					if (minOverlap == 0)
						minOverlap = i;
					maxOverlap = i;
				}
			}

			// First find out max number of bananas.
			int nonOverlappingLength = m_TargetWord.Length - maxOverlap;
			double maxBananas = 1 + Math.Truncate((double)(m_OutputSize - m_TargetWord.Length) / (double)nonOverlappingLength);

			// See probabilities for each key.
			SortedDictionary<char, double> keyProbabilities = new SortedDictionary<char, double>();
			foreach (char key in distinctKeys)
				keyProbabilities.Add(key, (double)m_Keys.Count(k => k == key) / (double)m_Keys.Length);

			// Probability of typing word completely.
			double fullWordChance = 1f;
			foreach (char c in m_TargetWord)
				fullWordChance *= keyProbabilities[c];

			if (fullWordChance < THRESHOLD)
				return maxBananas;

			// Get all possible output strings.
			long numberOfPossibleOutputs = (long)Math.Pow(m_Keys.Length, m_OutputSize);
			long foundWords = 0;
			for (long pos = 0; pos < numberOfPossibleOutputs; pos++)
			{
				StringBuilder builder = new StringBuilder(m_OutputSize);
				long temp = pos;
				for (int i = 0; i < m_OutputSize; i++)
				{
					if (i != 0)
						temp = temp / m_Keys.Length;

					long whichKey = temp % m_Keys.Length;
					builder.Append(m_Keys[(int)whichKey]);
				}

				// Count the number of successes.
				String output = builder.ToString();
//				Console.WriteLine(output);
				for (int j = 0; j < m_OutputSize - m_TargetWord.Length + 1; j++)
				{
					if (output.Substring(j, m_TargetWord.Length) == m_TargetWord)
						foundWords++;
				}
			}

			return maxBananas - (double)foundWords / (double)numberOfPossibleOutputs;
		}


		/*
		public double GetSolutionBySimulating()
		{
			const int SIMULATIONS = 10000000;

			// Special cases
			// 1) Have all necessary keys? If not, no need to bring bananas; none kept.
			List<char> distinctKeys = m_Keys.Distinct().ToList();
			List<char> neededKeys = m_TargetWord.Distinct().ToList();
			if (distinctKeys.Intersect(neededKeys).Count() != neededKeys.Count())
				return 0f; // 

			// 2) All keys are valid. All bananas are used.
			if (distinctKeys.Count() == 1)
				return 0f;

			// First step: See if words can overlap.
			int minOverlap = 0;
			int maxOverlap = 0;
			for (int i = 1; i < m_TargetWord.Length; i++)
			{
				if (m_TargetWord.EndsWith(m_TargetWord.Substring(0, i)))
				{
					if (minOverlap == 0)
						minOverlap = i;
					maxOverlap = i;
				}
			}

			// First find out max number of bananas.
			int nonOverlappingLength = m_TargetWord.Length - maxOverlap;
			double maxBananas = Math.Truncate(m_OutputSize / (double)nonOverlappingLength);

			long successes = 0;
			Random random = new Random();
			for (int i = 0; i < SIMULATIONS; i++)
			{
				StringBuilder result = new StringBuilder(m_OutputSize);
				for (int j = 0; j < m_OutputSize; j++)
					result.Append(m_Keys[random.Next(m_Keys.Length)]);

				// Count the number of successes.
				String output = result.ToString();
				for (int j = 0; j < m_OutputSize - m_TargetWord.Length + 1; j++)
				{
					if (output.Substring(j, m_TargetWord.Length) == m_TargetWord)
						successes++;
				}
			}

			return maxBananas - ((double)successes / (double)SIMULATIONS);
		}
		*/

		/*
		public double GetSolution()
		{
			// Special cases
			// 1) Have all necessary keys? If not, no need to bring bananas; none kept.
			List<char> distinctKeys = m_Keys.Distinct().ToList();
			List<char> neededKeys = m_TargetWord.Distinct().ToList();
			if (distinctKeys.Intersect(neededKeys).Count() != neededKeys.Count())
				return 0f; // 

			// 2) All keys are valid. All bananas are used.
			if (distinctKeys.Count() == 1)
				return 0f;

			// First step: See if words can overlap.
			int minOverlap = 0;
			int maxOverlap = 0;
			for (int i = 1; i < m_TargetWord.Length; i++)
			{
				if (m_TargetWord.EndsWith(m_TargetWord.Substring(0, i)))
				{
					if (minOverlap == 0)
						minOverlap = i;
					maxOverlap = i;
				}
			}

			// First find out max number of bananas.
			int nonOverlappingLength = m_TargetWord.Length - maxOverlap;
			double maxBananas = Math.Truncate(m_OutputSize / (double)nonOverlappingLength);

			// See probabilities for each key.
			SortedDictionary<char, double> keyProbabilities = new SortedDictionary<char, double>();
			foreach (char key in distinctKeys)
				keyProbabilities.Add(key, (double)m_Keys.Count(k => k == key) / (double)m_Keys.Length);

			// Probability of typing word completely.
			double fullWordChance = 1f;
			foreach (char c in m_TargetWord)
				fullWordChance *= keyProbabilities[c];

			double expectedSuccess;

			if (maxOverlap != 0)
			{
				double baseExpectedSuccess = fullWordChance * (m_OutputSize / m_TargetWord.Length);
				expectedSuccess = baseExpectedSuccess;

				string overlappedWord = m_TargetWord + m_TargetWord.Substring(0, minOverlap);
				double overlappedWordChance = 1f;
				foreach (char c in overlappedWord)
					overlappedWordChance *= keyProbabilities[c];

				double overlappedSuccess = overlappedWordChance * (m_OutputSize / m_TargetWord.Length) * 2f;

				double a1 = overlappedWordChance;
			}
			else
			{
				// Easy case.
				expectedSuccess = fullWordChance * (m_OutputSize / m_TargetWord.Length);
			}
	
			return maxBananas - expectedSuccess;
		}
		 */ 
	}
}
