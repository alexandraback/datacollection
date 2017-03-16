using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;

namespace LSCoder.CodeJam.ConsoleApp
{
    public class RecycledNumbers : GoogleProblem
    {
        #region Constructors

        public RecycledNumbers(string fileName)
            : base(fileName)
        {
        }

        #endregion

        #region Private Methods

        private int CountRecycledNumbers(string line)
        {
            var lineParts = line.Split(' ');
            var leftNumber = Int32.Parse(lineParts[0]);
            var rightNumber = Int32.Parse(lineParts[1]);

            var recycled = 0;
            for (var n = Math.Max(leftNumber, 10); n < rightNumber; n++)
            {
                var upperBound = (int)Math.Pow(10, n.ToString().Length) - 1;
                recycled +=
                    GetRecycledNumbers(n.ToString())
                        .Sum(recycledNumber =>
                             (recycledNumber > n) && (recycledNumber <= Math.Min(rightNumber, upperBound)) ? 1 : 0);
            }

            return recycled;
        }

        private int[] GetRecycledNumbers(string number)
        {
            var numbers = new List<int>();

            for (var i = 0; i < number.Length - 1; i++)
            {
                number = number.Substring(number.Length - 1) +
                         number.Substring(0, number.Length - 1);

                numbers.Add(Int32.Parse(number));
            }

            return numbers.Distinct().ToArray();
        }

        #endregion

        #region Public Methods

        public override void Execute()
        {
            var testCasesCount = Int32.Parse(GetNextLine());

            for (var i = 0; i < testCasesCount; i++)
            {
                Trace.WriteLine(string.Format("Case #{0}: {1}", (i + 1), CountRecycledNumbers(GetNextLine())));
            }
        }

        #endregion
    }
}
