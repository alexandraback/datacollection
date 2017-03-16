using System;
using System.IO;
using System.Linq;

namespace A
{
  class Program
  {
    static void Main(string[] args)
    {
      var instream = new StreamReader("A-small-practice.in");
      var outstream = new StreamWriter("output-small.txt");

      int n = Int32.Parse(instream.ReadLine());

      for (int x = 1; x <= n; ++x)
      {
        outstream.Write("Case #{0}:", x);

        int N = Int32.Parse(instream.ReadLine());
        int[] D = new int[10];

        if(N == 0)
        {
          outstream.WriteLine(" INSOMNIA");
          continue;
        }

        int i;
        for(i = 1;; i++)
        {
          int tmp = N*i;
          while(tmp != 0)
          {
            D[tmp % 10]++;
            tmp /= 10;
          }
          if (!D.Contains(0)) break;
        }

        outstream.WriteLine(" {0}", N*i);
      }

      instream.Close();
      outstream.Close();
    }
  }
}
