using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace D
{
  class Program
  {
    static void Main(string[] args)
    {
      var instream = new StreamReader("D-small-attempt2.in.txt");
      var outstream = new StreamWriter("output-small.txt");

      int n = Int32.Parse(instream.ReadLine());

      for (int x = 1; x <= n; ++x)
      {
        outstream.Write("Case #{0}:", x);

        int[] KCS = instream.ReadLine().Split(' ').Select(Int32.Parse).ToArray();
        int K = KCS[0];
        int C = KCS[1];
        int S = KCS[2];

        if (K != S) throw new Exception("Unexpected S");

        for (int i = 1; i <= K; i++)
          outstream.Write(" {0}", i);
        outstream.WriteLine();
      }

      instream.Close();
      outstream.Close();
    }
  }
}
