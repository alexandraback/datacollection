using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace C
{
    class Program
    {
        static void Main(string[] args)
        {
            int T, t;
            int N, M, K;
            string[] strs;
            int s;
            int a, b;
            int c, c1, c2, c3;

            using (StreamReader sr = new StreamReader("C-small-attempt0.in"))
            {
                using (StreamWriter sw = new StreamWriter("C-small-attempt0.out"))
                {
                    T = Convert.ToInt32(sr.ReadLine());

                    for (t = 1; t <= T; t++)
                    {
                        strs = sr.ReadLine().Split(new char[] { ' ' });
                        N = Convert.ToInt32(strs[0]);
                        M = Convert.ToInt32(strs[1]);
                        K = Convert.ToInt32(strs[2]);

                        if (N <= 2 || M <= 2)
                        {
                            sw.WriteLine(String.Format("Case #{0}: {1}", t, K));
                        }
                        else
                        {
                            s = (int)Math.Sqrt(K + 4);

                            c = Int32.MaxValue;
                            if (s < N && s < M)
                            {
                                c1 = s * s - 4;
                                if (c1 >= K)
                                    c = Math.Min(c, 4 * (s - 2));
                                else
                                    c = Math.Min(c, 4 * (s - 2) + K - c1);
                            }

                            if (s < Math.Max(N, M) && s <= Math.Min(N, M))
                            {
                                c1 = (s + 1) * s - 4;
                                if (c1 >= K)
                                    c = Math.Min(c, 2 * (s - 1) + 2 * (s - 2));
                                else
                                    c = Math.Min(c, 2 * (s - 1) + 2 * (s - 2) + K - c1);
                            }

                            if (s < Math.Max(N, M) && s < Math.Min(N, M))
                            {
                                c1 = (s + 1) * (s + 1) - 4;
                                if (c1 >= K)
                                    c = Math.Min(c, 4 * (s - 1));
                                else
                                    c = Math.Min(c, 4 * (s - 1) + K - c1);
                            }

                            c = Math.Min(c, Calc(N, M, K));
                            c = Math.Min(c, Calc(M, N, K));

                            sw.WriteLine(String.Format("Case #{0}: {1}", t, c));
                        }
                    }

                    sw.Flush();
                    sw.Close();
                }

                sr.Close();
            }
        }

        static int Calc(int n, int m, int k)
        {
            int c1;
            int c = Int32.MaxValue;

            int s = (int)((k + 4.0) / n);

            if (s <= m)
            {
                c1 = n * s - 4;
                if (c1 >= k)
                    c = Math.Min(c, 2 * (n - 2) + 2 * (s - 2));
                else
                    c = Math.Min(c, 2 * (n - 2) + 2 * (s - 2) + k - c1);
            }

            if (s < m)
            {
                c1 = n * (s + 1) - 4;
                if (c1 >= k)
                    c = Math.Min(c, 2 * (n - 2) + 2 * (s - 1));
                else
                    c = Math.Min(c, 2 * (n - 2) + 2 * (s - 1) + k - c1);
            }

            c1 = n * m - 4;
            if (c1 >= k)
                c = Math.Min(c, 2 * (n - 2) + 2 * (m - 2));
            else
                c = Math.Min(c, 2 * (n - 2) + 2 * (m - 2) + k - c1);

            return c;
        }
    }
}
