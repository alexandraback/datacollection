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
			string s = rl();
			Dictionary<char, int> d = new Dictionary<char, int>();
			for(int i=0; i<s.Length; i++) {
				if (d.ContainsKey(s[i])) {
					d[s[i]]++;
				} else {
					d.Add(s[i], 1);
				}
			}
			int[] nums = new int[10];
			for(int i=0; i<nums.Length; i++) {
				nums[i] = 0;
			}
			int[] order = new int[10] { 0, 2, 6, 8, 3, 4, 1, 5, 9, 7};
			string[] letters = new string[10] { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
			for(int b=0; b<letters.Length; b++) {
				int i = order[b];
				int min = 9999999;
				foreach(char c in letters[i]) {
					if (d.ContainsKey(c)) {
						if ((i == 9 && c == 'N') || (i==7 && c=='E') || (i==3 && c=='E')) {
							min = Math.Min(min, d[c] / 2);
                        } else {
							min = Math.Min(min, d[c]);
						}
					} else {
						min = 0;
						break;
					}
				}
				nums[i] = min;
				if(min > 0)
					foreach(char c in letters[i]) {
						d[c] -= min;
					}
			}
			string res = "";
			for (int i = 0; i < nums.Length; i++) {
				for (int j = 0; j < nums[i]; j++)
					res += i.ToString();
			}
			foreach (KeyValuePair<char, int> k in d)
				if (k.Value != 0) {
					Console.WriteLine(k.Key + " " + k.Value);
					throw new Exception();
				}
			return res;
		}

		public struct Settings {
			public const bool DEBUG = false;
			public const bool TOCONSOLE = true;
			public const bool EXAMPLE = false;
			public const bool SMALL = false;
			public const char PROBLEM_LETTER = 'A';
			public const int ATTEMPT_NUMBER = 1; // 0 for the first attempt
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