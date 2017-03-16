using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;
using System.Threading;
using GoogleCodeJamPractice.Library.Algorithms;
using GoogleCodeJamPractice.Library.Math;

namespace GoogleCodeJamPractice
{
    /// <summary>
    /// Reads a tipical Input for Google Code Jam's Problems, started by a line containing T, followed by T
    /// test cases
    /// </summary>
    class CodeJamInput
    {
        StreamReader reader = File.OpenText(@"i:\users\cecilia\documents\visual studio 2010\Projects\GoogleCodeJamPractice\GoogleCodeJamPractice\input.in");

        public CodeJamProblem[] problems;

        public string NextLine()
        {
            return reader.ReadLine();
        }

        public CodeJamInput()
        {
            int T = int.Parse(NextLine());

            problems = new CodeJamProblem[T];

            for (int i = 0; i < T; ++i)
            {
                problems[i] = new CodeJamProblem().BuildProblem(this);
                problems[i].Number = i + 1;
            }
        }
    }

    class Program
    {
        static string outputPath = @"i:\users\cecilia\documents\visual studio 2010\Projects\GoogleCodeJamPractice\GoogleCodeJamPractice\output.out";

        static void Main(string[] args)
        {
            //Reads the input
            CodeJamInput input = new CodeJamInput();
            StringBuilder output = new StringBuilder();

            foreach (CodeJamProblem p in input.problems)
            {
                //Solves each test case
                output.AppendLine(p.GetSolution());
            }

            //Print results to file
            File.WriteAllText(outputPath, output.ToString());
        }
    }

    /// <summary>
    /// Actual class to be implemented during contest, represents a test case
    /// </summary>
    class CodeJamProblem
    {
        public int Number;

        public int L;
        public int X;
        string s;

        /// <summary>
        /// Reads a test case and initializes the class' variables
        /// </summary>
        /// <param name="input"></param>
        /// <returns></returns>
        public CodeJamProblem BuildProblem(CodeJamInput input)
        {
            var ns = input.NextLine().Split(' ');

            L = int.Parse(ns[0]);
            X = int.Parse(ns[1]);

            s = input.NextLine();

            return this;
        }

        /// <summary>
        /// Solves a test case from the variables
        /// </summary>
        /// <returns></returns>
        public string GetSolution()
        {
            if (s.Length * X< 3)
            {
                return "Case #" + Number + ": NO";
            }

            string value = Evaluate(s);
            value = Power(value, X);

            if (value != "-1")
                return "Case #" + Number + ": NO";

            CycleInfo Iinfo = GenerateTargetInfo(s, 0, "i");

            foreach (int i in Iinfo.offsets)
            {
                CycleInfo Jinfo = GenerateTargetInfo(s, i+1, "j");

                foreach (int j in Jinfo.offsets)
                {
                    if (i+j < L * X)
                        return "Case #" + Number + ": YES";
                }
            }

            return "Case #" + Number + ": NO";
        }

        private bool CycHasIjk(string s)
        {
            throw new NotImplementedException();
        }

        private string Power(string value, int X)
        {
            string result = value;
            for (int i = 1; i < X; i++)
            {
                result = Multiply(result, value);
            }

            return result;
        }

        private string Evaluate(string s)
        {
            string current = s[0].ToString();

            for (int i = 1; i < s.Length; i++)
            {
                current = Multiply(current, s[i].ToString());
            }

            return current;
        }

        class CycleInfo
        {
            public int cycSize;
            public List<int> offsets = new List<int>();
            public List<string> cyc = new List<string>();
        }

        private CycleInfo GenerateTargetInfo(string s, int p, string target)
        {
            CycleInfo result = new CycleInfo();

            string sinitial = s[p % s.Length].ToString();
            string current = sinitial;
            result.cyc.Add(current);

            int pos = p % s.Length;
            int cycSize = 0;
            bool first = true;
            while (true){
                if (current == target)
                    result.offsets.Add(cycSize);

                pos++;
                cycSize++;
                if (pos == s.Length)
                    pos = 0;

                if (pos == ((p % s.Length) + 1) % s.Length && current == sinitial && !first)
                    break;

                current = Multiply(current, s[pos].ToString());
                result.cyc.Add(current);

                first = false;
            }

            result.cycSize = cycSize - 1;
            return result;
        }

        Dictionary<string, Dictionary<string, string>> table = new Dictionary<string,Dictionary<string,string>>() {
            {"1", new Dictionary<string, string>() {
                {"1", "1"}, {"i", "i"}, {"j", "j"}, {"k", "k"}
            }},
            {"i", new Dictionary<string, string>() {
                {"1", "i"}, {"i", "-1"}, {"j", "k"}, {"k", "-j"}
            }},
            {"j", new Dictionary<string, string>() {
                {"1", "j"}, {"i", "-k"}, {"j", "-1"}, {"k", "i"}
            }},
            {"k", new Dictionary<string, string>() {
                {"1", "k"}, {"i", "j"}, {"j", "-i"}, {"k", "-1"}
            }}
        };

        private string Multiply(string current, string p)
        {
            bool hadMinus = current.StartsWith("-");
            string toMultiply = current.StartsWith("-") ? current.Substring(1) : current;

            bool hadMinus2 = p.StartsWith("-");
            string toMultiply2 = p.StartsWith("-") ? p.Substring(1) : p;

            string result = table[toMultiply][toMultiply2];

            if (hadMinus != hadMinus2){
                if (result.StartsWith("-")){
                    return result.Substring(1);
                } else {
                    return "-" + result;
                }
            }

            return result;
        }
    }
}
