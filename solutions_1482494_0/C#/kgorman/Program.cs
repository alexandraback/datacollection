using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = "C:/temp/B-small-attempt5.in";

            var lines = File.ReadAllLines(input);

            var testCases = new Collection<TestCase>();
            var numTests = Convert.ToInt32(lines[0]);
            for (int i = 1; i < lines.Length; i++)
            {
                var testCase = new TestCase {Levels = new Collection<Level>()};
                var numLevels = Convert.ToInt32(lines[i]);

                for (int j = i + 1; j <= i + numLevels; j++)
                {
                    var levelRequirements = lines[j].Split(' ');
                    testCase.Levels.Add(new Level
                                            {
                                                OneStarRequirement = Convert.ToInt32(levelRequirements[0]),
                                                TwoStarRequirement = Convert.ToInt32(levelRequirements[1])
                                            });
                }

                i += numLevels;
                testCases.Add(testCase);
            }

            using (var writer = File.Create("C:/temp/output.txt"))
            {
                Console.SetOut(new StreamWriter(writer));
                for (int i = 0; i < testCases.Count; i++)
                {
                    var solution = Solve(testCases[i]);
                    Console.WriteLine("Case #{0}: {1}", i + 1,
                                      solution == int.MaxValue ? "Too Bad" : solution.ToString());
                }
                Console.Out.Flush();
            }
        }

        private static int Solve(TestCase testCase)
        {
            return Recurse(testCase, 0, 0);
        }

        private static int Recurse(TestCase testCase, int count, int stars)
        {
            if (testCase.Levels.All(l => l.TwoStarsEarnt))
            {
                return count;
            }

            int min = int.MaxValue;

            if (testCase.Levels.Any(l => !l.TwoStarsEarnt && l.TwoStarRequirement <= stars))
            {
                foreach (var level in testCase.Levels.Where(l => !l.TwoStarsEarnt && l.TwoStarRequirement <= stars))
                {
                    level.TwoStarsEarnt = true;
                    var value = Recurse(testCase, count + 1, stars + (level.OneStarEarnt ? 1 : 2));
                    level.TwoStarsEarnt = false;

                    min = Math.Min(min, value);
                }
            }
            else if (testCase.Levels.Any(l => !l.TwoStarsEarnt && !l.OneStarEarnt && l.OneStarRequirement <= stars))
            {
                foreach (var level in testCase.Levels.Where(l => !l.TwoStarsEarnt && !l.OneStarEarnt && l.OneStarRequirement <= stars))
                {
                    level.OneStarEarnt = true;
                    var value = Recurse(testCase, count + 1, stars + 1);
                    level.OneStarEarnt = false;

                    min = Math.Min(min, value);
                }
            }

            return min;
        }
    }

    class TestCase
    {
        public Collection<Level> Levels { get; set; }
    }

    internal class Level    
    {
        public int OneStarRequirement { get; set; }
        public int TwoStarRequirement { get; set; }

        public bool OneStarEarnt { get; set; }
        public bool TwoStarsEarnt { get; set; }
    }
}
