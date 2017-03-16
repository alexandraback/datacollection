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
		private const string fileName = "B-small-attempt0 (2)";

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
			var b = cin.NextInt();
			var k = cin.NextInt();
			var result = 0L;
			for (var i = 0; i < a; i++)
			{
				for (var j = 0; j < b; j++)
				{
					for (var m = 0; m < k; m++)
					{
						if ((i & j) == m)
						{
							result++;
						}
					}
				}
			}
			Console.WriteLine(result);
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