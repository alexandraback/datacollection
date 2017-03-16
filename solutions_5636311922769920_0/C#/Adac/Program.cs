using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ProblemD
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
        static string inputPath = @"C:\Users\Daniel\Documents\Visual Studio 2010\Projects\Google Code Jam\2016\ProblemD\ProblemD\input\";
        static string outputPath = @"C:\Users\Daniel\Documents\Visual Studio 2010\Projects\Google Code Jam\2016\ProblemD\ProblemD\output\";

        static string testing = "test.txt";
        static string small = "D-small-attempt0.in";
        static string large = "D-large.in";
        static string filename = small;
        static string outputname = "resultD.txt";

        public static void SolveProblem()
        {
            string filePathInput = inputPath + filename;
            string filePathOutput = outputPath + outputname;
            string result = "";
            string[] data = File.ReadAllLines(filePathInput);
            int casesNo = Convert.ToInt32(data[0]);
            for (int i = 1; i <= casesNo; i++)
            {
                string[] sData = data[i].Split(" "[0]);
                int K = Convert.ToInt32(sData[0]);
                int C = Convert.ToInt32(sData[1]);
                int S = Convert.ToInt32(sData[2]);
                result += "Case #" + i.ToString() + ": " + TheSolver.Solve(K,C,S)+"\n";
            }
            File.WriteAllText(filePathOutput, result);

        }
    }
    public static class TheSolver
    {
        public static string Solve(int K, int C, int S)
        {
            string ans = "";
            for (int i = 1; i <= S; i++)
            {
                ans += i.ToString() + " ";
            }
            return ans.Trim();
        }
    }
}
