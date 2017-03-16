using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System;
using System.Numerics;

namespace Problem_A {
    class Program {
        static void Main(string[] args) {
            string fileName = args != null && args.Length > 0 ? args[0] : "Input.txt";
            //string fileName = args != null && args.Length > 0 ? args[0] : "A-large-practice.in";
            
            string[] inputStrings = File.ReadAllLines(fileName);

            int numberOfTestCases = Convert.ToInt32(inputStrings[0]);
            List<TestCase> testCases = new List<TestCase>();
            int position = 1;
            for (int i = 0; i < numberOfTestCases; i++) {
                position = ReadTestCase(inputStrings, testCases, position);
            }
            string[] results = new string[numberOfTestCases];
            for (int i = 0; i < numberOfTestCases; i++) {
                results[i] = EvalTestCase(testCases[i]);
            }

            WriteOutput(results);
        }


        private static void WriteOutput(string[] results) {
            List<string> output = new List<string>();
            for (int i = 0; i < results.Length; i++) {
                output.Add(string.Format("Case #{0}: {1}", i + 1, results[i]));
            }
            File.WriteAllLines("Output.txt", output.ToArray());
        }

        static string EvalTestCase(TestCase testCase) {
            int result = 0;
            for (int i = 0; i < testCase.Name.Length; i++) {
                int consonants = 0;
                for (int j = i; j < testCase.Name.Length; j++) {
                    if (IsConsonant(testCase.Name[j])) {
                        consonants++;
                        if (consonants >= testCase.N)
                            result++;
                    } else
                        if (consonants < testCase.N)
                            consonants = 0;
                        else
                            result++;
                }

            }
            return result.ToString();
        }
        static bool IsConsonant(char ch) { 
            return ch != 'a' && ch != 'e'  && ch != 'i' && ch != 'o' && ch != 'u';
        }
        private static int ReadTestCase(string[] inputStrings, List<TestCase> testCases, int position) {
            string[] vals = inputStrings[position].Split(new[] { ' ' });
            string name = vals[0];
            int n = Convert.ToInt32(vals[1]);
            position++;
            TestCase testCase = new TestCase() { Name = name, N = n };
            testCases.Add(testCase);

            return position;
        }
        class TestCase {
            public string Name { get; set; }
            public double N { get; set; }
        }

    }
}
