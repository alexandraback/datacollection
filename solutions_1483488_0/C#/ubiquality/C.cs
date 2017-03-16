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
    internal class C
    {
        #region Methods

        /// <summary>
        /// Calculates case line.
        /// </summary>
        /// <param name="caseLine">
        /// The case line.
        /// </param>
        /// <returns>
        /// Case lien result.
        /// </returns>
        private static int CalculateCaseLine(string caseLine)
        {
            var caseLineSplitted = caseLine.Split(' ');

            var rangeMin = Convert.ToInt32(caseLineSplitted[0]);
            var rangeMax = Convert.ToInt32(caseLineSplitted[1]);

            var recycledPairs = new Dictionary<int, List<int>>();
            var totalrecycledPairsCount = 0;

            for (var testedNumber = Math.Max(rangeMin, 11); testedNumber <= rangeMax; testedNumber++)
            {
                var testedNumberAsString = testedNumber.ToString();

                for (var leftPartLength = 1; leftPartLength < testedNumberAsString.Length; leftPartLength++)
                {
                    var leftPartAsString = testedNumberAsString.Substring(0, leftPartLength);
                    var rightPartAsString = testedNumberAsString.Substring(leftPartLength);

                    if (rightPartAsString[0] == '0')
                    {
                        continue;
                    }

                    var changedPairsAsInt = Convert.ToInt32(rightPartAsString + leftPartAsString);

                    if (testedNumber < changedPairsAsInt && changedPairsAsInt >= rangeMin && changedPairsAsInt <= rangeMax)
                    {
                        if (!recycledPairs.ContainsKey(testedNumber))
                        {
                            recycledPairs[testedNumber] = new List<int> { changedPairsAsInt };

                            totalrecycledPairsCount++;
                        }
                        else
                        {
                            if (!recycledPairs[testedNumber].Contains(changedPairsAsInt))
                            {
                                recycledPairs[testedNumber].Add(changedPairsAsInt);

                                totalrecycledPairsCount++;
                            }
                        }
                    }
                }
            }

            return totalrecycledPairsCount;
        }

        /// <summary>
        /// The main method.
        /// </summary>
        private static void Main()
        {
            using (var inputFileStream = File.Open("C-small.in", FileMode.Open))
            {
                using (var outputFileStream = File.Open("C-small.out", FileMode.Create))
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