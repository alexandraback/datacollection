using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Numerics;

namespace C
{
    class Program
    {
        static bool[] row;
        static int R, C, M;

        static int[,] map;

        static int Around(int y, int x)
        {
            int count = 0;
            for (int i = y - 1; i <= y + 1; i++)
                for (int j = x - 1; j <= x + 1; j++)
                    if(i >= 0 && i < R && j >= 0 && j < C && map[i, j] == 10)
                        count++;
            return count;
        }

        static void Restore()
        {
            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++)
                    map[i, j] = (row[i * C + j]) ? 10 : -1;
        }

        static bool Untouched()
        {
            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++)
                    if (map[i, j] == -1)
                        return true;
            return false;            
        }

        static void Spread(int y, int x)
        {
            if (y >= 0 && y < R && x >= 0 && x < C)
            {
                if (map[y, x] != -1)
                    return;

                map[y, x] = Around(y, x);
                if (map[y, x] == 0)
                    for (int i = y - 1; i <= y + 1; i++)
                        for (int j = x - 1; j <= x + 1; j++)
                            Spread(i, j);
            }
        }

        static bool Analyze()
        {
            map = new int[R, C];
            Restore();

            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++)
                {
                    if (map[i, j] == 10)
                        continue;

                    Spread(i, j);
                    if (!Untouched())
                    {
                        map[i, j] = 11;
                        return true;
                    }

                    Restore();
                }

            return false;
        }

        static bool Generate(int p, int rest)
        {
            int N = R * C;

            if (rest == 0)
            {
                for (; p < N; p++)
                    row[p] = false;
                return Analyze();
            }

            if (N - p == rest)
            {
                for (; p < N; p++)
                    row[p] = true;
                return Analyze();
            }

            row[p] = false;
            if (Generate(p + 1, rest))
                return true;
            row[p] = true;
            return Generate(p + 1, rest - 1);
        }

        static void Solve()
        {
            row = new bool[R * C];
            if (!Generate(0, M))
                Console.WriteLine("Impossible");
            else
            {
                for (int i = 0; i < R; i++)
                {
                    for (int j = 0; j < C; j++)
                    {
                        int c = map[i, j];
                        Console.Write(c == 10 ? '*' : c == 11 ? 'c' : '.');
                        //Console.Write(c == 10 ? '*' : c == -1 ? '.' : (char)('0' + c));
                    }
                    Console.WriteLine();
                }
                    
            }
        }

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            int T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                string[] line = Console.ReadLine().Split();
                R = int.Parse(line[0]);
                C = int.Parse(line[1]);
                M = int.Parse(line[2]);
                Console.WriteLine("Case #{0}:", t);
                Solve();
            }
        }
    }
}
