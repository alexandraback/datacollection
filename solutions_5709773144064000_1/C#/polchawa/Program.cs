using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;

namespace GCJCookieClicker
{
    class Program
    {
        private static class InputParser
        {
            private static string ReadLine()
            {
                var lineStr = Console.ReadLine();
                if (string.IsNullOrEmpty(lineStr))
                    throw new Exception("Missing line");
                return lineStr;
            }

            private static double ParseDoubleFromStr(string str)
            {
                double result;
                if (!double.TryParse(str, NumberStyles.Any, CultureInfo.InvariantCulture, out result))
                    throw new Exception(string.Format("Invalid string: {0}", str));
                return result;
            }

            private static IEnumerable<string> ReadLineFragments()
            {
                return ReadLine().Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            }

            public static IEnumerable<double> ReadLineDoubles()
            {
                return ReadLineFragments().Select(ParseDoubleFromStr);
            }

            private static int ParseIntFromStr(string str)
            {
                int result;
                if (!int.TryParse(str, out result))
                    throw new Exception(string.Format("Invalid string: {0}", str));
                return result;
            }

            public static int ReadLineInt()
            {
                var lineStr = ReadLine();

                return ParseIntFromStr(lineStr);
            }
        }

        static void Main(string[] args)
        {
            //TestAll();
            //TestPerformance();

            SolveTestCases();
        }

        private static void SolveTestCases()
        {
            var testCases = InputParser.ReadLineInt();
            for (var test = 1; test <= testCases; ++test)
            {
                var input = InputParser.ReadLineDoubles().ToArray();
                if (input.Length != 3)
                    throw new Exception(string.Format("Invalid input length: {0}", input.Length));

                var solutionNaive = Solve(input[0], input[1], input[2], false);
                var solutionSmart = Solve(input[0], input[1], input[2], true);
                if (Math.Abs(solutionNaive - solutionSmart) > 1e-6)
                    throw new Exception("Different solutions: " + solutionNaive + " and " + solutionSmart);

                Console.WriteLine("Case #{0}: {1}", test, solutionNaive.ToString("F7", CultureInfo.InvariantCulture));
            }
        }

        private static double Solve(double C, double F, double X, bool smartSolution)
        {
            var minimum = double.MaxValue;

            int kStart, kEnd;

            if (smartSolution)
            {
                var kZero = X / C - 2 / F - 2;
                const int offset = 2;
                kStart = Math.Max(0, Convert.ToInt32(Math.Floor(kZero) - offset));
                kEnd = Math.Max(kStart, Convert.ToInt32(Math.Ceiling(kZero) + offset));
            }
            else
            {
                kStart = 0;
                kEnd = int.MaxValue;
            }

            var timeToCollectKFarms = Enumerable.Range(0, kStart).Sum(i => C / (2.0 + i*F));

            for (var k = kStart; k <= kEnd; ++k)
            {
                timeToCollectKFarms += C / (2.0 + k*F);

                var timeToCollectX = X / (2 + (k + 1)*F);
                var candidate = timeToCollectKFarms + timeToCollectX;

                if (!smartSolution && candidate > minimum + 1e-6 && k > kStart)
                    break;

                minimum = Math.Min(minimum, candidate);
            }
            return Math.Min(X / 2, minimum);
        }

        private static void TestAll()
        {
            foreach (var f in new[] { 1, 10, 49, 56, 100, 123, 200} )
            {
                foreach (var c in new[] {1, 13, 123, 500, 1325, 4096, 9999, 10000})
                {
                    foreach (var x in new[] {1, 11, 13, 17, 121, 23432, 23543, 99999, 100000})
                    {
                        var a = Solve(1, f, x, true);
                        var b = Solve(1, f, x, false);
                        if (Math.Abs(a - b) > 1e-6)
                        {
                            Console.WriteLine(f);
                            Console.WriteLine("How about a magic trick ?");
                            Console.ReadLine();
                        }
                    }
                }
            }
            Console.WriteLine("Done");
            Console.ReadLine();
        }

        private static void TestPerformance()
        {
            for (var test = 1; test <= 100; ++test)
                Solve(1, 2, 100000-test, false);
            Console.WriteLine("Done");
            Console.ReadLine();
        }
    }
}
