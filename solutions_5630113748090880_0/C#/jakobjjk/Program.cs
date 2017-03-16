using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Numerics;

namespace GCJ {
	class Program {
		public static object SolveCase(Func<string> rl) {
			int n = int.Parse(rl());
			int[] heights = new int[2501];
			for (int i = 0; i < heights.Length; i++)
				heights[i] = 0;
			for(int i=0; i<(2*n-1); i++) {
				int[] nums = rl().Split(' ').Select(int.Parse).ToArray();
				for (int j = 0; j < nums.Length; j++)
					heights[nums[j]]++;
			}
			List<int> missing = new List<int>();
			for(int i=0; i<heights.Length; i++) {
				if (heights[i] % 2 != 0)
					missing.Add(i);
			}
			missing.Sort();
			string res = missing[0].ToString();
			for (int i = 1; i < missing.Count; i++)
				res += " " + missing[i];
			return res;
		}

		public struct Settings {
			public const bool DEBUG = false;
			public const bool TOCONSOLE = true;
			public const bool EXAMPLE = false;
			public const bool SMALL = true;
			public const char PROBLEM_LETTER = 'B';
			public const int ATTEMPT_NUMBER = 0; // 0 for the first attempt
			public const int NUMBER = 0;
			public const bool PRACTICE = false;
		}

		private static void Debug() {
			Console.ReadKey();
		}

		private static void Main(string[] args) {
			if (Settings.DEBUG) {
				Debug();
			} else {
				Pattern.SolveAll();
			}
			Console.ReadKey();
		}
	}

	static class Pattern {
		public static void SolveAll() {
			using (StreamReader sr = new StreamReader(CreateInfPath()))
			using (StreamWriter sw = new StreamWriter(@"C:\Users\Jakob\Desktop\outf.txt")) {
				int cases = int.Parse(sr.ReadLine());

				DateTime start;
				Console.Title = "Google Code Jam";

				for (int currentCase = 1; currentCase <= cases; currentCase++) {
					start = DateTime.Now;
					object result = Program.SolveCase(sr.ReadLine);
					sw.WriteLine("Case #{0}: {1}", currentCase, result);
					Console.WriteLine("Case {0} / {1} : {2}ms", currentCase, cases, (DateTime.Now - start).TotalMilliseconds);
					if (Program.Settings.TOCONSOLE) {
						Console.WriteLine(result);
					}
				}
			}
			Console.WriteLine("END!");
			Console.Beep(300, 500);
		}
		private static string CreateInfPath() {
			string infPath;
			if (Program.Settings.EXAMPLE)
				infPath = @"C:\Users\Jakob\Desktop\ex.txt";
			else {
				infPath = @"C:\Users\Jakob\Downloads\" + Program.Settings.PROBLEM_LETTER.ToString() + "-" + (Program.Settings.SMALL ? "small" : "large");
				if (Program.Settings.PRACTICE)
					infPath += "-practice";
				if (Program.Settings.NUMBER != 0)
					infPath += "-" + Program.Settings.NUMBER.ToString();
				else if (!Program.Settings.PRACTICE && Program.Settings.SMALL)
					infPath += "-attempt" + Program.Settings.ATTEMPT_NUMBER.ToString();
				infPath += ".in";
			}
			return infPath;
		}
	}
}