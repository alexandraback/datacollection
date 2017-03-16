using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam2012Round1A
{
    class Program
    {
        static void Main(string[] args)
        {
            string numCasesString = Console.ReadLine();

            int numCases = int.Parse(numCasesString);

            for (int i = 0; i < numCases; i++)
            {
                string firstLine = Console.ReadLine();
                int[] data = firstLine.Split(' ').Select(int.Parse).ToArray();
                string probsString = Console.ReadLine();
                double[] probs = probsString.Split(' ').Select(double.Parse).ToArray();
                double solved = Solve(data[0], data[1], probs);
                Console.WriteLine(string.Format("Case #{0}: {1}", i + 1, solved));
            }
        }

        private static double Solve(int numTyped, int numTotal, double[] probs)
        {
            double p1 = 1;
            foreach (double d in probs)
            {
                p1 *= d;
            }
            double e1 = (1 + numTotal - numTyped) * p1 + (2 + 2 * numTotal - numTyped) * (1 - p1);

            double minE = e1;

            double p2 = 1;
            for (int i = 1; i < numTyped; i++)
            {
                p2 *= probs[i - 1];
                double e2 = (1 + 2 * (numTyped - i) + numTotal - numTyped) * p2 + (2 + 2 * (numTyped - i) + 2 * numTotal - numTyped) * (1 - p2);
                minE = Math.Min(e2, minE);
            }

            double e3 = 2 + numTotal;
            minE = Math.Min(e3, minE);

            return minE;
        }
    }
}
