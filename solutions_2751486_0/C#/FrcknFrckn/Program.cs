using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Collections;

namespace Google1
{
  class Program
  {
    static System.Numerics.BigInteger Cost(System.Numerics.BigInteger radius, System.Numerics.BigInteger rings)
    {
      return 2 * radius * rings + 2 * rings * rings - rings;
    }

    static int FindLayer(int number)
    {
      int layer = 1;
      int total = 1;
      while (total < number)
      {
        total += LayerSize(layer + 1);
        layer++;
      }
      return layer;
    }

    static int LayerSize(int layer)
    {
      return 1 + 4*(layer-1);
    }

    static int LayerTotalSize(int layer)
    {
      if (layer <= 0) return 0;
      return LayerSize(layer) + LayerTotalSize(layer - 1);
    }

    static int Factorial(int x)
    {
      if (x <= 1) return 1;
      return x * Factorial(x - 1);
    }

    static int Choose(int x, int y)
    {
      return Factorial(x) / Factorial(y) / Factorial(x - y);
    }

    static int nvalue(string s, int start, int end)
    {
      int nvalue = 0;
      int result = 0;
      const string vowels = "aeiou";


      for (int current = start; current <= end; current++)
      {
        if (vowels.Contains(s[current].ToString()))
        {
          nvalue = 0;
        }
        else
        {
          nvalue++;
        }

        result = Math.Max(result, nvalue);
      }

      return result;
    }

    static void Main(string[] args)
    {
      using( StreamWriter writer = File.CreateText("result.txt") )
      using (StreamReader reader = File.OpenText("A-small-attempt0.in"))
      {
        string line = reader.ReadLine();
        int testCount = Int32.Parse(line);

        for (int test = 0; test < testCount; test++)
        {
          string[] values = reader.ReadLine().Split( new char[] {' '} );
          string name = values[0];
          int length = System.Int32.Parse(values[1]);

          int result = 0;
          for (int start = 0; start < name.Length; start++ )
          {
            for (int end = start; end < name.Length; end++ )
            {
              if (nvalue(name, start, end) >= length)
              {
                result++;
              }
            }
          }

          Console.Out.WriteLine(string.Format("Case #{0}: {1}", test + 1, result));
          writer.WriteLine(string.Format("Case #{0}: {1}", test + 1, result));
        }

        writer.Close();
        reader.Close();
      }
    }
  }
}
