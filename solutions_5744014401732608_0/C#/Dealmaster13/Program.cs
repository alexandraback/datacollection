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
			File.WriteAllLines(@"../../lib/output.out", ProblemB(input));
			Console.ReadKey();
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
