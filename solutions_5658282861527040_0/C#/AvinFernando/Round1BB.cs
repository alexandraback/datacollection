using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;

namespace GoogleCodeJam.Fourteen.Round1B
{
    /// <summary>
    /// CodeJamProblem contains a collection of TestCases which are created by parsing the input file.
    /// The Solve method is called for each Test Case, then The output file is generated.
    /// </summary>
    public class Round1BB : CodeJamProblem<Round1BBTestCase>
    {
        protected override void ParseCase(Round1BBTestCase currentCase, int currentCaseNum, ref int currentLine, string[] lines)
        {
            var field = lines[currentLine].Split(_delimiterChars);
            currentCase.A = int.Parse(field[0]);
            currentCase.B = int.Parse(field[1]);
            currentCase.K = int.Parse(field[2]);
            currentLine++;
        }
        protected override StringBuilder OutputForEachCase(Round1BBTestCase testCase, StringBuilder currentString)
        {
            currentString.Append(testCase.NumWins);
            return currentString;
        }
    }

    public class Round1BBTestCase : ITestCase
    {
        public int A { get; set; }
        public int B { get; set; }
        public int K { get; set; }
        public long NumWins { get; set; }

        public Round1BBTestCase()
        {
        }

        static Round1BBTestCase()
        {
        }

        public void Solve()
        {
            //if (A < 2 || B < 2)
            //{
            //    for (int a = 0; a < A; a++)
            //        for (int b = 0; b < B; b++)
            //            if ((a & b) < K)
            //                NumWins++;
            //    return;
            //}

            for (int a = 0; a < A; a++)
                for (int b = 0; b < B; b++)
                    if ((a & b) < K)
                        NumWins++;
            //NumWins += A+A;
            //NumWins += B+B-4;
        }
    }
}
