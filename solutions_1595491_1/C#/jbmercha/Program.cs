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
            //const string inputFileName = "B-small-attempt0.in";
            const string inputFileName = "B-large.in";
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


            decimal result;

            decimal numberWithNoSuprise = 0;
            decimal numberWithSupprise = 0;

            foreach (var points in data.T_PointsOfGooglers)
            {
                if (GetBestScoreWithNoSuprise(points) >= data.P_BestResult)
                    numberWithNoSuprise++;
                else if (GetBestScoreWithSuprise(points) >= data.P_BestResult)
                    numberWithSupprise++;
            }

            result = numberWithNoSuprise + Math.Min(numberWithSupprise, data.S_NumberOfSuprises);



            data.Results = String.Format("Case #{0}: {1}", data.CaseNumber, result);
            if (Interlocked.Decrement(ref _tasksToComplete) == 0)
                _doneAll.Set();
        }


        private static ulong GetBestScoreWithSuprise(ulong total)
        {
            return total == 0 ? 0 : ((total + 1) / 3 + 1);
        }

        private static ulong GetBestScoreWithNoSuprise(ulong total)
        {
            return total == 0 ? 0 : ((total - 1) / 3 + 1);
        }
    }
}
