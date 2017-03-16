using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace round_0 {
  public class ProblemC {
    private static bool Palindrome(string s) {
      for (int i = 0; i < s.Length / 2; i++)
        if (s[i] != s[s.Length - i - 1]) return false;
      return true;
    }

    public static void Run(string infile, string outfile) {
      using (System.IO.StreamReader sr = System.IO.File.OpenText(infile)) {
        using (System.IO.StreamWriter sw = System.IO.File.CreateText(outfile)) {
          //
          //
          //
          List<BigInteger> nums = new List<BigInteger>();
          const string sMaxB = "100000000000000";
          BigInteger maxB = 0;
          BigInteger.TryParse(sMaxB, out maxB);

          BigInteger C = 1;

          while (true) {
            if (Palindrome(C.ToString())) {
              BigInteger D = C * C;
              if (Palindrome(D.ToString())) nums.Add(D);
              if (D > maxB) break;
            }
            C++;
          }

          int T = int.Parse(sr.ReadLine());

          for (int t = 1; t <= T; t++) {
            string s = sr.ReadLine();
            string[] ss = s.Split(' ');

            BigInteger A = 0;
            BigInteger.TryParse(ss[0], out A);
            BigInteger B = 0;
            BigInteger.TryParse(ss[1], out B);

            long N = 0;
            foreach (BigInteger b in nums)
              if (b >= A && b <= B) N++;

            sw.WriteLine(string.Format("Case #{0}: {1}", t, N.ToString()));
          }
          //
          //
          //
        }
      }
    }
  }
}

