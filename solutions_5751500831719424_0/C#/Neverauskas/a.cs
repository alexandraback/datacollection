using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace GoogleCodeJam
{
	internal class Template
	{
		private static readonly Scanner cin = new Scanner();
		private const string fileName = "A-small-attempt0 (2)";

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
			var n = cin.NextInt();
			var str = new List<string>();
			for (var i = 0; i < n; i++)
			{
				str.Add(cin.Next());
			}
			var counts = new List<State>[n];
			for (var j = 0; j < n; j++)
			{
				var s = str[j];
				counts[j] = new List<State>();
				var last = '0';
				var cnt = 1;
				for (var i = 0; i < s.Length; i++)
				{
					if (s[i] == last)
					{
						cnt++;
					}
					else
					{
						counts[j].Add(new State { Letter = last, Count = cnt });
						last = s[i];
						cnt = 1;
					}
				}
				if (cnt > 0)
				{
					counts[j].Add(new State { Letter = last, Count = cnt });
				}
			}

			var length = counts[0].Count;
			foreach (var cnt in counts)
			{
				if (cnt.Count != length)
				{
					Console.WriteLine("Fegla Won");
					return;
				}
			}

			for (var i = 0; i < counts.Length; i++)
			{
				for (var j = 0; j < counts[0].Count; j++)
				{
					if (counts[i][j].Letter != counts[0][j].Letter)
					{
						Console.WriteLine("Fegla Won");
						return;
					}
				}
			}

			var result = 0;

			for (var i = 0; i < counts[0].Count; i++)
			{
				var best = int.MaxValue;
				for (var j = 1; j < 110; j++)
				{
					var cnt = 0;
					for (var k = 0; k < n; k++)
					{
						cnt += Math.Abs(counts[k][i].Count - j);
					}
					best = Math.Min(best, cnt);
				}
				result += best;
			}

			Console.WriteLine(result);

			/*var letters = new List<char>();
			var counts = new int[150, 150];
			letters.Add(str[0][0]);
			var idx = 0;
			for (var i = 1; i < str[0].Length; i++)
			{
				if (letters.Last() != str[0][i])
				{
					letters.Add(str[0][i]);
				}
				counts[0, letters.Last()]++;
			}
			for (var i = 1; i < str.Count; i++)
			{
				var lets = new List<char>();
				lets.Add(str[i][0]);

			}*/
		}

	}

	public class State
	{
		public char Letter { get; set; }
		public int Count { get; set; }
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