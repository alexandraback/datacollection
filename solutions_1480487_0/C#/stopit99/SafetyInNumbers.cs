using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class SafetyInNumbers
    {
        private static SafetyCase[] ReadFile(string filepath)
        {
            string[] lines = File.ReadAllLines(filepath);
            int cases = int.Parse(lines[0]);
            var result = new SafetyCase[cases];
            for (int caseNo = 1; caseNo < lines.Length; caseNo++)
            {
                var items = lines[caseNo].Split(' ').Select(s => int.Parse(s)).ToArray();

                result[caseNo - 1] = new SafetyCase{ N = items[0], s = items.Where((i, index) => index > 0).ToArray() };
            }

            return result;
        }

        private class SafetyCase
        {
            public int N;
            public int[] s;
        }

        public static void Main()
        {
            string inputSize = "small";
            string inputFilepath = @"C:\src\CodeJam\CodeJam\Data Files\SafetyInNumbers\"+inputSize+" input.txt";
            string outputFilepath = @"C:\src\CodeJam\CodeJam\Data Files\SafetyInNumbers\" + inputSize + " output.txt";

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

        private static string SolveCase(SafetyCase gCase)
        {
            double[] resultArray = new double[gCase.N];

            for (int candidate = 0; candidate < gCase.N; candidate++)
                resultArray[candidate] = MinVoteShare(candidate, gCase);

            return string.Join(" ", resultArray.Select(d => string.Format("{0:0.000000}", d*100)).ToArray());
        }

        private static double MinVoteShare(int candidate, SafetyCase gCase)
        {
            double lower = 0;
            double upper = 1;
            double pivot = 1;
            int[] opponentPoints = gCase.s.Where((i, index) => index != candidate).OrderBy(i => i).ToArray();
            int totalPoints = gCase.s.Sum();
            while (upper - lower > 0.0000000001)
                if (CanSurvive(gCase.s[candidate], opponentPoints, totalPoints, pivot = (lower + upper) / 2))
                    upper = pivot;
                else
                    lower = pivot;

            return pivot;
        }

        private static bool CanSurvive(int candidatePoints, int[] opponentPoints, int totalPoints, double candidateShare)
        {
            double candidateScore = candidatePoints + totalPoints * candidateShare;
            double remainingShare = 1 - candidateShare;
            foreach (var opponentPoint in opponentPoints)
            {
                double requiredShare = (candidateScore - opponentPoint) / totalPoints;
                remainingShare -= requiredShare;
                if (remainingShare < 0)
                    return true;
            }
            return false;
        }

    }
}
