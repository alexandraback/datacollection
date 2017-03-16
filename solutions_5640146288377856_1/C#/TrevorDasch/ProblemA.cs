using System;
using System.IO;
using System.Linq;

namespace CodeJam.Round1C
{
	public class ProblemA
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

			int R = int.Parse(splits[0]);
			int C = int.Parse(splits[1]);
			int W = int.Parse(splits[2]);

			int result = (R - 1) * MinChecksForMissedRow(C, W) + MinChecksForHitRow(C, W);

			return result.ToString();
		}

		public static int MinChecksForMissedRow(int C, int W)
		{
			// if the ship covers more than half the board
			if (W > C / 2)
			{
				return 1;
			}
				
			//binary search

			return 1 + MinChecksForMissedRow(C - W, W);
		}

		public static int MinChecksForHitRow(int C, int W)
		{
			if (C == W)
			{
				return W;
			}

			if (W > C / 2)
			{
				return 1 + W;
			}

			return 1 + MinChecksForHitRow(C - W, W);
		}
	}
}

