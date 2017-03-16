using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            using (TextReader input = new StreamReader("input.txt"))
            using (TextWriter output = new StreamWriter("output.txt"))
            //using (TextReader input = new StreamReader(Console.OpenStandardInput()))
            //using (TextWriter output = new StreamWriter(Console.OpenStandardOutput()))
            {
                Process(input, output);
            }
        }

        private static void Process(TextReader input, TextWriter output)
        {
            int numberOfCases = int.Parse(input.ReadLine());
            for (int currentCase = 0; currentCase < numberOfCases; currentCase++)
            {
                output.Write("Case #" + (currentCase + 1).ToString() + ": ");
                ProcessLine(input, output);
            }
        }

        private static void ProcessLine(TextReader input, TextWriter output)
        {
            double productionRate = 2f;
            string[] parts = input.ReadLine().Split(' ');
            double cost = double.Parse(parts[0]);
            double extra = double.Parse(parts[1]);
            double required = double.Parse(parts[2]);
            double extras = required - cost;
            double timeTaken = 0f;
            if (extras > 0)
            {
                timeTaken = cost / productionRate;
                int bought = 0;
                bool doBuy = false;
                do
                {
                    double noBuyTime = extras / productionRate;
                    double buyRate = productionRate + extra;
                    double buyTime = required / buyRate;
                    doBuy = buyTime < noBuyTime;
                    if (doBuy)
                    {
                        productionRate = buyRate;
                        timeTaken += cost / productionRate;
                    }

                } while (doBuy);
                timeTaken += extras / productionRate;
            }
            else
            {
                timeTaken = required / productionRate;
            }
            output.WriteLine(timeTaken.ToString("0.0000000"));
        }
    }
}
