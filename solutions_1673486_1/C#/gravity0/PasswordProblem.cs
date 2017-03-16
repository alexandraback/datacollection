using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;
using System.Numerics;
using System.Globalization;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            Stopwatch sw = Stopwatch.StartNew();

            PasswordProblem.Go();

            sw.Stop();
            Console.WriteLine("Time spent {0} ms.", sw.ElapsedMilliseconds);
            Console.ReadKey(false);
        }
    }

    class PasswordProblem
    {
        public static void Go()
        {
            using (StreamReader sr = new StreamReader(@"C:\MyWorks\CodeJam\Data\PasswordProblem\A-large.in"))
            using (StreamWriter sw = new StreamWriter(@"C:\MyWorks\CodeJam\Data\PasswordProblem\A-large.out"))
            {
                string line = sr.ReadLine().Trim();
                int T = Int32.Parse(line);

                for (int i = 0; i < T; i++)
                {
                    Console.WriteLine("Processing Case #{0} ...", i + 1);

                    line = sr.ReadLine().Trim();
                    string[] split = line.Split();

                    int A = Int32.Parse(split[0]);
                    int B = Int32.Parse(split[1]);
                    
                    line = sr.ReadLine().Trim();
                    split = line.Split();

                    double[] P = new double[A];

                    for (int j = 0; j < A; j++)
                    {
                        P[j] = Double.Parse(split[j]);
                    }

                    sw.WriteLine("Case #{0}: {1}", i + 1, Solve(A, B, P));
                }
            }
        }

        private static string Solve(int A, int B, double[] P)
        {
            double dMinStroke = 1 + B + 1; // Press Enter and retype;

            for (int iBS = 0; iBS <= A; iBS++)
            {
                double dFix = 1;

                for (int j = 0; j < A - iBS; j++)
                    dFix *= P[j];

                double dStroke = dFix * (iBS + iBS + B - A + 1)
                    + (1 - dFix) * (iBS + iBS + B - A + 1 + B + 1);

                if (dMinStroke > dStroke)
                    dMinStroke = dStroke;

            }

            return dMinStroke.ToString("F6");

        }




    }
}
