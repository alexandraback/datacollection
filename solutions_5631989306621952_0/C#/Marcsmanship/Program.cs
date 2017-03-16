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
                
                for (var i = 0; i < numTestCases; ++i)
                {
                    var sWord = streamReader.ReadLine();

                    var strBuilder = new StringBuilder(sWord.Length);
                    strBuilder.Append(sWord[0]);
                    for(var index = 1; index < sWord.Length; ++index)
                    {
                        var currentChar = sWord[index];
                        if (strBuilder[0] > currentChar)
                        {
                            strBuilder.Append(currentChar);
                        }
                        else
                        {
                            strBuilder.Insert(0, currentChar);
                        }
                    }

                    answersList.Add(strBuilder.ToString());
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
            SolveProblem("A-small-attempt0.in", "output.txt");

        }
    }
}
