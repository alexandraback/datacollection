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
                long r = long.Parse(line.Split(' ')[0]);
                long t = long.Parse(line.Split(' ')[1]);

                string result = Solve(r, t);

                Console.WriteLine(String.Format("Case #{0}: {1}", i + 1, result));
                output.WriteLine(String.Format("Case #{0}: {1}", i + 1, result));
            }


            input.Close();
            output.Close();
        }

        private static string Solve(long r, long t)
        {
            int n = 0;
            while (1 + 2 * r <= t)
            {
                n++;
                t -= 1 + 2 * r;
                r += 2;
            }

            return n.ToString();
        }
    }
}
