using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using Helpers;

namespace _2015Q4
{
    class Program
    {
        static void Main(string[] args)
        {
            System.Threading.Thread.CurrentThread.CurrentCulture = new CultureInfo("en-US");
            System.Threading.Thread.CurrentThread.CurrentUICulture = new CultureInfo("en-US");
            double lastMs = 0;
            Stopwatch sw = new Stopwatch();
            sw.Start();

            var inFileName = "A_small.in";
            var outFileName = inFileName.Replace(".in", "_out.out");
            using (var reader = new StreamReader(inFileName))
            using (var writer = new StreamWriter(outFileName))
            {
                int numTests = reader.ReadLineAsInt();

                for (int testcase = 1; testcase <= numTests; testcase++)
                {
                    var arr = reader.ReadLineAsIntArray();
                    int X = arr[0];
                    int R = arr[1];
                    int C = arr[2];

                    var result = String.Format("Case #{0}: {1}", testcase, Solve(X, R, C) ? "GABRIEL" : "RICHARD");
                    writer.WriteLine(result);
                    Console.WriteLine(String.Format("{0} (ms: {1: 0.})", result, sw.Elapsed.TotalMilliseconds - lastMs));
                    lastMs = sw.Elapsed.TotalMilliseconds;
                }
            }
            Console.WriteLine(String.Format("Done. (ms: {0: 0.})", sw.Elapsed.TotalMilliseconds));
            Console.ReadKey();
        }

        private static bool Solve(int X, int R, int C)
        {
            if (X == 1)
                return true;

            if (X >= 7)
                return false;

            if (((R * C) % X) != 0)
                return false;

            int minDim = (X / 2) + (X % 2);
            if (R < minDim || C < minDim)
                return false;

            if (X == 2 || X == 3)
                return true;

            if (X == 5 && (R == 3 || C == 3) && R*C > 15)     // 3x5 false, 3x10+ true
                return true;

            return (R > minDim && C > minDim);
        }
    }
}
