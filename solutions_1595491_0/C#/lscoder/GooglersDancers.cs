using System;
using System.Diagnostics;

namespace LSCoder.CodeJam.ConsoleApp
{
    public class GooglersDancers : GoogleProblem
    {
        #region Constructors

        public GooglersDancers(string fileName)
            : base(fileName)
        {
        }

        #endregion

        #region Private Methods

        private string CountBestScores(string line)
        {
            var lineParts = line.Split(' ');

            var googlersCount = Int32.Parse(lineParts[0]);
            var surprisingCount = Int32.Parse(lineParts[1]);
            var minScore = Int32.Parse(lineParts[2]);
            //var scores = new int[googlersCount];
            var result = 0;

            for (var i = 0; i < googlersCount; i++)
            {
                var score = Int32.Parse(lineParts[3 + i]);

                var avg = score / 3;
                var rest = score%3;

                if ((avg >= minScore) || ((avg == minScore-1) && (rest > 0)))
                {
                    result++;
                    continue;
                }

                if ((((avg > 0) && (avg == minScore - 1)) || ((avg == minScore - 2) && (rest == 2))) && (surprisingCount > 0))
                {
                    result++;
                    surprisingCount--;
                    continue;
                }
            }

            return result.ToString();
        }

        #endregion

        #region Public Methods

        public override void Execute()
        {
            var testCasesCount = Int32.Parse(GetNextLine());

            for (var i = 0; i < testCasesCount; i++)
            {
                Trace.WriteLine(string.Format("Case #{0}: {1}", (i + 1), CountBestScores(GetNextLine())));
            }
        }

        #endregion
    }
}
