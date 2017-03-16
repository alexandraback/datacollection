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

        public int Smax;
        public int[] Shynessses;

        /// <summary>
        /// Reads a test case and initializes the class' variables
        /// </summary>
        /// <param name="input"></param>
        /// <returns></returns>
        public CodeJamProblem BuildProblem(CodeJamInput input)
        {
            string[] numbers = input.NextLine().Split(' ');

            Smax = int.Parse(numbers[0]);
            
            Shynessses = new int[Smax+1];

            for (int i=0; i<Shynessses.Length; i++){
                Shynessses[i] = int.Parse(numbers[1][i].ToString());
            }

            return this;
        }

        /// <summary>
        /// Solves a test case from the variables
        /// </summary>
        /// <returns></returns>
        public string GetSolution()
        {
            int required = 0;
            int present = 0;
            int result = 0;

            for (int i = 0; i < Shynessses.Length; i++)
            {
                if (required > present)
                {
                    result += required - present;
                    present += required - present;
                }

                present += Shynessses[i];
                required++;
            }

            return "Case #" + Number + ": " + result.ToString();
        }
    }
}
