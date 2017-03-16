using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Jam1A
{
    static class Program
    {
        static void Main()
        {
            const string exercise = "B";
            const bool isLarge = false;

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
            var i = 1;
            for (var cse = 1; cse <= numberOfCases; cse++)
            {
                var firstLine = input[i++];
                var nrOfLevels = int.Parse(firstLine);
                var levels = new List<Level>();
                for (int level = 0; level < nrOfLevels; level++)
                {
                    var levelLine = input[i++];
                    var parts = levelLine.Split(' ');
                    levels.Add(new Level(int.Parse(parts[0]), int.Parse(parts[1])));
                }

                output.Add(String.Format("Case #{0}: {1}", cse, HandleCase(levels)));
            }
            return output;
        }

        static string HandleCase(List<Level> levels)
        {
            var stars = 0;
            var tries = 0;
            bool failed;
            while (true)
            {
                var level = levels.FirstOrDefault(l => !l.FinishedOneStar && !l.FinishedTwoStars && stars >= l.TwoStarReq);
                if (level != null)
                {
                    stars += 2;
                    level.FinishedOneStar = level.FinishedTwoStars = true;
                    tries++;
                    continue;
                }

                level = levels.FirstOrDefault(l => l.FinishedOneStar && !l.FinishedTwoStars && stars >= l.TwoStarReq);
                if (level != null)
                {
                    stars += 1;
                    level.FinishedTwoStars = true;
                    tries++;
                    continue;
                }

                level = levels.FirstOrDefault(l => !l.FinishedOneStar && !l.FinishedTwoStars && stars >= l.OneStarReq);
                if (level != null)
                {
                    stars += 1;
                    level.FinishedOneStar = true;
                    tries++;
                    continue;
                }

                failed = levels.Any(l => !l.FinishedTwoStars);
                break;
            }

            return failed ? "Too Bad" : "" + tries;
        }

        static string GetFileName(string exercise, bool isLarge, bool isInput)
        {
            return string.Format(@"C:\data\{0}-{1}.{2}", exercise, isLarge ? "large" : "small", isInput ? "in" : "out");
        }
    }

    internal class Level
    {
        public Level(int oneStarReq, int twoStarReq)
        {
            OneStarReq = oneStarReq;
            TwoStarReq = twoStarReq;
        }

        public bool FinishedOneStar { get; set; }
        public bool FinishedTwoStars { get; set; }
        public int OneStarReq { get; private set; }
        public int TwoStarReq { get; private set; } // TwoStarReq >= OneStarReq
    }
}
