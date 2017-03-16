using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace r0pc
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var inputStream = new StreamReader("../../input.txt"))
            using (var outputStream = new StreamWriter("../../output.txt", false, Encoding.Default))
            {
                var caseCount = int.Parse(inputStream.ReadLine());

                for (var caseNumber = 1; caseNumber <= caseCount; caseNumber++)
                {
                    var X = inputStream.ReadLine().Split().Select(s => long.Parse(s)).ToArray()[1];
                    var word = inputStream.ReadLine().Select(c => {
                        switch (c)
                        {
                            case 'i': return 1;
                            case 'j': return 2;
                            case 'k': return 3;
                            default: throw new ArgumentException();
                        }
                    }).ToArray();

                    var transitions = new int[][] {
                        new int[] {0,1,2,3,4,5,6,7},
                        new int[] {1,4,3,6,5,0,7,2},
                        new int[] {2,7,4,1,6,3,0,5},
                        new int[] {3,2,5,4,7,6,1,0},
                        new int[] {4,5,6,7,0,1,2,3},
                        new int[] {5,0,7,2,1,4,3,6},
                        new int[] {6,3,0,5,2,7,4,1},
                        new int[] {7,6,1,0,3,2,5,4}
                    };

                    var fullWordTransitions = new int[8][];
                    for (var i = 0; i < fullWordTransitions.Length; i++)
                    {
                        fullWordTransitions[i] = new int[word.Length];
                        var current = i;
                        for (var j = 0; j < word.Length; j++)
                        {
                            current = transitions[current][word[j]];
                            fullWordTransitions[i][j] = current;
                        }
                    }

                    var cycleLengths = new int[8];
                    for (var i = 0; i < fullWordTransitions.Length; i++)
                    {
                        var visited = new HashSet<int>();
                        var current = i;
                        while (!visited.Contains(current))
                        {
                            visited.Add(current);
                            current = fullWordTransitions[current].Last();
                        }
                        cycleLengths[i] = visited.Count;
                    }

                    var startingLetterTransitions = new int[word.Length][];
                    for (var i = 0; i < startingLetterTransitions.Length; i++)
                    {
                        startingLetterTransitions[i] = new int[word.Length - i];
                        var current = 0;
                        for (var j = i; j < word.Length; j++)
                        {
                            current = transitions[current][word[j]];
                            startingLetterTransitions[i][j - i] = current;
                        }
                    }

                    var result = CanFindPath(0, X - 1, fullWordTransitions, startingLetterTransitions, cycleLengths, 1, 2, 3);
                    outputStream.WriteLine("Case #{0}: {1}", caseNumber, result ? "YES" : "NO");
                }
            }
        }

        private static bool CanFindPath(int startingLetter, long wordsLeft, int[][] fullWordTransitions, int[][] startingLetterTransitions, int[] cycleLengths, params int[] lettersToBeFound)
        {
            if (lettersToBeFound.Length == 1)
            {
                return WillEndWithLastLetter(startingLetter, wordsLeft, fullWordTransitions, startingLetterTransitions, cycleLengths, lettersToBeFound[0]);
            }

            var startingLetterStates = startingLetterTransitions[startingLetter];
            for (var i = 0; i < startingLetterStates.Length; i++)
            {
                if (startingLetterStates[i] == lettersToBeFound[0])
                {
                    var nextStartingLetter = startingLetter + i + 1;
                    var nextWordsLeft = wordsLeft;
                    if (nextStartingLetter == fullWordTransitions[0].Length)
                    {
                        nextStartingLetter = 0;
                        nextWordsLeft--;
                    }

                    if (nextWordsLeft >= 0 && CanFindPath(nextStartingLetter, nextWordsLeft, fullWordTransitions, startingLetterTransitions, cycleLengths, lettersToBeFound.Skip(1).ToArray()))
                        return true;
                }
            }

            var checkedFullWordTransitions = new HashSet<int>();
            var wordLetter = startingLetterStates.Last();
            while (wordsLeft > 0 && !checkedFullWordTransitions.Contains(wordLetter))
            {
                wordsLeft--;
                checkedFullWordTransitions.Add(wordLetter);
                var wordLetterStates = fullWordTransitions[wordLetter];
                for (var i = 0; i < wordLetterStates.Length; i++)
                {
                    if (wordLetterStates[i] == lettersToBeFound[0])
                    {
                        var nextStartingLetter = i + 1;
                        var nextWordsLeft = wordsLeft;
                        if (nextStartingLetter == fullWordTransitions[0].Length)
                        {
                            nextStartingLetter = 0;
                            nextWordsLeft--;
                        }

                        if (nextWordsLeft >= 0 && CanFindPath(nextStartingLetter, nextWordsLeft, fullWordTransitions, startingLetterTransitions, cycleLengths, lettersToBeFound.Skip(1).ToArray()))
                            return true;
                    }
                }
                wordLetter = wordLetterStates.Last();
            }

            return false;
        }

        private static bool WillEndWithLastLetter(int startingLetter, long wordsLeft, int[][] fullWordTransitions, int[][] startingLetterTransitions, int[] cycleLengths, int lastLetter)
        {
            var endingLetter = startingLetterTransitions[startingLetter].Last();
            wordsLeft = wordsLeft % cycleLengths[endingLetter];
            while (wordsLeft > 0)
            {
                endingLetter = fullWordTransitions[endingLetter].Last();
                wordsLeft--;
            }

            return endingLetter == lastLetter;
        }

    }
}
