using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace codejam.round_1b {
  public class ProblemA {
    public static void Run(string infile, string outfile) {
      using (System.IO.StreamReader sr = System.IO.File.OpenText(infile)) {
        using (System.IO.StreamWriter sw = System.IO.File.CreateText(outfile)) {
          //
          int T = int.Parse(sr.ReadLine());

          for (int t = 1; t <= T; t++) {
            string s = sr.ReadLine();
            string[] ss = s.Split(' ');
            int A = int.Parse(ss[0]);
            int N = int.Parse(ss[1]);
            int[] a = new int[N];
            s = sr.ReadLine();
            ss = s.Split(' ');
            for (int i = 0; i < N; i++) a[i] = int.Parse(ss[i]);
            Array.Sort(a);
            
            int idx = 0;
            int addOp = 0;
            int maxOp = addOp + N - idx;

            while (addOp < maxOp && idx < N) {
              if (A <= a[idx]) {
                A += A - 1;
                addOp++;
              } else {
                A += a[idx];
                idx++;
              }
              int op = addOp + N - idx;
              if (op < maxOp) maxOp = op;
            }

            sw.WriteLine(string.Format("Case #{0}: {1}", t, maxOp));
          }
          //
        }
      }
    }
  }
}
