using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace JamOne
{
    class TestCaseInput
    {
        public string Data { get; }

        public string S1{ get; set; }
        public string S2 { get; set; }

        public TestCaseInput(string s)
        {
            Data = s;

            Parse();
        }

        private void Parse()
        {
            string[] tokens = Data.Split(' ');
            S1 = tokens[0];
            S2 = tokens[1];
        }
    }

    class Program
    {
        static void Solve(int pos, string s1, string s2, ref long bestScoreDiff, ref long min_score1, ref long min_score2)
        {
            if (pos == s1.Length)
            {
                long n1 = Int64.Parse(s1);
                long n2 = Int64.Parse(s2);

                long scoreDiff = Math.Abs(n1 - n2);

                if (scoreDiff < bestScoreDiff)
                {
                    bestScoreDiff = scoreDiff;
                    min_score1 = n1;
                    min_score2 = n2;
                }
                else if (scoreDiff == bestScoreDiff && (n1 < min_score1 || (n1 == min_score1 && n2 < min_score2)))
                {
                    min_score1 = n1;
                    min_score2 = n2;
                }
            }
            else
            {
                if (s1[pos] == '?' && s2[pos] == '?')
                {
                    Solve(pos + 1, SetInPos(s1, pos, '0'), SetInPos(s2, pos, '0'), ref bestScoreDiff, ref min_score1, ref  min_score2);
                    Solve(pos + 1, SetInPos(s1, pos, '0'), SetInPos(s2, pos, '1'), ref bestScoreDiff, ref min_score1, ref  min_score2);
                    Solve(pos + 1, SetInPos(s1, pos, '1'), SetInPos(s2, pos, '0'), ref bestScoreDiff, ref min_score1, ref  min_score2);
                    Solve(pos + 1, SetInPos(s1, pos, '0'), SetInPos(s2, pos, '9'), ref bestScoreDiff, ref min_score1, ref  min_score2);
                    Solve(pos + 1, SetInPos(s1, pos, '9'), SetInPos(s2, pos, '0'), ref bestScoreDiff, ref min_score1, ref  min_score2);
                }
                else if (s1[pos] == '?')
                {
                    Solve(pos + 1, SetInPos(s1, pos, s2[pos] == '0' ? '9' : (char)(s2[pos] - 1)), s2, ref bestScoreDiff, ref min_score1, ref min_score2);
                    Solve(pos + 1, SetInPos(s1, pos, s2[pos] == '9' ? '0' : (char)(s2[pos] + 1)), s2, ref bestScoreDiff, ref min_score1, ref min_score2);
                    Solve(pos + 1, SetInPos(s1, pos, s2[pos]), s2, ref bestScoreDiff, ref min_score1, ref min_score2);

                    Solve(pos + 1, SetInPos(s1, pos, '0'), s2, ref bestScoreDiff, ref min_score1, ref min_score2);
                    Solve(pos + 1, SetInPos(s1, pos, '9'), s2, ref bestScoreDiff, ref min_score1, ref min_score2);
                }
                else if (s2[pos] == '?')
                {
                    Solve(pos + 1, s1, SetInPos(s2, pos, s1[pos] == '0' ? '9' : (char)(s1[pos] - 1)), ref bestScoreDiff, ref min_score1, ref min_score2);
                    Solve(pos + 1, s1, SetInPos(s2, pos, s1[pos] == '9' ? '0' : (char)(s1[pos] + 1)), ref bestScoreDiff, ref min_score1, ref min_score2);
                    Solve(pos + 1, s1, SetInPos(s2, pos, s1[pos]), ref bestScoreDiff, ref min_score1, ref min_score2);

                    Solve(pos + 1, s1, SetInPos(s2, pos, '0'), ref bestScoreDiff, ref min_score1, ref min_score2);
                    Solve(pos + 1, s1, SetInPos(s2, pos, '9'), ref bestScoreDiff, ref min_score1, ref min_score2);
                }
                else
                {
                    Solve(pos+1, s1, s2, ref bestScoreDiff, ref min_score1, ref  min_score2);
                }
            }
        }

        public static string SetInPos(string s, int pos, char c)
        {
            StringBuilder res = new StringBuilder(s);
            res[pos] = c;
            return res.ToString();
        }

        public static void WriteOutput(string fileName, List<TestCaseInput> testCases)
        {
            List<string> output = new List<string>();

            int i = 1;
            foreach (var testCaseInput in testCases)
            {
                StringBuilder line = new StringBuilder();
                line.Append($"Case #{i}: ");

                StringBuilder value = new StringBuilder();

                long min_score1 = Int64.MaxValue;
                long min_score2 = Int64.MaxValue;
                long bestScoreDiff = Int64.MaxValue;

                Solve(0, testCaseInput.S1, testCaseInput.S2, ref bestScoreDiff, ref min_score1, ref min_score2);

                value.Append(min_score1.ToString("D" + testCaseInput.S1.Length));
                value.Append(" ");
                value.Append(min_score2.ToString("D" + testCaseInput.S1.Length));

                    //
                line.Append(value);

                i++;
                output.Add(line.ToString());
            }

            File.WriteAllLines(fileName, output);
        }

        public static List<TestCaseInput> ReadInput(string fileName)
        {
            var inputLines = File.ReadAllLines(fileName).Skip(1);

            List<TestCaseInput> testCaseInputs = new List<TestCaseInput>();

            foreach (var line in inputLines)
                testCaseInputs.Add(new TestCaseInput(line));

            return testCaseInputs;
        }

        static void Main(string[] args)
        {
            var testCases = ReadInput(args[0]);
            WriteOutput(args[1], testCases);
        }
    }
}
