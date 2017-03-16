using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;

namespace ProblemA
{
    class Program
    {
        class Solver
        {
            public double Solve(int n, int x, int y)
            {
                int m = 1;
                int l = 1;
                while (true)
                {
                    l += 2;
                    if (m + l + l - 1 > n)
                        break;
                    m += l + l - 1;
                }

                if (Math.Abs(x) + y <= l - 3)
                {
                    return 1;
                }

                if (Math.Abs(x) + y > l - 1 || x == 0)
                {
                    return 0;
                }

                l -= 1;
                n -= m;

                double[] p = new double[l + 1];
                p[0] = 1;
                for (int i = 0; i < l; i++)
                {
                    if (n == 2 * l - i)
                    {
                        return 1 - p[l - y];
                    }
                    for (int j = l; j > 0; j--)
                    {
                        p[j] = 0.5 * (p[j] + p[j - 1]);
                    }
                    if (i + 1 == n)
                    {
                        return p[y + 1];
                    }
                }

                return 0;
            }
        }

        static void Main(string[] args)
        {
            //string filename = "sample";
            string filename = "B-small-attempt0";
            //string filename = "B-large";
            using (StreamReader reader = new StreamReader("..\\..\\" + filename + ".in"))
            {
                using (StreamWriter writer = new StreamWriter("..\\..\\" + filename + ".out"))
                {
                    int T = Int32.Parse(reader.ReadLine());
                    Solver solver = new Solver();
                    for (int i = 0; i < T; i++)
                    {
                        string[] tmp = reader.ReadLine().Split();
                        int n = Int32.Parse(tmp[0]);
                        int x = Int32.Parse(tmp[1]);
                        int y = Int32.Parse(tmp[2]);
                        writer.WriteLine("Case #" + (i + 1) + ": " +
                            solver.Solve(n, x, y).ToString(CultureInfo.InvariantCulture));
                    }
                }
            }
        }
    }
}
