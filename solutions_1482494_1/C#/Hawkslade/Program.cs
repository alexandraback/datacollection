using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    public class Mode
    {
        public int Easy = 0;
        public bool EasyDone = false;
        public int Hard = 0;
        public bool HardDone = false;
    }

    class Program
    {
        static void Main(string[] args)
        {
            using (TextReader input = new StreamReader("input.txt"))
            using (TextWriter output = new StreamWriter("output.txt"))
            //using (TextReader input = new StreamReader(Console.OpenStandardInput()))
            //using (TextWriter output = new StreamWriter(Console.OpenStandardOutput()))
            {
                Process(input, output);
            }
        }

        private static void Process(TextReader input, TextWriter output)
        {
            int numberOfCases = int.Parse(input.ReadLine());
            for (int currentCase = 0; currentCase < numberOfCases; currentCase++)
            {
                int levels = int.Parse(input.ReadLine());
                Mode[] levelInfo = new Mode[levels];
                for (int currentLevel = 0; currentLevel < levels; currentLevel++)
                {
                    string[] values = input.ReadLine().Split(' ');
                    levelInfo[currentLevel] = new Mode();
                    levelInfo[currentLevel].Easy = int.Parse(values[0]);
                    levelInfo[currentLevel].Hard = int.Parse(values[1]);
                }
                int stars = 0;
                int previousStars = 0;
                int games = 0;
                do
                {
                    previousStars = stars;
                    if (!CanSkipEasy(levels, levelInfo, ref stars, ref games))
                    {
                        if (!CanDoHard(levels, levelInfo, ref stars, ref games))
                        {
                            CanDoEasy(levels, levelInfo, ref stars, ref games);
                        }
                    }
                } while (stars != previousStars);
                bool done = true;
                for (int currentLevel = 0; currentLevel < levels; currentLevel++)
                {
                    if (!levelInfo[currentLevel].HardDone)
                    {
                        done = false;
                        break;
                    }
                }
                if (done)
                {
                    output.WriteLine("Case #" + (currentCase + 1).ToString() + ": " + games.ToString());
                }
                else
                {
                    output.WriteLine("Case #" + (currentCase + 1).ToString() + ": Too Bad");
                }
            }
        }

        private static bool CanSkipEasy(int levels, Mode[] levelInfo, ref int stars, ref int games)
        {
            for (int currentLevel = 0; currentLevel < levels; currentLevel++)
            {
                Mode currentInfo = levelInfo[currentLevel];
                if (currentInfo.EasyDone == false)
                {
                    if (currentInfo.Hard <= stars)
                    {
                        currentInfo.EasyDone = true;
                        currentInfo.HardDone = true;
                        stars += 2;
                        games++;
                        return true;
                    }
                }
            }
            return false;
        }
        private static bool CanDoEasy(int levels, Mode[] levelInfo, ref int stars, ref int games)
        {
            int easyIndex = -1;
            for (int currentLevel = 0; currentLevel < levels; currentLevel++)
            {
                Mode currentInfo = levelInfo[currentLevel];
                if (currentInfo.EasyDone == false)
                {
                    if (currentInfo.Easy <= stars)
                    {
                        if (easyIndex >= 0)
                        {
                            if (levelInfo[easyIndex].Hard < currentInfo.Hard)
                            {
                                easyIndex = currentLevel;
                            }
                        }
                        else
                        {
                            easyIndex = currentLevel;
                        }
                    }
                }
            }
            if (easyIndex >= 0)
            {
                levelInfo[easyIndex].EasyDone = true;
                stars++;
                games++;
                return true;
            }
            return false;
        }

        private static bool CanDoHard(int levels, Mode[] levelInfo, ref int stars, ref int games)
        {
            for (int currentLevel = 0; currentLevel < levels; currentLevel++)
            {
                Mode currentInfo = levelInfo[currentLevel];
                if (currentInfo.HardDone == false)
                {
                    if (currentInfo.Hard <= stars)
                    {
                        currentInfo.HardDone = true;
                        stars++;
                        games++;
                        return true;
                    }
                }
            }
            return false;
        }
    }
}
