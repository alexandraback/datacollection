using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Dfs.GoogleCodeJam.CodeJam2013.Round1C
{
    /// <summary>Pogo solver.</summary>
    [ProblemInfo(ContestNames.CodeJam2013, RoundNames.Round1C, ProblemIdentifiers.B)]
    internal class Pogo : ProblemBase
    {
        #region Protected Methods

        /// <summary>Parses a single test case given an input reader.</summary>
        /// <param name="reader">An input reader.</param>
        /// <returns>A test case solver for the problem.</returns>
        protected override ProblemCaseBase ParseCase(TextReader reader)
        {
            return new PogoCase(reader);
        }

        #endregion

        #region Nested Types

        /// <summary>Pogo test case solver.</summary>
        private class PogoCase : ProblemCaseBase
        {
            #region Public Constructors

            /// <summary>Creates an instance of this solver.</summary>
            /// <param name="reader">The input reader.</param>
            public PogoCase(TextReader reader)
            {
                int[] temp = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();
                x = temp[0];
                y = temp[1];
            }

            #endregion

            #region Public Methods

            /// <summary>Solves a test case for a problem.</summary>
            /// <returns>The output for the test case.</returns>
            public override string Solve()
            {
                string result = "";
                if (x != 0)
                    result += string.Join("", Enumerable.Repeat(x > 0 ? "WE" : "EW", Math.Abs(x)));

                if (y != 0)
                    result += string.Join("", Enumerable.Repeat(y > 0 ? "SN" : "NS", Math.Abs(y)));

                return result;
            }



            #endregion

            private readonly int x;
            private readonly int y;
        }

        #endregion
    }
}