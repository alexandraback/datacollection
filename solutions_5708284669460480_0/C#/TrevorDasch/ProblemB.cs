using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;

namespace CodeJam.Round1C
{
	public class ProblemB
	{
		public static void Main(string[] args)
		{
			using (var input = new StreamReader(File.OpenRead("../../Input.txt")))
			{
				using (var output = new StreamWriter(File.OpenWrite("../../Output.txt")))
				{
					long cases = long.Parse(input.ReadLine());

					for (long i = 0; i < cases; i++)
					{
						var result = GetResult(input);

						Console.WriteLine("Case #" + (i + 1) + ": " + result);
						output.WriteLine("Case #" + (i + 1) + ": " + result);
					}
				}
			}
		}

		public static string GetResult(StreamReader input)
		{
			string line = input.ReadLine();

			var splits = line.Split(' ');

			int K = int.Parse(splits[0]);
			int L = int.Parse(splits[1]);
			int S = int.Parse(splits[2]);

			string keyboard = input.ReadLine();

			string target = input.ReadLine();

			for (int i = 0; i < target.Length; i++)
			{
				if (keyboard.IndexOf(target[i]) == -1)
				{
					return "0.0";
				}
			}

			int length = target.Length;
			for (int i = 1; i < target.Length; i++)
			{
				bool repeat = true;
				for (int j = 0; j < target.Length - i; j++)
				{
					if (target[j] != target[i + j])
					{
						repeat = false;
						break;
					}
				}
				if (repeat)
				{
					length = i;
					break;
				}
			}

			int count = (S - (target.Length - length)) / length;

			Dictionary<char, int> wc = new Dictionary<char, int>();
			for(int i = 0; i < keyboard.Length; i++)
			{
				if (!wc.ContainsKey(keyboard[i]))
				{
					wc[keyboard[i]] = 0;
				}

				wc[keyboard[i]]++;
			}


			double probabilityAtPointP = 1;

			for (int i = 0; i < target.Length; i++)
			{
				probabilityAtPointP *= wc[target[i]] / (double)keyboard.Length;
			}

			double totalProbabilities = 0;
			for (int i = 1; i < count; i++)
			{
				totalProbabilities += Math.Pow(probabilityAtPointP, count) * count;
			}

			double mostLikelyGiveAway = (count - totalProbabilities);


			double probability = BruteForce(keyboard, string.Empty, S, target) / (double)Math.Pow(keyboard.Length, S);


			double mostLikelyBrute = (count - probability);

			Console.WriteLine(mostLikelyGiveAway + " " + mostLikelyBrute);
			return mostLikelyBrute.ToString();

			//return mostLikelyGiveAway.ToString();
		}

		public static int BruteForce(string keyboard, string word, int S, string target)
		{
			if (word.Length == S)
			{
				int start = 0;
				int count = 0;
				while ((start = word.IndexOf(target, start) + 1) > 0)
				{
					count++;
				}
				return count;
			}

			int total = 0;
			for (int i = 0; i < keyboard.Length; i++)
			{
				total += BruteForce(keyboard, word + keyboard[i], S, target);
			}
			return total;
		}
	}
}

