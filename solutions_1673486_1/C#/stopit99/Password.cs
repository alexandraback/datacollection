using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class Password
    {
        private static PasswordCase[] ReadFile(string filepath)
        {
            string[] lines = File.ReadAllLines(filepath);
            int cases = int.Parse(lines[0]);
            var result = new PasswordCase[cases];
            for (int caseNo = 1; caseNo <= cases; caseNo++)
            {
                var items1 = lines[2 * caseNo - 1].Split(' ').Select(s => int.Parse(s)).ToArray();
                var items2 = lines[2 * caseNo].Split(' ').Select(s => double.Parse(s)).ToArray();
                result[caseNo - 1] = new PasswordCase { A = items1[0], B = items1[1], p = items2 };
            }
            return result;
        }

        private class PasswordCase
        {
            public int A;
            public int B;
            public double[] p;
        }

        public static void Main()
        {
            string inputSize = "large";
            string inputFilepath = @"C:\src\CodeJam\CodeJam\Data Files\Password\" + inputSize + " input.txt";
            string outputFilepath = @"C:\src\CodeJam\CodeJam\Data Files\Password\" + inputSize + " output.txt";

            var cases = ReadFile(inputFilepath);

            var outputFile = File.CreateText(outputFilepath);

            int caseNo = 1;

            foreach (var gCase in cases)
            {
                string outputLine = string.Format("Case #{0}: {1}", caseNo++, SolveCase(gCase));
                Console.WriteLine(outputLine);
                outputFile.WriteLine(outputLine);
            }

            outputFile.Close();
        }

        private static double SolveCase(PasswordCase gCase)
        {
            double[] correctTillProbArray = new double[gCase.A+1];
            correctTillProbArray[0] = 1;
            for (int i = 1; i <= gCase.A; i++)
                correctTillProbArray[i] = correctTillProbArray[i-1] * gCase.p[i-1];

            double quitCost = 1 + gCase.B + 1;
            double bestCase = quitCost;
            
            //delete i characters then continue
            for (int i = 0; i <= gCase.A; i++)
            {
                double continueCost = i + i + gCase.B - gCase.A + 1 + (1 - correctTillProbArray[gCase.A - i]) * (gCase.B + 1);
                bestCase = Math.Min(bestCase, continueCost);
                //Console.WriteLine(continueCost);
            }
            //Console.Write(quitCost);

            return bestCase;
        }
    }
}
