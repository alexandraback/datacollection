using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;

namespace Test
{
	public class Program
	{
		private static void Main()
		{
			Solve(Console.In, Console.Out);
		}

		private static long Mul(long x, long y)
		{
			return (x * y) % 1000000007;
		}

		private static long Fact(int x)
		{
			long r = 1;

			for (int i = 2; i <= x; i++)
				r = Mul(r, i);

			return r;
		}

		private static long SolveOne(int n, string[] data)
		{
			Dictionary<char, int> inside = new Dictionary<char, int>();
			Dictionary<char, int> same = new Dictionary<char, int>();
			Dictionary<char, char> begin = new Dictionary<char, char>();
			Dictionary<char, char> end = new Dictionary<char, char>();

			for (char c = 'a'; c <= 'z'; c++)
			{
				inside[c] = 0;
				same[c] = 0;
			}

			for (int i = 0; i < n; i++)
			{
				string s = data[i];

				if (s.Length > 1)
				{
					for (int j = s.Length - 1; j > 0; j--)
						if (s[j] == s[j - 1]) s = s.Remove(j, 1);
				}

				for (int j = 1; j < s.Length - 1; j++)
					inside[s[j]]++;

				if (s[0] == s[s.Length - 1])
				{
					if (s.Length > 2)
						return 0;

					same[s[0]]++;
				}
				else
				{
					if (begin.ContainsKey(s[0]) || end.ContainsKey(s[s.Length - 1]))
						return 0;

					begin[s[0]] = s[s.Length - 1];
					end[s[s.Length - 1]] = s[0];
				}
			}

			for (char c = 'a'; c <= 'z'; c++)
			{
				if (begin.ContainsKey(c) && (inside[c] > 0) || end.ContainsKey(c) && (inside[c] > 0) || (same[c] > 0) && (inside[c] > 0) || (inside[c] > 1))
					return 0;

				if (begin.ContainsKey(c) && begin.ContainsKey(begin[c]) && (begin[begin[c]] == c))
					return 0;
			}

			long r = 1;
			int g = 0;

			for (char c = 'a'; c <= 'z'; c++)
			{
				if (!end.ContainsKey(c))
				{
					if (begin.ContainsKey(c))
					{
						if (same[c] > 0)
						{
							r = Mul(r, Fact(same[c]));
							same[c] = 0;
						}

						char curr = c;

						while (begin.ContainsKey(curr))
						{
							curr = begin[curr];

							if (same[curr] > 0)
							{
								r = Mul(r, Fact(same[curr]));
								same[curr] = 0;
							}

							begin.Remove(end[curr]);
							end.Remove(curr);
						}

						g++;
					}
					else if (same[c] > 0)
					{
						r = Mul(r, Fact(same[c]));
						same[c] = 0;
						g++;
					}
				}
			}

			return Mul(r, Fact(g));
		}

		public static void Solve(TextReader input, TextWriter output)
		{
			int t = Convert.ToInt32(input.ReadLine());

			for (int z = 1; z <= t; z++)
			{
				int n = Int32.Parse(input.ReadLine());
				string[] data = input.ReadLine().Split(' ');

				output.WriteLine("Case #{0}: {1}", z, SolveOne(n, data));
			}
		}
	}
}