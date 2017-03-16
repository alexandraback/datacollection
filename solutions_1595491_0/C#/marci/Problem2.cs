using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam2012
{
    class Problem2
    {
        public static void Solve(string inFilePath, string outFilePath)
        {
            using (var inFile = File.OpenText(inFilePath))
            using (var outFile = File.OpenWrite(outFilePath))
            using (var outWriter = new StreamWriter(outFile))
            {
                var cases = int.Parse(inFile.ReadLine());

                for (int c = 0; c < cases; ++c)
                {
                    var inputLine = inFile.ReadLine();
                    var parts = inputLine.Split(' ').Select(s => int.Parse(s)).ToList();
                    var N = parts[0];
                    var S = parts[1];
                    var p = parts[2];

                    List<int> scores = new List<int>(S);
                    for (int n = 0; n < N; ++n)
                    {
                        scores.Add(parts[n+3]);
                    }

                    int minNonSupriseingScore;
                    int minSuprisingScore;
                    if (p >= 2)
                    {
                        minNonSupriseingScore = 3 * p - 2;   //p, p-1, p-1
                        minSuprisingScore = 3 * p - 4;  //p, p-2, p-2
                    }
                    else if (p == 1)
                    {
                        minNonSupriseingScore = 1;  //1,0,0
                        minSuprisingScore = int.MaxValue;
                    }
                    else if (p == 0)
                    {
                        minNonSupriseingScore = 0;  //0,0,0
                        minSuprisingScore = int.MaxValue;
                    }
                    else
                        throw new ArgumentException();

                    var result = scores.Where(s => s >= minNonSupriseingScore).Count();
                    result += Math.Min(S, scores.Where(s => s >= minSuprisingScore && s < minNonSupriseingScore).Count());

                    var outLine = string.Format("Case #{0}: {1}", c + 1, result);
                    Console.WriteLine("N={0}, S={1}, p={2}", N, S, p);
                    Console.WriteLine(inputLine);
                    Console.WriteLine(outLine);
                    Console.WriteLine();
                    outWriter.WriteLine(outLine);
                }
                outWriter.Flush();
            }
        }
    }
}
