using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;

namespace CodeJam
{
    class Program
    {
        private static ManualResetEvent _doneAll = new ManualResetEvent(false);
        private static TestCaseData[] _testCaseData;
        private static long _tasksToComplete;
        static void Main(string[] args)
        {
            //const string inputFileName = "C-small-attempt0.in";
            const string inputFileName = "C-large.in";
            //const string inputFileName = "Sample.txt";
            const string outputFileName = "Answer.txt";
            var inputFile = File.OpenText(inputFileName);

            GenerateLookup();

            long numberOfTestCases = Int64.Parse(inputFile.ReadLine());
            _tasksToComplete = numberOfTestCases;

            _testCaseData = new TestCaseData[numberOfTestCases];
            for (long testCaseIndex = 0; testCaseIndex < numberOfTestCases; testCaseIndex++)
            {
                _testCaseData[testCaseIndex] = TestCaseData.Read(inputFile);
                _testCaseData[testCaseIndex].CaseNumber = testCaseIndex + 1;
                ThreadPool.QueueUserWorkItem(ProcessTestCase, testCaseIndex);    
            }
            inputFile.Close();
            _doneAll.WaitOne();

            var outputFile = File.CreateText(outputFileName);
            for (long testCaseIndex = 0; testCaseIndex < numberOfTestCases; testCaseIndex++)
            {
                outputFile.WriteLine(_testCaseData[testCaseIndex].Results);
            }
            outputFile.Close();
        }

        

        private static void ProcessTestCase(Object threadContext)
        {
            var testCaseIndex = (long)threadContext;
            var data = _testCaseData[testCaseIndex];




            var result = recycled.Count(x => x.Key >= data.A && x.Value <= data.B);



            data.Results = String.Format("Case #{0}: {1}", data.CaseNumber, result);
            if (Interlocked.Decrement(ref _tasksToComplete) == 0)
                _doneAll.Set();
        }

        static List<KeyValuePair<int, int>> recycled = new List<KeyValuePair<int, int>>();
        static void GenerateLookup()
        {
            var start = 1;
            var end = 2000000;

            for (int i = start; i < end - 1; i++)
            {
                var iStr = i.ToString();

                var cArray = iStr.ToCharArray();
                if (cArray.All(c => c == iStr[0]))
                    continue;

                for (int j = 0; j < iStr.Length; j++)
                {
                    var cHolder = cArray[0];
                    for (int z = 1; z < iStr.Length; z++)
                    {
                        cArray[z - 1] = cArray[z];
                    }
                    cArray[iStr.Length - 1] = cHolder;
                    var val = int.Parse(new string(cArray, 0, iStr.Length));
                    if (val > i)
                        recycled.Add(new KeyValuePair<int, int>(i, val));
                }
            }
            recycled = recycled.Distinct().ToList();
        }

        
    }
}
