using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace osmos
{
  class Program
  {
    static int[] motes;
    static int size;

    static void Main(string[] args)
    {
      var lines = File.ReadAllLines(args[0]);
      int T = int.Parse(lines[0]);
      for (int i = 1; i <= T; ++i)
      {
        var an = lines[i * 2 - 1].Split(' ');
        size = int.Parse(an[0]);
        var N = int.Parse(an[1]);

        motes = lines[i * 2].Split(' ').Select(int.Parse).OrderBy(x => x).ToArray();
        int minMoves = MinMoves(0);

        Console.WriteLine("Case #{0}: {1}", i, minMoves);
      }
    }

    static int MinMoves(int toEat)
    {
      if (toEat == motes.Length)
        return 0;

      if (size > motes[toEat])
      {
        size += motes[toEat];
        return MinMoves(toEat + 1);
      }

      int removes = motes.Length - toEat;
      if (size == 1)
        return removes;
      int adds = 0;
      while (size <= motes[toEat])
      {
        size += size - 1;
        ++adds;
      }

      size += motes[toEat];
      adds += MinMoves(toEat + 1);

      return Math.Min(adds, removes);
    }
  }
}
