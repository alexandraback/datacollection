using System;
using System.Collections.Generic;
using System.Collections;
using System.IO;
using System.Text;
using System.Collections;
using System.Drawing;

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
      using (StreamReader reader = File.OpenText("B-small-attempt0.in"))
      {
        string line = reader.ReadLine();
        int testCount = Int32.Parse(line);

        for (int test = 0; test < testCount; test++)
        {
          string[] values = reader.ReadLine().Split(new char[] { ' ' });
          int x = System.Int32.Parse(values[0]);
          int y = System.Int32.Parse(values[1]);
          Point target = new Point(x, y);

          Dictionary<System.Drawing.Point, string> map = new Dictionary<System.Drawing.Point, string>();
          map[new Point(0, 0)] = "";
          Queue<Point> newKeyList = new Queue<Point>();
          newKeyList.Enqueue(new Point(0, 0));

          for (int i = 0; i < 500; i++)
          {
            Queue<Point> nextKeyList = new Queue<Point>();

            foreach (Point p in newKeyList)
            {
              string path = map[p];
              Point north = new Point(p.X, p.Y + i + 1);
              Point south = new Point(p.X, p.Y - i - 1);
              Point east = new Point(p.X + i + 1, p.Y);
              Point west = new Point(p.X - i - 1, p.Y);
              if (!map.ContainsKey(north))
              {
                map[north] = path + "N";
                nextKeyList.Enqueue(north);
              }
              if (!map.ContainsKey(south))
              {
                map[south] = path + "S";
                nextKeyList.Enqueue(south);
              }
              if (!map.ContainsKey(east))
              {
                map[east] = path + "E";
                nextKeyList.Enqueue(east);
              }
              if (!map.ContainsKey(west))
              {
                map[west] = path + "W";
                nextKeyList.Enqueue(west);
              }
            }

            newKeyList = nextKeyList;
            if (map.ContainsKey(target))
            {
              break;
            }
          }

          Console.Out.WriteLine(string.Format("Case #{0}: {1}", test + 1, map[target]));
          writer.WriteLine(string.Format("Case #{0}: {1}", test + 1, map[target]));
        }

        writer.Close();
        reader.Close();
      }
    }
  }
}
