using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace GJam_R1SubA_A
{
    class Program
    {
        private static CultureInfo culture = new CultureInfo("en-US");

        static void Main(string[] args)
        {
            if (args.Length == 0) return;

            string filename = args[0];
            var lines = File.ReadLines(filename).ToList();

            int testCount = int.Parse(lines.ElementAt(0));
            int lineNum = 1;
            for (int i = 0; i < testCount; i++)
            {
                string firstLine = lines[lineNum];
                string[] tmp = firstLine.Split(new char[] { ' ' });
                int k = int.Parse(tmp[0]);
                int n = int.Parse(tmp[1]);
                lineNum++;

                string secondLine = lines[lineNum];
                string[] tmp2 = secondLine.Split(new char[] { ' ' });
                double[] probabilities = new double[tmp2.Length];
                for (int j = 0; j < tmp2.Length; j++)
                    probabilities[j] = double.Parse(tmp2[j], culture);

                lineNum++;

                double res = GetBestPassTriage(k, n, probabilities);
                File.AppendAllText(filename + ".out", "Case #" + (i + 1) + ": " + res.ToString("g", culture));
                File.AppendAllText(filename + ".out", "\n");
            }
        }

        private static double GetBestPassTriage(int k, int n, double[] probabilities)
        {
            double bestSolution = 2 * n + 2;

            //Press enter straight away
            if (k == n)
            {
                double poss1 = Multiply(probabilities, probabilities.Length);
                bestSolution = poss1 + (n + 2) * (1.0 - poss1);
            }
            else
            {
                bestSolution = n + 2;
            }

            for (int backCount = 0; backCount <= k; backCount++)
            {
                double prob1 = Multiply(probabilities, k-backCount);

                double curRes = prob1*(n+1-k+backCount) + (1.0-prob1)*(2*n+2-k+backCount) + backCount;


                if (bestSolution > curRes)
                    bestSolution = curRes;
            }

            return bestSolution;
        }

        private static double Multiply(double[] probabilities, int countFromStart)
        {
            double res = 1;
            for (int i = 0; i < countFromStart; i++)
                res *= probabilities[i];

            return res;
        }
    }
}
