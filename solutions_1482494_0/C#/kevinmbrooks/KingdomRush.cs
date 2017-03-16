using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GoogleCodeJam.Solvers
{
    class KingdomRush
    {
        public static void Main(string[] args)
        {
            string problemName = args[0];
            string inputFileName = problemName + ".in";
            string outputFileName = problemName + ".out.txt";

            using (var reader = System.IO.File.OpenText(inputFileName))
            using (var writer = new System.IO.StreamWriter(outputFileName))
            {
                var sw = System.Diagnostics.Stopwatch.StartNew();
                SolveProblem(reader, writer);
                Console.WriteLine(sw.Elapsed.ToString());
            }
        }

        private static void SolveProblem(System.IO.TextReader input, System.IO.TextWriter output)
        {
            int numberOfTestCases = Int32.Parse(input.ReadLine());

            for (int i = 0; i < numberOfTestCases; i++)
            {
                output.Write("Case #{0}:", i + 1);
                SolveTestCase(input, output);
                output.WriteLine();
            }
        }

        private static void SolveTestCase(System.IO.TextReader input, System.IO.TextWriter output)
        {
            int numberOfLevels = Int32.Parse(input.ReadLine());
            StarsRequired[] required = new StarsRequired[numberOfLevels];
            for (int n = 0; n < numberOfLevels; n++)
            {
                string[] parts = input.ReadLine().Split(' ');
                required[n] = new StarsRequired(
                    Int32.Parse(parts[0]), Int32.Parse(parts[1]));
            }
            output.Write(' ');
            output.Write(FewestNumber(required));
        }

        private static string FewestNumber(StarsRequired[] required)
        {
            int totalLevelsFinished = 0;
            int timesPlayed = 0;
            int[] starsOnLevel = new int[required.Length];
            int starTotal = 0;
            while (totalLevelsFinished < required.Length)
            {
                bool didIAdvance = false;
                do
                {
                    didIAdvance = false;
                    // Try for two-stars
                    for (int i = 0; i < required.Length; i++)
                    {
                        int starsOnThisLevelSoFar = starsOnLevel[i];
                        if (starsOnThisLevelSoFar == 0 && starTotal >= required[i].TwoStars)
                        {
                            starTotal += 2;
                            starsOnLevel[i] = 2;
                            timesPlayed++;
                            totalLevelsFinished++;
                            didIAdvance = true;
                            if (totalLevelsFinished == required.Length) { goto END; }
                        }
                    }
                } while (didIAdvance);

                // Try for one-star
                for (int i = 0; i < required.Length; i++)
                {
                    int starsOnThisLevelSoFar = starsOnLevel[i];
                    if (starsOnThisLevelSoFar == 1 && starTotal >= required[i].TwoStars)
                    {
                        starTotal++;
                        starsOnLevel[i] = 2;
                        timesPlayed++;
                        totalLevelsFinished++;
                        didIAdvance = true;
                        if (totalLevelsFinished == required.Length) { goto END; }
                        goto NEXT;
                    }
                }
                for (int i = 0; i < required.Length; i++)
                {
                    int starsOnThisLevelSoFar = starsOnLevel[i];
                    if (starsOnThisLevelSoFar == 0 && starTotal >= required[i].OneStar)
                    {
                        starTotal++;
                        starsOnLevel[i] = 1;
                        timesPlayed++;
                        didIAdvance = true;
                        break;
                    }
                }
            NEXT:

                if (!didIAdvance) { break; }
            }
        END:
            return totalLevelsFinished < required.Length ? "Too Bad" : timesPlayed.ToString();
        }

        private struct StarsRequired
        {
            public int OneStar;
            public int TwoStars;
            public StarsRequired(int one, int two)
            {
                this.OneStar = one;
                this.TwoStars = two;
            }
        }
    }
}
