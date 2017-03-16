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
          int ways = 0;
          var p = sr.ReadLine().Split(' ').Select(s => int.Parse(s)).ToList();
          int A = p[0];
          int B = p[1];
          int K = p[2];

          for (int a = 0; a < A; ++a)
          {
            for (int b = 0; b < B; ++b)
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
