/* C# Program
 * Google Code Jam 2012
 * Round 1A
 * Problem B. Kingdom Rush
 * 
 * Copyright Craig A Maher - 2012
 */
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJamR1B
{
    class Program
    {
        static void Main(string[] args)
        {
            //Do("testB", false);
            //Do("B-small-attempt0", true);
            Do("B-small-attempt2", false);
            //Do("testC", false);

            Console.ReadLine();
        }

        static void Do(string FileName, bool comp)
        {
            Console.WriteLine("Doing: " + FileName);
            StreamReader input;
            StreamWriter output;
            input = new StreamReader(FileName + ".in");
            output = new StreamWriter(FileName + ".out");

            StreamReader compare = null;
            if (comp)
            {
                compare = new StreamReader(FileName + ".compare");
            }

            //if it fails porgram needs to exit anyway
            int TestCases = int.Parse(input.ReadLine());
            string outString;
            for (int i = 1; i <= TestCases; ++i)
            {
                outString = Process(input);
                outString = string.Format("Case #{0}: {1}", i, outString);
                output.WriteLine(outString);

                if (!comp || outString != compare.ReadLine())
                {
                    Console.WriteLine(outString);
                }
            }
            Console.WriteLine("Fin");
            if (comp)
            {
                compare.Close();
            }
            input.Close();
            output.Close();
        }

        //private static string Process(StreamReader input)
        //{
        //    int N = int.Parse(input.ReadLine());
        //    char[] Lane = new char[N];
        //    int[] speed = new int[N];
        //    int[] position = new int[N];
        //    string[] temp;
        //    for (int i = 0; i < N; ++i)
        //    {
        //        temp = input.ReadLine().Split(' ');
        //        speed[i] = int.Parse(temp[1]);
        //        position[i] = int.Parse(temp[2]);
        //    }
        //    double MinCollisionTime = -1;
        //    double collisionTime;
        //    for (int i = 0; i < N; ++i)
        //    {
        //        for (int j = i+1; j < N; ++j)
        //        {
        //            if (Lane[j] == Lane[i])
        //            {
        //                //check if or when a collision will occur
        //                //check if
        //                //who is behind
        //                //is person behind traveling faster then person in front
        //                if (position[i] > position[j])
        //                {
        //                    //is I faster then J
        //                    if (speed[i] < speed[j])
        //                    {
        //                        //calc collision
        //                        collisionTime = (double)(position[i] - (position[j] + 5)) / (double)(speed[j] - speed[i]);
        //                        //deterine if minimum
        //                        if (collisionTime < MinCollisionTime || MinCollisionTime == -1)
        //                        {
        //                            MinCollisionTime = collisionTime;
        //                        }
        //                    }
        //                }
        //                else
        //                {
        //                    //Is J faster then I
        //                    if (speed[j] < speed[i])
        //                    {
        //                        //calc collision
        //                        collisionTime = (double)((position[i]+5) - position[j]) / (double)(speed[j] - speed[i]);
        //                        //deterine if minimum
        //                        if (collisionTime < MinCollisionTime || MinCollisionTime == -1)
        //                        {
        //                            MinCollisionTime = collisionTime;
        //                        }
        //                    }
                            
        //                }
        //            }
        //        }
        //    }
        //    if (MinCollisionTime == -1)
        //    {
        //        return "Possible";
        //    }
        //    return MinCollisionTime.ToString();
        //}



        private static string Process(StreamReader input)
        {
            int N = int.Parse(input.ReadLine());
            int[,] levels = new int[N, 2];
            string[] level;
            for (int i = 0; i < N; ++i)
            {
                level = input.ReadLine().Split(' ');
                levels[i, 0] = int.Parse(level[0]);
                levels[i, 1] = int.Parse(level[1]);
            }
            bool[,] completed = new bool[N, 2];
            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < 2; j++)
                {
                    completed[i, j] = false;
                }
            }
            long MinLevels = 0;
            long currentStars = 0;
            bool complete = false;
            bool NewLevelCompleted = false;
            do
            {
                NewLevelCompleted = false;
                complete = true;
                for (int i = 0; i < N; ++i)
                {
                    if (!completed[i, 1])
                    {
                        if (levels[i, 1] <= currentStars)
                        {
                            completed[i, 1] = true;
                            currentStars++;
                            NewLevelCompleted = true;
                            MinLevels++;
                            if (!completed[i, 0])
                            {
                                currentStars++;
                                completed[i, 0] = true;
                            }
                        }
                        else
                        {
                            complete = false;
                        }
                    }
                }

                if (!NewLevelCompleted && !complete)
                {
                    //loop through and find the avalble star with the highest 2nd star
                    int pos = -1;
                    int highestStar = -1;
                    for (int i = 0; i < N; ++i)
                    {
                        if (!completed[i, 0])
                        {
                            if (levels[i, 0] <= currentStars)
                            {
                                if (levels[i, 1] > highestStar)
                                {
                                    pos = i;
                                    highestStar = levels[i, 1];
                                }
                            }
                        }
                        //if (!completed[i, 0] && !NewLevelCompleted)
                        //{
                        //    if (levels[i, 0] <= currentStars)
                        //    {

                        //        completed[i, 0] = true;
                        //        currentStars++;
                        //        MinLevels++;
                        //        NewLevelCompleted = true;
                        //        break;

                        //    }
                        //}
                    }
                    if (pos >= 0)
                    {
                        completed[pos, 0] = true;
                        currentStars++;
                        MinLevels++;
                        NewLevelCompleted = true;
                    }

                }
            } while (!complete && NewLevelCompleted);


            if (!NewLevelCompleted)
            {
                return "Too Bad";
            }
            return MinLevels.ToString();
            throw new NotImplementedException();
        }

        //private static string Process(StreamReader input)
        //{
        //    string line1 = input.ReadLine();
        //    string line2 = input.ReadLine();
        //    string[] AandB = line1.Split(' ');
        //    string[] Percentages = line2.Split(' ');
        //    int A = int.Parse(AandB[0]);//number of characters that I have already typed
        //    int B = int.Parse(AandB[1]);//total number of characters in my password
        //    double[] probabilities = new double[A];//probability that I correctly typed the ith letter in my password
        //    for (int i = 0; i < probabilities.Length; ++i)
        //    {
        //        probabilities[i] = double.Parse(Percentages[i]);
        //    }

        //    double MinimalAvergeKeyStrokes;

        //    //Keystrokes if I press enter right away
        //    MinimalAvergeKeyStrokes = 1 + B + 1;

        //    //Keystrokes if I keep typing
        //    int KeystorkesIfRight = 1 + (B-A);
        //    int KeystrokesIfWrong = KeystorkesIfRight + B + 1;
        //    double chanceRight = 1;
        //    for (int i = 0; i < probabilities.Length; ++i)
        //    {
        //        chanceRight *= probabilities[i];
        //    }
        //    //double Avergae = Math.Pow(A, 2);
        //    double KeyStrokes = chanceRight * KeystorkesIfRight + (1 - chanceRight) * KeystrokesIfWrong;

        //    if (KeyStrokes < MinimalAvergeKeyStrokes)
        //    {
        //        MinimalAvergeKeyStrokes = KeyStrokes;
        //    }

        //    //Keystrokes if I press backspace multi
        //    for (int i = 1; i <= A; ++i)
        //    {
        //        KeyStrokes = i;
        //        //Keystrokes if I keep typing
        //        KeystorkesIfRight = 1 + (B - A)+i;
        //        KeystrokesIfWrong = KeystorkesIfRight + B + 1;
        //        chanceRight = 1;
        //        for (int j = 0; j < probabilities.Length-i; ++j)
        //        {
        //            chanceRight *= probabilities[j];
        //        }
        //        //double Avergae = Math.Pow(A, 2);
        //        KeyStrokes += chanceRight * KeystorkesIfRight + (1 - chanceRight) * KeystrokesIfWrong;

        //        if (KeyStrokes < MinimalAvergeKeyStrokes)
        //        {
        //            MinimalAvergeKeyStrokes = KeyStrokes;
        //        }
        //    }

            	
            
            

            
        //    return MinimalAvergeKeyStrokes.ToString();
        //}
    }
}
