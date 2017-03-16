using System;
using System.Collections.Generic;
using System.Text;

class C
{
    static void Main(string[] args)
    {
        int T = ReadInt();
        for (int t = 1; t <= T; ++t)
        {
            int[] V = ReadInts();
            int N = V[0];
            bool done = false;
            List<int>[] bag = new List<int>[5000000];
            List<int> pos = new List<int>();
            pos.Add(0);
            bag[0] = new List<int>();
            Console.WriteLine("Case #{0}:", t);
            for (int i = 1; i <= N && !done; i++)
            {
                int n = V[i];
                int count = pos.Count;
                for (int j = 0; j < count; j++)
                {
                    int p = pos[j];
                    int k = p + n;
                    if (bag[k] == null)
                    {
                        bag[k] = new List<int>(bag[p]);
                        bag[k].Add(n);
                        pos.Add(k);
                    }
                    else
                    {
                        bag[p].Add(n);
                        WriteArray(bag[k]);
                        WriteArray(bag[p]);
                        done = true;
                        break;
                    }
                }
            }
            if(!done)
                Console.WriteLine("Impossible");
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
        for (int i = 0; i < count-1; i++)
            Console.Write(col[i] + " ");
        Console.WriteLine(col[count-1]);
    }
}
