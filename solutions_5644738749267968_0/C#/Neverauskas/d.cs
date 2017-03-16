using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
	internal class Template
	{
		private static readonly Scanner cin = new Scanner();
		private const string fileName = "D-small-attempt0";

		private static void Main()
		{
			Console.SetIn(new StreamReader(string.Format(@"C:\GoogleCodeJam\{0}.in", fileName)));
			Console.SetOut(new StreamWriter(string.Format(@"C:\GoogleCodeJam\{0}.out", fileName)) { AutoFlush = true });
			var t = cin.NextInt();
			for (var c = 1; c <= t; c++)
			{
				Console.Write("Case #{0}: ", c);
				Solve();
			}
		}

		private static void Solve()
		{
			var cnt = cin.NextInt();
			var naomi = new List<double>();
			for (var i = 0; i < cnt; i++)
			{
				naomi.Add(cin.NextDouble());
			}
			naomi.Sort();
			var ken = new List<double?>();
			for (var i = 0; i < cnt; i++)
			{
				ken.Add(cin.NextDouble());
			}
			ken.Sort();
			var score = 0;
			for (var i = 0; i < cnt; i++)
			{
				if (naomi[i] > ken[score])
				{
					score++;
				}
			}
			Console.Write(score);
			score = 0;
			for (var i = 0; i < cnt; i++)
			{
				var value = naomi[i];
				var smallestWeight = 1d;
				var smallestIdx = -1;
				var hevierWeight = 1d;
				var hevierIdx = -1;
				for (var j = 0; j < cnt; j++)
				{
					if (ken[j] == null)
					{
						continue;
					}
					var val = ken[j].Value;
					if (val > value && val < hevierWeight)
					{
						hevierWeight = val;
						hevierIdx = j;
					}
					else if (val < value && val < smallestWeight)
					{
						smallestWeight = val;
						smallestIdx = j;
					}
				}
				if (hevierIdx != -1)
				{
					ken[hevierIdx] = null;
				}
				else if (smallestIdx != -1)
				{
					ken[smallestIdx] = null;
					score++;
				}
			}
			Console.WriteLine(" " + score);
		}
	}

	internal class Scanner
	{
		private string[] s = new string[0];
		private int i;
		private readonly char[] cs = { ' ' };

		public string Next()
		{
			if (i < s.Length) return s[i++];
			var line = Console.ReadLine() ?? string.Empty;
			if (line == string.Empty)
			{
				return Next();
			}
			s = line.Split(cs, StringSplitOptions.RemoveEmptyEntries);
			i = 1;
			return s.First();
		}

		public double NextDouble()
		{
			return double.Parse(Next());
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