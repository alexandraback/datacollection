using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ14Q4
{
  class Program
  {
    static void Main(string[] args)
    {
      using (var sr = new StreamReader(args[0]))
      {

        // Test cases
        int nCases = int.Parse(sr.ReadLine());

        for (int nCase = 1; nCase <= nCases; ++nCase)
        {
          int stones = int.Parse(sr.ReadLine());
          var naomiStones = sr.ReadLine().Split(' ').Select(ds => new Tuple<double, string>(double.Parse(ds), "n"));
          var kenStones = sr.ReadLine().Split(' ').Select(ds => new Tuple<double, string>(double.Parse(ds), "k"));
          var sortedStones = naomiStones.Concat(kenStones).OrderBy(t => t.Item1).Select(t => t.Item2);
          string owners = String.Join(String.Empty, sortedStones);
          Console.WriteLine("Case #{0}: {1} {2}", nCase, DeceitfulWar(owners), War(owners));
        }
      }
    }

    static int War(String stones)
    {
      // Remove all NKs R-to-L
      for(;;)
      {
        int sl = stones.Length;
        int nk = stones.LastIndexOf("nk");
        if (nk < 0) break;
        string before = (nk > 0) ? stones.Substring(0, nk) : String.Empty;
        string after = ((nk + 2) < sl) ? stones.Substring(nk + 2, sl - (nk + 2)) : String.Empty;
        stones = before + after;
      }

      // Count training Ns
      int score = 0;
      int last = stones.Length - 1;
      while ((last > 0) && stones[last] == 'n')
      {
        ++score;
        --last;
      }
      return score;
    }

    static int DeceitfulWar(String stones)
    {
      int score = 0;

      // Remove all KNs L-to-R, scoring
      for (; ; )
      {
        int sl = stones.Length;
        int kn = stones.LastIndexOf("kn");
        if (kn < 0) break;
        string before = (kn > 0) ? stones.Substring(0, kn) : String.Empty;
        string after = ((kn + 2) < sl) ? stones.Substring(kn + 2, sl - (kn + 2)) : String.Empty;
        stones = before + after;
        ++score;
      }

      return score;
    }
  }
}
