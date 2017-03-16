using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace TaskD
{
  // https://stackoverflow.com/questions/13731796/create-batches-in-linq
  public static class MyExtensions
  {
    public static IEnumerable<IEnumerable<T>> Batch<T>(this IEnumerable<T> items,
                                                       int maxItems)
    {
      return items.Select((item, inx) => new { item, inx })
                  .GroupBy(x => x.inx / maxItems)
                  .Select(g => g.Select(x => x.item));
    }
  }

  class Program
  {
    // Rounds up
    static int updiv(int n, int divisor)
    {
      return (n + divisor - 1) / divisor;
    }

    static BigInteger[] solve(int k, int c, int s)
    {
      BigInteger pow = 1;
      List<BigInteger> powers = Enumerable.Range(0, k).Select(x => (pow *= k) / k).ToList();
      IEnumerable<int> neededpositions = Enumerable.Range(0, k);
      IEnumerable<IEnumerable<int>> neededbatches = neededpositions.Batch(c).Select(x => x.Reverse());
      IEnumerable<BigInteger> needtoview = neededbatches.Select(x => x.Zip(powers, (xx, yy) => yy * xx).Aggregate((currentSum, item) => currentSum + item));

      BigInteger[] ret = needtoview.Select(x => x + 1).ToArray();

      if (ret.Length > s) return new BigInteger[0];

      return ret;
    }

    static void Main(string[] args)
    {
      using (TextReader reader = File.OpenText("../../input.txt"))
      {
        int tn = int.Parse(reader.ReadLine());

        for (int ti = 0; ti < tn; ++ti)
        {
          string line = reader.ReadLine();
          string[] bits = line.Split(' ');
          int k = int.Parse(bits[0]);
          int c = int.Parse(bits[1]);
          int s = int.Parse(bits[2]);
          BigInteger[] sol = solve(k, c, s);
          Console.WriteLine("Case #{0}: {1}", ti + 1, sol.Length == 0 ? "IMPOSSIBLE" : string.Join(" ", sol));
        }
      }
    }
  }
}
