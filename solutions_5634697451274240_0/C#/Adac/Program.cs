using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ProblemB
{
    class Program
    {
        static void Main(string[] args)
        {
            SolveHandler.SolveProblem();
        }
    }
    static class SolveHandler
    {
        static string inputPath = @"C:\Users\Daniel\Documents\Visual Studio 2010\Projects\Google Code Jam\2016\ProblemB\ProblemB\input\";
        static string outputPath = @"C:\Users\Daniel\Documents\Visual Studio 2010\Projects\Google Code Jam\2016\ProblemB\ProblemB\output\";

        static string testing = "test.txt";
        static string small = "B-small-attempt1.in";
        static string large = "B-large.in";
        static string filename = small;
        static string outputname = "resultB.out";

        public static void SolveProblem()
        {
            string filePathInput = inputPath + filename;
            string filePathOutput = outputPath + outputname;
            string result = "";
            string[] data = File.ReadAllLines(filePathInput);
            int casesNo = Convert.ToInt32(data[0]);
            
            for (int i = 1; i <= casesNo; i++)
            {
                int[] cakes = TheSolver.ToIntArray(data[i]);
                result += "Case #" + i.ToString() + ": " + TheSolver.Solve(cakes, cakes.Length - 1).ToString() + "\n";
            }
            File.WriteAllText(filePathOutput, result);
            
        }
    }
    public static class TheSolver
    {
        public static int[] ToIntArray(string cakes)
        {
            int[] newCakes = new int[cakes.Length];
            int i = 0;
            foreach (char cake in cakes)
            {
                newCakes[i] = Convert.ToInt32(cake.ToString()+"1");
                i++;
            }
            return newCakes;
        }
        private static int[] FlipCakes(int[] cakes, int index)
        {
            if (index == 0)
            {
                cakes[index] = cakes[index]*-1;
                return cakes;
            }
            
            int loopSz = (index+1) / 2;
            for (int i = 0; i < loopSz; i++)
            {
                int j = index - i;
                int hd = cakes[j];
                cakes[j] = cakes[i]*-1;
                cakes[i] = hd * -1;
            }

            if ((index % 2) == 0)
            {
                int k = index/2;
                cakes[k] = cakes[k] * -1;
            }

            return cakes;
        }
        private static bool IsCakeSet(int[] cakes)
        {
            return cakes.Sum() == cakes.Length;
        }
        public static int Solve(int[] cakes, int endIndex)
        {
            int ans = 0;

            if (IsCakeSet(cakes))
            {
                return ans;
            }
            else if (endIndex == 0)
            {
                ans = 1;
                return ans;
            }
            int flip = 0;
            if (cakes[endIndex] == 1)
            {
                ans = Solve(cakes, endIndex - 1);
            }
            else
            {
                
                if (cakes[0] == -1)
                {
                    cakes = FlipCakes(cakes, endIndex);
                    flip = 1;
                }
                else
                {
                    int lastPos = Array.IndexOf(cakes, -1) - 1;
                    cakes = FlipCakes(cakes, lastPos);
                    cakes = FlipCakes(cakes, endIndex);
                    flip = 2;
                }
                ans = flip + Solve(cakes, endIndex - 1);
            }
            return ans;
        }

        
    }
}
