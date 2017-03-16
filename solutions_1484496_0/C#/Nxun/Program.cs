using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace c
{
    class Program
    {
        static StreamReader sr = new StreamReader("C-small-attempt2.in");
        static StreamWriter sw = new StreamWriter("out.txt");

        static int s1 = 0;
        static int s2 = 0;

        static void Main(string[] args)
        {
            

            int T = int.Parse(sr.ReadLine());
            for (int t = 1; t <= T; ++t)
            {
                string[] ss = sr.ReadLine().Split();
                int N = int.Parse(ss[0]);
                int[] a = new int[N];
                int[] f = new int[N];
                for (int i = 0; i < N; ++i)
                {
                    a[i] = int.Parse(ss[i + 1]);
                }
                sw.WriteLine("Case #{0}:", t);
                s1 = 0;
                s2 = 0;
                if (!Dfs(0, a, f))
                    sw.WriteLine("Impossible");
            }

            sw.Close();
            sr.Close();
        }

        private static bool Dfs(int x, int[] a, int[] f)
        {
            
            if (x != 0)
            {
                if (s1 == s2)
                {
                    for (int i = 0; i < x; ++i)
                        if (f[i] == 0)
                            sw.Write("{0} ", a[i]);
                    sw.WriteLine();
                    for (int i = 0; i < x; ++i)
                        if (f[i] == 1)
                            sw.Write("{0} ", a[i]);
                    sw.WriteLine();
                    return true;
                }
            }
            if (x >= a.Length)
            {
                return false;
            }
            f[x] = 0;
            s1 += a[x];
            if (Dfs(x + 1, a, f))
                return true;
            s1 -= a[x];
            f[x] = 1;
            s2 += a[x];
            if (Dfs(x + 1, a, f))
                return true;
            s2 -= a[x];
            f[x] = 2;
            if (Dfs(x + 1, a, f))
                return true;
            return false;
        }
    }
}
