using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lawnmower
{
  class Program
  {
    static void Main(string[] args)
    {
      var lines = File.ReadAllLines(args[0]);
      int T = int.Parse(lines[0]);
      for (int i = 1, k = 1; i <= T; ++i)
      {
        var nm = lines[k].Split(' '); ++k;
        var N = int.Parse(nm[0]);
        var M = int.Parse(nm[1]);
        int[,] desired = new int[N, M];
        for (int j = 0; j < N; ++j)
        {
          var row = lines[k++].Split(' ');
          for (int l = 0; l < M; ++l)
            desired[j, l] = int.Parse(row[l]);
        }

        Console.Write("Case #{0}: ", i);
        Console.WriteLine(Mow(desired) ? "YES" : "NO");
      }
    }

    static bool Mow(int[,] desired)
    {
      int N = desired.GetLength(0);
      int M = desired.GetLength(1);

      var colConstraints = new int[M];

      for (int r = 0; r < N; ++r)
      {
        int max = 0;
        for (int c = 0; c < M; ++c)
          max = Math.Max(max, desired[r, c]);

        for (int c = 0; c < M; ++c)
          if (desired[r, c] < max)
          {
            if (colConstraints[c] == 0)
              colConstraints[c] = desired[r, c];
            else if (colConstraints[c] != desired[r, c])
              return false;
          }
      }

      for (int c = 0; c < M; ++c)
        if (colConstraints[c] != 0)
          for (int r = 0; r < N; ++r)
            if (desired[r, c] > colConstraints[c])
              return false;

      return true;
    }
  }
}
