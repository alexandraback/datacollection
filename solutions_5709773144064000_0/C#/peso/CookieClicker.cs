using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;
using System.Threading;

namespace CookieClicker
{
    class CookieClicker
    {
        /// <summary>
        /// Compute time needed to buy N factories and win
        /// </summary>
        /// <param name="N">Number of factories to build</param>
        /// <returns></returns>
        static double TotalTime(double C, double F0, double F, int N) {
            double s = 0;
            for (int i = N - 1; i >= 0; i--)
            {
                s += 1 / (F0 + i * F);
            }
            return C * s;
        }
        static void Main(string[] args)
        {
            // Enforce English encoding of numbers
            Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");

            using (var rd = File.OpenText(args[0]))
            using (var wr = File.CreateText(args[1]))
            {
                int t = int.Parse(rd.ReadLine()); // test cases

                for (int i = 1; i <= t; i++)
                {
                    Console.WriteLine("Processing case #{0}", i);
                    double F0 = 2; // Initial cookie production rate
                    double C; // Cost of new cookie farm
                    double F; // Cookie farm production rate
                    double X; // Target cookie count
                    string[] s = rd.ReadLine().Split(' ');
                    C = double.Parse(s[0]); // 1 .. 10 000
                    F = double.Parse(s[1]); // 1 .. 100
                    X = double.Parse(s[2]); // 1 .. 100 000
                    Console.WriteLine("  C={0} F={1} X={2}", C,F,X);

                    // Compute theoretical optimal number of factories
                    double n_max = (X - C) / C - F0 / F;
                    Console.WriteLine("  n = {0}", n_max);

                    // First compute for floor(n)
                    int n = Convert.ToInt32(Math.Floor(n_max)); // Factories to build
                    if (n < 0) n = 0;
                    double buildTime = TotalTime(C,F0,F,n);
                    double winTime = X / (F0 + n*F);
                    double t_low = buildTime + winTime;

                    // Now compute time for floor(n)+1
                    buildTime += C / (F0 + n * F);
                    winTime = X / (F0 + (n+1) * F);
                    double t_high = buildTime + winTime;

                    wr.WriteLine("Case #{0}: {1}", i, Math.Min(t_low, t_high));
                }
            }
        }
    }
}
