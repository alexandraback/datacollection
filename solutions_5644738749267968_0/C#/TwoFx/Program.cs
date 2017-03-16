using System;
using System.Linq;
using System.IO;
using System.Collections.Generic;

namespace _20140_Deceitful_War
{
    class Program
    {
        private const bool DEBUG = false;
        static void debug()
        {
            Console.WriteLine(simulateDeceitful(new[] { 0.186, 0.389, 0.907, 0.832, 0.959, 0.557, 0.300, 0.992, 0.899, }.OrderBy(x => x).ToArray(),
                new[] { 0.916, 0.728, 0.271, 0.520, 0.700, 0.521, 0.215, 0.341, 0.458 }.OrderBy(x => x).ToArray()));
        }

        static string solveCase(Func<string> readLine)
        {
            readLine();
            double[] naomi = readLine().Split(' ').Select(x => double.Parse(x)).OrderBy(x => x).ToArray();
            double[] ken = readLine().Split(' ').Select(x => double.Parse(x)).OrderBy(x => x).ToArray();
            int war = simulateWar((double[])naomi.Clone(), (double[])ken.Clone());
            int deceitful = simulateDeceitful((double[])naomi.Clone(), (double[])ken.Clone());
            return String.Format("{0} {1}", deceitful, war);
        }

        static int simulateWar(double[] anaomi, double[] aken)
        {
            List<double> ken = new List<double>(aken);
            List<double> naomi = new List<double>(anaomi.Reverse());
            int points = 0;
            foreach (double block in anaomi)
            {
                double kens = simulateKen(block, ken);
                if (block > kens) points++;
            }
            return points;
        }

        static int simulateDeceitful(double[] anaomi, double[] aken)
        {
            List<double> ken = new List<double>(aken);
            List<double> naomi = new List<double>(anaomi);
            int points = 0;
            while (naomi.Min() < ken.Min())
            {
                ken.Remove(ken.Last());
                naomi.Remove(naomi.First());
                if (ken.Count == 0) return 0;
            }
            while (naomi.Count > 0)
            {
                double kmin = ken.Min();
                double kmax = ken.Max();
                double naomichosen = naomi.FirstOrDefault(c => c > kmin);
                double naomitold;
                if (naomichosen == 0)
                {
                    naomichosen = naomi[0];
                    naomitold = kmax - 0.000000001;
                }
                else
                {
                    naomitold = kmax + 0.000000001;
                }
                naomi.Remove(naomichosen);
                double kenchosen = simulateKen(naomitold, ken);
                if (naomichosen > kenchosen) points++;
            }
            return points;
        }

        static double simulateKen(double naomitold, List<double> kens)
        {
            double chosen = kens.FirstOrDefault(b => b > naomitold);
            if (chosen == 0) chosen = kens[0];
            kens.Remove(chosen);
            return chosen;
        }

        static void Main(string[] args)
        {
            if (DEBUG)
            {
                debug();
            }
            else
            {
                GCJ.Initialize();
                GCJ.SolveAll(solveCase);
            }
            Console.ReadKey();
        }
    }

    static class GCJ
    {
        private static StreamReader inf;
        private static StreamWriter outf;

        private delegate void o(string format, params object[] args);
        private static o Output;

        public static void Initialize()
        {
            Console.Write("Input file: ");
            inf = new StreamReader(Console.ReadLine());
            Console.Write("Output file: ");
            outf = new StreamWriter(Console.ReadLine());
            Output = Console.WriteLine;
            Output += outf.WriteLine;
        }

        public static void SolveAll(Func<Func<string>, string> calc)
        {
            int cases = int.Parse(inf.ReadLine());
            for (int @case = 1; @case <= cases; @case++)
            {
                Output("Case #{0}: {1}", @case, calc(inf.ReadLine));
            }
            inf.Close();
            outf.Close();
            Console.WriteLine("Eureka!");
        }
    }
}
