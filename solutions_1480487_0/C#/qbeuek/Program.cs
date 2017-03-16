using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

//na dobry początek!

namespace safety
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var inputStream = new StreamReader("..\\..\\input.txt"))
            using (var outputStream = new StreamWriter("..\\..\\output.txt.", false))
            {
                var totalCases = int.Parse(inputStream.ReadLine());

                for (var currentCase = 1; currentCase <= totalCases; currentCase++)
                {
                    var scores = inputStream.ReadLine().Split().Select(s => int.Parse(s)).Skip(1).ToArray();

                    outputStream.Write("Case #{0}:", currentCase);

                    for (var i = 0; i < scores.Length; i++)
                    {
                        var currentScore = scores[i];
                        var originalScore = scores[i];
                        var currentSum = scores.Sum();
                        var originalSum = scores.Sum();
                        var flowingScores = scores.ToArray();

                        for (var j = 0; j < flowingScores.Length; j++)
                        {
                            if (flowingScores[j] < currentScore)
                            {
                                currentSum -= currentScore - flowingScores[j];
                                flowingScores[j] = currentScore;
                            }
                        }

                        if (currentSum <= 0)
                        {
                            outputStream.Write(" 0");
                        }
                        else
                        {
                            while (true)
                            {
                                var larger = flowingScores.Where(s => s > currentScore).ToArray();
                                if (larger.Any())
                                {
                                    var nextLevel = larger.Min();
                                    var currentLevelCount = flowingScores.Count(s => s == currentScore);
                                    var scoreToAdvanceToNextLevel = (nextLevel - currentScore) * currentLevelCount;
                                    if (scoreToAdvanceToNextLevel < currentSum)
                                    {
                                        for (var j = 0; j < flowingScores.Length; j++)
                                        {
                                            if (flowingScores[j] == currentScore)
                                            {
                                                currentSum -= nextLevel - currentScore;
                                                flowingScores[j] = nextLevel;
                                            }
                                        }
                                        currentScore = nextLevel;
                                    }
                                    else
                                    {
                                        var result = 100.0M * (currentScore - originalScore + (decimal)currentSum / currentLevelCount) / originalSum;
                                        outputStream.Write(" {0:0.000000}", result);
                                        break;
                                    }
                                }
                                else
                                {
                                    var result = 100.0M * (currentScore - originalScore + (decimal)currentSum / scores.Length) / originalSum;
                                    outputStream.Write(" {0:0.000000}", result);
                                    break;
                                }
                            }
                        }
                    }

                    outputStream.WriteLine();
                }
            }
        }
    }
}
