using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ
{
    class Program
    {
        static void Main(string[] args)
        {

            var root = @"D:\gcj\p2\";

            string[] input = System.IO.File.ReadAllLines(root + "small.txt");
            StreamWriter output = new StreamWriter(root + "out.txt");
            int numCases = Int32.Parse(input[0]);

            double[] data = input.Reverse().Take(input.Length - 1).Reverse().SelectMany(x => x.Split(' ').Select(y => Double.Parse(y))).ToArray();
            IEnumerator<double> scanner = data.AsEnumerable<double>().GetEnumerator();
            scanner.MoveNext();
            for (int nc = 0; nc < numCases; ++nc)
            {
                double C = scanner.Current;
                scanner.MoveNext();
                double F = scanner.Current;
                scanner.MoveNext();
                double X = scanner.Current;
                scanner.MoveNext();

                double secsSinceStart = 0;
                double curRate = 2;
                while (true)
                {
                    double secsToFarm = C / curRate;
                    double secsToGoalWithFram = secsToFarm + X / (curRate + F);
                    double secsToGoal = X / curRate;

                    if (secsToGoalWithFram < secsToGoal)
                    {
                        secsSinceStart += secsToFarm;
                        curRate += F;
                    }
                    else
                    {
                        secsSinceStart += secsToGoal;
                        break;
                    }

                }

                output.WriteLine("Case #{0}: {1:0.0000000}", nc + 1, secsSinceStart);
                Console.WriteLine("Case #{0}: {1:0.0000000}", nc + 1, secsSinceStart);
            }

            output.Close();

            string readOut = File.ReadAllText(root + "out.txt");
            string pOut = File.ReadAllText(root + "outP.txt");

            if (readOut.Equals(pOut))
            {
                Console.WriteLine("Match found");
            }
            else
            {
                Console.WriteLine("Match not found");
                Console.WriteLine("v1 is: {0}\nv2 is: {1}", readOut, pOut);
            }
        }
    }
}
