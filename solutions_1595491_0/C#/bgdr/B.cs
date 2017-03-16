using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
namespace GoogleCodeJam
{
    class B
    {
        static int[] sum;
        static int p, N, s;
        static bool[,] incache;
        static int[,] cache;
        static int get(int from, int s)
        {
            int ret = 0;
            if (from == N) return 0;
            if (incache[from, s])
                return cache[from, s];
            for (int i = 0; i <= 10; ++i)
                for(int j = Math.Max(0, i - 2); j <= Math.Min(10, i + 2); ++j)
                    for (int k = Math.Max(0, i - 2); k <= Math.Min(10, i + 2); ++k)
                    {
                        if (Math.Abs(k - j) > 2) continue;

                        if (i + j + k == sum[from])
                        {
                            int best = Math.Max(i, Math.Max(j, k));
                            bool surp = Math.Abs(i - j) == 2 || Math.Abs(i - k) == 2 || Math.Abs(j - k) == 2;
                            if (surp && s == 0) continue;
                            ret = Math.Max(ret, (best >= p ? 1 : 0) + get(from + 1, surp ? s - 1 : s));
                        }
                    }
            incache[from, s] = true;
            cache[from, s] = ret;
            return ret;
        }
        public static void Main(String[] args)
        {
            int T;
            StreamReader sr = new StreamReader("B.in");
            StreamWriter sw = new StreamWriter("B.out");
            T = Int32.Parse(sr.ReadLine());
            for (int i = 1; i <= T; ++i)
            {
                string[] toks = sr.ReadLine().Split(' ');
                N = Int32.Parse(toks[0]);
                sum = new int[N];
                cache = new int[N, N + 1];
                incache = new bool[N, N + 1];
                p = Int32.Parse(toks[2]);
                s = Int32.Parse(toks[1]);

                for (int j = 0; j < N; j++)
                    sum[j] = Int32.Parse(toks[3 + j]);
                sw.WriteLine("Case #" + i + ": " + get(0, s));
            }
            sw.Close();
        }
    }
}
