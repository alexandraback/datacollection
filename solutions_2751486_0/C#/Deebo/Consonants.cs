using System;
using System.IO;
using System.Linq;

namespace Dfs.GoogleCodeJam.CodeJam2013.Round1C
{
    /// <summary>Consonants solver.</summary>
    [ProblemInfo(ContestNames.CodeJam2013, RoundNames.Round1C, ProblemIdentifiers.A)]
    internal class Consonants : ProblemBase
    {
        #region Protected Methods

        /// <summary>Parses a single test case given an input reader.</summary>
        /// <param name="reader">An input reader.</param>
        /// <returns>A test case solver for the problem.</returns>
        protected override ProblemCaseBase ParseCase(TextReader reader)
        {
            return new ConsonantsCase(reader);
        }

        #endregion

        #region Nested Types

        /// <summary>Consonants test case solver.</summary>
        private class ConsonantsCase : ProblemCaseBase
        {
            #region Public Constructors

            /// <summary>Creates an instance of this solver.</summary>
            /// <param name="reader">The input reader.</param>
            public ConsonantsCase(TextReader reader)
            {
                string[] temp = reader.ReadLine().Split(' ').ToArray();
                str = temp[0];
                n = int.Parse(temp[1]);
            }

            #endregion

            #region Public Methods

            /// <summary>Solves a test case for a problem.</summary>
            /// <returns>The output for the test case.</returns>
            public override string Solve()
            {
                bool[] vowels = str.Select(x => "aeiou".Contains(x)).ToArray();

                int result = 0;

                int length = str.Length;

                for (int i = 0; i < length; i++)
                    for (int j = i; j < length; j++)
                    {
                        int acc = 0;
                        for (int k = i; k <= j; k++)
                        {
                            if (vowels[k])
                                acc = 0;
                            else
                                acc++;
                            if (acc < n) continue;
                            result++;
                            break;
                        }

                    }

                return result.ToString();
            }

            #endregion

            private readonly string str;
            private readonly int n;
        }

        #endregion
    }
}