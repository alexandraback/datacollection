using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Round1A
{
	class Program
	{
		static void Main(string[] args)
		{
			TextReader tr = new StreamReader("input.in");
			TextWriter tw = new StreamWriter("output.out");
			int N = int.Parse(tr.ReadLine());
			for (int t = 1; t <= N; t++)
			{
				int count = int.Parse(tr.ReadLine());
				List<Level> levels = new List<Level>();
				for (int i = 0; i < count; i++)
				{
					int[] values = tr.ReadLine().Split(' ').Select(ch => int.Parse(ch)).ToArray();
					levels.Add(new Level(values[0], values[1]));
				}
				int res = Solve(levels);
				tw.WriteLine(string.Format("Case #{0}: {1}", t, res == -1 ? "Too Bad" : res.ToString()));
			}
			tw.Close();
			tr.Close();
		}

		private static int Solve(List<Level> levels)
		{
			int stars = 0;
			int moves = 0;

			while (levels.Any())
			{
				moves++;
				Level level = levels.FirstOrDefault(l => l.TwoStar <= stars);
				if (level != null)
				{
					stars += level.RemainStars;
					levels.Remove(level);
					continue;
				}

				level = levels.Where(l => l.OneStar <= stars && l.RemainStars == 2).OrderByDescending(l => l.TwoStar).FirstOrDefault();
				if (level != null)
				{
					level.RemainStars = 1;
					stars += 1;
					continue;
				}
				else
					return -1;
			}
			return moves;
		}

		class Level
		{
			public int OneStar { get; set; }
			public int TwoStar { get; set; }

			public int RemainStars { get; set; }

			public Level(int oneStar, int twoStar)
			{
				OneStar = oneStar;
				TwoStar = twoStar;
				RemainStars = 2;
			}
		}
	}
}
