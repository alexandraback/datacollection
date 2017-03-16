using System;
using System.Collections;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Collections.Generic;

public class Problem1AA
{
    public static void Main(String[] args)
    {
        StreamReader reader = new StreamReader(@"D:\codejam\A-large.in");
        StreamWriter writer = new StreamWriter(@"D:\codejam\A-large.out");
        var inputPool = reader.ReadToEnd()
                              .Trim()
                              .Split(new[] { ' ', '\r', '\n' }, StringSplitOptions.RemoveEmptyEntries)
            //.Select(Int32.Parse)
                              .ToArray();

        int index = 0;
        var T = int.Parse(inputPool[index++]);
        for (int t = 1; t <= T; t++)
        {
            var r = Double.Parse(inputPool[index++]);
            var v = Double.Parse(inputPool[index++]);
            var b = 2 * r - 1;
            var n = (long)((Math.Sqrt(8 * v + b * b) - b) / 4);
            while (2 * n * n + b * n <= v)
            {
                n++;
            }
            n--;

            while (2 * n * n + b * n > v)
            {
                n--;
            }

            writer.WriteLine(String.Format("Case #{0}: {1}", t, n));
        }

        writer.Flush();
        writer.Close();
        reader.Close();
    }
}