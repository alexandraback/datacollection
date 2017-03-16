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

    static void Main(string[] args)
    {
      using( StreamWriter writer = File.CreateText("result.txt") )
      using (StreamReader reader = File.OpenText("A-large.in"))
      {
        string line = reader.ReadLine();
        int testCount = Int32.Parse(line);

        for (int test = 0; test < testCount; test++)
        {
          string[] values = reader.ReadLine().Split( new char[] {' '} );
          uint armin = System.UInt32.Parse(values[0]);
          uint moteCount = System.UInt32.Parse(values[1]);
          uint result = moteCount;

          List<uint> motes = new List<uint>();
          values = reader.ReadLine().Split(new char[] { ' ' });
          for (int i = 0; i < values.Length; i++)
          {
            motes.Add(System.UInt32.Parse(values[i]));
          }

          uint moveCount = 0;
          while (motes.Count > 0 && moveCount < result)
          {
            bool grown = false;
            for (int i = 0; i < motes.Count; i++)
            {
              if (motes[i] < armin)
              {
                armin += motes[i];
                motes.RemoveAt(i);
                grown = true;

                if (moveCount + (uint)motes.Count < result)
                {
                  result = moveCount + (uint)motes.Count;
                }
                break;
              }
            }

            if (!grown)
            {
              armin += armin - 1;
              moveCount++;
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
