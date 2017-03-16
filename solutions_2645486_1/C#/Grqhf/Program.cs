using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace GoogleCodeJam1
{
    class Program
    {
        private const string InputFilePath = @"C:\temp\input.txt";
        private const string OutputFilePath = @"C:\temp\output.txt";

        static void Main(string[] args)
        {
            Parser.ParseAndSolve(InputFilePath, OutputFilePath);

            Console.ReadKey();
        }

    }

    class Parser
    {
        public static void ParseAndSolve(string inputPath, string outputPath)
        {
            StreamReader input = new StreamReader(inputPath);
            StreamWriter output = new StreamWriter(outputPath);

            /* Parse number of cases */
            int numberOfCases;
            if (!int.TryParse(input.ReadLine(), out numberOfCases))
            {
                throw new Exception("Could not parse number of cases.");
            }

            /* Parse all cases and solve */
            for (long i = 0; i < numberOfCases; ++i)
            {
                string line = input.ReadLine();
                long e = long.Parse(line.Split(' ')[0]);
                long r = long.Parse(line.Split(' ')[1]);
                long n = long.Parse(line.Split(' ')[2]);

                line = input.ReadLine();
                var tokens = line.Split(' ');
                var values = new long[n];
                for (long j = 0; j < n; j++)
                {
                    values[j] = int.Parse(tokens[j]);
                }

                string result = Solve(e, r, n, values);

                Console.WriteLine(String.Format("Case #{0}: {1}", i + 1, result));
                output.WriteLine(String.Format("Case #{0}: {1}", i + 1, result));
            }


            input.Close();
            output.Close();
        }

        private static string Solve(long e, long r, long n, long[] values)
        {
            _currentMaxGain = -1;
            SolveRec(e, r, n, values, 0L, 0L, e);
            return _currentMaxGain.ToString();
        }

        private static void SolveRec(long e, long r, long n, long[] values, long currentActivity, long cumulGain, long energyLeft)
        {
            /*Console.WriteLine();
            Console.WriteLine("Current activity: {0}", currentActivity);
            Console.WriteLine("Energy left: {0}", energyLeft);
            Console.WriteLine("Cumul gain: {0}", cumulGain);*/
            //Console.WriteLine("Going to use: {0}", goingToUse);


            while (currentActivity < n)
            {
                long goingToUse = r;

                long count = 1;
                while ((currentActivity + count < n) && values[currentActivity] > values[currentActivity + count] && (goingToUse < energyLeft))
                {
                    count++;
                    goingToUse += r;

                }
                if (currentActivity + count == n)
                {
                    goingToUse = energyLeft;
                }
                goingToUse = Math.Min(goingToUse, energyLeft);
                long newEnergy = Math.Min(energyLeft - goingToUse + r, e);


                //SolveRec(e, r, n, values, currentActivity + 1, cumulGain + goingToUse * values[currentActivity], newEnergy);

                cumulGain = cumulGain + goingToUse*values[currentActivity];
                currentActivity++;
                energyLeft = newEnergy;
            }
            _currentMaxGain = Math.Max(_currentMaxGain, cumulGain);
            return;

        }

        private static long _currentMaxGain = 0;
    }
}
