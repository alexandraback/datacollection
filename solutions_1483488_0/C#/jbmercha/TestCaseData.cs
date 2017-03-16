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
        public int A;
        public int B;


        public static TestCaseData Read(StreamReader inputFile)
        {
            var results = new TestCaseData();

            string testLine = inputFile.ReadLine();

            var tokens = testLine.Split(' ');
            results.A = int.Parse(tokens[0]);
            results.B = int.Parse(tokens[1]);

            return results;
        }

    }
}