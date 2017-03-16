using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace round_0 {
  public class ProblemB {
    public static void Run(string infile, string outfile) {
      using (System.IO.StreamReader sr = System.IO.File.OpenText(infile)) {
        using (System.IO.StreamWriter sw = System.IO.File.CreateText(outfile)) {
          //
          //
          //
          int T = int.Parse(sr.ReadLine());

          for (int t = 1; t <= T; t++) {
            string s = sr.ReadLine();
            string[] ss = s.Split(' ');
            int N = int.Parse(ss[0]);
            int M = int.Parse(ss[1]);
            int[,] A = new int[N, M];

            for (int n = 0; n < N; n++) {
              s = sr.ReadLine();
              ss = s.Split(' ');
              for (int m = 0; m < M; m++) {
                A[n, m] = int.Parse(ss[m]);
              }
            }

            int[] maxN = new int[N];
            for (int i = 0; i < N; i++) {
              maxN[i] = 0;
              for (int j = 0; j < M; j++) {
                if (maxN[i] < A[i, j]) maxN[i] = A[i, j];
              }
            }

            int[] maxM = new int[M];
            for (int j = 0; j < M; j++) {
              maxM[j] = 0;
              for (int i = 0; i < N; i++) {
                if (maxM[j] < A[i, j]) maxM[j] = A[i, j];
              }
            }

            bool OK = true;
            for (int i = 0; i < N; i++) {
              for (int j = 0; j < M; j++) {
                if (A[i, j] < maxN[i] && A[i, j] < maxM[j]) {
                  OK = false;
                  break;
                }
              }
              if (!OK) break;
            }

            sw.WriteLine(string.Format("Case #{0}: {1}", t, OK ? "YES" : "NO"));
          }
          //
          //
          //
        }
      }
    }
  }
}

