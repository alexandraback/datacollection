using System;
using System.Collections.Generic;
using System.Diagnostics;
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
        private static bool _found = false;

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
                long x = int.Parse(line.Split(' ')[0]);
                long y = int.Parse(line.Split(' ')[1]);
                

                string result = Solve(x, y);

                Console.WriteLine("Case #{0}: {1}", i + 1, result);
                output.WriteLine("Case #{0}: {1}", i + 1, result);
            }


            input.Close();
            output.Close();
        }

        private static string Solve(long x, long y)
        {
            _found = false;
            return SolveRec(x, y, 0, 0, 1, "");
        }

        
        private static string SolveRec(long x, long y, long myX, long myY, long increment, string currentSol)
        {
            int n = 0;
            if (_found)
            {
                return string.Empty;
            }
            if (x == myX && y == myY)
            {
                _found = true;
                return currentSol;
            }

            while (myX > x)
            {
                n += 2;
                myX--;
                currentSol += "EW";
            }
            while (myX < x)
            {
                n += 2;
                myX++;
                currentSol += "WE";
            }
            while (myY > y)
            {
                n += 2;
                myY--;
                currentSol += "NS";
            }
            while (myY < y)
            {
                n += 2;
                myY++;
                currentSol += "SN";
            }

            if(n > 500)
            {
                Console.WriteLine("OUPS");
            }

            return currentSol;
        }
    }
}
