using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
{
  class Program
  {
    static void sub(char c, int d, int[] a, int[] n, string[] digits)
    {
      n[d] = a[c - 'A'];
      foreach (char x in digits[d])
      {
        a[x - 'A'] -= n[d];
      }
    }

    static void Main(string[] args)
    {
      string inputFile = (args.Length > 0) ? args[0] : @"..\..\test.in";
      var input = File.ReadAllLines(inputFile);
      int ncase = 1;

      var digits = new[] {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

      // Z = 0
      // W = 2
      // X = 6
      // G = 8
      // V = 5 or 7
      // U = 4



      foreach (string s in input.Skip(1))
      {
        int[] a = new int[26];
        foreach (var g in s.GroupBy(c => c))
        {
          a[g.Key - 'A'] = g.Count();
        }

        int[] n = new int[10];

        // Uniques
        sub('Z', 0, a, n, digits);
        sub('W', 2, a, n, digits);
        sub('U', 4, a, n, digits);
        sub('X', 6, a, n, digits);
        sub('G', 8, a, n, digits);

        // Left: ONE, THREE, FIVE, SEVEN, NINE
        sub('H', 3, a, n, digits);
        sub('O', 1, a, n, digits);
        sub('F', 5, a, n, digits);
        sub('V', 7, a, n, digits);
        sub('I', 9, a, n, digits);

        Console.Write("Case #{0}: ", ncase);
        for (int i = 0; i <= 9; ++i)
        {
          for (int j = 0; j < n[i]; ++j)
          {
            Console.Write(i);
          }
        }

        Console.WriteLine();
        ++ncase;
      }
    }
  }
}

