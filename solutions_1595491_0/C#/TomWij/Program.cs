using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GCJ.DWtG
{
    class Program
    {
        static bool SurprisingCheck(int i, int j, int k, bool surprising)
        {
            var diff1 = Math.Abs((int) (i - j));
            var diff2 = Math.Abs((int) (j - k));
            var diff3 = Math.Abs((int) (i - k));

            if (surprising)
                return (diff1 == 2 && diff2 <= 2 && diff3 <= 2) || (diff1 <= 2 && diff2 == 2 && diff3 <= 2) || (diff1 <= 2 && diff2 <= 2 && diff3 == 2);
            else
                return diff1 <= 1 && diff2 <= 1 && diff3 <= 1;
        }

        static List<int> GenerateBestTriplet(int totalScore, bool surprising)
        {
            var i = 0; var j = 0; var k = 0;
            var done = false;

            for (i = 10; i >= 0; --i)
            {
                if (i == totalScore && SurprisingCheck(i, j, k, surprising))
                    break;

                if (i >= totalScore)
                    continue;

                for (j = 10; j >= 0; --j)
                {
                    if (i + j == totalScore && SurprisingCheck(i, j, k, surprising))
                    {
                        done = true;
                        break;
                    }

                    if (i + j >= totalScore)
                        continue;

                    for (k = 10; k >= 0; --k)
                    {
                        if (i + j + k > totalScore || i + j + k != totalScore || !SurprisingCheck(i, j, k, surprising))
                            continue;

                        done = true;
                        break;
                    }

                    if (done)
                        break;

                    k = 0;
                }

                if (done)
                    break;

                j = 0;
            }

            var bestTriplet = new List<int> {i, j, k};
            return bestTriplet;
        }

        static void Main(string[] args)
        {
            using (var sr = new StreamReader(new FileStream("file.in", FileMode.Open)))
            {
                var testCases = Convert.ToInt32(sr.ReadLine());
                var output = new List<String>();

                var surprisingTriplets = new Dictionary<int, List<int>>();
                var notSurprisingTriplets = new Dictionary<int, List<int>>();

                for (var t = 0; t <= 30; ++t)
                {
                    surprisingTriplets.Add(t, GenerateBestTriplet(t, true));
                    notSurprisingTriplets.Add(t, GenerateBestTriplet(t, false));
                }

                var i = 0;
                while (!sr.EndOfStream)
                {
                    var line = sr.ReadLine().Split(' ');
                    var googlers = Convert.ToInt32(line[0]);
                    var surprising = Convert.ToInt32(line[1]);
                    var minBestResult = Convert.ToInt32(line[2]);
                    var totalScores = line.Skip(3).Take(googlers).Select(x => Convert.ToInt32(x));
                    var maxNumber = 0;

                    foreach (var totalScore in totalScores)
                    {
                        var bestSurprisingTriplet = surprisingTriplets[totalScore];
                        var bestNotSurprisingTriplet = notSurprisingTriplets[totalScore];

                        var bestMatch = false;
                        var bestNotMatch = false;
                        for (var j = 0; j < 3; ++j)
                        {
                            if (bestSurprisingTriplet[j] >= minBestResult)
                                bestMatch = true;

                            if (bestNotSurprisingTriplet[j] >= minBestResult)
                                bestNotMatch = true;
                        }

                        if (bestNotMatch)
                            ++maxNumber;
                        else
                        {
                            if (bestMatch && surprising > 0)
                            {
                                ++maxNumber;
                                --surprising;
                            }
                        }
                    }

                    output.Add("Case #" + ++i + ": " + maxNumber);   
                }

                File.WriteAllLines("file.out", output);
            }
        }
    }
}
