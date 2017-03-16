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
			int n = read<int>();

			string[] firsts = new string[n];
			string[] seconds = new string[n];

			for (int i = 0; i < n; i++)
			{
				var x = readMany();
				firsts[i] = x[0];
				seconds[i] = x[1];
			}

			List<int> remaining = Enumerable.Range(0, n).ToList();
			List<string> novelf = new List<string>();
			List<string> novels = new List<string>();

			for (int i = 0; i < n; i++)
			{
				if (firsts.Count(x => x == firsts[i]) == 1 || seconds.Count(x => x == seconds[i]) == 1)
				{
					remaining.Remove(i);

					novelf.Add(firsts[i]);
					novels.Add(seconds[i]);
				}
			}

			var mf = firsts.Except(novelf).ToList();
			var ms = seconds.Except(novels).ToList();

			try
			{
				while (true)
				{
					var next = remaining.First(x => mf.Contains(firsts[x]) && ms.Contains(seconds[x]));
					mf.Remove(firsts[next]);
					mf.Remove(seconds[next]);
					remaining.Remove(next);
				}
			}
			catch (Exception)
			{

			}
			return (remaining.Count - mf.Count - ms.Count).ToString();
			//int bestfakes = 0;
			//return remaining.Count.ToString();
			//if (remaining.Count == 0)
			//	return "0";
			//foreach (var perm in Permutations(remaining, remaining.Count))
			//{
			//	int fakes = 0;
			//	List<string> fs = new List<string>();
			//	List<string> ss = new List<string>();
			//	foreach (int idx in perm)
			//	{
			//		if (
			//			(novelf.Contains(firsts[idx]) || fs.Contains(firsts[idx])) &&
			//			(novels.Contains(seconds[idx]) || ss.Contains(seconds[idx]))
			//			)
			//		{
			//			fakes++;
			//		}
			//		else
			//		{
			//			fs.Add(firsts[idx]);
			//			ss.Add(seconds[idx]);
			//		}
			//		bestfakes = Math.Max(bestfakes, fakes);
			//	}
			//}
			//return bestfakes.ToString();
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

		static IEnumerable<IEnumerable<T>> Permutations<T>(IEnumerable<T> list, int length)
		{
			if (length == 1) return list.Select(t => new T[] { t });

			return Permutations(list, length - 1)
				.SelectMany(t => list.Where(e => !t.Contains(e)),
					(t1, t2) => t1.Concat(new T[] { t2 }));
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