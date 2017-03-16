using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Numerics;

namespace B
{
    class Program
    {
        static double Solve(double C, double F, double X)
        {
            int n = 0;
            while (X / (2 + F * n) > C / (2 + F * n) + X / (2 + F * (n + 1)))
                n++;

            double sum = 0.0;
            for (int i = n - 1; i >= 0; i--)
                sum += C / (2 + F * i);

            sum += X / (2 + F * n);
            return sum;
        }

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            int T = int.Parse(Console.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                string[] line = Console.ReadLine().Split();
                double C = double.Parse(line[0]);
                double F = double.Parse(line[1]);
                double X = double.Parse(line[2]);
                Console.WriteLine("Case #{0}: {1:0.0000000}", t, Solve(C, F, X));
            }
        }
    }
}
