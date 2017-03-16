using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Fractiles
{
    struct TestCaseInput
    {
        public int K { get; }
        public int C { get; }
        public int S { get; }

        public TestCaseInput(int k, int c, int s)
        {
            K = k;
            C = c;
            S = s;
        }
    }

    class Program
    {
        public static long IntPow(long x, int pow)
        {
            long ret = 1;
            while (pow != 0)
            {
                if ((pow & 1) == 1)
                    ret *= x;
                x *= x;
                pow >>= 1;
            }
            return ret;
        }

        public static void WriteOutput(string fileName, List<TestCaseInput> testCases)
        {
            List<string> output = new List<string>();

            int i = 1;
            foreach (var testCaseInput in testCases)
            {
                StringBuilder line = new StringBuilder();
                line.Append($"Case #{i}:");

                for (int j = 0; j < testCaseInput.K; j++)
                {
                    line.Append(" ");

                    long positionToCheck = IntPow(testCaseInput.K, testCaseInput.C - 1) * j  + 1;
                    line.Append(positionToCheck);
                }
                i++;

                Console.WriteLine(line);
                output.Add(line.ToString());
            }

            File.WriteAllLines(fileName, output);
        }

        public static List<TestCaseInput> ReadInput(string fileName)
        {
            var inputLines = File.ReadAllLines(fileName).Skip(1);
            
            List<TestCaseInput> testCaseInputs = new List<TestCaseInput>();

            foreach (var line in inputLines)
            {
                var tokens = line.Split(' ');
                testCaseInputs.Add(new TestCaseInput(Int32.Parse(tokens[0]), Int32.Parse(tokens[1]), Int32.Parse(tokens[2])));
            }

            return testCaseInputs;
        }

        static void Main(string[] args)
        {
            var testCases = ReadInput(args[0]);
            WriteOutput(args[1], testCases);
        }
    }
}
