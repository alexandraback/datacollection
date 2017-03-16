using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using System.Globalization;
using System.Threading;

class A
{
    static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");
        int T = ReadInt();
        for (int t = 1; t <= T; ++t)
        {
            int[] V = ReadInts();
            int N = V[0];
            int X = V.Sum() - N;
            double[] f = new double[N+1];
            f[N] = (2 - N * V[N] / (double)X) / N;
            for (int i = N - 1; i >= 1; i--)
            {
                f[i] = (V[i + 1] - V[i]) / (double)X + f[i + 1];
            }
            double negative = 0;
            int negCount = 0;
            for (int i = N; i >= 1; i--)
            {
                f[i] *= 100;
                if (f[i] < 0)
                {
                    negative += f[i];
                    negCount++;
                }
            }
            double minus = negative / (N - negCount);
            for (int i = N; i >= 1; i--)
            {
                if (f[i] < 0)
                {
                    f[i] = 0;
                }
                else
                {
                    f[i] += minus;
                }
            }
            Console.Write("Case #{0}: ", t);
            for (int i = 1; i < N; i++)
                Console.Write("{0} ", f[i]);
            Console.WriteLine("{0}", f[N]);
        }
    }

    static string ReadLine()
    {
        return Console.ReadLine();
    }

    static string[] ReadWords()
    {
        return ReadLine().Split();
    }

    static int ReadInt()
    {
        return int.Parse(ReadLine());
    }

    static long ReadLong()
    {
        return long.Parse(ReadLine());
    }

    static double ReadDouble()
    {
        return double.Parse(ReadLine());
    }

    static int[] ReadInts()
    {
        return Array.ConvertAll(ReadWords(), int.Parse);
    }

    static long[] ReadLongs()
    {
        return Array.ConvertAll(ReadWords(), long.Parse);
    }

    static double[] ReadDoubles()
    {
        return Array.ConvertAll(ReadWords(), double.Parse);
    }

    static void WriteArray<T>(List<T> col)
    {
        int count = col.Count;
        for (int i = 0; i < count - 1; i++)
            Console.Write(col[i] + " ");
        Console.WriteLine(col[count - 1]);
    }

    static void WriteArray<T>(T[] col)
    {
        int count = col.Length;
        for (int i = 0; i < count - 1; i++)
            Console.Write(col[i] + " ");
        Console.WriteLine(col[count - 1]);
    }
}
