using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;

namespace GoogleCodeJam
{
    /// <summary>
    /// CodeJamProblem contains a collection of TestCases which are created by parsing the input file.
    /// The Solve method is called for each Test Case, then The output file is generated.
    /// </summary>
    public class Round1CA : CodeJamProblem<Round1CATestCase>
    {
        protected override void ParseCase(Round1CATestCase currentCase, int currentCaseNum, ref int currentLine, string[] lines)
        {
            var field = lines[currentLine].Split(_delimiterChars);
            currentCase.Name = field[0];
            currentCase.N = int.Parse(field[1]);
            currentLine++;
        }
        protected override StringBuilder OutputForEachCase(Round1CATestCase testCase, StringBuilder currentString)
        {
            currentString.Append(testCase.NValue);
            return currentString;
        }
    }

    public class Round1CATestCase : ITestCase
    {
        public string Name { get; set; }
        public int N { get; set; }
        public long NValue { get; set; }

        public Round1CATestCase()
        {
        }

        static Round1CATestCase()
        {
        }

        private int? LastStart { get; set; }

        private void AddSubstring(int start, int end)
        {
            var toEnd = Name.Length - end;
            var toBegin = LastStart == null ? start + 1 : (end - start >= N) ? 1 : start - LastStart.Value;
            if (toBegin > 0)
                NValue += toEnd * toBegin;
            LastStart = end - N + 1;
        }

        public void Solve()
        {
            int start = 0;
            var cName = Name.ToLower().ToCharArray();
            HashSet<char> Vowels = new HashSet<char>{'a','e','i','o','u'};
            for (int i = 0; i < cName.Length; i++)
            {
                if (i - start >= N)
                    AddSubstring(start, i-1);
                if (Vowels.Contains(cName[i]))
                    start = i + 1;
            }
            if (cName.Length - start >= N)
                AddSubstring(start, cName.Length - 1);
        }
    }
}
