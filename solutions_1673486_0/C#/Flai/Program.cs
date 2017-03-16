using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace GCJ
{
    class Program
    {
        private const string inFilePath = @"A:\Users\Zeikko\Desktop\A-small-attempt2.in";
        private const string outFilePath = "C:\\file.out";

        static void Main(string[] args)
        {
            var reader = OpenReader();
            var writer = OpenWriter();
            int cases = int.Parse(reader.ReadLine());

            int c = 1;
            while (c <= cases)
            {
                string firstLine = reader.ReadLine();
                string secondLine = reader.ReadLine();

                string[] firstParts = firstLine.Split(' ');
                int typed = int.Parse(firstParts[0]);
                int total = int.Parse(firstParts[1]);

                string[] p = secondLine.Split(' ');
                double[] probabilities = new double[p.Length];

                for(int x = 0; x < p.Length; x++)
                {
                    probabilities[x] = double.Parse(p[x], System.Globalization.CultureInfo.InvariantCulture);
                }
                

                double propabilitySoFar = 1;
                for (int x = 0; x < Math.Min(typed, probabilities.Length); x++)
                {
                    propabilitySoFar *= probabilities[x];
                }

                double best = Math.Min(FindBest(typed, total, propabilitySoFar, probabilities), EnterRightAway(typed, total));
                writer.WriteLine("Case #{0}: {1}", c, best.ToString(System.Globalization.CultureInfo.InvariantCulture));
                c++;
            }
            writer.Flush();
        }

        public static double EnterRightAway(int typed, int total)
        {
            return total  + 2;
        }

        public static double KeepTyping(int typed, int total, int backspaces, double probSF) 
        {
            return probSF * (total - typed + 1 + backspaces) + (total + (total - typed + backspaces) + 2) * (1 - probSF);
        }

        public static double FindBest(int typed, int total, double probSF, double[] probs)
        {
            double best = int.MaxValue;
            for (int x = typed; x >= 0; x--)
            {
                double prob = 1;
                for(int y = 0; y < x; y++)
                {
                    prob *= probs[y];
                }
                double val = KeepTyping(x, total, (typed-x), prob);
                if (val < best)
                    best = val;
            }

            return best;
        }

        public static StreamReader OpenReader()
        {
            return new StreamReader(inFilePath);
        }

        public static StreamWriter OpenWriter()
        {
            return new StreamWriter(outFilePath) { AutoFlush = true };
        }

        public static void WriteCase(int i)
        {
            Console.Write("Case ");
        }

    }
}
