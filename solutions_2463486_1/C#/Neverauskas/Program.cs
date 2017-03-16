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
		private const string fileName = "C-large-1";

		private static List<long> correct = new List<long>(); 

		private static void Main()
		{
			Console.SetIn(new StreamReader(string.Format(@"C:\GoogleCodeJam\{0}.in", fileName)));
			Console.SetOut(new StreamWriter(string.Format(@"C:\GoogleCodeJam\{0}.out", fileName)) { AutoFlush = true });

			for (long i = 1; i <= 1000 * 1000 * 10 * 10; i++)
			{
				if (IsPalindrome(i.ToString()) && IsPalindrome((i * i).ToString()))
				{
					correct.Add(i * i);
					Debug.WriteLine("{0} {1}", i, i * i);
				}
			}

			var t = cin.NextInt();
			for (var c = 1; c <= t; c++)
			{
				Console.Write("Case #{0}: ", c);
				Solve();
			}
		}

		private static bool IsPalindrome(string str)
		{
			for (var i = 0; i < str.Length / 2; i++)
			{
				if (str[i] != str[str.Length - 1 - i])
				{
					return false;
				}
			}
			return true;
		}

		private static void Solve()
		{
			var a = cin.NextLong();
			var b = cin.NextLong();
			var count = 0;
			foreach (var cor in correct)
			{
				if (cor >= a && cor <= b)
				{
					count++;
				}
			}
			Console.WriteLine(count);
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