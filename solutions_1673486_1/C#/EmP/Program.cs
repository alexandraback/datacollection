using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace Password_Problem
{
	class Program
	{
		const int EnterCost = 1;
		const int BackspaceCost = 1;

		static void Main(string[] args)
		{
			Input input = new Input(new StreamReader(args[0]));
			TextWriter output = new StreamWriter("output.txt");
			int CasesCount = input.NextInt();

			for (int tCase = 1; tCase <= CasesCount; tCase++) {
				int alreadyTyped = input.NextInt();
				int totalLength = input.NextInt();

				Queue<double> probabilities = new Queue<double>();
				for (int i = 0; i < alreadyTyped; i++)
					probabilities.Enqueue(input.NextDouble());

				double lowestExpectation = EnterCost + totalLength + EnterCost;

				double p = 1;
				for (int backspaces = alreadyTyped; backspaces >= 0; backspaces--) {
					double cost = p * (totalLength - alreadyTyped + 2 * backspaces + EnterCost) +
						(1 - p) * (2 * totalLength - alreadyTyped + 2 * backspaces + 2 * EnterCost);

					lowestExpectation = Math.Min(lowestExpectation, cost);
					if (probabilities.Count > 0)
						p *= probabilities.Dequeue();
				}

				output.WriteLine("Case #{0}: {1}", tCase, lowestExpectation.ToString("0.000000", input.numberForamt));
			}

			output.Close();
		}
	}

	class Input
	{
		TextReader inputStream = null;
		Queue<string> currentLine = new Queue<string>();
		public NumberFormatInfo numberForamt;

		#region Constructors
		public Input(TextReader inputStream)
		{
			this.inputStream = inputStream;

			numberForamt = new NumberFormatInfo();
			numberForamt.NumberDecimalSeparator = ".";
		}

		public Input()
			: this(Console.In)
		{ }

		public Input(string filename)
			: this(new StreamReader(filename))
		{ }
		#endregion

		public string Next()
		{
			while (currentLine.Count == 0)
				foreach (string word in inputStream.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries))
					currentLine.Enqueue(word);

			return currentLine.Dequeue();
		}

		public double NextDouble()
		{
			return double.Parse(Next(), numberForamt);
		}

		public float NextFloat()
		{
			return float.Parse(Next());
		}

		public int NextInt()
		{
			return int.Parse(Next());
		}

		public long NextLong()
		{
			return long.Parse(Next());
		}
	}
}
