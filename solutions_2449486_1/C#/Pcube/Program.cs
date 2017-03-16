using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Lawnmower
{
    class Program
    {
        static int numberOfTestcases = 0;
        static string[] allInputLines, allOutputLines;
        static int nextLine = 0;
        static char[] split = { ' ' };

        static string YES = "YES";
        static string NO = "NO";

        static void Main(string[] args)
        {
            allInputLines = File.ReadAllLines("Input.txt");
            numberOfTestcases = int.Parse(allInputLines[nextLine].Trim());
            nextLine++;
            allOutputLines = new String[numberOfTestcases];
            for (int i = 1; i <= numberOfTestcases; i++)
            {
                string output = PatternChecker(i);
                allOutputLines[i - 1] = String.Format("Case #{0}: {1}", i, output);
            }
            File.WriteAllLines("Output.txt", allOutputLines);
        }

        static string PatternChecker(int testCase)
        {
            int N, M;
            string[] inputs = allInputLines[nextLine].Split(split);
            nextLine++;
            N = int.Parse(inputs[0]);
            M = int.Parse(inputs[1]);
            int[,] lawn = new int[N, M];
            for (int i = 0; i < N; i++)
            {
                inputs = allInputLines[nextLine].Split(split);
                nextLine++;
                for (int j = 0; j < M; j++)
                    lawn[i, j] = int.Parse(inputs[j]);
            }
            for (int i = 0; i < N; i++)
            {
                int highest = lawn[i, 0];
                bool isSameLength = true;
                for (int j = 1; j < M; j++)
                {
                    if (lawn[i, j] != highest)
                    {
                        isSameLength = false;
                        if (lawn[i, j] > highest)
                            highest = lawn[i, j];
                    }
                }
                if (isSameLength) //This row is possible
                    continue;
                for (int j = 0; j < M; j++)
                {
                    if (lawn[i, j] != highest)
                    {
                        //if anything is taller than this in that column
                        for (int k = 0; k < N; k++)
                        {
                            if (k != i)
                                if (lawn[k, j] > lawn[i, j])
                                    return NO;
                        }
                    }
                }
            }
            return YES;
        }
    }
}
