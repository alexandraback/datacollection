using System;
using System.IO;
using System.Linq;

namespace Dfs.GoogleCodeJam.CodeJam2013.Round1A
{
    /// <summary>Bullseye solver.</summary>
    [ProblemInfo(ContestNames.CodeJam2013, RoundNames.Round1A, ProblemIdentifiers.A)]
    internal class Bullseye : ProblemBase
    {
        #region Protected Methods

        /// <summary>Parses a single test case given an input reader.</summary>
        /// <param name="reader">An input reader.</param>
        /// <returns>A test case solver for the problem.</returns>
        protected override ProblemCaseBase ParseCase(TextReader reader)
        {
            return new BullseyeCase(reader);
        }

        #endregion

        #region Nested Types

        /// <summary>Bullseye test case solver.</summary>
        private class BullseyeCase : ProblemCaseBase
        {
            #region Public Constructors

            /// <summary>Creates an instance of this solver.</summary>
            /// <param name="reader">The input reader.</param>
            public BullseyeCase(TextReader reader)
            {
                long[] temp = reader.ReadLine().Split(' ').Select(long.Parse).ToArray();
                radius = temp[0];
                paint = temp[1];
            }

            #endregion

            #region Public Methods

            /// <summary>Solves a test case for a problem.</summary>
            /// <returns>The output for the test case.</returns>
            public override string Solve()
            {
                double a = 2 * radius - 1.0;
                var result = 2.0 * paint /  (a + Math.Sqrt(a * a + 8.0 * paint));
                return ((long)result).ToString();
            }

            #endregion

            private readonly long radius;
            private readonly long paint;
        }

        #endregion
    }
}