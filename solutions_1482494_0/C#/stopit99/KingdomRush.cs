using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class KingdomRush
    {
        private static KingdomCase[] ReadFile(string filepath)
        {
            string[] lines = File.ReadAllLines(filepath);
            int cases = int.Parse(lines[0]);
            var result = new KingdomCase[cases];
            int caseNo = 1;
            int lineNo = 1;
            for (caseNo = 1; caseNo <= cases; caseNo++)
            {
                var N = int.Parse(lines[lineNo++]);
                var a = new int[N];
                var b = new int[N];
                for (int levelNo = 0; levelNo < N; levelNo++)
                {
                    var items = lines[lineNo++].Split(' ').Select(s => int.Parse(s)).ToArray();
                    a[levelNo] = items[0];
                    b[levelNo] = items[1];
                }
                
                result[caseNo - 1] = new KingdomCase { N = N, a = a, b = b};
            }
            return result;
        }

        private class KingdomCase
        {
            public int N;
            public int[] a;
            public int[] b;
        }

        public static void Main()
        {
            string inputSize = "small";
            string inputFilepath = @"C:\src\CodeJam\CodeJam\Data Files\KingdomRush\" + inputSize + " input.txt";
            string outputFilepath = @"C:\src\CodeJam\CodeJam\Data Files\KingdomRush\" + inputSize + " output.txt";

            var cases = ReadFile(inputFilepath);

            var outputFile = File.CreateText(outputFilepath);

            int caseNo = 1;

            foreach (var gCase in cases)
            {
                //foreach (var x in new[] { -0.000001, +0.000001 })
                //    foreach (var y in new[] { -0.000001, +0.000001 })
                //    {
                //        if (true)
                //        {
                string outputLine = string.Format("Case #{0}: {1}", caseNo, SolveCase(gCase));
                Console.WriteLine(outputLine);
                outputFile.WriteLine(outputLine);
                //    }
                //}
                caseNo++;
            }

            outputFile.Close();
        }

        private static object SolveCase(KingdomCase gCase)
        {
            var twoStarCosts = gCase.b.Select((cost, index) => new Tuple<int, int>(index, cost)).OrderBy(t => t.Item2).ToArray();
            var oneStarCosts = gCase.a.Select((cost, index) => new Tuple<int, int>(index, cost)).OrderBy(t => t.Item2 - 0.000001 * gCase.b[t.Item1]).ToArray();

            var oneStarCompletedCheck = new bool[gCase.N];
            var twoStarCompletedCheck = new bool[gCase.N];
            int twoStarCompleted = 0;
            int starCount = 0;
            int oneStarCompleted = 0;
            int attemptCount = 0;

            while (twoStarCompleted < gCase.N)
            {
                int bestTwoStarIndex = -1;
                int bestTwoStarScore = 0;

                for(int i = 0; i < gCase.N; i++)
                    if (!twoStarCompletedCheck[i] && gCase.b[i] <= starCount)
                    {
                        int twoStarScore = oneStarCompletedCheck[i] ? 1 : 2;
                        if (twoStarScore > bestTwoStarScore)
                        {
                            bestTwoStarScore = twoStarScore;
                            bestTwoStarIndex = i;
                        }
                    }

                if (bestTwoStarScore > 0)
                {
                    twoStarCompletedCheck[bestTwoStarIndex] = true;
                    starCount += bestTwoStarScore;
                    twoStarCompleted++;
                    attemptCount++;
                }
                else
                {
                    if (oneStarCompleted >= gCase.N)
                        goto TooBad;
                    while (twoStarCompletedCheck[oneStarCosts[oneStarCompleted].Item1])
                    {
                        if (oneStarCompleted < gCase.N - 1)
                            oneStarCompleted++;
                        else
                            goto TooBad;
                    }
                    if (oneStarCosts[oneStarCompleted].Item2 <= starCount)
                    {
                        oneStarCompletedCheck[oneStarCosts[oneStarCompleted].Item1] = true;
                        oneStarCompleted++;
                        starCount += 1;
                        attemptCount++;
                    }
                    else
                        goto TooBad;
                }
            }
            return attemptCount;

        TooBad:
            {
                for (int i = 0; i < gCase.N; i++)
                {
                    if (!oneStarCompletedCheck[i] && !twoStarCompletedCheck[i] && gCase.a[i] <= starCount)
                        Console.WriteLine();
                    if (!twoStarCompletedCheck[i] && gCase.b[i] <= starCount)
                        Console.WriteLine();
                }

                return "Too Bad";
            }
        }

        //private static object SolveCase2(KingdomCase gCase, bool[] completedOneStar, bool[] completedTwoStar)
        //{
        //    for(int i = 0; i < gCase.N; i++)
        //        if(!completedTwoStar[i])
        //            if(gCase.b


    }
}
