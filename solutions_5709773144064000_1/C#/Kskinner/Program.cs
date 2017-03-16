using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
    public class Problem
    {
        double C, F, X;

        public string Solve()
        {
            var ar = ReadArray<double>();
            C = ar[0];
            F = ar[1];
            X = ar[2];

            double timeSoFar = 0.0;
            double rate = 2.0;

            while (true) {
                double timeToX = X / rate;
                double timeToNextFarm = C / rate;
                double timeToXWithNextFarm = timeToNextFarm + X / (rate + F);
                if (timeToX <= timeToXWithNextFarm)
                    return (timeSoFar + timeToX).ToString("F7");

                rate += F;
                timeSoFar += timeToNextFarm;
            }
        }

        static StreamReader reader;

        static void Main(string[] args)
        {
            string filename = args.Length > 0 ? args[0] : "test.in";
            string outFileName = filename.Replace(".in", ".out");

            using (reader = File.OpenText(filename))
            using (var outFile = File.CreateText(outFileName))
            {
                int T = ReadInt();
                Console.WriteLine("{0} test cases", T);

                for (int tc = 1; tc <= T; tc++)
                {
                    Console.WriteLine("Starting test case {0}", tc);
                    var problem = new Problem();
                    string solution = problem.Solve();

                    outFile.WriteLine("Case #{0}: {1}", tc, solution);
                    Console.WriteLine("Case #{0}: {1}", tc, solution);
                }
            }
        }

        #region Readers

        private static string ReadLine()
        {
            return reader.ReadLine();
        }

        private static int ReadInt()
        {
            return int.Parse(ReadLine());
        }

        private static T Read<T>()
        {
            return (T)Convert.ChangeType(ReadLine(), typeof(T));
        }

        private static T[] ReadArray<T>()
        {
            return ReadLine().Split(' ').Select(v => (T)Convert.ChangeType(v, typeof(T))).ToArray();
        }

        #endregion
    }
}
