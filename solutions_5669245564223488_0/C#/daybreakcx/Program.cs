using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ {
	class Program {
		public static long mod = 1000000007;
		public static string merge(string x) {
			StringBuilder ret = new StringBuilder();
			for (int i = 0; i < x.Length; ++i)
				if (i == 0 || !x[i].Equals(x[i - 1]))
					ret.Append(x[i]);
			return ret.ToString();
		}

		public static long calc(long init, int f) {
			for (long i = 1; i <= f; ++i)
				init = (init * i) % mod;
			return init;
		}

		static void Main(string[] args) {
			using (StreamWriter sw = new StreamWriter(args[1])) {
				using (StreamReader sr = new StreamReader(args[0])) {
					int tn = int.Parse(sr.ReadLine());
					for (int ti = 1; ti <= tn; ++ti) {
						long ans = 1;
						sw.Write("Case #{0}: ", ti);
						sr.ReadLine();
						string[] tokens = sr.ReadLine().Trim().Split(' ').Select(x => merge(x)).ToArray();
						int i;
						for (i = 0; i < tokens.Length; ++i)
							if (tokens[i].Length >= 3) {
								HashSet<char> hs = new HashSet<char>();
								int j;
								for (j = 0; j < tokens[i].Length; ++j)
									if (!hs.Contains(tokens[i][j]))
										hs.Add(tokens[i][j]);
									else
										break;
								if (j != tokens[i].Length)
									break;
							}
						if (i != tokens.Length) {
							sw.WriteLine("0");
							continue;
						}
						char ch;
						Dictionary<char, KeyValuePair<int, int>> store = new Dictionary<char, KeyValuePair<int, int>>();
						for (ch = 'a'; ch <= 'z'; ++ch) {
							HashSet<int> left = new HashSet<int>(), right = new HashSet<int>(), all = new HashSet<int>(), inside = new HashSet<int>();
							for (i = 0; i < tokens.Length; ++i)
								if (tokens[i].Contains(ch)) {
									int j = tokens[i].IndexOf(ch);
									if (tokens[i].Length == 1)
										all.Add(i);
									else if (j == 0)
										right.Add(i);
									else if (j == tokens[i].Length - 1)
										left.Add(i);
									else
										inside.Add(i);
								}
							if (left.Count + right.Count + all.Count + inside.Count == 0)
								continue;
							if (inside.Count > 0) {
								if (inside.Count > 0 || left.Count + right.Count + all.Count != 0)
									break;
							} else {
								if (left.Count > 1 || right.Count > 1)
									break;
								else
									store[ch] = new KeyValuePair<int, int>(left.Count > 0 ? left.First() : -1, right.Count > 0 ? right.First() : -1);
							}
							ans = calc(ans, all.Count);
						}
						if (ch <= 'z') {
							sw.WriteLine("0");
							continue;
						}
						Dictionary<char, int> income = new Dictionary<char, int>(), outgo = new Dictionary<char, int>();
						foreach (var entry in store)
							income[entry.Key] = outgo[entry.Key] = 0;
						foreach (var entry0 in store) {
							foreach (var entry1 in store) {
								if (entry0.Key != entry1.Key) {
									if (entry0.Value.Key != -1 && entry0.Value.Key == entry1.Value.Value) {
										income[entry0.Key] += 1;
										outgo[entry1.Key] += 1;
									}
									if (entry0.Value.Value != -1 && entry0.Value.Value == entry1.Value.Key) {
										outgo[entry0.Key] += 1;
										income[entry1.Key] += 1;
									}
								}
							}
						}
						if (income.Count(x => x.Value > 2) > 0 || outgo.Count(x => x.Value > 2) > 0)
							sw.WriteLine("0");
						else
							sw.WriteLine(calc(ans, income.Count(x => x.Value == 0)).ToString());
					}
					sr.Close();
				}
				sw.Close();
			}
		}
	}
}
