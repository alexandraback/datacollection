using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

namespace GoogleCodeJam1
{
    class Program
    {
        private const string InputFilePath = @"C:\temp\input.txt";
        private const string OutputFilePath = @"C:\temp\output.txt";

        static void Main(string[] args)
        {
            Parser.ParseAndSolve(InputFilePath, OutputFilePath);

            Console.ReadKey();
        }

    }

    class Parser
    {
        public static void ParseAndSolve(string inputPath, string outputPath)
        {
            StreamReader input = new StreamReader(inputPath);
            StreamWriter output = new StreamWriter(outputPath);

            /* Parse number of cases */
            int numberOfCases;
            if (!int.TryParse(input.ReadLine(), out numberOfCases))
            {
                throw new Exception("Could not parse number of cases.");
            }

            /* Parse all cases and solve */
            for (long i = 0; i < numberOfCases; ++i)
            {
                string line = input.ReadLine();
                string name = line.Split(' ')[0];
                int n = int.Parse(line.Split(' ')[1]);



                string result = Solve(name, n);

                Console.WriteLine("Case #{0}: {1}", i + 1, result);
                output.WriteLine("Case #{0}: {1}", i + 1, result);
            }


            input.Close();
            output.Close();
        }

        private static string Solve(string name, int n)
        {
            long result = 0;
            long l = name.Count();
            for (int i = 0; i < l-n+1; i++)
            {
                for(int j=i+n-1; j<l; j++)
                {
                    string sub = name.Substring(i, j - i + 1);
                    if(Consonants(sub, n))
                    {
                        result++;
                    }
                }
            }
            return result.ToString();
        }

        private static bool Consonants(string sub, long n)
        {
            int consecutive = 0;
            for(int i=0; i<sub.Count(); i++)
            {
                if(Consonant(sub[i]))
                {
                    consecutive++;
                    if(consecutive >= n)
                    {
                        return true;
                    }
                } else
                {
                    consecutive = 0;
                }
            }
            return false;
        }

        private static bool Consonant(char c)
        {
            return !((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'));
        }
    }
}
