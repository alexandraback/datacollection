using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ProblemA
{
    class Program
    {
        const string InputPath = @"d:\Work\Current\CodeJam\2012-1A\1\A-large.in";
        const string OutputPath = @"d:\Work\Current\CodeJam\2012-1A\1\A-large.out";


        static void Main(string[] args)
        {

            var sr = new StreamReader(InputPath);
            var sw = new StreamWriter(OutputPath);

            int N = Int32.Parse(sr.ReadLine());
            for (int n = 1; n <= N; n++)
            {
                var x = SolveNextInput(sr);

                sw.WriteLine(GetCaseSolutionString(x, n));

            }
            sr.Close();
            sw.Close();
        }

        private static string GetCaseSolutionString(string result, int n)
        {
            return string.Format("Case #{0}: {1}", n, result);
        }

        private static string SolveNextInput(StreamReader sr)
        {
            string line1 = sr.ReadLine();
            var tx = line1.Split(' ').Select(t => int.Parse(t)).ToList();
            int A = tx[0];
            int B = tx[1];
            var line2 = sr.ReadLine();
            var ty = line2.Split(' ').Select(t => double.Parse(t)).ToList();

            double res = B + 2;
            for (int i = 0; i <= A; i++)
            {
                double success = 1;
                for (int j = 0; j < A-i; j++)
                {
                    success *= ty[j];
                }
                double rem = 2*i + B - A + B + 2 - success*(B + 1);
                if (rem < res)
                    res = rem;
            }
            string result = res.ToString("#.000000");

            return result;
        }

    }

}
