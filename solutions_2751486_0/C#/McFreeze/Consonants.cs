// Mike Terranova
// Google Code Jam 2013
// Using Visual Studio 2012 with .NET Framework 4.5
// May 12, 2013

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace CodeJam
{
    class Consonants
    {
        #region Common stuff

        static string outputFormat = "Case #{0}: {1}";
        static int caseNumber;

        public static void WriteOutput(string output)
        {
            Console.WriteLine(outputFormat, caseNumber, output);
        }

        public static int ReadInt()
        {
            return Convert.ToInt32(Console.ReadLine());
        }

        public static double ReadFloat()
        {
            return Convert.ToDouble(Console.ReadLine());
        }

        public static decimal ReadDecimal()
        {
            return Convert.ToDecimal(Console.ReadLine());
        }

        #endregion

        static void Main(string[] args)
        {
            int numberOfCases = ReadInt();
            for (caseNumber = 1; caseNumber <= numberOfCases; caseNumber++)
            {
                string[] input = Console.ReadLine().Split(null, 2);
                string word = input[0];
                int minCons = Convert.ToInt32(input[1]);

                TestCase(word, minCons);
            }
        }

        public static bool IsMatch(string word, Regex regex)
        {
            return regex.IsMatch(word);
        }

        public static void TestCase(string word, int minCons)
        {
            Regex consonantRegex = new Regex("[bcdfghjklmnpqrstvwxyz]{" + minCons.ToString() + "}");
            
            // query adapted from stack overflow
            int score = (from i in Enumerable.Range(0, word.Length - 1)
                         from j in Enumerable.Range(0, word.Length - i + 1)
                         where i + j <= word.Length
                            && IsMatch(word.Substring(i, j), consonantRegex)
                         select word.Substring(i, j)).Count();

            WriteOutput(score.ToString());
        }
    }
}

