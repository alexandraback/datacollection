using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GoogleCodeJam
{
    public interface ITestCase
    {
        void Solve();
    }

    public class CodeJamProblem<T> : ICodeJamProblem
        where T:class, ITestCase, new()
    {
        public CodeJamProblem()
        {
            TestCases = new List<T>();
        }

        protected int NumCases { get; set; }
        protected List<T> TestCases { get; set; }

        protected virtual void DoBeforeSolve()
        {
        }

        protected virtual void DoAfterSolve()
        {
        }

        public virtual void Solve()
        {
            DoBeforeSolve();
            foreach (var tcase in TestCases)
            {
                tcase.Solve();
            }
            DoAfterSolve();
        }

        protected char[] _delimiterChars = { ' ', ',', '.', ':', '\t' };
        protected char[] _delimiterLines = { '\n' };

        protected virtual void ParseCase(T currentCase, int currentCaseNum, ref int currentLine, string[] lines)
        {
        }

        public virtual void ParseInput(string text)
        {
            string[] lines = text.Split(_delimiterLines);
            NumCases = int.Parse(lines[0]);
            int currentLine = 1;
            for (int i = 0; i < NumCases; i++)
            {
                var tcase = new T();
                ParseCase(tcase, i, ref currentLine, lines);                
                TestCases.Add(tcase);
            }
        }

        protected virtual StringBuilder OutputForEachCase(T testCase, StringBuilder currentString)
        {
            return currentString;
        }

        public virtual string OutputToString()
        {
            StringBuilder output = new StringBuilder();
            for (int i = 0; i < NumCases; i++)
            {
                output.Append("Case #")
                    .Append(i + 1)
                    .Append(": ");
                OutputForEachCase(TestCases[i], output);
                output.AppendLine();

            }
            return output.ToString();
        }

        public string DoProblem(string input)
        {
            ParseInput(input);
            Solve();
            return OutputToString();
        }
    }

    public interface ICodeJamProblem
    {
        string DoProblem(string input);
    }

}
