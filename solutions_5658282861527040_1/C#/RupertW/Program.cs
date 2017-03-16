using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ141BQ2
{
  using System.IO;

  class Program
  {
    static void Main(string[] args)
    {
      //args = new string[] {"..\\..\\sample.in"};
      using (var sr = new StreamReader(args[0]))
      {
        int nCases = int.Parse(sr.ReadLine());

        for (int nCase = 1; nCase <= nCases; ++nCase)
        {
          var p = sr.ReadLine().Split(' ').Select(s => int.Parse(s)).ToList();
          long A = p[0];
          long B = p[1];
          long K = p[2];
          long ways = (K * A) + (K * B) - (K * K);

          for (long a = K; a < A; ++a)
          {
            for (long b = K; b < B; ++b)
            {
              if ((a & b) < K)
              {
                ++ways;
              }
            }
          }

          Console.WriteLine("Case #{0}: {1}", nCase, ways);
        }
      }
    }
  }
}
