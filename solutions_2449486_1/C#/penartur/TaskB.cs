using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace QualificationRound2013 {
	class TaskB {
		private static bool TestLawn(int N, int M, int[,] lawn) {
			int[] rows = new int[N];
			int[] columns = new int[M];

			for(int i=0; i<N; i++) {
				rows[i] = 0;
				for(int j=0; j<M; j++) {
					rows[i] = Math.Max(rows[i], lawn[i, j]);
				}
			}

			for(int i=0; i<M; i++) {
				columns[i] = 0;
				for(int j=0; j<N; j++) {
					columns[i] = Math.Max(columns[i], lawn[j, i]);
				}
			}

			for(int i=0; i<N; i++) {
				for(int j=0; j<M; j++) {
					if(lawn[i, j] < rows[i] && lawn[i, j] < columns[j]) {
						return false;
					}
				}
			}
			return true;
		}

		public static void Run() {
			int T = int.Parse(Console.ReadLine());
			for(int i=1; i<=T; i++) {
				string[] parts = Console.ReadLine().Split(' ');
				int N = int.Parse(parts[0]);
				int M = int.Parse(parts[1]);
				int[,] lawn = new int[N, M];
				for(int j=0; j<N; j++) {
					string[] row = Console.ReadLine().Split(' ');
					for(int k=0; k<M; k++) {
						lawn[j, k] = int.Parse(row[k]);
					}
				}

				Console.Write("Case #" + i + ": ");
				if(TestLawn(N, M, lawn)) {
					Console.WriteLine("YES");
				} else {
					Console.WriteLine("NO");
				}
			}
		}
	}
}
