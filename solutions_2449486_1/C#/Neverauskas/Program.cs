using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
	internal class Template
	{
		private static readonly Scanner cin = new Scanner();
		private const string fileName = "B-large";

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
			var h = cin.NextInt();
			var w = cin.NextInt();
			var loan = new int[w,h];
			for (var y = 0; y < h; y++)
			{
				for (var x = 0; x < w; x++)
				{
					var val = cin.NextInt();
					//Debug.WriteLine("{0} {1}: {2}", x, y, val);
					loan[x, y] = val;
				}
			}
			for (var y = 0; y < h; y++)
			{
				for (var x = 0; x < w; x++)
				{
					var value = loan[x, y];
					var wOk = true;
					for (var yy = 0; yy < h; yy++)
					{
						if (loan[x, yy] > value)
						{
							wOk = false;
							break;
						}
					}
					var hOk = true;
					for (var xx = 0; xx < w; xx++)
					{
						if (loan[xx, y] > value)
						{
							hOk = false;
							break;
						}
					}
					if (!wOk && !hOk)
					{
						Console.WriteLine("NO");
						return;
					}
				}
			}
			Console.WriteLine("YES");
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