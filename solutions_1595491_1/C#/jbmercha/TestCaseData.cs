using System.Collections.Generic;
using System.IO;

namespace CodeJam
{
    public abstract class TestCaseDataRequired
    {
        public long CaseNumber;
        public string Results;
    }
    public class TestCaseData : TestCaseDataRequired
    {
        public ulong N_NumberOfGooglers;
        public ulong S_NumberOfSuprises;
        public ulong P_BestResult;
        public List<ulong> T_PointsOfGooglers = new List<ulong>();


        public static TestCaseData Read(StreamReader inputFile)
        {
            var results = new TestCaseData();

            string testLine = inputFile.ReadLine();

            var tokens = testLine.Split(' ');
            results.N_NumberOfGooglers = ulong.Parse(tokens[0]);
            results.S_NumberOfSuprises = ulong.Parse(tokens[1]);
            results.P_BestResult = ulong.Parse(tokens[2]);
            for (ulong i = 0; i < results.N_NumberOfGooglers; i++)
            {
                results.T_PointsOfGooglers.Add(ulong.Parse(tokens[i + 3]));
            }

            return results;
        }

    }
}