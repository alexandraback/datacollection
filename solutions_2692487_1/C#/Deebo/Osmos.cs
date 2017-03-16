using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Dfs.GoogleCodeJam.CodeJam2013.Round1B
{
    /// <summary>Osmos solver.</summary>
    [ProblemInfo(ContestNames.CodeJam2013, RoundNames.Round1B, ProblemIdentifiers.A)]
    internal class Osmos : ProblemBase
    {
        #region Protected Methods

        /// <summary>Parses a single test case given an input reader.</summary>
        /// <param name="reader">An input reader.</param>
        /// <returns>A test case solver for the problem.</returns>
        protected override ProblemCaseBase ParseCase(TextReader reader)
        {
            return new OsmosCase(reader);
        }

        #endregion

        #region Nested Types

        /// <summary>Osmos test case solver.</summary>
        private class OsmosCase : ProblemCaseBase
        {
            #region Public Constructors

            /// <summary>Creates an instance of this solver.</summary>
            /// <param name="reader">The input reader.</param>
            public OsmosCase(TextReader reader)
            {
                firstMote = int.Parse(reader.ReadLine().Split(' ')[0]);
                motes = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();
            }

            #endregion

            #region Public Methods

            /// <summary>Solves a test case for a problem.</summary>
            /// <returns>The output for the test case.</returns>
            public override string Solve()
            {
                // Special case.
                if (firstMote == 1) return motes.Length.ToString();

                Array.Sort(motes);

                List<int> adds = new List<int>();

                int myMote = firstMote;
                for (int moteIndex = 0; moteIndex < motes.Length; moteIndex++)
                {
                    while (myMote <= motes[moteIndex])
                    {
                        myMote += (myMote - 1);
                        adds.Add(moteIndex);
                    }

                    myMote += motes[moteIndex];
                }

                int best = adds.Count;

                while (adds.Count > 0)
                {
                    int last = adds.Last();
                    while (adds.Count > 0 && adds.Last() == last)
                        adds.RemoveAt(adds.Count - 1);
                    best = Math.Min(best, motes.Length - last + adds.Count);
                }

                return best.ToString();
            }

            #endregion

            private readonly int firstMote;

            private readonly int[] motes;
        }

        #endregion
    }
}