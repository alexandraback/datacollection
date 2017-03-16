using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using Helpers;

namespace _2015Q1
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

            var inFileName = "A_large.in";
            var outFileName = inFileName.Replace(".in", "_out.out");
            using (var reader = new StreamReader(inFileName))
            using (var writer = new StreamWriter(outFileName))
            {
                int numTests = reader.ReadLineAsInt();

                for (int testcase = 1; testcase <= numTests; testcase++)
                {
                    var arr = reader.ReadLineAsStringArray();
                    int SMax = int.Parse(arr[0]);
                    int[] audience = arr[1].ToCharArray().Select(t=> (int)Char.GetNumericValue(t)).ToArray();

                    var result = String.Format("Case #{0}: {1}", testcase, Solve(SMax, audience));
                    writer.WriteLine(result);
                    Console.WriteLine(String.Format("{0} (ms: {1: 0.})", result, sw.Elapsed.TotalMilliseconds - lastMs));
                    lastMs = sw.Elapsed.TotalMilliseconds;
                }
            }
            Console.WriteLine(String.Format("Done. (ms: {0: 0.})", sw.Elapsed.TotalMilliseconds));
            Console.ReadKey();
        }

        private static int Solve(int smax, int[] audience)
        {
            var result = 0;
            var sum = audience[0];
            for (int i = 1; i <= smax; i++)
            {
                if (i > sum)
                {
                    int usersToInvite = (i - sum);
                    result += usersToInvite;
                    sum += usersToInvite;
                }

                sum += audience[i];
            }
            return result;
        }
    }
}
