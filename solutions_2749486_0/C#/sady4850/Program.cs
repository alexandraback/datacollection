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
            //string fileName = args != null && args.Length > 0 ? args[0] : "A-large.in";
            
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
            string result = string.Empty;
            int currentX = 0;
            int currentY = 0;
            int step = 1;
            while(true) {
                if(currentX == testCase.X && currentY == testCase.Y)
                    return result;
                if(currentX != testCase.X) {
                    if (currentX < testCase.X && currentX + step <= testCase.X) {
                        currentX += step;
                        result += "E";
                    } else {
                        currentX -= step;
                        result += "W";
                    }
                } else {
                    if (currentY < testCase.Y && currentY + step <= testCase.Y) {
                        currentY += step;
                        result += "N";
                    } else {
                        currentY -= step;
                        result += "S";
                    }
                }
                step++;
            }
        }

        private static int ReadTestCase(string[] inputStrings, List<TestCase> testCases, int position) {
            string[] vals = inputStrings[position].Split(new[] { ' ' });
            int x = Convert.ToInt32(vals[0]);
            int y = Convert.ToInt32(vals[1]);
            position++;
            TestCase testCase = new TestCase() { X = x, Y = y };
            testCases.Add(testCase);

            return position;
        }
        class TestCase {
            public int X { get; set; }
            public int Y { get; set; }
        }

    }
}
