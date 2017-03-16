using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ_1A_A1
{
    class Program
    {
        static double f(long a, long m)
        {
            return ((double)a + a + 4 * (m - 1)) * m / 2;
        }

        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int nc = 1; nc <= T; nc++)
            {
                string[] ss = Console.ReadLine().Split(' ');
                long r = long.Parse(ss[0]);
                long t = long.Parse(ss[1]);

                long a = 2 * r + 1;
                long lb = 0;
                long ub = int.MaxValue;
                long m = (lb + ub) / 2;

                while (!(f(a, m) <= t && f(a, m + 1) > t))
                {
                    if (f(a, m) > t) ub = m;
                    else lb = m;
                    m = (lb + ub) / 2;
                }
                Console.WriteLine("Case #{0}: {1}", nc, m);
            }
        }
    }
}
