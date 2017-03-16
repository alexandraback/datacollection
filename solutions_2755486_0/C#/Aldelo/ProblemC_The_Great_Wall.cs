using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJamRound1C2013Console
{
    class ProblemC_The_Great_Wall
    {

        public static void Run(string fname, string ofname)
        {
            string[] solution = ReadProblemA(fname);

            string[] output = new string[solution.Length];
            for (int i = 0; i < solution.Length; i++)
            {
                output[i] = String.Format("Case #{0}: {1}", i + 1, solution[i]);

                Console.Out.WriteLine(output[i]);

            }
            Helpers.IO.WriteOutput(ofname, output.Length, output);

            //Console.ReadLine();
        }

        public static string[] ReadProblemA(string fname)
        {
            string[] outputStr = null;
            int inputlength = 0;
            int count = 0;
            StreamReader fr = new StreamReader("..\\..\\" + fname);
            while (!fr.EndOfStream)
            {
                if (inputlength == 0) // read total case
                {
                    string s = fr.ReadLine();
                    inputlength = Convert.ToInt32(s);
                    outputStr = new string[inputlength];
                }
                else
                {
                    /*
                     *  2
                        2
                        0 3 0 2 10 2 3 -2
                        10 3 2 3 8 7 2 0
                        3
                        1 2 0 5 10 2 8 0
                        0 3 0 1 7 1 2 2
                        3 3 0 5 1 1 4 0
                     */
                    TheGreatWallCase input = new TheGreatWallCase {tribes = new List<Tribes>()};
                    int inputTribes = Convert.ToInt32(fr.ReadLine());                    
                    for (int i = 0; i < inputTribes; i++)
                    {
                        string[] peek = fr.ReadLine().Split(' ');
                        int attackLeft = Convert.ToInt32(peek[1]);
                        input.tribes.Add(new Tribes
                        {
                            startDate = Convert.ToInt32(peek[0]),
                            attackLeft = attackLeft,
                            west = Convert.ToInt32(peek[2]),
                            east = Convert.ToInt32(peek[3]),
                            strLeft = Convert.ToInt32(peek[4]),
                            attackEvery = Convert.ToInt32(peek[5]),
                            moveDirection = Convert.ToInt32(peek[6]),
                            strModifier = Convert.ToInt32(peek[7]),
                        });
                        input.attackLeft += attackLeft;
                    }
                    


                    outputStr[count] = AnswerOfCase(input);

                    ++count;
                }
            }
            fr.Close();
            return outputStr;
        }

        public class TheGreatWallCase
        {
            public List<Tribes> tribes;
            public int attackLeft = 0;
        }

        public class Tribes
        {
            public int startDate;
            public int attackLeft;
            public int west, east;
            public int strLeft;
            public int attackEvery;
            public int moveDirection;
            public int strModifier;
        }


        private static string AnswerOfCase(TheGreatWallCase c)
        {
            int timeLine = 0;
            int success = 0;
            Dictionary<int, int> wall = new Dictionary<int, int>();
            while (c.attackLeft > 0)
            {
                Dictionary<int, int> wallToday = new Dictionary<int, int>(wall);
                foreach (var t in c.tribes)
                {
                    if (t.startDate > timeLine || t.attackLeft < 1)
                        continue; //not time for running yet
                    if ((timeLine - t.startDate) % t.attackEvery == 0)
                    {
                        bool successTime = false;
                        t.attackLeft--;
                        c.attackLeft--;
                        for (int i = t.west; i < t.east; i++)
                        {
                            if (!wallToday.ContainsKey(i) || wallToday[i] < t.strLeft)
                            {
                                successTime = true;
                                wall[i] = t.strLeft;
                            }
                        }
                        if (successTime)
                        {
                           // Console.WriteLine("Day " + timeLine + ": [" + t.west + "," + t.east + "] : " + t.strLeft);
                            success++;
                        }
                        t.strLeft += t.strModifier;
                        t.west += t.moveDirection;
                        t.east += t.moveDirection;
                    }
                }
                timeLine++;
            }
            return "" + success;
        }


    }
}
