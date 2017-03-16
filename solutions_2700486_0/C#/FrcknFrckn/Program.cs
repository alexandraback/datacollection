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

    static void Main(string[] args)
    {
      using( StreamWriter writer = File.CreateText("result.txt") )
      using (StreamReader reader = File.OpenText("B-small-attempt1.in"))
      {
        string line = reader.ReadLine();
        int testCount = Int32.Parse(line);

        for (int test = 0; test < testCount; test++)
        {
          string[] values = reader.ReadLine().Split( new char[] {' '} );
          int num = System.Int32.Parse(values[0]);
          int x = System.Int32.Parse(values[1]);
          int y = System.Int32.Parse(values[2]);

          int layer = FindLayer(num);
          int targetLayer = (x + y) / 2 + 1;

          float result = 0.0f;
          if (targetLayer < layer)
          {
            result = 1.0f;
          }
          else if (targetLayer > layer)
          {
            result = 0.0f;
          }
          else
          {
            int layerSize = LayerSize(layer);
            int droppedCount = LayerTotalSize(layer - 1);
            int remaining = num - droppedCount;

            if (remaining == layerSize)
            {
              result = 1.0f;
            }
            else if (x == 0)
            {
              result = 0.0f;
            }
            else
            {
              int slots = (layerSize / 2);
              int slotIndex = slots - Math.Abs(x);

              if (remaining - slots > slotIndex)
              {
                result = 1.0f;
              }
              else
              {
                // can have up to slotIndex left
                // so combine number of case where 0..(slotIndex-1) are left, remainder right
                int chances = 0;
                for (int i = 0; i <= slotIndex; i++)
                {
                  chances += Choose(remaining, i);
                }

                float instanceProb = 1.0f;
                for (int i = 0; i < remaining; i++)
                {
                  instanceProb *= 0.5f;
                }

                result = 1.0f - (float)chances * instanceProb;
                if (result > 1.0f)
                {
                  result = 1.0f;
                }
                if (result < 0.0f)
                {
                  result = 0.0f;
                }
              }
            }
          }


          writer.WriteLine(string.Format("Case #{0}: {1}", test + 1, result));
        }

        writer.Close();
        reader.Close();
      }
    }
  }
}
