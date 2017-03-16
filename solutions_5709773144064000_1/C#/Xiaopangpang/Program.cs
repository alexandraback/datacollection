using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemB
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length != 2)
            {
                Console.WriteLine("Invalid input parameters!");
                return;
            }

            string inputFile = args[0];
            string outputFile = args[1];

            using (var reader = new StreamReader(inputFile))
            using (var writer = new StreamWriter(outputFile))
            {
                int testCases = int.Parse(reader.ReadLine());
                for (int caseNumber = 1; caseNumber <= testCases; caseNumber++)
                {
                    var parameters =reader.ReadLine().Split();
                    var C = decimal.Parse(parameters[0]);
                    var F = decimal.Parse(parameters[1]);
                    var X = decimal.Parse(parameters[2]);

                    const decimal initialRate = 2.0m;
                    var currentRate = initialRate;
                    var finalRate = initialRate;
                    while ((X - C)/finalRate > X/(finalRate + F))
                    {
                        finalRate += F;
                    }

                    var timeToReachFinalRate = 0.0m;
                    while (currentRate < finalRate)
                    {
                        timeToReachFinalRate += C / currentRate;
                        currentRate += F;
                    }

                    var totalTimeToWin = timeToReachFinalRate + X / finalRate;
                    Console.WriteLine("Case #{0}: {1:0.000000}", caseNumber, totalTimeToWin);
                    writer.WriteLine("Case #{0}: {1:0.000000}", caseNumber, totalTimeToWin);
                }
            }
        }
    }
}
