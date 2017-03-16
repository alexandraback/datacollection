using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace GJam_R1SubB_A
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
            for (int i = 1; i <= testCount; i++)
            {
                string line = lines[i];
                string[] digits = line.Split(new char[]{' '});
                int N = int.Parse(digits[0]);
                int[] judges = new int[N];
                for (int j = 0; j < N; j++)
                {
                    judges[j] = int.Parse(digits[j+1]);
                }

                double[] res = GetVotesLevels(N, judges);

                File.AppendAllText(filename + ".out", "Case #" + (i) + ": ");
                for (int j = 0; j < res.Length; j++)
                {
                    File.AppendAllText(filename + ".out", res[j].ToString("g", culture) + " ");
                }

                File.AppendAllText(filename + ".out", "\n");
            }
        }

        private static double[] GetVotesLevels(int N, int[] judges)
        {
            double sum = 0;

            for (int i = 0; i < N; i++)
                sum += judges[i];

            double[] res = new double[N];
            double limit = 2*sum/N;
            int K1 = 0;
            double S1 = 0;

            for (int i = 0; i < N; i++)
                if (judges[i] < limit)
                {
                    K1++;
                    S1 += judges[i];
                }

            for (int i = 0; i < N; i++)
            {
                if (judges[i] >= limit)
                {
                    res[i] = 0;
                    continue;

                }

                res[i] = (((sum + S1) / K1 - judges[i]) / sum) * 100.0;

                if (res[i] < 0)
                    res[i] = 0;
            }

            return res;
        }
    }
}
