using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;

namespace GoogleCodeJam
{
    /// <summary>
    /// CodeJamProblem contains a collection of TestCases which are created by parsing the input file.
    /// The Solve method is called for each Test Case, then The output file is generated.
    /// </summary>
    public class Round1AA: CodeJamProblem<Round1AATestCase>
    {
        protected override void ParseCase(Round1AATestCase currentCase, int currentCaseNum, ref int currentLine, string[] lines)
        {
            var field = lines[currentLine].Split(_delimiterChars);
            currentCase.CenterRadius = long.Parse(field[0]);
            currentCase.Paint = long.Parse(field[1]);
            currentLine++;
        }
        protected override StringBuilder OutputForEachCase(Round1AATestCase testCase, StringBuilder currentString)
        {
            currentString.Append(testCase.Rings);
            return currentString;
        }
    }

    public class Round1AATestCase : ITestCase
    {
        public long Rings { get; set ;}
        public long CenterRadius { get; set; }
        public long Paint { get; set; }

        static Round1AATestCase()
        {
        }

        public void Solve()
        {
            long ToUse = Paint;
            long UsedPaint = 0;
            long CurrentRadius = CenterRadius + 1;
            while (UsedPaint <= ToUse)
            {
                Rings++;
                UsedPaint += 2 * CurrentRadius - 1;
                CurrentRadius += 2;
            }
            Rings--;
        }
    }
}
