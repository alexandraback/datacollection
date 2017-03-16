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
		private const string fileName = "C-large";

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
			Console.WriteLine();
			var r = cin.NextInt();
			var c = cin.NextInt();
			var m = cin.NextInt();
			var left = r*c - m;
			if (left == 1)
			{
				for (var i = 0; i < r; i++)
				{
					if (i == 0)
					{
						Console.WriteLine('c' + new string('*', c - 1));
					}
					else
					{
						Console.WriteLine(new string('*', c));
					}
				}
				return;
			}
			if (r == 1)
			{
				Console.WriteLine(new string('*', m) + new string('.', left - 1) + 'c');
				return;
			}
			if (c == 1)
			{
				for (var i = 0; i < m; i++)
				{
					Console.WriteLine('*');
				}
				for (var i = 0; i < left - 1; i++)
				{
					Console.WriteLine('.');
				}
				Console.WriteLine('c');
				return;
			}
			if (left == 2 || left == 3)
			{
				Console.WriteLine("Impossible");
				return;
			}
			if (r == 2 || c == 2)
			{
				if (m%2 != 0)
				{
					Console.WriteLine("Impossible");
					return;
				}
			}
			if (r == 2)
			{
				Console.WriteLine(new string('*', m / 2) + new string('.', left / 2));
				Console.WriteLine(new string('*', m / 2) + new string('.', left / 2 - 1) + 'c');
				return;
			}
			var edge = r*2 + c*2 - 4;
			if (m <= r*c - edge || left%2 == 0)
			{
				var mines = m;
				var array = new char[r, c];
				for (var i = 0; i < r - 2; i++)
				{
					for (var j = 0; j < c - 2; j++)
					{
						if (mines > 0)
						{
							array[i, j] = '*';
							mines--;
						}
					}
				}
				for (var j = 0; j < c - 2; j++)
				{
					for (var i = r - 2; i < r; i++)
					{
						if (mines > 0)
						{
							array[i, j] = '*';
							mines--;
						}
					}
				}
				for (var i = 0; i < r - 2; i++)
				{
					for (var j = c - 2; j < c; j++)
					{
						if (mines > 0)
						{
							array[i, j] = '*';
							mines--;
						}
					}
				}
				for (var i = 0; i < r; i++)
				{
					for (var j = 0; j < c; j++)
					{
						var ch = array[i, j];
						Console.Write(ch == '*' ? '*' : (i == r - 1 && j == c - 1) ? 'c' : '.');
					}
					Console.WriteLine();
				}
				return;
			}
			if (left < 9)
			{
				Console.WriteLine("Impossible");
				return;
			}
			if (Check(r, c, left, false))
			{ }
			else if (Check(c, r, left, true))
			{ }
			else
			{
				Console.WriteLine("Impossible");
			}
		}

		private static bool Check(int r, int c, int left, bool swapped)
		{
			var add = (left - 9) / 2;
			var arr = new char[r, c];
			for (var i = 0; i < r; i++)
			{
				for (var j = 0; j < c; j++)
				{
					arr[i, j] = '*';
				}
			}
			var mid = Math.Min(r / 2, 2);
			for (var i = mid - 1; i <= mid + 1; i++)
			{
				for (var j = c - 3; j < c; j++)
				{
					arr[i, j] = '.';
				}
			}
			var last = c - 1;
			while (add-- > 0)
			{
				var cnt = 0;
				for (var j = c - 1; j >= 0 && cnt != 2; j--)
				{
					for (var i = 0; i < r && cnt != 2; i++)
					{
						if (arr[i, j] == '*')
						{
							if (j == c - 1)
							{
								arr[i, j] = '.';
								arr[i, j - 1] = '.';
								cnt = 2;
							}
							else
							{
								arr[i, j] = '.';
								cnt++;
							}
							last = j;
						}
					}
				}
				Debug.Assert(cnt == 2);
			}
			arr[mid, c - 2] = 'c';
			for (var i = 0; i < r; i++)
			{
				if (arr[i, last] == '*' && i == 1)
				{
					return false;
				}
			}

			if (!swapped)
			{
				for (var i = 0; i < r; i++)
				{
					for (var j = 0; j < c; j++)
					{
						Console.Write(arr[i, j]);
					}
					Console.WriteLine();
				}
			}
			else
			{
				for (var i = 0; i < c; i++)
				{
					for (var j = 0; j < r; j++)
					{
						Console.Write(arr[j, i]);
					}
					Console.WriteLine();
				}
			}
			return true;
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