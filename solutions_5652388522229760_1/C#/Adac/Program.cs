using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;

namespace ProblemA
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
        static string inputPath = @"C:\Users\Daniel\Documents\Visual Studio 2010\Projects\Google Code Jam\2016\ProblemA\ProblemA\input\";
        static string outputPath = @"C:\Users\Daniel\Documents\Visual Studio 2010\Projects\Google Code Jam\2016\ProblemA\ProblemA\output\";

        static string testing = "test.txt";
        static string small = "A-small-attempt0.in";
        static string large = "A-large.in";
        static string filename = large;
        static string outputname = "resultA.txt";

        public static void SolveProblem()
        {
            string filePathInput = inputPath + filename;
            string filePathOutput = outputPath + outputname;
            string result = "";
            string[] data = File.ReadAllLines(filePathInput);
            int casesNo = Convert.ToInt32(data[0]);
            for (int i = 1; i <= casesNo; i++)
            {
                int N = Convert.ToInt32(data[i]);
                result += "Case #" + i.ToString() + ": " + TheSolver.Solve(N)+"\n";
            }
            File.WriteAllText(filePathOutput, result);
            
        }
    }
    public static class TheSolver
    {
        public static string Solve(int N)
        {
            if (N == 0)
            {
                return "INSOMNIA";
            }
            //Console.WriteLine(N.ToString());
            //Console.Read();
            int ans = N;
            List<char> numList = "0123456789".ToCharArray().ToList();
            bool keepOn = true;
            long lastNum = N;
            int ct = 1;
            int maxIter = 10000000;
            while (keepOn && ct < maxIter)
            {
                lastNum = ct * N;
                char[] charNum = lastNum.ToString().ToCharArray();
                List<char> newList = new List<char>();
                foreach (char ach in numList)
                {
                    if (!charNum.Contains(ach))
                    {
                        newList.Add(ach);
                    }
                }
                if (newList.Count == 0)
                {
                    keepOn = false;
                    return lastNum.ToString();
                }
                numList = newList;
                
                ct++;
            }
            return "INSOMNIA";
        }
    }
}
