using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QualificationRound
{
    public abstract class Problem
    {
        private string[] inputLines;
        private string outputFilePath;
        private int currentLine;
        private int currentCaseNumber;

        public void Solve(string inputFilePath)
        {
            this.Initialise(inputFilePath);
            int numberOfTestCases = this.ReadNextLineAsInt32();
            for (int i = 1; i <= numberOfTestCases; i++)
            {
                this.currentCaseNumber = i;
                string output = this.SolveCase();
                if (!string.IsNullOrWhiteSpace(output))
                {
                    this.WriteCaseOutput(i, output);
                }
            }
        }

        protected abstract string SolveCase();

        protected virtual void Initialise(string inputFilePath)
        {
            this.inputLines = File.ReadAllLines(inputFilePath);
            this.currentLine = -1;
            this.outputFilePath = inputFilePath.Replace(".in", ".out");
            File.WriteAllText(this.outputFilePath, string.Empty);
        }

        protected string ReadNextLineAsString()
        {
            this.currentLine++;
            return this.inputLines[this.currentLine];
        }

        protected string[] ReadNextLineAsStringArray()
        {
            this.currentLine++;
            return this.inputLines[this.currentLine].Split(new char[] { ' ' }).ToArray();
        }

        protected int ReadNextLineAsInt32()
        {
            this.currentLine++;
            return Convert.ToInt32(this.inputLines[this.currentLine]);
        }

        protected int[] ReadNextLineAsInt32Array()
        {
            this.currentLine++;
            return this.inputLines[this.currentLine]
                .Split(new char[] { ' ' })
                .Select(s => Convert.ToInt32(s))
                .ToArray();
        }

        protected double[] ReadNextLineAsDoubleArray()
        {
            this.currentLine++;
            return this.inputLines[this.currentLine]
                .Split(new char[] { ' ' })
                .Select(s => Convert.ToDouble(s))
                .ToArray();
        }

        protected long ReadNextLineAsInt64()
        {
            this.currentLine++;
            return Convert.ToInt64(this.inputLines[this.currentLine]);
        }

        protected long[] ReadNextLineAsInt64Array()
        {
            this.currentLine++;
            return this.inputLines[this.currentLine]
                .Split(new char[] { ' ' })
                .Select(s => Convert.ToInt64(s))
                .ToArray();
        }

        protected void WriteCaseOutput(int caseNumber, string output)
        {
            this.WriteLineToFile(string.Format("Case #{0}: {1}", caseNumber, output));
        }

        protected void WriteLineToFile(string line)
        {
            Console.WriteLine(line);
            using (StreamWriter file = 
                new StreamWriter(this.outputFilePath, true))
            {
                file.WriteLine(line);
            }
        }
    }
}
