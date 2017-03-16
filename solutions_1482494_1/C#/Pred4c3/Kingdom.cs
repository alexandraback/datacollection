using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Round1A
{
	class Kingdom
	{
		static void Main(string[] args)
		{
			var inFileName = args.Length == 0 ? "B-large.in" : args[0];
			var outFileName = inFileName.Replace(".in", "") + ".out";
			using (var reader = new StreamReader(inFileName))
			using (var writer = new StreamWriter(outFileName))
			{
				int numTests = reader.ReadLineAsInt();

				for (int i = 0; i < numTests; i++)
				{
					var numLevels = reader.ReadLineAsInt();
					var comp = new int[numLevels, 2];
					for (int j = 0; j < numLevels; j++)
					{
						var stars = reader.ReadLineAsIntArray();
						comp[j, 0] = stars[0];
						comp[j, 1] = stars[1];
					}
					var result = Solve(i + 1, numLevels, comp);
					writer.WriteLine(result);
					Console.WriteLine(result);
				}
			}
			Console.WriteLine("Done.");
			Console.ReadKey();
		}


		private static string Solve(int testNum, int numLevels, int[,] levelComp)
		{
			int result = 0;

			int currStars = 0;
			int[] levelsProg = new int[numLevels];

			bool progress = true;
			while (progress)
			{
				progress = false;
				for (int i = 0; i < numLevels; i++)
				{
					if (levelsProg[i] == 0 && levelComp[i, 1] <= currStars)
					{
						levelsProg[i] = 2;
						currStars += 2;
						result++;
						i = -1;
					}
				}

				for (int i = 0; i < numLevels; i++)
				{
					if (levelsProg[i] == 1 && levelComp[i, 1] <= currStars)
					{
						levelsProg[i] = 2;
						currStars += 1;
						result++;
						progress = true;
						break;
					}
				}
				if (progress) continue;

				int maxId = -1;
				for (int i = 0; i < numLevels; i++)
				{
					if (levelsProg[i] == 0 && levelComp[i, 0] <= currStars)
					{
						if (maxId == -1 || levelComp[i, 1] > levelComp[maxId, 1])
						{
							maxId = i;
						}
					}
				}
				if (maxId != -1)
				{
					levelsProg[maxId] = 1;
					currStars += 1;
					result++;
					progress = true;
				}
			}

			bool tooBad = levelsProg.Any(n => n != 2);

			return "Case #" + testNum + ": " + (tooBad ? "Too Bad" : result.ToString());
		}
	}
}
