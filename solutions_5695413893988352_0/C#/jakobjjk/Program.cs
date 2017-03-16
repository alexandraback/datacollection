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
			int mindiff = 9999999;
			string cand = "";
			int count = 0;
			for (int i = 0; i < s.Length; i++)
				if (s[i] == '?')
					count++;
			for(int i=0; i<(int)Math.Pow(10, count); i++) {
				string m = MakeFull(i,count);
				int c = 0;
				string n = "";
				for(int j=0; j<s.Length; j++) {
					if (s[j] == '?') {
						n += m[c];
						c++;
					} else {
						n += s[j];
					}
				}
				int d = GetDiff(n);
				if(d < mindiff) {
					cand = n;
					mindiff = d;
				}
			}
			return cand;
		}

		static int GetDiff(string s) {
			string[] arr = s.Split(' ').ToArray();
			string s1 = arr[0];
			string s2 = arr[1];
			return Math.Abs(int.Parse(s1) - int.Parse(s2));
		}

		static string MakeFull(int i, int count) {
			string res = i.ToString();
			while(res.Length < count) {
				res = "0" + res;
			}
			return res;
		}

		static bool ContainsNum(string s) {
			return s.Where(c => "0123456789".Contains(c)).Any();
		}

		public struct Settings {
			public const bool DEBUG = false;
			public const bool TOCONSOLE = true;
			public const bool EXAMPLE = false;
			public const bool SMALL = true;
			public const char PROBLEM_LETTER = 'B';
			public const int ATTEMPT_NUMBER = 2	; // 0 for the first attempt
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