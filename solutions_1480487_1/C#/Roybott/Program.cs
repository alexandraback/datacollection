using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

namespace ProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            var inputFilename = @"A-large.in";
            //var inputFilename = @"A-small-attempt2.in";
            //var inputFilename = @".\TestInput.txt";
            var outputFilename = @".\TestOutput.txt";

            var inputLines = HelperFunctions.LoadLinesFromFile(inputFilename);
            var outputLines = ProcessProblem(inputLines);
            HelperFunctions.WriteLinesToFile(outputFilename, outputLines);
        }

        static List<string> ProcessProblem(List<string> inputLines)
        {
            List<string> output = new List<string>();

            int cases = int.Parse(inputLines[0]);
            if (inputLines.Count != cases + 1)
                Debugger.Break(); // We have a parsing error!

            // Parse each test cases
            for (int i = 1; i < inputLines.Count; i++)
            {
                var items = inputLines[i].Split(' ');
                var numVotes = int.Parse(items[0]);
                var points = items.Skip(1).Select(int.Parse).ToList();

                if (points.Count() != numVotes)
                    Debugger.Break();

                // Now process this test case
                var answer = ProcessTestCase(points);

                // And store the output
                output.Add(string.Format("Case #{0}: {1}", i, answer));
                Debug.WriteLine(string.Format("Case #{0}: {1}", i, answer));
            }

            return output;
        }

        static string ProcessTestCase(IEnumerable<int> points)
        {
            var results = new List<double>();
            var totalPoints = points.Sum();
            var min = points.Min();
            
            foreach (var point in points)
            {
                // distribute the total points between all the scores below mine, until they are all equal to me
                var deminishingTotal = totalPoints;
                var NumEqualScores = points.Count(a => a == point);
                foreach (var i in points.Where(a => a < point))
                {
                    deminishingTotal -= (point - i);
                    NumEqualScores++;
                }

                // Early out if I can't lose
                if (deminishingTotal <= 0)
                {
                    // I can't lose!
                    results.Add(0.0);
                }
                else
                {
                    // Now start sharing the points out between everyone who is now equal to me, until we run out of points
                    // also check if we need to add anyone new to our 'lowest' group each time

                    // Find the next score that is above ours
                    var theNewLowestScore = point;
                    while (points.Any(a => a > theNewLowestScore))
                    {
                        var nextLowest = points.OrderBy(a => a).First(a => a > theNewLowestScore);
                        var numNewLowScores = points.Count(a => a == nextLowest);

                        // Figure out how many points we'll have left after raising us all to this new total
                        var costToRaise = (nextLowest - theNewLowestScore)*NumEqualScores;

                        if (costToRaise > deminishingTotal)
                        {
                            // We can't reach them so just split the remaining points between us
                            break;
                        }
                        else
                        {
                            deminishingTotal -= costToRaise;
                            NumEqualScores += numNewLowScores;
                            theNewLowestScore = nextLowest;
                        }
                    }

                    // No more scores higher than us so just split the remaining points
                    var remainingPointsEach = deminishingTotal / (double)NumEqualScores;

                    // then my total - my original gives the number of the total points I need
                    var percentageNeeded = ((remainingPointsEach + (theNewLowestScore - point)) / totalPoints) * 100;

                    results.Add(percentageNeeded);
                }
            }

            StringBuilder output = new StringBuilder();
            foreach (var result in results)
            {
                output.Append(result.ToString("F6") + " ");
            }
            output.Remove(output.Length - 1, 1);
            return output.ToString();
        }
    }

    internal static class HelperFunctions
    {
        public static List<string> LoadLinesFromFile(string filepath)
        {
            List<string> result = new List<string>();
            using (var reader = new StreamReader(filepath))
            {
                while (!reader.EndOfStream)
                    result.Add(reader.ReadLine());
            }

            return result;
        }

        public static void WriteLinesToFile(string filepath, List<string> lines)
        {
            using (var writer = new StreamWriter(filepath))
            {
                foreach (var line in lines)
                {
                    writer.WriteLine(line);
                }
            }
        }
    }
}
