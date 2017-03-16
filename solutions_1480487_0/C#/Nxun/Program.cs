using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace a
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("A-small-attempt1.in");
            StreamWriter sw = new StreamWriter("out.txt");

            double eps = 1e-10;

            int T = int.Parse(sr.ReadLine());
            for (int t = 1; t <= T; ++t)
            {
                string[] ss = sr.ReadLine().Split();
                int N = int.Parse(ss[0]);
                int[] J = new int[N];
                int JSum = 0;
                for (int i = 0; i < N; ++i)
                {
                    J[i] = int.Parse(ss[i + 1]);
                    JSum += J[i];
                }

                sw.Write("Case #{0}:", t);
                for (int i = 0; i < N; ++i)
                {
                    double l = 0;
                    double r = 1.0;
                    double k = 0;
                    while (l < r - eps)
                    {
                        k = (l + r) / 2;
                        double x1 = (double)JSum * k;
                        double x2 = (double)JSum - x1;
                        x1 += J[i];
                        for (int j = 0; j < N; ++j)
                        {
                            if (i != j && x1 > J[j])
                                x2 -= x1 - J[j];
                        }
                        if (x2 < eps)
                            r = k;
                        else
                            l = k;
                    }
                    sw.Write(" {0:F8}", k * 100);
                }
                //for (int i = 0; i < N; ++i)
                //{
                //    double s = 0;
                //    if (JSum != 0.0)
                //    {
                //        s = (2.0 * JSum - N * J[i]) / (N * JSum);
                //    }
                //    if (s < 0.0)
                //        s = 0.0;
                //    sw.Write(" {0}", s * 100);
                //}
                sw.WriteLine();
            }

            sw.Close();
            sr.Close();
        }
    }
}
