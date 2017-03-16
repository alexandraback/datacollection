using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TheRepeater
{
    class Program
    {
        const string filename = "A-small-attempt2.in";
        const int linesForCaseNumber = 1;

        const string notPossible = "Fegla Won";

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(filename);
            int T_cases = int.Parse(sr.ReadLine());

            Debug.Assert(T_cases >= 1, "Input cases not correct");

            for (int currentCase = 1; currentCase <= T_cases; currentCase++)
            {
                int N_strings = int.Parse(sr.ReadLine());
                string[] allStringsForProblem = new string[N_strings];
                for (int i = 0; i < N_strings; i++)
                {
                    allStringsForProblem[i] = sr.ReadLine();
                }
                string resultForCase = SolveTheRepeaterProblemForLines(allStringsForProblem);

                Console.WriteLine("Case #{0}: {1}", currentCase, resultForCase);
            }
        }

        private static string SolveTheRepeaterProblemForLines(string[] allStringsForProblem)
        {
            int countWords = allStringsForProblem.Length;

            List<WordDepiction> convertedWords = allStringsForProblem.Select(ConvertWord).ToList();

            int simplestForms = convertedWords.Select(Simplify).Distinct().Count();

            if (simplestForms > 1)
            {
                return notPossible;
            }
            else
            {
                // There is solution
                return SolveForWords(convertedWords);
            }
        }

        private static string SolveForWords(List<WordDepiction> convertedWords)
        {
            int totalMinimum = 0;
            int countOfLetters = convertedWords.First().chars.Count;

            for (int i = 0; i < countOfLetters; i++)
            {
                int minimumMovesOfNumbers = ForLetters(convertedWords.Select(word => word.chars[i].repeat).ToArray());
                totalMinimum += minimumMovesOfNumbers;
            }

            return totalMinimum.ToString();
        }

        private static int ForLetters(int[] numbers)
        {
            int maxNum = numbers.Max();
            int totalMin = int.MaxValue;

            for (int i = 1; i <= maxNum; i++)
            {
                int allDiffs = DifferenceNumbers(numbers, i);
                if (allDiffs < totalMin)
                    totalMin = allDiffs;
            }

            return totalMin;
        }

        private static int DifferenceNumbers(int[] numbers, int i)
        {
            return numbers.Sum(eachNum => Math.Abs(eachNum - i));
        }

        private static int CalculateDiff(WordDepiction wordA, WordDepiction wordB)
        {
            int diff = 0;

            for (int i = 0; i < wordA.chars.Count; i++)
            {
                diff += Math.Abs(wordA.chars[i].repeat - wordB.chars[i].repeat);
            }

            return diff;
        }

        private static string Simplify(WordDepiction arg)
        {
            return new String(arg.chars.Select(eachCharacter => eachCharacter.c).ToArray());
        }

        private static WordDepiction ConvertWord(string arg)
        {
            char? prevLetter = null;
            int letterCount = 0;
            List<RepeatedCharacter> repeatedCharacters = new List<RepeatedCharacter>();

            foreach (char letter in arg)
            {
                if (!prevLetter.HasValue)
                {
                    prevLetter = letter;
                }

                if (prevLetter.Value == letter)
                {
                    letterCount++;
                }
                else
                {
                    repeatedCharacters.Add(new RepeatedCharacter() { c = prevLetter.Value, repeat = letterCount });
                    letterCount = 1;
                }

                prevLetter = letter;
            }

            // last letter
            repeatedCharacters.Add(new RepeatedCharacter() { c = prevLetter.Value, repeat = letterCount });

            return new WordDepiction { chars = repeatedCharacters, word = arg };
        }

        class WordDepiction
        {
            public List<RepeatedCharacter> chars { get; set; }

            public string word { get; set; }
        }

        class RepeatedCharacter
        {
            public char c { get; set; }
            public int repeat { get; set; }
        }
    }
}
