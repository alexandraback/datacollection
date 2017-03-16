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
			Dictionary<string, int> first = new Dictionary<string, int>();
			Dictionary<string, int> second = new Dictionary<string, int>();
			Queue<Tuple<string, string>> l = new Queue<Tuple<string, string>>();
			for (int i=0; i< n; i++) {
				string[] arr = rl().Split(' ').ToArray();
				if (first.ContainsKey(arr[0])) {
					first[arr[0]]++;
				} else {
					first.Add(arr[0], 1);
				}
				if (second.ContainsKey(arr[1])) {
					second[arr[1]]++;
				} else {
					second.Add(arr[1], 1);
				}
				l.Enqueue(new Tuple<string, string>(arr[0], arr[1]));
			}
			int max = 0;
			while (l.Any()) {
				var t = l.Dequeue();
				if (first[t.Item1] > 1 && second[t.Item2] > 1) {
					bool c1 = false;
					bool c2 = false;
					foreach (var t2 in l) {
						if (t2.Item1 == t.Item1)
							c1 = true;
						if (t2.Item2 == t.Item1)
							c2 = true;
						if (c1 && c2) break;
					}
					if (!(c1 && c2)) {
						max++;
						first[t.Item1]--;
						second[t.Item2]--;
					} else {
						l.Enqueue(t);
					}
				}
			}
			return max;
		}

		public struct Settings {
			public const bool DEBUG = false;
			public const bool TOCONSOLE = true;
			public const bool EXAMPLE = false;
			public const bool SMALL = true;
			public const char PROBLEM_LETTER = 'C';
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