using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace _2012R1A2
{
    class Program
    {
        static void Main()
        {
            string[] input = File.ReadAllLines("in2_small.in");
            int T = int.Parse(input[0]);
            string[] output = new string[T];

            int rowOffset = 1;
            for (int testcase = 1; testcase <= T; testcase++)
            {
                int N = int.Parse(input[rowOffset++]);
                List<Level> levels = new List<Level>();
                for (int i = 0; i < N; i++)
                {
                    string[] line = input[rowOffset++].Split(' ');
                    levels.Add(new Level
                                   {
                                       star1 = int.Parse(line[0]),
                                       star2 = int.Parse(line[1])
                                   });
                }

                int result = Solve(N, levels);
                output[testcase - 1] = String.Format("Case #{0}: {1}", testcase, (result != -1 ? result.ToString() : "Too Bad"));
            }

            File.WriteAllLines("out2.out", output);
        }

        private static int Solve(int N, List<Level> levels)
        {
            int numberOfTries = 0;
            int currentStars = 0;

            while (levels.Count > 0)
            {
                Level levelToRemove = null;
                foreach (Level level in levels)
                {
                    if (level.star2 <= currentStars)
                    {
                        if (level.doneStar1)
                            currentStars = currentStars + 1;
                        else
                            currentStars = currentStars + 2;

                        levelToRemove = level;
                        break;
                    }
                }
                
                if (levelToRemove != null)
                {
                    levels.Remove(levelToRemove);
                    numberOfTries++;
                    continue;
                }

                // no more star2 can be done
                Level maxLevel = null;
                foreach (Level level in levels)
                {
                    if (!level.doneStar1 && level.star1 <=currentStars)
                    {
                        if (maxLevel == null || maxLevel.star2 < level.star2)
                            maxLevel = level;
                    }
                }

                if (maxLevel == null)
                    return -1;

                currentStars++;
                numberOfTries++;
                maxLevel.doneStar1 = true;
            }

            return numberOfTries;
        }

        public class Level
        {
            public int star1;
            public int star2;
            public bool doneStar1;
        }
    }
}
