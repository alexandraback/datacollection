using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2015_BA
{
  class Program
  {
    static int rev(int p)
    {
      int r = 0;
      while (p > 0)
      {
        int d = p % 10;
        p /= 10;
        r *= 10;
        r += d;
      }
      return r;
    }


    static void Main(string[] args)
    {
      int N = 1000001;
      int[] c = new int[N];
      c[1] = 1;
      var q = new Queue<int>();
      q.Enqueue(1);
      while(q.Count > 0)
      {
        int j = q.Dequeue();
        int d = c[j] + 1;
        if (j + 1 < N)
        {
          if ((c[j+1] == 0) || c[j+1] > d)
          {
            c[j + 1] = d;
            q.Enqueue(j + 1);
          }
        }
        int r = rev(j);
        if ((r > 0) && (r < N))
        {
          if ((c[r] == 0) || (c[r] > d))
          {
            c[r] = d;
            q.Enqueue(r);
          }
        }
      }

      int tests = ReadInt();
      for (int test = 1; test <= tests; ++test)
      {
        int t = ReadInt();
        int result = c[t];
        Console.WriteLine("Case #{0}: {1}", test, result);
      }
    }

    static int ReadInt()
    {
      return Convert.ToInt32(Console.ReadLine());
    }

    static IEnumerable<String> ReadStrings()
    {
      string line = Console.ReadLine();
      return line.Split((char[])null, StringSplitOptions.RemoveEmptyEntries);
    }

    static IEnumerable<int> ReadInts()
    {
      return ReadStrings().Select(s => Convert.ToInt32(s));
    }

    static IEnumerable<long> ReadLongs()
    {
      return ReadStrings().Select(s => Convert.ToInt64(s));
    }

    static int[] ReadInts(int count)
    {
      return ReadInts().Take(count).ToArray();
    }

  }
}
