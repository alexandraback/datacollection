using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Numerics;

namespace D
{
    class Program
    {
        static string Solve(double[] naomi, double[] ken)
        {
            Array.Sort(naomi);
            Array.Sort(ken);

            int w = 0;
            for (int p = 0, q = 0; q < ken.Length; q++)
            {
                if (ken[q] > naomi[p])
                {
                    w++; p++;
                }
            }

            int dw = 0;
            for (int p = 0, q = 0; p < naomi.Length; p++)
            {
                if (naomi[p] > ken[q])
                {
                    dw++;  q++;
                }
            }

            return string.Format("{0} {1}", dw, naomi.Length - w);
        }

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            int T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                int N = int.Parse(Console.ReadLine());
                double[] naomi = Array.ConvertAll(Console.ReadLine().Split(), double.Parse);
                double[] ken = Array.ConvertAll(Console.ReadLine().Split(), double.Parse);
                Console.WriteLine("Case #{0}: {1}", t, Solve(naomi, ken));
            }
        }
    }
}
