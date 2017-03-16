using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;

namespace GCJ_Round_1 {
	class Program {
		public static Dictionary<int, List<int>> g;
		public static byte[] visited;
		public static String answer = "No";
		public static bool found = false;

		static void Main(string[] args) {
			String line;
			String[] split;
			int T, v;

			T = Int32.Parse(Console.ReadLine());

			for (int i = 1; i <= T; i++) {
				Console.Write("Case #" + i + ": ");

				g = new Dictionary<int, List<int>>();
				v = Int32.Parse(Console.ReadLine());
				visited = new byte[v + 1];

				for (int j = 1; j <= v; j++) {
					line = Console.ReadLine();
					split = line.Split(' ');

					g.Add(j, new List<int>());

					if (split[0] != "0") {
						for (int k = 1; k < split.Length; k++) {
							g[j].Add(Int32.Parse(split[k]));
						}
					}
				}

				for (int j = 1; j <= v; j++) {
					if (found) break;
					search(j);
					Array.Clear(visited, 0, visited.Length);
				}

				Console.WriteLine(answer);
				answer = "No"; found = false;
			}
		}

		static void search(int start) {
			visited[start] = 1;
			foreach (int n in g[start]) {
				if (found) return;
				if (visited[n] == 0) {
					search(n);
				} else {
					answer = "Yes";
					found = true;
					return;
				}
			}
		}

	}
}
