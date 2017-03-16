using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ14Q2
{
  internal class Program
  {
    private static void Main(string[] args)
    {
      // args = new string[] {"..\\..\\sample.in"};
      using (var sr = new StreamReader(args[0]))
      {
        int nCases = int.Parse(sr.ReadLine());

        for (int nCase = 1; nCase <= nCases; ++nCase)
        {
          var vals = sr.ReadLine().Split(' ').Select(ds => Double.Parse(ds)).ToList();
          double result = Play(vals[0], vals[1], vals[2]);
          Console.WriteLine("Case #{0}: {1:0.0000000}", nCase, result);
        }
      }
    }

    static double Play(double c, double f, double x)
    {
      double rate = 2;
      double best = x/rate;
      double timeSoFar = 0;

      for (;;)
      {
        timeSoFar += c/rate;
        rate += f;
        double winTime = timeSoFar + (x/rate);
        if (winTime > best) return best;
        best = winTime;
      }
    }
  }
}
