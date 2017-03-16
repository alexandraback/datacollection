using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.IO;

namespace ProblemC
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
        static string inputPath = @"C:\Users\Daniel\Documents\Visual Studio 2010\Projects\Google Code Jam\2016\ProblemC\ProblemC\input\";
        static string outputPath = @"C:\Users\Daniel\Documents\Visual Studio 2010\Projects\Google Code Jam\2016\ProblemC\ProblemC\output\";

        static string testing = "test.txt";
        static string small = "C-small-attempt0.in";
        static string large = "C-large.in";
        static string filename = large;
        static string outputname = "resultC.out";

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
                int N = Convert.ToInt32(sData[0]);
                int J = Convert.ToInt32(sData[1]);
                result += "Case #" + i.ToString() + ":\n" + TheSolver.Solve(N, J);
            }
            File.WriteAllText(filePathOutput, result);
        }
    }
    public static class TheSolver
    {
        private static int CheckDivisibility(string num)
        {
            int evenSum = 0;
            int oddSum = 0;
            int totalSum = 0;
            int result = 0;
            int ct = 1;
            foreach (char ach in num)
            {
                int bit = Convert.ToInt32(ach.ToString());
                totalSum += bit;
                if ((ct % 2) == 0)
                {
                    evenSum += bit;
                }
                else
                {
                    oddSum += bit;
                }
                ct++;
            }
            if ((totalSum % 3) == 0)
            {
                return 3;
            }
            else if ((Math.Abs(oddSum - evenSum) % 11) == 0)
            {
                return 11;
            }
            else
            {
                return 7;
            }

        }
        private static long NonTrivialFactor(long num)
        {
            if (num <= 3) return -1;
            if ((num % 2) == 0) return 2;
            if ((num % 3) == 0) return 3;

            long i = 5;
            int w = 2;
            long minNum = Convert.ToInt64(Math.Ceiling(Math.Sqrt((double)num)));
            while (i <= minNum)
            {
                if (num % i == 0)
                {
                    return i;
                }
                i += w;
                w = 6 - w;
            }
            return -1;
        }

        public static string Solve(int N, int J)
        {
            string ans = "";
            string factors = " 3 2 5 2 7 2 3 2";
            int zeroSz = 2;
            int strLen = N - 2;
            int curPos = 1;
            string temp = Template(N);
            string move = "0";
            string zeros = Template(zeroSz, move);
            int mn = 1;
            List<string> coinList = new List<string>();
            int step = 0;

            while (coinList.Count < J)
            {
                string right = temp.Substring(curPos + zeroSz);
                string jamCoin = temp.Substring(0, curPos) + zeros + temp.Substring(curPos + zeroSz);
                if (!coinList.Contains(jamCoin))
                {
                    coinList.Add(jamCoin);
                    ans += jamCoin + factors + " " + CheckDivisibility(jamCoin) + "\n";
                }
                if (right.Length == 1)
                {
                    if (zeroSz >= N - 2 - step)
                    {
                        if (mn == 1)
                        {
                            mn++;
                            move = "1";
                            temp = "1" + Template(N - 2, "0") + "1";
                            zeroSz = 0;
                        }
                        else if (mn == 2)
                        {
                            mn++;
                            move = "0";
                            temp = "100" + Template(N - 4, "1") + "1";
                            step = 2;
                            zeroSz = 0;
                        }
                    }
                    curPos = 1 + step;
                    zeroSz += 2;
                    zeros = Template(zeroSz, move);
                }
                else
                {
                    curPos++;
                }
            }
            return ans;
        }
        private static string Template(int N, string s = "1")
        {
            string res = "";
            for (int i = 0; i < N; i++)
            {
                res += s;
            }
            return res;
        }
        
    }
}

