using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;

public class A
{
    public static int N;
    public static LinkedList<int>[] outGoing;
    public static bool[] done;

    public static void Main(string[] args)
    {
        Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
        int CASES = int.Parse(Console.ReadLine());
        for (int CASE = 1; CASE <= CASES; CASE++)
        {
            Console.Error.WriteLine("Case " + CASE);
            N = int.Parse(Console.ReadLine());
            outGoing = new LinkedList<int>[N];
            for (int i = 0; i < N; i++)
            {
                string[] p = Console.ReadLine().Split();
                outGoing[i] = new LinkedList<int>();
                for (int j = 1; j < p.Length; j++)
                    outGoing[i].AddLast(int.Parse(p[j]) - 1);
            }

            bool ret = false;
            for (int i = 0; i < N; i++)
            {
                done = new bool[N];
                ret |= dfs(i);
            }

            Console.WriteLine("Case #" + CASE + ": " + (ret ? "Yes" : "No"));
        }
    }

    public static bool dfs(int i)
    {
        if (done[i]) return true;
        done[i] = true;
        foreach (int j in outGoing[i])
        {
            if (dfs(j)) return true;
        }
        return false;
    }
}
