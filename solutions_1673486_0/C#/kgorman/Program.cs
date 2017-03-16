using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Text;

namespace Question1
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = "C:/temp/A-small-attempt0.in";

            var lines = File.ReadAllLines(input);

            var testCases = new Collection<TestCase>();
            var numTests = Convert.ToInt32(lines[0]);
            for (int i = 1; i < lines.Length; i++)
            {
                var temp = lines[i].Split(' ');
                var testCase = new TestCase
                                   {
                                       AlreadyTyped = Convert.ToInt32(temp[0]),
                                       PasswordLength = Convert.ToInt32(temp[1])
                                   };

                var probabilities = lines[++i].Split(' ');
                testCase.Probabilities = new Collection<double>(probabilities.Select(Convert.ToDouble).ToList());

                testCases.Add(testCase);
            }

            using (var writer = File.Create("C:/temp/output.txt"))
            {
                Console.SetOut(new StreamWriter(writer));
                for (int i = 0; i < testCases.Count; i++)
                {
                    var solution = Solve(testCases[i]);
                    Console.WriteLine("Case #{0}: {1}", i + 1, solution);
                }
                Console.Out.Flush();
            }
        }

        private static double Solve(TestCase testCase)
        {
            var probablityCorrect = testCase.Probabilities.Aggregate(1.0, (d, d1) => d*d1);

            // keep typing
            double keepTyping = (testCase.PasswordLength - testCase.AlreadyTyped + 1)*probablityCorrect
                                +
                                (testCase.PasswordLength - testCase.AlreadyTyped + 1 + testCase.PasswordLength + 1)*
                                (1 - probablityCorrect);

            // give up now
            double giveUp = (1 + testCase.PasswordLength + 1);

            double best = Math.Min(keepTyping, giveUp);

            // try deleting chars
            double correctUpToThisPoint = probablityCorrect;
            var reverseProbs = testCase.Probabilities.Reverse().ToArray();
            for (int i = 1; i < testCase.AlreadyTyped; i++)
            {
                correctUpToThisPoint /= reverseProbs[i - 1];

                var charsToFinish = testCase.PasswordLength - testCase.AlreadyTyped + 1 + i*2;
                double expected = charsToFinish*correctUpToThisPoint
                                  +
                                  (charsToFinish + testCase.PasswordLength + 1)*(1 - correctUpToThisPoint);

                best = Math.Min(best, expected);
            }

            return best;
        }
    }

    internal class TestCase
    {
        public int AlreadyTyped { get; set; }

        public int PasswordLength { get; set; }

        public Collection<double> Probabilities { get; set; }
    }
}
