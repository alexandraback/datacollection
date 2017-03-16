using System;
using System.Linq;
using System.IO;
using System.Collections.Generic;

namespace _16QA
{
	class Program
	{
		private static bool DEBUG = false;
		static void debug()
		{
		}

		static string solveCase()
		{
			string s = read();
			Dictionary<char, int> cts = new Dictionary<char, int>();


			foreach (char c in "ONETWOTHREEFOURFIVESIXSEVENEIGHTNINEZERO".Distinct())
			{
				cts[c] = 0;
			}

			foreach (char c in s)
			{
				cts[c]++;
			}

			string[] vals = new[] { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

			List<int> result = new List<int>();
			foreach (int i in new[] { 6, 8, 7, 5, 0, 2, 4, 9, 3, 1})
			{
				while (vals[i].All(d => cts[d] >= vals[i].Count(r => r == d)))
				{
					result.Add(i);
					foreach (char x in vals[i])
					{
						cts[x]--;
					}
				}
			}
			if (cts.Values.Any(x => x != 0))
				Console.WriteLine();
			return new string(result.OrderBy(x => x).Select(x => x.ToString()).SelectMany(x => x).ToArray());
		}

		static void Main(string[] args)
		{
			if (DEBUG)
			{
				debug();
			}
			else
			{
				Initialize();
				SolveAll(solveCase);
			}
			Console.ReadKey();
		}

		private static StreamReader inf;
		private static StreamWriter outf;

		private delegate void o(string format, params object[] args);
		private static o Output;

		private static T read<T>()
		{
			return (T)Convert.ChangeType(inf.ReadLine(), typeof(T));
		}

		private static string read()
		{
			return inf.ReadLine();
		}

		private static T[] readMany<T>()
		{
			return readMany<T>(' ');
		}

		private static _[] readMany<_>(params char[] ___)
		{
			return read().Split(___).Select(__ => (_)Convert.ChangeType(__, typeof(_))).ToArray();
		}

		private static string[] readMany()
		{
			return readMany<string>();
		}

		private static T[][] readField<T>(int height, Func<char, T> map)
		{
			T[][] res = new T[height][];
			for (int _ = 0; _ < height; _++)
			{
				res[_] = read().Select(c => map(c)).ToArray();
			}
			return res;
		}

		private static char[][] readField(int height)
		{
			return readField(height, c => c);
		}

		private static T[][] readField<T>(int height, Dictionary<char, T> dic)
		{
			return readField(height, c => dic[c]);
		}


		static Func<T1, TResult> DP<T1, TResult>(Func<T1, TResult> f)
		{
			var cache = new Dictionary<Tuple<T1>, TResult>();
			return (t1) =>
			{
				var key = Tuple.Create(t1);
				if (!cache.ContainsKey(key))
					cache.Add(key, f(t1));
				return cache[key];
			};
		}

		static Func<T1, T2, TResult> DP<T1, T2, TResult>(Func<T1, T2, TResult> f)
		{
			var cache = new Dictionary<Tuple<T1, T2>, TResult>();
			return (t1, t2) =>
			{
				var key = Tuple.Create(t1, t2);
				if (!cache.ContainsKey(key))
					cache.Add(key, f(t1, t2));
				return cache[key];
			};
		}

		static Func<T1, T2, T3, TResult> DP<T1, T2, T3, TResult>(Func<T1, T2, T3, TResult> f)
		{
			var cache = new Dictionary<Tuple<T1, T2, T3>, TResult>();
			return (t1, t2, t3) =>
			{
				var key = Tuple.Create(t1, t2, t3);
				if (!cache.ContainsKey(key))
					cache.Add(key, f(t1, t2, t3));
				return cache[key];
			};
		}


		public static void Initialize()
		{
			Console.ForegroundColor = ConsoleColor.Yellow;
			Console.Write("File name: ");
			string name = Console.ReadLine();
			inf = new StreamReader("D:\\Users\\marku\\Downloads\\" + name + ".in");
			outf = new StreamWriter("D:\\Users\\marku\\Downloads\\" + name + ".out");
			Console.ForegroundColor = ConsoleColor.White;
			Output = highlightedPrint;
			Output += outf.WriteLine;
		}

		private static void highlightedPrint(string format, params object[] args)
		{
			ConsoleColor prev = Console.ForegroundColor;
			Console.ForegroundColor = ConsoleColor.Green;
			Console.WriteLine(format, args);
			Console.ForegroundColor = prev;
		}

		public static void SolveAll(Func<string> calc)
		{
			int cases = int.Parse(inf.ReadLine());
			for (int _ = 1; _ <= cases; _++)
			{
				Output("Case #{0}: {1}", _, calc());
			}
			inf.Close();
			outf.Close();
			Console.ForegroundColor = ConsoleColor.Cyan;
			Console.WriteLine("Eureka!");
		}
	}
}