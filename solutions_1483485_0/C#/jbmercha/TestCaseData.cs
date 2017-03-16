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
        public string Text;

        public static TestCaseData Read(StreamReader inputFile)
        {
            var results = new TestCaseData();

            string testLine = inputFile.ReadLine();
            results.Text = testLine;

            return results;
        }

    }
}