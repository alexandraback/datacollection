using System;
using System.Collections.Generic;
using System.Text;

class A
{
    static bool dfs(int[][] G, bool[] visit, int v)
    {
        if (visit[v])
            return true;
        visit[v] = true;
        int Mv = G[v].Length;
        for (int i = 0; i < Mv; i++)
        {
            if (dfs(G, visit, G[v][i]))
                return true;
        }
        return false;
    }

    static void Main(string[] args)
    {
        int T = ReadInt();
        for (int t = 1; t <= T; ++t)
        {
            int N = ReadInt();
            int[][] G = new int[N][];
            bool[] visit = new bool[N];
            bool[] notRoot = new bool[N];
            bool diamond = false;
            for (int i = 0; i < N; i++)
            {
                int[] V = ReadInts();
                int Mi = V[0];
                G[i] = new int[Mi];
                for (int j = 1; j <= Mi; j++)
                {
                    G[i][j - 1] = V[j] - 1;
                    notRoot[G[i][j - 1]] = true;
                }
            }
            for (int i = 0; i < N; i++)
            {
                if (!notRoot[i])
                {
                    if (dfs(G, new bool[N], i))
                    {
                        diamond = true;
                        break;
                    }
                }
            }
            if (!diamond)
                Console.WriteLine("Case #{0}: No", t);
            else
                Console.WriteLine("Case #{0}: Yes", t);
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

    static void WriteList<T>(List<T> col)
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
