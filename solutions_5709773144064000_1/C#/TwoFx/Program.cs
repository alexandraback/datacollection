using System;
using System.Linq;
using System.IO;

namespace _20140_Cookie_Clicker_Alpha
{
    class Program
    {
        private const bool DEBUG = false;
        static void debug()
        {
            Console.WriteLine(solveCase(() => "500.0 4.0 2000.0"));
        }

        static string solveCase(Func<string> readLine)
        {
            double[] cfx = readLine().Split(' ').Select(x => double.Parse(x)).ToArray();
            double rate = 2.0;
            double currentTime = 0;
            double currentBest;
            do
            {
                currentBest = currentTime + cfx[2] / rate;
                currentTime += cfx[0] / rate;
                rate += cfx[1];
            } while (currentTime + cfx[2] / rate < currentBest);
            return currentBest.ToString("F7");
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
