using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

namespace _2016_1BA
{
    class Program
    {
        static string RemoveFirst(char c, string s)
        {
            return s.Remove(s.IndexOf(c), 1);
        }

        static string Remove(string r, string s)
        {
            //Console.Out.WriteLine(r);
            foreach (char c in r)
            {
                s = RemoveFirst(c, s);
            }

            return s;
        }

        static string RunCase(StreamReader inputReader)
        {
            string line = inputReader.ReadLine();
            List<int> numbers = new List<int>();

            while (line.Length > 0)
            {
                //Console.Out.WriteLine(line);

                if (line.Contains('Z'))
                {
                    line = Remove("ZERO", line);
                    numbers.Add(0);
                }
                else if (line.Contains('X'))
                {
                    line = Remove("SIX", line);
                    numbers.Add(6);
                }
                else if (line.Contains('G'))
                {
                    line = Remove("EIGHT", line);
                    numbers.Add(8);
                }
                else if (line.Contains('W'))
                {
                    line = Remove("TWO", line);
                    numbers.Add(2);
                }
                else if (line.Contains('U'))
                {
                    line = Remove("FOUR", line);
                    numbers.Add(4);
                }
                else if (line.Contains('H'))
                {
                    line = Remove("THREE", line);
                    numbers.Add(3);
                }
                else if (line.Contains('F'))
                {
                    line = Remove("FIVE", line);
                    numbers.Add(5);
                }
                else if (line.Contains('V'))
                {
                    line = Remove("SEVEN", line);
                    numbers.Add(7);
                }
                else if (line.Contains('I'))
                {
                    line = Remove("NINE", line);
                    numbers.Add(9);
                }
                else
                {
                    line = Remove("ONE", line);
                    numbers.Add(1);
                }
            }

            numbers.Sort();

            return string.Join("", numbers);
        }

        static String fileName = "A-small-attempt1";
        //static String fileName = "practice";
        static String pathToFiles = "../../" + "/" + fileName;
        static String inputFileName = pathToFiles + ".in";
        static String outputFileName = pathToFiles + ".out";

        static void Main(string[] args)
        {
            using (StreamReader inputReader = new StreamReader(inputFileName))
            {
                File.WriteAllText(outputFileName, string.Empty);
                using (StreamWriter outputFile = new StreamWriter(outputFileName))
                {
                    int testCaseCount = Int32.Parse(inputReader.ReadLine());
                    for (int caseIterator = 0; caseIterator < testCaseCount; caseIterator++)
                    {
                        String caseResult = RunCase(inputReader);
                        String caseOutput = "Case #" + (caseIterator + 1) + ": " + caseResult;
                        outputFile.WriteLine(caseOutput);
                        Console.Out.WriteLine(caseOutput);
                    }
                }
            }

            Console.Read();
        }
    }
}
