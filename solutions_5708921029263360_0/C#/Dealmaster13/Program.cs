using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ20161C
{
	public class Program
	{
		public static void Main(string[] args)
		{
			string[] input = File.ReadAllLines(@"input.in");
			File.WriteAllLines(@"../../lib/output.out", ProblemC(input));
			Console.ReadKey();
		}

		public static string[] ProblemC(string[] input)
		{
			int t = int.Parse(input[0]);
			string[] output = new string[t];
			for (int i = 1; i <= t; i++)
			{
				output[i - 1] = $"Case #{i}: {ProblemC(input[i])}";
				Console.WriteLine(output[i - 1]);
			}

			return output;
		}

		public static string ProblemC(string input)
		{
			string[] vs = input.Split(' ');
			int j = int.Parse(vs[0]);
			int p = int.Parse(vs[1]);
			int s = int.Parse(vs[2]);
			int k = int.Parse(vs[3]);

			var combs = ProblemCGetCombs(j, p, s);

			List<string> output = new List<string>();
			List<Tuple<int, int, int>> jp;
			List<Tuple<int, int, int>> js;
			List<Tuple<int, int, int>> ps;

			ProblemCInit(j, p, s, out jp, out js, out ps);

			List<Tuple<int, int, int>> hist = new List<Tuple<int, int, int>>();
			string nextComb = ProblemCNextComb(combs, hist, jp, js, ps, k);
			while (nextComb != null)
			{
				output.Add(nextComb);
				nextComb = ProblemCNextComb(combs, hist, jp, js, ps, k);
			}

			return $"{output.Count}\n{string.Join("\n", output)}";
		}

		public static List<Tuple<int, int, int>> ProblemCGetCombs(int j, int p, int s)
		{
			List<Tuple<int, int, int>> combs = new List<Tuple<int, int, int>>();
			for (int ji = 1; ji <= j; ji++)
			{
				for (int pi = 1; pi <= p; pi++)
				{
					for (int si = 1; si <= s; si++)
					{
						combs.Add(new Tuple<int, int, int>(ji, pi, si));
					}
				}
			}

			return combs;
		}

		public static string ProblemCNextComb(List<Tuple<int, int, int>> combs, List<Tuple<int, int, int>> hist, List<Tuple<int, int, int>> jp, List<Tuple<int, int, int>> js, List<Tuple<int, int, int>> ps, int k)
		{
			for (int i = 0; i < combs.Count; i++)
			{
				if (!ProblemCInHist(combs[i], hist) && ProblemCCombAllowed(combs[i], jp, js, ps, k))
				{
					int j = combs[i].Item1;
					int p = combs[i].Item2;
					int s = combs[i].Item3;

					var x = jp.First(a => a.Item1 == j && a.Item2 == p);
					jp.Add(new Tuple<int, int, int>(j, p, x.Item3 + 1));
					jp.Remove(x);

					var y = js.First(a => a.Item1 == j && a.Item2 == s);
					js.Add(new Tuple<int, int, int>(j, s, y.Item3 + 1));
					js.Remove(y);

					var z = ps.First(a => a.Item1 == p && a.Item2 == s);
					ps.Add(new Tuple<int, int, int>(p, s, z.Item3 + 1));
					ps.Remove(z);

					hist.Add(new Tuple<int, int, int>(j, p, s));

					return $"{j} {p} {s}";
				}
			}

			return null;
		}

		public static bool ProblemCInHist(Tuple<int, int, int> comb, List<Tuple<int, int, int>> hist)
		{
			return hist.Any(h => h.Item1 == comb.Item1 && h.Item2 == comb.Item2 && h.Item3 == comb.Item3);
		}

		public static bool ProblemCCombAllowed(Tuple<int, int, int> comb, List<Tuple<int, int, int>> jp, List<Tuple<int, int, int>> js, List<Tuple<int, int, int>> ps, int k)
		{
			int j = comb.Item1;
			int p = comb.Item2;
			int s = comb.Item3;

			var x = jp.First(a => a.Item1 == j && a.Item2 == p);
			if (x.Item3 >= k)
			{
				return false;
			}

			var y = js.First(a => a.Item1 == j && a.Item2 == s);
			if (y.Item3 >= k)
			{
				return false;
			}


			var z = ps.First(a => a.Item1 == p && a.Item2 == s);
			if (z.Item3 >= k)
			{
				return false;
			}

			return true;
		}

		public static void ProblemCInit(int j, int p, int s, out List<Tuple<int, int, int>> jp, out List<Tuple<int, int, int>> js, out List<Tuple<int, int, int>> ps)
		{
			List<Tuple<int, int, int>> x = new List<Tuple<int, int, int>>();
			List<Tuple<int, int, int>> y = new List<Tuple<int, int, int>>();
			List<Tuple<int, int, int>> z = new List<Tuple<int, int, int>>();

			for (int a = 0; a < j; a++)
			{
				for (int b = 0; b < p; b++)
				{
					x.Add(new Tuple<int, int, int>(a + 1, b + 1, 0));
				}
			}

			for (int a = 0; a < j; a++)
			{
				for (int b = 0; b < s; b++)
				{
					y.Add(new Tuple<int, int, int>(a + 1, b + 1, 0));
				}
			}

			for (int a = 0; a < p; a++)
			{
				for (int b = 0; b < s; b++)
				{
					z.Add(new Tuple<int, int, int>(a + 1, b + 1, 0));
				}
			}

			jp = x;
			js = y;
			ps = z;
		}





























































		public static string[] ProblemB(string[] input)
		{
			int t = int.Parse(input[0]);
			string[] output = new string[t];
			for (int i = 1; i <= t; i++)
			{
				output[i - 1] = $"Case #{i}: {ProblemB(input[i])}";
				Console.WriteLine(output[i - 1]);
			}

			return output;
		}

		public static string ProblemB(string input)
		{
			string[] vs = input.Split(' ');
			int b = int.Parse(vs[0]);
			long m = long.Parse(vs[1]);

			long maxM = ProblemBGetMaxM(b);

			if (m > maxM)
			{
				return "IMPOSSIBLE";
			}

			List<string> output = new List<string>();
			output.Add("POSSIBLE");

			var slides = ProblemBGetAllSlides(b);

			for (int i = 0; i < b - 2; i++)
			{
				if (m == 0 || (((maxM - m) >> i) & 1L) == 1)
				{
					ProblemBRemoveSlide(slides, 1, (b - i - 1));
				}
			}

			if (m == 0)
			{
				ProblemBRemoveSlide(slides, 1, b);
			}

			output.AddRange(ProblemBPrintSlides(b, slides));

			return $"{string.Join("\n", output)}";
		}

		public static long ProblemBGetMaxM(int b)
		{
			return 1 << (b - 2);
		}

		public static List<Tuple<int, int>> ProblemBGetAllSlides(int b)
		{
			List<Tuple<int, int>> result = new List<Tuple<int, int>>();

			for (int i = 1; i < b; i++)
			{
				for (int j = i + 1; j <= b; j++)
				{
					result.Add(new Tuple<int, int>(i, j));
				}
			}

			return result;
		}

		public static void ProblemBRemoveSlide(List<Tuple<int, int>> slides, int i, int j)
		{
			var v = slides.FirstOrDefault(s => s.Item1 == i && s.Item2 == j);
			if (v == null)
			{
				Console.WriteLine("oops");
				return;
			}

			slides.Remove(v);
		}

		public static List<string> ProblemBPrintSlides(int b, List<Tuple<int, int>> slides)
		{
			List<string> result = new List<string>();

			for (int i = 1; i <= b; i++)
			{
				string r = "";
				for (int j = 1; j <= b; j++)
				{
					r += slides.Any(s => s.Item1 == i && s.Item2 == j) ? "1" : "0";
				}

				result.Add(r);
			}

			return result;
		}












































































		public static string[] ProblemA(string[] input)
		{
			int t = int.Parse(input[0]);
			string[] output = new string[t];
			for (int i = 1; i <= t; i++)
			{
				output[i - 1] = $"Case #{i}: {ProblemA(input[(i * 2) - 1], input[i * 2])}";
				Console.WriteLine(output[i - 1]);
			}

			return output;
		}

		public static string ProblemA(string n, string input)
		{
			string[] ns = input.Split(' ');
			int[] pi = new int[ns.Length];

			for (int i = 0; i < ns.Length; i++)
			{
				pi[i] = int.Parse(ns[i]);
			}

			int min;
			int[] excess = ProblemAExcess(pi, out min);

			List<char> result = new List<char>();

			int pos = ProblemAGetMax(excess);
			while (pos > -1)
			{
				result.Add(ProblemAGetChar(pos));
				excess[pos]--;
				pos = ProblemAGetMax(excess);
			}

			for (int i = 0; i < min; i++)
			{
				for (int j = 0; j < ns.Length; j++)
				{
					result.Add(ProblemAGetChar(j));
				}
			}

			string output = "";

			for (int i = 0; i < result.Count; i++)
			{
				output += result[i];
				if (i <= result.Count - 3)
				{
					if (i % 2 != result.Count % 2)
					{
						output += " ";
					}
				}
			}

			return $"{output}";
		}

		public static int[] ProblemAExcess(int[] pi, out int min)
		{
			int[] result = new int[pi.Length];

			min = int.MaxValue;

			for (int i = 0; i < pi.Length; i++)
			{
				if (min > pi[i])
				{
					min = pi[i];
				}
			}

			for (int i = 0; i < pi.Length; i++)
			{
				result[i] = pi[i] - min;
			}

			return result;
		}

		public static int ProblemAGetMax(int[] excess)
		{
			int pos = -1;
			int max = int.MinValue;

			for (int i = 0; i < excess.Length; i++)
			{
				if (excess[i] > max && excess[i] > 0)
				{
					pos = i;
					max = excess[i];
				}
			}

			return pos;
		}

		public static char ProblemAGetChar(int i)
		{
			return (char)(i + (int)'A');
		}
	}
}
