using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class Program
    {

        static void Main(string[] args)
        {
            string[] lines = readFromFile();

            List<string> ans = new List<string>();

            for (int i = 0; i < lines.Length; ++i)
            {
                List<int> twoStar = new List<int>();
                List<int> oneStar = new List<int>();
                List<int> total = new List<int>();
                List<int> done = new List<int>();
                List<int> doneOne = new List<int>();

                int starts = 0;
                int steps = 0;

                int lvls = Convert.ToInt32(lines[i]);
                for (int j = 0; j < lvls; j++)
                {
                    total.Add(j);
                    i++;
                    string[] rounds = lines[i].Split(' ');
                    oneStar.Add(Convert.ToInt32(rounds[0]));
                    twoStar.Add(Convert.ToInt32(rounds[1]));
                }
                bool changeMade;

            checkTwoStars:
                //check two stars
                changeMade = false;

            for (int j = 0; j < lvls; ++j)
            {
                if (starts >= twoStar[j] && !done.Contains(j) && !doneOne.Contains(j))
                {
                    steps++;
                    starts += 2;
                    done.Add(j);
                    changeMade = true;
                }
            }

            if (done.Count == lvls)
            {
                ans.Add(steps.ToString());
                goto finishLoop;
            }

            while (changeMade)
            {
                changeMade = false;
                for (int j = 0; j < lvls; ++j)
                {
                    if (starts >= twoStar[j] && !done.Contains(j) && !doneOne.Contains(j))
                    {
                        steps++;
                        starts += 2;
                        done.Add(j);
                        changeMade = true;
                        if (done.Count == lvls)
                        {
                            ans.Add(steps.ToString());
                            goto finishLoop;
                        }
                    }
                }
            }


                for (int j = 0; j < lvls; ++j)
                {
                    if (starts >= twoStar[j] && !done.Contains(j) && doneOne.Contains(j))
                    {
                        steps++;
                        starts++;
                        done.Add(j);
                        changeMade = true;
                        if (done.Count == lvls)
                        {
                            ans.Add(steps.ToString());
                            goto finishLoop;
                        }
                        goto checkTwoStars;
                    }
                }

                if (!changeMade)
                {
                    for (int j = 0; j < lvls; ++j)
                    {
                        if (starts >= oneStar[j] && !doneOne.Contains(j) && !done.Contains(j))
                        {
                            steps++;
                            starts++;
                            doneOne.Add(j);
                            changeMade = true;
                            if (done.Count == lvls)
                            {
                                ans.Add(steps.ToString());
                                goto finishLoop;
                            }
                            goto checkTwoStars;
                        }
                    }
                }

                if (done.Count == lvls)
                {
                    ans.Add(steps.ToString());
                }
                else
                {
                    ans.Add("Too Bad");
                }
            finishLoop:
                int x = 1;
            }

            writeAnsToFile(ans.ToArray());
        }

        /*
        private static double calculatePart(double[] prob, int first, int sec)
        {
            double min = sec * 999999;
            for (int i = 0; i < first; ++i)
            {
                int deleted = first - i;
                double p = 1;
                for (int j = 0; j < deleted; ++j) p *= prob[j];
                double correct = p * (i + sec - deleted + 1);
                double wrong = (1 - p) * (sec + 1 + i + sec - deleted + 1);
                if (min > correct + wrong) min = correct + wrong;
            }

            return min;
        }

        private static double calculateTerminate(double[] prob, int first, int sec)
        {
            if (first != sec)
            {
                return sec + 2;
            }
            else
            {
                double p = 1;
                foreach (double d in prob) p *= d;
                return p + (1 - p) * (sec + 2);
            }
        }

        private static double calculateContinue(double[] prob, int first, int sec)
        {
            double p = 1;
            foreach (double d in prob) p *= d;
            double correct = p * (sec - first + 1);
            double wrong = (1 - p) * ((sec - first + 1) + (sec + 1));
            return correct + wrong;
        }

        */
        private static string[] readFromFile()
        {
            List<string> ans = new List<string>();

            //using (StreamReader sr = new StreamReader("C:\\Temp\\B-small-attempt2.in"))
            using (StreamReader sr = new StreamReader("C:\\Temp\\B-small-attempt3.in"))
            {
                string line;
                line = sr.ReadLine();
                int lineNum = Convert.ToInt16(line);
                int num = 0;
                while (num < lineNum)
                {
                    int numOflvl = Convert.ToInt32(sr.ReadLine());
                    ans.Add(numOflvl.ToString());
                    for (int i = 0; i < numOflvl; i++) ans.Add(sr.ReadLine());
                    num++;
                }
            }
            //ans.Sort();
            return ans.ToArray();
        }


        private static void writeAnsToFile(string[] totalLines)
        {
            for (int i = 0; i < totalLines.Length; ++i)
            {
                totalLines[i] = "Case #" + (i+1) + ": " + totalLines[i];
            }
            System.IO.File.WriteAllLines(@"C:\Temp\Output.txt", totalLines);
        }

        /*
        private static int getCol(char[,] maze, int rows, int cols)
        {
            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < cols; ++j)
                {
                    if (maze[i, j] == 'X') return j;
                }
            }
            return -1;
        }

        private static int getRow(char[,] maze, int rows, int cols)
        {
            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < cols; ++j)
                {
                    if (maze[i, j] == 'X') return i;
                }
            }
            return -1;
        }


        private static void printMaze(char[,] maze, int rows, int cols)
        {
            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < cols; ++j)
                {
                    Console.Write(maze[i, j]);
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }

        private static bool ConsoleSpecialKey(int score, int target)
        {
            if (target == 0) return true;
            return (score >= 3 * target - 4) && (score >= target);
        }

        private static bool regular(int score, int target)
        {
            if (target == 0) return true;
            return (score >= 3 * target - 2) && (score >= target);
        }
        */
        /*
        private static void setKeys(Dictionary<char, char> translator)
        {
            translator.Add('a', 'y');
            translator.Add('b', 'h');
            translator.Add('c', 'e');
            translator.Add('d', 's');
            translator.Add('e', 'o');
            translator.Add('f', 'c');
            translator.Add('g', 'v');
            translator.Add('h', 'x');
            translator.Add('i', 'd');
            translator.Add('j', 'u');
            translator.Add('k', 'i');
            translator.Add('l', 'g');
            translator.Add('m', 'l');
            translator.Add('n', 'b');
            translator.Add('o', 'k');
            translator.Add('p', 'r');
            translator.Add('q', 'z');
            translator.Add('r', 't');
            translator.Add('s', 'n');
            translator.Add('t', 'w');
            translator.Add('u', 'j');
            translator.Add('v', 'p');
            translator.Add('w', 'f');
            translator.Add('x', 'm');
            translator.Add('y', 'a');
            translator.Add('z', 'q');
            translator.Add(' ', ' ');

        }
        */

    }
}
