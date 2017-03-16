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

		static void sad1<T>(Dictionary<T, int> dict, T key)
		{
			if (!dict.ContainsKey(key))
				dict[key] = 0;
			dict[key]++;
		}

		static bool legal(IEnumerable<Tuple<int, int, int>> it, int k)
		{
			Dictionary<Tuple<int, int>, int> jp = new Dictionary<Tuple<int, int>, int>(), ps = new Dictionary<Tuple<int, int>, int>(), sj = new Dictionary<Tuple<int, int>, int>();

			foreach (var item in it)
			{
				var ey = Tuple.Create(item.Item1, item.Item2);
				sad1(jp, ey);
				ey = Tuple.Create(item.Item2, item.Item3);
				sad1(ps, ey);
				ey = Tuple.Create(item.Item3, item.Item1);
				sad1(sj, ey);

				if (new[] { jp, ps, sj }.Any(d => d.Values.Any(v => v > k)))
				{
					return false;
				}
			}
			return true;
		}

		static long lp(long a, long b)
		{
			long r = 1;
			for (int i = 0; i < b; i++)
			{
				r *= a;
			}
			return r;
		}



		static string solveCase(int num)
		{
			int[] jpsk = readMany<int>();
			int j = jpsk[0];
			int p = jpsk[1];
			int s = jpsk[2];
			int k = jpsk[3];


			List<Tuple<int, int, int>> pre = new List<Tuple<int, int, int>>();
			HashSet<Tuple<int, int>> jp = new HashSet<Tuple<int, int>>(), ps = new HashSet<Tuple<int, int>>(), sj = new HashSet<Tuple<int, int>>();

			List<Tuple<int, int, int>> post = new List<Tuple<int, int, int>>();

			for (int cj = 1; cj <= j; cj++)
			{
				for (int cp = 1; cp <= p; cp++)
				{
					for (int cs = 1; cs <= s; cs++)
					{
						List<Tuple<int, int, int>> sink;
						if (jp.Contains(Tuple.Create(cj, cp)) || ps.Contains(Tuple.Create(cp, cs)) || sj.Contains(Tuple.Create(cs, cj)))
							sink = post;
						else {
							sink = pre;
							jp.Add(Tuple.Create(cj, cp));
							ps.Add(Tuple.Create(cp, cs));
							sj.Add(Tuple.Create(cs, cj));
						}
						sink.Add(Tuple.Create(cj, cp, cs));
					}
				}
			}

			long max = lp(2, post.Count) - 1;

			List<Tuple<int, int, int>> best = new List<Tuple<int, int, int>>();

			for (long mask = 0; mask <= max; mask++)
			{
				List<Tuple<int, int, int>> cur = new List<Tuple<int, int, int>>(pre);

				for (int i = 0; i < post.Count; i++)
				{
					if ((mask & (1 << i)) != 0)
					{
						cur.Add(post[i]);
					}
				}
				if (cur.Count > best.Count && legal(cur, k))
					best = cur;
			}

			string res = best.Count.ToString();

			foreach (var item in best)
			{
				res += Environment.NewLine + item.Item1 + " " + item.Item2 + " " + item.Item3;
			}

			return res;
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

		public static void SolveAll(Func<int, string> calc)
		{
			int cases = int.Parse(inf.ReadLine());
			for (int _ = 1; _ <= cases; _++)
			{
				Output("Case #{0}: {1}", _, calc(_));
			}
			inf.Close();
			outf.Close();
			Console.ForegroundColor = ConsoleColor.Cyan;
			Console.WriteLine("Eureka!");
		}
	}
}