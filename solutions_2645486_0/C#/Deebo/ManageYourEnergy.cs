using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Dfs.GoogleCodeJam.CodeJam2013.Round1A
{
    /// <summary>Manage Your Energy solver.</summary>
    [ProblemInfo(ContestNames.CodeJam2013, RoundNames.Round1A, ProblemIdentifiers.B)]
    internal class ManageYourEnergy : ProblemBase
    {
        #region Protected Methods

        /// <summary>Parses a single test case given an input reader.</summary>
        /// <param name="reader">An input reader.</param>
        /// <returns>A test case solver for the problem.</returns>
        protected override ProblemCaseBase ParseCase(TextReader reader)
        {
            return new ManageYourEnergyCase(reader);
        }

        #endregion

        #region Nested Types

        /// <summary>Manage Your Energy test case solver.</summary>
        private class ManageYourEnergyCase : ProblemCaseBase
        {
            #region Public Constructors

            /// <summary>Creates an instance of this solver.</summary>
            /// <param name="reader">The input reader.</param>
            public ManageYourEnergyCase(TextReader reader)
            {
                int[] temp = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();
                energy = temp[0];
                regain = temp[1];
                values = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();
            }

            #endregion

            #region Public Methods

            /// <summary>Solves a test case for a problem.</summary>
            /// <returns>The output for the test case.</returns>
            public override string Solve()
            {
                FindBest(energy, new LinkedList<int>(values), 0);


                return best.ToString();
            }

            private void FindBest(int currEnergy, LinkedList<int> rest, int currVal)
            {
                if (rest.Count == 0)
                {
                    best = Math.Max(best, currVal);
                    return;
                }

                int front = rest.First.Value;
                rest.RemoveFirst();
                foreach (int energyUsed in Enumerable.Range(0, currEnergy + 1))
                    FindBest(Math.Min(energy, currEnergy - energyUsed + regain), rest, currVal + energyUsed * front);

                rest.AddFirst(front);
            }

            #endregion

            private int best;

            private readonly int energy;
            private readonly int regain;
            private readonly int[] values;
        }

        #endregion
    }
}