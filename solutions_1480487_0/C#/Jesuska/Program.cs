using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using Helpers;

namespace _2012R1B1
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

                for (int testcase = 1; testcase <= numTests; testcase++)
                {
                    int[] line = reader.ReadLineAsIntArray();
                    int N = line[0];
                    int[] judge = new int[N];
                    for (int i = 1; i < line.Length; i++)
                    {
                        judge[i - 1] = line[i];
                    }

                    var result = String.Format("Case #{0}: {1}", testcase, Solve(N, judge));
                    writer.WriteLine(result);
                    Console.WriteLine(String.Format("{0} (ms: {1: 0.})", result, sw.Elapsed.TotalMilliseconds - lastMs));
                    lastMs = sw.Elapsed.TotalMilliseconds;
                }
            }
            Console.WriteLine(String.Format("Done. (ms: {0: 0.})", sw.Elapsed.TotalMilliseconds));
            Console.ReadKey();
        }

        private static string Solve(int N, int[] judge)
        {
            int sum = judge.Sum();

            int[] sortedJudge = judge.ToArray();
            Array.Sort(sortedJudge);

            int tempSum = sum;
            double minLimit = 0;
            for (int i = 0; i < N-1; i++)
            {
                int diff = sortedJudge[i + 1] - sortedJudge[i]; // need to complete until the greater one
                if (tempSum >= diff * (i + 1))
                {
                    tempSum -= diff * (i + 1);    // complete lower columns
                    minLimit += diff;
                    continue;
                }

                // we will have a breakpoint here
                minLimit += (tempSum / (double)(i + 1));
                tempSum = 0;
            }


            if (tempSum > 0)
            {
                // every columns must be grown
                minLimit += (tempSum / (double)N);
            }

            double[] result = new double[N];
            double limitMustBeReached = sortedJudge[0] + minLimit;
            for (int i = 0; i < N; i++)
            {
                if (judge[i] >= limitMustBeReached)
                {
                    result[i] = 0;
                    continue;
                }

                result[i] = (limitMustBeReached - judge[i])/sum;
            }

            string t = "";
            for (int i = 0; i < N; i++)
            {
                t += String.Format("{0: 0.000000}", result[i]*100);
            }

            return t;
        }
    }
}
