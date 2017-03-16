using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GJam_R1SubA_B
{
    class Program
    {
        static void Main(string[] args)
        {
            if (args.Length == 0) return;

            string filename = args[0];
            var lines = File.ReadLines(filename).ToList();

            int testCount = int.Parse(lines.ElementAt(0));
            int lineNum = 1;
            for (int i = 0; i < testCount; i++)
            {
                string firstLine = lines[lineNum];
                int levelCount = int.Parse(firstLine);
                int[,] levels = new int[2, levelCount];
                lineNum++;
                for (int j = 0; j < levelCount; j++)
                {
                    string linen = lines[lineNum];
                    lineNum++;

                    string[] tmp = linen.Split(new char[] { ' ' });
                    levels[0, j] = int.Parse(tmp[0]);
                    levels[1, j] = int.Parse(tmp[1]);
                }

                int res = GetMinLevelPassing(levelCount, levels);
                if (res >= 0)
                    File.AppendAllText(filename + ".out", "Case #" + (i + 1) + ": " + res);
                else
                    File.AppendAllText(filename + ".out", "Case #" + (i + 1) + ": " + "Too Bad");
                File.AppendAllText(filename + ".out", "\n");
            }
        }

        private static int GetMinLevelPassing(int levelCount, int[,] levels)
        {
            int stars = 0;
            int turnsMade = 0;
            bool[,] levelsPassed = new bool[2, levelCount]; 

            while (stars < levelCount * 2)
            {
                bool foundTurn = false;

                //find the second level to pass, if possible
                for (int i = 0; i < levelCount; i++ )
                {
                    if (levels[1, i] <= stars && !levelsPassed[1, i])
                    {
                        stars++;
                        if (!levelsPassed[0, i])
                            stars++;

                        levelsPassed[0, i] = true;
                        levelsPassed[1, i] = true;

                        foundTurn = true;
                        break;
                    }
                }

                if (foundTurn)
                {
                    turnsMade++;
                    continue;
                }

                
                //find the first level to pass, if possible;
                //take the highest 2nd
                int index = -1;
                for (int i = 0; i < levelCount; i++)
                {
                    if (levels[0, i] <= stars && !levelsPassed[0, i])
                    {
                        if (index < 0 ||
                            levels[1, index] < levels[1, i])
                        {
                            index = i;
                        }
                    }
                }

                if (index >= 0)
                {
                    stars++;

                    levelsPassed[0, index] = true;

                    turnsMade++;
                    continue;
                }

                //else
                return -1;
            }

            return turnsMade;
        }
    }
}
