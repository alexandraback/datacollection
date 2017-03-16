using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Xml.Schema;
using NUnit.Framework.Constraints;

namespace Problem2
{
    internal class Program
    {
        public static void RunTestCases(string[] rawTestCases, int numTestCases, Action<string> outputAction, Action<string> debugAction)
        {
            int currentLine = 0;
            for (int i = 0; i < numTestCases; i++)
            {
                long[] settings = rawTestCases.GetSettings(currentLine++);
                var keyboardLength = settings[0];
                var wordLength = settings[1];
                var attemptLength = settings[2];

                string keyboard = rawTestCases[currentLine++];
                string word = rawTestCases[currentLine++];

                var keyboardOdds = new Dictionary<char, int>();
                foreach (char c in keyboard)
                {
                    if (keyboardOdds.ContainsKey(c)) 
                    {keyboardOdds[c] += 1;}
                    else
                    {
                        keyboardOdds[c] = 1;
                    }
                }

                //Number of possible words
                var bestOverlap = FindOverlap(word);
                var mostTimes = CalcNumberOfTimes(attemptLength, wordLength, bestOverlap);
                
                //Odds of getting word
                float oddsWord = 1;
                float oddsOverlap = 1;
                int pos = 0;
                foreach (char c in word)
                {
                    int number = 0;
                    if (keyboardOdds.ContainsKey(c))
                    {
                        number = keyboardOdds[c];
                    }
                    else
                    {
                        oddsWord = -1;
                        break;
                    }
                    oddsWord *= number / (float)keyboardLength;
                    if (wordLength-pos<=bestOverlap)
                        oddsOverlap *= number / (float)keyboardLength;
                    pos++;
                }

                float expectedTimes;
                if (bestOverlap > 0)
                {
                    expectedTimes = oddsWord + ((mostTimes - 1)*oddsOverlap);
                }
                else
                {
                    expectedTimes = mostTimes*oddsWord;
                }
                var bananasKeep = mostTimes - expectedTimes;
                if (oddsWord == -1) bananasKeep = 0;

                outputAction("Case #" + (i + 1) + ": " + bananasKeep);
                Console.WriteLine("Case #" + (i + 1) + ": " + bananasKeep);
            }
        }

        public static int CalcNumberOfTimes(long attemptLength, long wordLength, int bestOverlap)
        {
            if (attemptLength < wordLength) return 0;
            if (bestOverlap == 0) return (int)attemptLength/(int)wordLength;
            var total = 1;
            var remainder = attemptLength - wordLength;
            var tail = wordLength - bestOverlap;
            return 1 + (int) remainder/(int) tail;

        }

        public static int FindOverlap(string word)
        {
            for (int i = 1; i < word.Length; i++)
            {
                bool overlap = true;
                int tPos = 0;
                for (int j = i; j < word.Length; j++)
                {
                    if (word[j] != word[tPos])
                    {
                        overlap = false;
                        break;
                    }
                    tPos++;
                }
                if (overlap) return word.Length - i;
            }
            return 0;
        }

        private static void Main(string[] args)
        {
            string filename = args.Length == 0 ? "" : args[0];
            if (filename == "")
            {
                var filenames = Directory.GetFiles(Environment.CurrentDirectory).Where(x => x.EndsWith(".in")).ToArray();
                Console.WriteLine("Test file?");
                int n = 0;
                foreach (var f in filenames)
                {
                    Console.WriteLine(n++ + ":" + f);
                }
                var i = int.Parse(Console.ReadLine());
                filename = filenames[i];
            }
            if (filename == "")
            {
                filename = Directory.GetFiles(Environment.CurrentDirectory).First(x => x.EndsWith(".in"));
            }

            string[] testFile = File.ReadAllLines(filename);
            int NumberOfTestCases = int.Parse(testFile.First().Trim());

            List<string> output = new List<string>();
            RunTestCases(testFile.Skip(1).ToArray(),
                NumberOfTestCases,
                output.Add,
                Console.WriteLine);
            File.WriteAllLines("output.out", output);
            Console.WriteLine("Finished " + filename);
            Console.WriteLine("-- press any key --");
            Console.ReadKey();
        }
    }

    internal static class Helpers
    {
        public static long[] GetSettings(this string[] rawFile, int line)
        {
            return rawFile[line].Split(' ')
                .Select(x => long.Parse(x.Trim())).ToArray();
        }
    }
}
