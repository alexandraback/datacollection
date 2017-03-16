using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ12_1A_A
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int nt = 1; nt <= T; nt++)
            {
                string[] ss = Console.ReadLine().Split(' ');
                int A = int.Parse(ss[0]);
                int B = int.Parse(ss[1]);
                double[] p = new double[A+1];
                ss = Console.ReadLine().Split(' ');
                p[0] = 1.0;
                for (int i = 1; i <= A; i++) p[i] = p[i - 1] * double.Parse(ss[i-1]);
                double min = double.MaxValue;
                for (int i = 0; i <= A; i++)
                {
                    double cp = p[A - i] * (B - (A-i) + 1 + i) + (1 - p[A - i]) * (B - (A-i) + 1 + B + 1 + i);
                    min = Math.Min(min, cp);
                }
                min = Math.Min(min, B + 2);
                Console.WriteLine("Case #{0}: {1:0.000000}", nt, min);
            }
        }
    }
}
