using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using Helpers;

namespace _2015Q2
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
                    int D = reader.ReadLineAsInt();
                    int[] pancakes = reader.ReadLineAsIntArray();

                    var result = String.Format("Case #{0}: {1}", testcase, Solve(pancakes.ToList()));
                    writer.WriteLine(result);
                    Console.WriteLine(String.Format("{0} (ms: {1: 0.})", result, sw.Elapsed.TotalMilliseconds - lastMs));
                    lastMs = sw.Elapsed.TotalMilliseconds;
                }
            }
            Console.WriteLine(String.Format("Done. (ms: {0: 0.})", sw.Elapsed.TotalMilliseconds));
            Console.ReadKey();
        }

        private static int Solve(List<int> pancakes)
        {
            var result = 0;

            var ordered = pancakes.OrderByDescending(t => t).ToList();

            var firstMax = ordered[0];
            var secondMax = ordered.Count >= 2 ? ordered[1] : 0;
            var thirdMax = ordered.Count >= 3 ? ordered[2] : 0;
            var fourthMax = ordered.Count >= 4 ? ordered[3] : 0;

            if (firstMax == 1 || firstMax == 2 || firstMax == 3)
                return firstMax;

            if (firstMax == 4)
                return secondMax > 2 ? 4 : 3;

            if (firstMax == 5)
                return secondMax > 3 ? 5 : 4;

            if (firstMax == 6)
            {
                if (secondMax <= 3) return 4;
                if (secondMax == 4) return 5;
                return thirdMax <= 3 ? 5 : 6;
            }

            if (firstMax == 7)
            {
                if (secondMax <= 4) return 5;
                if (secondMax == 5) return 6;
                return thirdMax <= 4 ? 6 : 7;
            }

            if (firstMax == 8)
            {
                if (secondMax <= 4) return 5;
                if (secondMax == 5) return 6;
                if (thirdMax <= 4) return 6;
                if (secondMax == 6) return 7;
                return fourthMax <= 4 ? 7 : 8;
            }

            if (firstMax == 9)
            {
                var orderedHalf = ordered.ToList();
                var orderedThird = ordered.ToList();

                orderedHalf[0] = 5;
                orderedHalf.Add(4);

                orderedThird[0] = 6;
                orderedThird.Add(3);

                int resulthalf = Solve(orderedHalf);
                int resultthird = Solve(orderedThird);

                return Math.Min(Math.Min(resulthalf, resultthird) + 1, 9);
                //if (secondMax <= 3) return 5;
                //if (secondMax <= 5) return 6;
                //if (secondMax == 6 && thirdMax <= 3) return 6;
                //if (thirdMax <= 5) return 7;
                //if (secondMax == 6 && thirdMax == 6 && fourthMax <= 3) return 7;
                //if (secondMax == 6 && thirdMax == 6 && fourthMax <= 5) return 8;
                //if (secondMax == 6 && thirdMax == 6 && fourthMax == 6 && fifthMax <= 3) return 8;
                //if (secondMax == 6 && thirdMax == 6 && fourthMax == 6 && fifthMax > 3) return 9;
            }


            return result;
        }
    }
}
