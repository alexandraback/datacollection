using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
	internal class Template
	{
		private static readonly Scanner cin = new Scanner();
		private const string fileName = "A-small-attempt1";

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
			var a = cin.NextInt();
			var n = cin.NextInt();
			var m = new int[n];
			for (var i = 0; i < m.Length; i++)
			{
				m[i] = cin.NextInt();
			}
			Array.Sort(m);
			var res = 0;
			var best = int.MaxValue;
			for (var i = 0; i < m.Length; i++)
			{
				best = Math.Min(best, m.Length - i + res);
				if (m[i] < a)
				{
					a += m[i];
				}
				else
				{
					res++;
					a += a - 1;
					i--;
				}
				if (res >= m.Length)
				{
					break;
				}
			}
			best = Math.Min(best, res);
			Console.WriteLine(best);
		}
	}

	internal class Scanner
	{
		private string[] s = new string[0];
		private int i;
		private readonly char[] cs = new[] { ' ' };

		public string Next()
		{
			if (i < s.Length) return s[i++];
			var line = Console.ReadLine() ?? string.Empty;
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