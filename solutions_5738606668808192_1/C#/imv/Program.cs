using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;

namespace С
{
  class Program
  {
    static void Main(string[] args)
    {
      var instream = new StreamReader("C-large.txt");
      var outstream = new StreamWriter("output-large.txt");

      int n = Int32.Parse(instream.ReadLine());

      for (int x = 1; x <= n; ++x)
      {
        outstream.WriteLine("Case #{0}:", x);

        int[] NJ = instream.ReadLine().Split(' ').Select(Int32.Parse).ToArray();
        int N = NJ[0];
        int J = NJ[1];
        
        int[] number = new int[N];//16 bit for small dataset;
        number[0] = 1;
        number[N-1] = 1;

        int J_counter = 0;

        while (J_counter < J)
        {
          BigInteger[] bases = new BigInteger[9];
          for (int i = 0; i < N; i++)
            for (int j = 2; j <= 10; j++)
              if (number[i] == 1)
                bases[j - 2] += BigInteger.Pow(j, i);

          bool[] divisorFound = new bool[9];
          BigInteger[] divisors = new BigInteger[9];
          for (int i = 0; i < 9; i++) divisors[i] = 2;

          for (int i = 0; i < 9; i++)
          {
            BigInteger maxdiv = BigInteger.Divide(bases[i], 2);
            if (maxdiv > 1000000) maxdiv = 1000000;
            for (; divisors[i] < maxdiv; divisors[i]++)
            {
              if (BigInteger.Remainder(bases[i], divisors[i]) == 0)
              {
                divisorFound[i] = true;
                break;
              }
            }
          }

          if(!divisorFound.Contains(false))
          {
            for (int i = N-1; i >= 0; i--) outstream.Write(number[i]);
            for (int i = 0; i < 9; i++) outstream.Write(" {0}", divisors[i]);
            outstream.WriteLine();
            J_counter++;
            Console.WriteLine(J_counter);
          }

          number[1]++;
          for (int i = 1; i < N; i++)
          {
            if (number[i - 1] > 1)
            {
              number[i - 1] = 0;
              number[i]++;
            }
          }
          if (number[N - 1] > 1) break;
        }
      }

      instream.Close();
      outstream.Close();
    }
  }
}
