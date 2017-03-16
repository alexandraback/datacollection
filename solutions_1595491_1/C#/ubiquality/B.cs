// --------------------------------------------------------------------------------------------------------------------
// <copyright file="B.cs" company="">
//   
// </copyright>
// <summary>
//   The program.
// </summary>
// --------------------------------------------------------------------------------------------------------------------

namespace CodeJam
{
    using System;
    using System.Collections.Generic;
    using System.IO;

    /// <summary>
    /// The program.
    /// </summary>
    internal class B
    {
        #region Constants and Fields

        /// <summary>
        /// The not suprising mappings.
        /// </summary>
        private static readonly Dictionary<int, int[]> NotSuprisingMappings = new Dictionary<int, int[]>
            {
                { 0, new[] { 0, 0, 0 } }, 
                { 1, new[] { 0, 0, 1 } },
                { 2, new[] { 0, 1, 1 } },
                { 3, new[] { 1, 1, 1 } },
                { 4, new[] { 1, 1, 2 } },
                { 5, new[] { 1, 2, 2 } },
                { 6, new[] { 2, 2, 2 } },
                { 7, new[] { 2, 2, 3 } },
                { 8, new[] { 2, 3, 3 } },
                { 9, new[] { 3, 3, 3 } },
                { 10, new[] { 3, 3, 4 } },
                { 11, new[] { 3, 4, 4 } },
                { 12, new[] { 4, 4, 4 } },
                { 13, new[] { 4, 4, 5 } },
                { 14, new[] { 4, 5, 5 } },
                { 15, new[] { 5, 5, 5 } },
                { 16, new[] { 5, 5, 6 } },
                { 17, new[] { 5, 6, 6 } },
                { 18, new[] { 6, 6, 6 } },
                { 19, new[] { 6, 6, 7 } },
                { 20, new[] { 6, 7, 7 } },
                { 21, new[] { 7, 7, 7 } },
                { 22, new[] { 7, 7, 8 } },
                { 23, new[] { 7, 8, 8 } },
                { 24, new[] { 8, 8, 8 } },
                { 25, new[] { 8, 8, 9 } },
                { 26, new[] { 8, 9, 9 } },
                { 27, new[] { 9, 9, 9 } },
                { 28, new[] { 9, 9, 10 } },
                { 29, new[] { 9, 10, 10 } },
                { 30, new[] { 10, 10, 10 } }
            };

        /// <summary>
        /// The suprising mappings.
        /// </summary>
        private static readonly Dictionary<int, int[]> SuprisingMappings = new Dictionary<int, int[]>
            {
                { 2, new[] { 0, 0, 2 } },
                { 3, new[] { 0, 1, 2 } },
                { 4, new[] { 0, 2, 2 } },
                { 5, new[] { 1, 1, 3 } },
                { 6, new[] { 1, 2, 3 } },
                { 7, new[] { 1, 3, 3 } },
                { 8, new[] { 2, 2, 4 } },
                { 9, new[] { 2, 3, 4 } },
                { 10, new[] { 2, 4, 4 } },
                { 11, new[] { 3, 3, 5 } },
                { 12, new[] { 3, 4, 5 } },
                { 13, new[] { 3, 5, 5 } },
                { 14, new[] { 4, 4, 6 } },
                { 15, new[] { 4, 5, 6 } },
                { 16, new[] { 4, 6, 6 } },
                { 17, new[] { 5, 5, 7 } },
                { 18, new[] { 5, 6, 7 } },
                { 19, new[] { 5, 7, 7 } },
                { 20, new[] { 6, 6, 8 } },
                { 21, new[] { 6, 7, 8 } },
                { 22, new[] { 6, 8, 8 } },
                { 23, new[] { 7, 7, 9 } },
                { 24, new[] { 7, 8, 9 } },
                { 25, new[] { 7, 9, 9 } },
                { 26, new[] { 8, 8, 10 } },
                { 27, new[] { 8, 9, 10 } },
                { 28, new[] { 8, 10, 10 } }
            };

        #endregion

        #region Methods

        /// <summary>
        /// Calculates case line.
        /// </summary>
        /// <param name="caseLine">
        /// The case line.
        /// </param>
        /// <returns>
        /// Number of Googlers with the best result equal or greater p.
        /// </returns>
        private static object CalculateCaseLine(string caseLine)
        {
            var caseLineSplitted = caseLine.Split(' ');

            var numberOfGooglers = Convert.ToInt32(caseLineSplitted[0]);
            var numberOfSuprisingTriplets = Convert.ToInt32(caseLineSplitted[1]);
            var p = Convert.ToInt32(caseLineSplitted[2]);

            var numberOfUsedSuprisingTriplets = 0;
            var numberOfMatchedGooglers = 0;

            for (var i = 3; i < numberOfGooglers + 3; i++)
            {
                var totalScore = Convert.ToInt32(caseLineSplitted[i]);

                if (NotSuprisingMappings[totalScore][2] >= p)
                {
                    numberOfMatchedGooglers++;

                    continue;
                }

                if (numberOfUsedSuprisingTriplets < numberOfSuprisingTriplets)
                {
                    if (SuprisingMappings.ContainsKey(totalScore) && SuprisingMappings[totalScore][2] >= p)
                    {
                        numberOfMatchedGooglers++;
                        numberOfUsedSuprisingTriplets++;

                        continue;
                    }
                }
            }

            return numberOfMatchedGooglers;
        }

        /// <summary>
        /// The main method.
        /// </summary>
        private static void Main()
        {
            using (var inputFileStream = File.Open("B-large.in", FileMode.Open))
            {
                using (var outputFileStream = File.Open("B-large.out", FileMode.Create))
                {
                    using (var outputFileWriter = new StreamWriter(outputFileStream))
                    {
                        using (var inputFileStreamReader = new StreamReader(inputFileStream))
                        {
                            var numberOfTestCases = Convert.ToInt32(inputFileStreamReader.ReadLine());

                            for (var i = 0; i < numberOfTestCases; i++)
                            {
                                outputFileWriter.WriteLine("Case #{0}: {1}", i + 1, CalculateCaseLine(inputFileStreamReader.ReadLine()));
                            }
                        }
                    }
                }
            }
        }

        #endregion
    }
}