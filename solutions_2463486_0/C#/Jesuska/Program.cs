using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using Helpers;

namespace _2013Q3
{
    class Program
    {
        static void Main()
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

                HashSet<long> sqNumbers = GetSqrPoliNumbersBetween(1, (long)10000000 * 10000000);      // 1 - 10^14

                for (int testcase = 1; testcase <= numTests; testcase++)
                {
                    long[] la = reader.ReadLineAsLongArray();
                    long A = la[0];
                    long B = la[1];

                    var result = String.Format("Case #{0}: {1}", testcase, Solve(A, B, sqNumbers));
                    writer.WriteLine(result);
                    Console.WriteLine(String.Format("{0} (ms: {1: 0.})", result, sw.Elapsed.TotalMilliseconds - lastMs));
                    lastMs = sw.Elapsed.TotalMilliseconds;
                }
            }
            Console.WriteLine(String.Format("Done. (ms: {0: 0.})", sw.Elapsed.TotalMilliseconds));
            Console.ReadKey();
        }

        private static int Solve(long A, long B, HashSet<long> sqNumbers)
        {
            int counter = 0;

            foreach (long sqNumber in sqNumbers)
            {
                if (sqNumber >= A && sqNumber <=B)
                    counter++;
            }

            return counter;
        }

        private static HashSet<long> GetSqrPoliNumbersBetween(long A, long B)
        {
            HashSet<long> result = new HashSet<long>();

            for (long i = A; i<=Math.Sqrt(B); i++)
            {
                if (IsPolindrome(i))
                {
                    long sqr = (long)Math.Pow(i, 2);
                    if (IsPolindrome(sqr))
                        result.Add(sqr);
                }
            }

            return result;
        }

        private static bool IsPolindrome(long l)
        {
            char[] arr = l.ToString().ToCharArray();
            Array.Reverse(arr);
            return (long.Parse(new string(arr)) == l);
        }
    }
}
