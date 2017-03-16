using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace c
{
    class Program
    {
        static int N;
        static int M;
        static long[,] a;
        static long[,] b;
        static long ans;

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("in.txt");
            StreamWriter sw = new StreamWriter("out.txt");

            int T = int.Parse(sr.ReadLine());
            for (int t = 1; t <= T; ++t)
            {
                string[] ss = sr.ReadLine().Split();
                N = int.Parse(ss[0]);
                M = int.Parse(ss[1]);
                a = new long[2, N];
                b = new long[2, M];
                ss = sr.ReadLine().Split();
                for (int i = 0; i < N; ++i)
                {
                    for (int j = 0; j < 2; ++j)
                    {
                        a[j, i] = long.Parse(ss[2 * i + j]);
                    }
                }
                ss = sr.ReadLine().Split();
                for (int i = 0; i < M; ++i)
                {
                    for (int j = 0; j < 2; ++j)
                    {
                        b[j, i] = long.Parse(ss[2 * i + j]);
                    }
                }

                ans = 0;
                Solve(0, 0, 0, 0, 0);

                sw.WriteLine("Case #{0}: {1}", t, ans);
            }

            sw.Close();
            sr.Close();
        }

        //static void Solve(int x, int y, long usedy, long count)
        //{
        //    if (x >= N || y >= M)
        //    {
        //        if (ans < count)
        //            ans = count;
        //        return;
        //    }
        //    Solve(x + 1, y, usedy, count);
        //    long c = count;
        //    for (int j = y; j < M; ++j)
        //    {
        //        if (a[1, x] == b[1, j])
        //        {
        //            c += b[0, j];
        //            if (c <= a[0, x])
        //            {
        //                Solve(x + 1, j + 1, 0, c);
        //            }
        //            else
        //            {
        //                Solve(x + 1, j, 0, c);
        //            }
        //        }

        //    }
        //}

        static void Solve(int m, int k, int whichismore, long used, long c)
        {
            if (k >= N)
            {
                if (ans < c)
                    ans = c;
                return;
            }
            Solve(m, k + 1, 0, 0, c);
            for (int j = m; j < M; ++j)
            {
                if (a[1, k] == b[1, j])
                {
                    long aa = a[0, k] - (whichismore == 1 ? used : 0);
                    long bb = b[0, j] - (whichismore == 2 ? used : 0);
                    Solve(j + 1, k + 1, 0, 0, c + Math.Min(aa, bb));
                    if (aa < bb)
                    {
                        Solve(j, k + 1, 2, whichismore == 2 ? used + aa : aa, c + Math.Min(aa, bb));
                    }
                    if (aa > bb)
                    {
                        Solve(j + 1, k, 1, whichismore == 1 ? used + bb : bb, c + Math.Min(aa, bb));
                    }
                }
            }
        }
    }
}
