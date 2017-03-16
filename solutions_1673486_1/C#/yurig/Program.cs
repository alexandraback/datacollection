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
                string[] line =  lines[i].Split(' ');
                int first = Convert.ToInt32(line[0]);
                int sec = Convert.ToInt32(line[1]);
                i++;
                line = lines[i].Split(' ');
                double[] prob = new double[line.Length];
                for (int j = 0; j < line.Length; ++j) prob[j] = Convert.ToDouble(line[j]);

                double cont = calculateContinue(prob, first, sec);
                double terminate = calculateTerminate(prob, first, sec);
                double part = calculatePart(prob, first, sec);

                if (cont < terminate)
                {
                    if (cont < part) ans.Add(cont.ToString());
                    else ans.Add(part.ToString());
                }
                else
                {
                    if (terminate < part) ans.Add(terminate.ToString());
                    else ans.Add(part.ToString());
                }
            }

            writeAnsToFile(ans.ToArray());
        }

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


        private static string[] readFromFile()
        {
            List<string> ans = new List<string>();

            using (StreamReader sr = new StreamReader("C:\\Temp\\A-large.in"))
            {
                string line;
                line = sr.ReadLine();
                int lineNum = Convert.ToInt16(line);
                int num = 0;
                while (num < lineNum)
                {
                    ans.Add(sr.ReadLine());
                    ans.Add(sr.ReadLine());
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
