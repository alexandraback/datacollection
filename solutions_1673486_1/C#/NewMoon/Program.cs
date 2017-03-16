using System;
using System.Collections.Generic;
using System.IO;
using System.Threading;
using System.Linq;

namespace Jam1A
{
    class Program
    {
        static void Main()
        {
            const string exercise = "A";
            const bool isLarge = true;

            var input = File.ReadAllLines(GetFileName(exercise, isLarge, true));
            var numberOfCases = int.Parse(input[0]);
            
            var start = DateTime.Now;

            var output = HandleInput(input, numberOfCases);
            File.WriteAllLines(GetFileName(exercise, isLarge, false), output.ToArray());

            var end = DateTime.Now;
            var span = end - start;
            Console.WriteLine("Milliseconds spent = " + span.TotalMilliseconds);
            Console.ReadKey();
        }

        static List<string> HandleInput(string[] input, int numberOfCases)
        {
            var output = new List<string>();
            int i = 1;
            for (var cse = 0; cse < numberOfCases; cse++)
            {
                Console.WriteLine("Case " + (cse + 1));
                var firstLine = input[i++];
                var firstParts = firstLine.Split(' ');
                var alreadyTyped = long.Parse(firstParts[0]);
                var passwordLength = long.Parse(firstParts[1]);
                var secondLine = input[i++];
                var secondParts = secondLine.Split(' ');
                var probs = secondParts.Select(double.Parse).ToList();

                output.Add(String.Format("Case #{0}: {1}", cse + 1, HandleCase(alreadyTyped, passwordLength, probs)));
            }
            return output;
        }

        static string HandleCase(long alreadyTyped, long passwordLength, List<double> probs)
        {
            var scores = new List<double>();
            scores.Add(GetKeepTypingScore(alreadyTyped, passwordLength, probs));
            for (int i = 1; i < alreadyTyped; i++)
            {
                if (i % 100 == 0)
                    Console.WriteLine("" + i + " of " + alreadyTyped);
                scores.Add(BackspaceScore(alreadyTyped, passwordLength, probs, i));
            }
            scores.Add(EnterScore(alreadyTyped, passwordLength, probs));
            return "" + scores.Min();
        }

        static double EnterScore(long alreadyTyped, long passwordLength, List<double> probs)
        {
            return 1 + passwordLength + 1;
        }

        static double BackspaceScore(long alreadyTyped, long passwordLength, List<double> probs, int nrOfBack)
        {
            var correctChance = 1.0;
            for (int i = 0; i < alreadyTyped - nrOfBack; i++)
                correctChance *= probs[i];
            var toTypeIfCorrect = passwordLength - alreadyTyped + nrOfBack + nrOfBack + 1;
            return correctChance * toTypeIfCorrect +
                (1 - correctChance) * (toTypeIfCorrect + passwordLength + 1);
        }

        static double GetKeepTypingScore(long alreadyTyped, long passwordLength, List<double> probs)
        {
            var correctChance = 1.0;
            foreach (var prob in probs)
                correctChance *= prob;
            var toTypeIfCorrect = passwordLength - alreadyTyped + 1;
            return correctChance * toTypeIfCorrect +
                (1 - correctChance) * (toTypeIfCorrect + passwordLength + 1);
        }

        static string GetFileName(string exercise, bool isLarge, bool isInput)
        {
            return string.Format(@"C:\data\{0}-{1}.{2}", exercise, isLarge ? "large" : "small", isInput ? "in" : "out");
        }
    }
}
