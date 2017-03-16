using System;
using System.Collections;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Collections.Generic;

public class Problem1AB
{
    public static void Main(String[] args)
    {
        StreamReader reader = new StreamReader(@"D:\codejam\B-small-attempt0.in");
        StreamWriter writer = new StreamWriter(@"D:\codejam\B-small-attempt0.out");
        var inputPool = reader.ReadToEnd()
                              .Trim()
                              .Split(new[] { ' ', '\r', '\n' }, StringSplitOptions.RemoveEmptyEntries)
                              .Select(Int32.Parse)
                              .ToArray();

        int index = 0;
        int T = inputPool[index++];

        for (int t = 1; t <= T; t++)
        {
            int E = inputPool[index++];
            int R = inputPool[index++];
            int N = inputPool[index++];
            int[] values = new int[N];
            int[] spends = new int[N];
            for (int i = 0; i < N; i++)
            {
                values[i] = inputPool[index++];
            }
            MaxMax(0, N, E, R, E, 0, spends, values);
            long total = 0;
            for (int i = 0; i < N; i++)
            {
                total += values[i] * spends[i];
            }
            writer.WriteLine(String.Format("Case #{0}: {1}", t, total));
        }

        writer.Flush();
        writer.Close();
        reader.Close();
    }

    private static void MaxMax(int s, int t, int E, int R, int maxStartE, int minEndE, int[] spends, int[] values)
    {
        if (s >= t)
        {
            return;
        }
        int maxVal = -1;
        int maxIndex = -1;
        for (int i = s; i < t; i++)
        {
            if (values[i] > maxVal)
            {
                maxVal = values[i];
                maxIndex = i;
            }
        }
        int maxAvailableSpend = Math.Min(E, maxStartE + (maxIndex - s) * R);
        int minKeep = Math.Max(minEndE - (t - maxIndex) * R, 0);
        spends[maxIndex] = maxAvailableSpend - minKeep;
        int prevMin = maxAvailableSpend;
        int nextMax = minKeep + R;
        MaxMax(s, maxIndex, E, R, maxStartE, prevMin, spends, values);
        MaxMax(maxIndex + 1, t, E, R, nextMax, minEndE, spends, values);
    }
}