using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    public abstract class Problem
    {
        protected string[] _InputLines;
        protected string _OutputFilePath;
        protected int _CurrentLine;
        protected int _CurrentCaseNumber;

        protected abstract string SolveCase();

        public void Solve(string inputFilePath)
        {
            Initialise(inputFilePath);
            int numberOfTestCases = ReadNextLineAsInt32();
            for (int i = 1; i <= numberOfTestCases; i++)
            {
                _CurrentCaseNumber = i;
                string output = SolveCase();
                if (!String.IsNullOrWhiteSpace(output))
                {
                    WriteCaseOutput(i, output);
                }
            }
        }

        protected void Initialise(string inputFilePath)
        {
            _InputLines = System.IO.File.ReadAllLines(inputFilePath);
            _CurrentLine = -1;
            _OutputFilePath = inputFilePath.Replace(".in", ".out");
            System.IO.File.WriteAllText(_OutputFilePath, String.Empty);
        }

        protected string ReadNextLineAsString()
        {
            _CurrentLine++;
            return _InputLines[_CurrentLine];
        }

        protected string[] ReadNextLineAsStringArray()
        {
            _CurrentLine++;
            return _InputLines[_CurrentLine].Split(new char[] { ' ' }).ToArray();
        }

        protected int ReadNextLineAsInt32()
        {
            _CurrentLine++;
            return Convert.ToInt32(_InputLines[_CurrentLine]);
        }

        protected int[] ReadNextLineAsInt32Array()
        {
            _CurrentLine++;
            return _InputLines[_CurrentLine].Split(new char[] { ' ' }).Select(s => Convert.ToInt32(s)).ToArray();
        }

        protected long ReadNextLineAsInt64()
        {
            _CurrentLine++;
            return Convert.ToInt64(_InputLines[_CurrentLine]);
        }

        protected long[] ReadNextLineAsInt64Array()
        {
            _CurrentLine++;
            return _InputLines[_CurrentLine].Split(new char[] { ' ' }).Select(s => Convert.ToInt64(s)).ToArray();
        }

        protected void WriteCaseOutput(int caseNumber, string output)
        {
            WriteLineToFile(String.Format("Case #{0}: {1}", caseNumber, output));
        }

        protected void WriteLineToFile(string line)
        {
            Console.WriteLine(line);
            using (System.IO.StreamWriter file = new System.IO.StreamWriter(_OutputFilePath, true))
            {
                file.WriteLine(line);
            }
        }
    }
}
