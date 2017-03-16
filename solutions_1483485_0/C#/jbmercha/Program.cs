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
            const string inputFileName = "A-small-attempt0.in";
            //const string inputFileName = "D-large.in";
            //const string inputFileName = "Sample.txt";
            const string outputFileName = "Answer.txt";
            var inputFile = File.OpenText(inputFileName);


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

            var lookup = new Dictionary<char, char>
                             {
                                 {' ', ' '},
                                 {'y', 'a'},
                                {'n', 'b'},
                                {'f', 'c'},
                                {'i', 'd'},
                                {'c', 'e'},
                                {'w', 'f'},
                                {'l', 'g'},
                                {'b', 'h'},
                                {'k', 'i'},
                                {'u', 'j'},
                                {'o', 'k'},
                                {'m', 'l'},
                                {'x', 'm'},
                                {'s', 'n'},
                                {'e', 'o'},
                                {'v', 'p'},
                                {'p', 'r'},
                                {'d', 's'},
                                {'r', 't'},
                                {'j', 'u'},
                                {'g', 'v'},
                                {'t', 'w'},
                                {'h', 'x'},
                                {'a', 'y'},
                                {'q', 'z'},
                                {'z', 'q'},
                             };


            var sb = new StringBuilder();
            foreach (var c in data.Text)
            {
                sb.Append(lookup[c]);
            }
            data.Results = String.Format("Case #{0}: {1}", data.CaseNumber, sb);
            if (Interlocked.Decrement(ref _tasksToComplete) == 0)
                _doneAll.Set();
        }
    }
}
