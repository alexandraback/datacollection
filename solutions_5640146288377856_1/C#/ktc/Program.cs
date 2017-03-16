using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Round1c._1
{
    class Program
    {
        private const string inputFileName = "A-large.in";
        private const string outputFileName = "A-large.out";
        
        private static void Main(string[] args)
        {
            int numberOfCases;
            int[,] testCase;
            int[] solution;
            //reading test cases

            using (var inputFile = new FileStream(inputFileName, FileMode.Open))
            {

                using (var reader = new StreamReader(inputFile))
                {

                    numberOfCases = Int32.Parse(reader.ReadLine());
                    testCase = new int[numberOfCases, 3];
                    for (int i = 0; i < numberOfCases; i++)
                    {
                        var s =
                            reader.ReadLine()
                                .Split(new[] {' '}, StringSplitOptions.RemoveEmptyEntries)
                                .Select(Int32.Parse)
                                .ToArray();
                        testCase[i, 0] = s[0];
                        testCase[i, 1] = s[1];
                        testCase[i, 2] = s[2];
                    }
                    solution = new int[numberOfCases];

                }
            }
            //problem solving
            for (int i = 0; i <numberOfCases; i++)
            {
                int sol = 0;
                sol += (testCase[i, 1]/testCase[i, 2])*testCase[i,0];
                sol += testCase[i, 1]%testCase[i, 2] == 0 ? 0 : 1;
                sol += testCase[i, 2] - 1;
                solution[i] = sol;
            }
            //writing solution
            using (var outputFile = new FileStream(outputFileName, FileMode.Create))
            {
                using (var writer = new StreamWriter(outputFile))
                {
                    for (int i = 0; i < numberOfCases; i++)
                    {
                        
                        writer.WriteLine("Case #{0}: {1}", i + 1, solution[i]/*solution of test case*/);
                    }
                }
            }
        }
    }
}
