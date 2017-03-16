using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Dancing
{
    class Dancing
    {
        static string ProcessCase(TextReader rd)
        {
            var def = rd.ReadLine().Split(' ');

            int n = int.Parse(def[0]);
            int s = int.Parse(def[1]);
            int p = int.Parse(def[2]);

            int[] totals = new int[n];
            for (int i = 0; i < n; i++)
            {
                totals[i] = int.Parse(def[3 + i]);
            }

            int countDef = 0;
            int countIfSur = 0;

            foreach (var t in totals)
            {
                int maxUnsur = t / 3;
                if ((t % 3) > 0)
                    maxUnsur++;
                if (maxUnsur >= p)
                    countDef++;
                else
                {
                    int maxSur = 
                        (t > 2)
                            ? (t + 4) / 3   // Could have up to extra 4 points to bring all scores to best result
                            : t;            // If total is 0 - 2, then max is equal to total (others could be 0)

                    if (maxSur >= p)
                        countIfSur++;
                }
            }

            int result = countDef + Math.Min(countIfSur, s);

            return result.ToString();
        }

        static void Main(string[] args)
        {
            //const string InFile = @"C:\Users\Owen\Downloads\B-Eg.txt";
            const string InFile = @"C:\Users\Owen\Downloads\B-small-attempt0.in";
            //const string InFile = @"C:\Users\Owen\Downloads\A-large-practice.in";

            using (var rd = File.OpenText(InFile))
            using (var wr = File.CreateText(@"C:\Users\Owen\Downloads\Out.txt"))
            {
                int t = int.Parse(rd.ReadLine());

                for (int i = 1; i <= t; i++)
                {
                    var result = ProcessCase(rd);
                    Console.WriteLine("Case #{0}: {1}", i, result);
                    wr.WriteLine("Case #{0}: {1}", i, result);
                }
            }
        }
    }
}
