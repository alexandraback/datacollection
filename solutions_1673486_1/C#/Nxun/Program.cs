using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace a
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("in.txt");
            StreamWriter sw = new StreamWriter("out.txt");

            int T = int.Parse(sr.ReadLine());
            for (int t = 1; t <= T; ++t)
            {
                string[] ss = sr.ReadLine().Split();
                int A = int.Parse(ss[0]);
                int B = int.Parse(ss[1]);
                ss = sr.ReadLine().Split();
                double[] Probability = new double[A + 1];
                for (int i = 1; i <= A; ++i)
                {
                    Probability[i] = double.Parse(ss[i - 1]);
                }
                double[] AllRight = new double[A + 1];
                AllRight[0] = 1.0;
                AllRight[1] = Probability[0];
                for (int i = 1; i <= A; ++i)
                {
                    AllRight[i] = AllRight[i - 1] * Probability[i];
                }

                double best = B + 2;
                for (int i = 0; i <= A; ++i)
                {
                    double ans = (A - i) + AllRight[i] * (B - i + 1) + (1 - AllRight[i]) * (B - i + 1 + B + 1);
                    if (best > ans)
                        best = ans;
                }
                sw.WriteLine("Case #{0}: {1:F6}", t, best);
            }

            sw.Close();
            sr.Close();
        }
    }
}
