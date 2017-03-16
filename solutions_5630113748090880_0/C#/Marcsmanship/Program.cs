using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace ConsoleApplication1
{
    class Program
    {

        static string FilePath = @"C:\Users\marc\Desktop\";

        static void SolveProblem(string inputFileName, string outputFileName)
        {
            var answersList = new List<string>();
            
            using (var streamReader = new StreamReader(FilePath + inputFileName))
            {
                var numTestCases = int.Parse(streamReader.ReadLine());
                for (var test = 0; test < numTestCases; ++test)
                {
                    var gridWidth = int.Parse(streamReader.ReadLine());
                    var numLines = gridWidth * 2 - 1;
                    var soldierSet = new HashSet<string>();

                    for (var i = 0; i < numLines; ++i)
                    {
                        var soldierArrayChar = streamReader.ReadLine().Split(' ');

                        foreach (var soldier in soldierArrayChar)
                        {
                            if (soldierSet.Contains(soldier))
                            {
                                soldierSet.Remove(soldier);
                            }
                            else
                            {
                                soldierSet.Add(soldier);
                            }
                        }
                    }


                    var sortedSoldierSet = new List<int>();
                    foreach (var soldier in soldierSet)
                    {
                        sortedSoldierSet.Add(int.Parse(soldier));
                    }

                    sortedSoldierSet.Sort();

                    var strBuilder = new StringBuilder();
                    for (var index = 0; index < sortedSoldierSet.Count; ++index)
                    {
                        strBuilder.Append(sortedSoldierSet[index]);
                        strBuilder.Append(' ');
                    }

                    var answer = strBuilder.ToString().TrimEnd(' ');
                    answersList.Add(answer);
                }

                
            }

            

            using (var streamWriter = new StreamWriter(FilePath + outputFileName))
            {
                for (var i = 0; i < answersList.Count; ++i)
                {
                    var output = string.Format("Case #{0}: {1}", i + 1, answersList[i]);
                    
                    streamWriter.WriteLine(output);
                    Console.WriteLine(output);
                }
            }                
        }

        static void Main(string[] args)
        {
            SolveProblem("B-small-attempt2.in", "output.txt");

        }
    }
}
