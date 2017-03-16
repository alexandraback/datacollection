using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using System.Globalization;
using System.Threading;

class B
{

    class Result
    {
        public int filled;
        public int added;
        public Result(int filled, int added)
        {
            this.filled = filled;
            this.added = added;
        }
    }

    static int fill(bool[] kp, int d, int V)
    {
        int filled = 0;
        for (int i = V; i >= 0; --i)
        {
            if (kp[i] && i + d <= V && !kp[i + d])
            {
                kp[i + d] = true;
                ++filled;
            }
        }
        return filled;
    }

    static int solve(bool[] kp, List<int> D, int k, int V)
    {
        int minAdded = int.MaxValue;
        int maxFill = 0;
        for (int i=k; i < D.Count; ++i)
        {
            int d = D[i];
            bool[] kpCopy = new bool[V + 1];
            Array.Copy(kp, kpCopy, V + 1);
            int filled = fill(kpCopy, d, V);
            if (filled == 0)
                continue;
            if (filled > maxFill)
            {
                maxFill = filled;
            }
        }
        for (int i = k; i < D.Count; ++i)
        {
            int d = D[i];
            bool[] kpCopy = new bool[V + 1];
            Array.Copy(kp, kpCopy, V + 1);
            int filled = fill(kpCopy, d, V);
            if (filled == 0)
                continue;
            if (filled == maxFill)
            {
                int added = solve(kpCopy, D, k + 1, V);
                if (added < minAdded)
                {
                    minAdded = added;
                }
            }
        }
        return minAdded == int.MaxValue ? 0 : 1+minAdded;
    }

    static int Solve(int C, List<int> D, int V)
    {
        int added = 0;
        int[] must = new int[]{1,2};
        foreach(int m in must){
            if(m <= V && !D.Contains(m)){
                D.Add(m);
                ++added;
            }
        }
        List<int> denom = new List<int>();
        bool[] kp = new bool[V + 1];
        kp[0] = true;
        for (int i = 1; i <= V; ++i)
        {
            denom.Add(i);
        }
        int filled = 0;
        foreach (int d in D)
        {
            filled += fill(kp, d, V);
            denom.Remove(d);
        }
        return added+solve(kp, denom, 0, V);
    }

    static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");
        int T = ReadInt();
        for (int t = 1; t <= T; ++t)
        {
            int[] I = ReadInts();
            int[] D = ReadInts();
            Console.WriteLine("Case #{0}: {1}", t, Solve(I[0], new List<int>(D), I[2]));
        }
    }

    // INPUT READING
    static string ReadLine()
    {
        return Console.ReadLine();
    }

    static string[] ReadWords()
    {
        return ReadLine().Split();
    }

    static string[] ReadWords(char separator)
    {
        return ReadLine().Split(separator);
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

    static int[] ReadInts(char separator)
    {
        return Array.ConvertAll(ReadWords(separator), int.Parse);
    }

    static long[] ReadLongs()
    {
        return Array.ConvertAll(ReadWords(), long.Parse);
    }

    static long[] ReadLongs(char separator)
    {
        return Array.ConvertAll(ReadWords(separator), long.Parse);
    }

    static double[] ReadDoubles()
    {
        return Array.ConvertAll(ReadWords(), double.Parse);
    }

    static double[] ReadDoubles(char separator)
    {
        return Array.ConvertAll(ReadWords(separator), double.Parse);
    }

    static void WriteList<T>(List<T> col)
    {
        int count = col.Count;
        for (int i = 0; i < count; i++)
            Console.Write(col[i] + (i < count - 1 ? " " : "\n"));
    }

    static void WriteArray<T>(T[] col)
    {
        int count = col.Length;
        for (int i = 0; i < count; i++)
            Console.Write(col[i] + (i < count - 1 ? " " : "\n"));
    }
}
