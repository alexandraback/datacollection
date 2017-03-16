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
			var x = cin.NextInt();
			var r = cin.NextInt();
			var c = cin.NextInt();
			const string richard = "RICHARD";
			if (x >= 7)
			{
				Console.WriteLine(richard);
				return;
			}
			if (Math.Max(r, c) < x)
			{
				Console.WriteLine(richard);
				return;
			}
			if ((r*c)%x != 0)
			{
				Console.WriteLine(richard);
				return;
			}
			if (r > c)
			{
				var temp = r;
				r = c;
				c = temp;
			}
			// r <= c
			var len = x + 1;
			for (var i = 1; i <= x; i++)
			{
				var p1 = len - i;
				var p2 = len - p1;
				if (Math.Min(p1, p2) > r)
				{
					Console.WriteLine(richard);
					return;
				}
				if (Math.Max(p1, p2) > c)
				{
					Console.WriteLine(richard);
					return;
				}
			}
			if ((x == 4 || x == 5) && r <= 2)
			{
				Console.WriteLine(richard);
				return;
			}
			if (x == 6 && r <= 3)
			{
				Console.WriteLine(richard);
				return;
			}
			Console.WriteLine("GABRIEL");
		}

	}
	internal class Scanner
	{
		private string[] s = new string[0];
		private int i;
		private readonly char[] cs = { ' ' };

		public string NextString()
		{
			if (i < s.Length) return s[i++];
			var line = Console.ReadLine() ?? string.Empty;
			if (line == string.Empty)
			{
				return NextString();
			}
			s = line.Split(cs, StringSplitOptions.RemoveEmptyEntries);
			i = 1;
			return s.First();
		}

		public double NextDouble()
		{
			return double.Parse(NextString());
		}

		public int NextInt()
		{
			return int.Parse(NextString());
		}

		public long NextLong()
		{
			return long.Parse(NextString());
		}
	}
}