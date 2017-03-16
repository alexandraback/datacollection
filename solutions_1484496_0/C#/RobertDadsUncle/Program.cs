using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

namespace Round_1B_Problem_B
{
    public class CaseData
    {
        private readonly List<int> m_Integers;


        public CaseData(List<int> integers)
        {
            m_Integers = integers;
        }

        private int SetSum(List<int> set)
        {
            int total = 0;
            foreach(var value in set)
            {
                total += value;
            }
            return total;
        }
        
        public string Solve()
        {
            var allpossiblesets = GetAllPossibleSubSets(m_Integers);

            foreach(var set in allpossiblesets)
            {
                var total = SetSum(set);
                List<int> otherValues = new List<int>(m_Integers);
                foreach(var value in set)
                {
                    otherValues.Remove(value);
                }
                var allothersets = GetAllPossibleSubSets(otherValues);
                foreach(var otherSet in allothersets)
                {
                    var otherSetTotal = SetSum(otherSet);
                    if(otherSetTotal == total)
                    {
                        var result = new StringBuilder();
                        result.Append("\n");
                        foreach(var value in set)
                        {
                            result.Append(value.ToString() + " ");
                        }
                        result.Remove(result.Length - 1, 1);
                        result.Append("\n");
                        foreach (var value in otherSet)
                        {
                            result.Append(value.ToString() + " ");
                        }
                        result.Remove(result.Length - 1, 1);
                        return result.ToString();
                    }
                }
            }

            return "\nImpossible";
        }


        private List<List<int>> GetAllPossibleSubSets(List<int> integers)
        {
            List<List<int>> allpossiblesets = new List<List<int>>();
            var newset = new List<int>();

            for(int i1=0;i1<integers.Count;i1++)
            {
                for (int i2 = i1 + 1; i2 < integers.Count && integers.Count >= 2; i2++)
                {
                    for (int i3 = i2 + 1; i3 < integers.Count && integers.Count >= 3; i3++)
                    {
                        for (int i4 = i3 + 1; i4 < integers.Count && integers.Count >= 4; i4++)
                        {
                            for (int i5 = i4 + 1; i5 < integers.Count && integers.Count >= 5; i5++)
                            {
                                for (int i6 = i5 + 1; i6 < integers.Count && integers.Count >= 6; i6++)
                                {
                                    for (int i7 = i6 + 1; i7 < integers.Count && integers.Count >= 7; i7++)
                                    {
                                        for (int i8 = i7 + 1; i8 < integers.Count && integers.Count >= 8; i8++)
                                        {
                                            for (int i9 = i8 + 1; i9 < integers.Count && integers.Count >= 9; i9++)
                                            {
                                                /*for (int i10 = i9 + 1; i10 < integers.Count && integers.Count >= 10; i10++)
                                                {
                                                    allpossiblesets.Add(new List<int>() { integers[i1], integers[i2], integers[i3], integers[i4], integers[i5], integers[i6], integers[i7], integers[i8], integers[i9], integers[i10] });
                                                }*/
                                                allpossiblesets.Add(new List<int>() { integers[i1], integers[i2], integers[i3], integers[i4], integers[i5], integers[i6], integers[i7], integers[i8], integers[i9]});
                                            }
                                            allpossiblesets.Add(new List<int>() { integers[i1], integers[i2], integers[i3], integers[i4], integers[i5], integers[i6], integers[i7], integers[i8]});
                                        }
                                        allpossiblesets.Add(new List<int>() { integers[i1], integers[i2], integers[i3], integers[i4], integers[i5], integers[i6], integers[i7]});
                                    }
                                    allpossiblesets.Add(new List<int>() { integers[i1], integers[i2], integers[i3], integers[i4], integers[i5], integers[i6]});
                                }
                                allpossiblesets.Add(new List<int>() { integers[i1], integers[i2], integers[i3], integers[i4], integers[i5]});
                            }
                            allpossiblesets.Add(new List<int>() { integers[i1], integers[i2], integers[i3], integers[i4]});
                        }
                        allpossiblesets.Add(new List<int>() { integers[i1], integers[i2], integers[i3] });
                    }
                    allpossiblesets.Add(new List<int>() { integers[i1], integers[i2] });
                }
                allpossiblesets.Add(new List<int>() { integers[i1] });
            }
            return allpossiblesets;
        }
    }
    class Program
    {
        const string INPUT_FILE = "C-small-attempt0.in";
        const string OUTPUT_FILE = "C-small-attempt0.out";

        static void Main(string[] args)
        {
            var lines = new List<string>();
            using (var sr = new StreamReader(INPUT_FILE))
            {
                while (!sr.EndOfStream)
                {
                    lines.Add(sr.ReadLine());
                }
            }

            var numTestCases = int.Parse(lines[0]);

            var outputLines = new List<string>();
            int currentLineNumber = 1;
            var cases = new List<CaseData>();
            for (int i = 0; i < numTestCases; i++)
            {
                var caseData = lines[currentLineNumber];
                currentLineNumber++;

                var ints = new List<int>();
                {
                    var tokens = caseData.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    foreach (var token in tokens)
                    {
                        ints.Add(int.Parse(token));
                    }
                }
                Debug.Assert(ints.Count > 1);
                var numContestants = ints[0];
                var contestantScores = new List<int>(ints);
                contestantScores.RemoveAt(0);

                cases.Add(new CaseData(contestantScores));
            }

            for (int i = 0; i < cases.Count; i++)
            {
                Console.WriteLine("*** Case " + (i + 1));
                var caseData = cases[i];
                var output = "Case #" + (i + 1) + ": " + caseData.Solve();
                outputLines.Add(output);
            }

            using (var sw = new StreamWriter(OUTPUT_FILE))
            {
                foreach (var line in outputLines)
                {
                    sw.Write(line + "\n");
                }
            }
        }

    }
}
