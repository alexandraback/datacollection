using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace Safety_In_Numbers
{
    class Program
    {
        static void Main(string[] args)
        {
            List<TestCase> testCases = new List<TestCase>();

            using (StreamReader sr = new StreamReader("input_large.txt"))
            {
                int numOfTestCases = int.Parse(sr.ReadLine());

                for (int i = 0; i < numOfTestCases; i++)
                {
                    int[] nums = sr.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
                    testCases.Add(new TestCase(nums.Skip(1)));
                }
            }

            using (StreamWriter sw = new StreamWriter("output_large.txt"))
            {
                for (int i = 0; i < testCases.Count; i++)
                {
                    sw.Write("Case #" + (i + 1).ToString() + ": ");

                    foreach (var result in testCases[i].GetAudienceValues())
                    {
                        sw.Write(result + " ");
                    }

                    sw.WriteLine();
                }
            }
        }
    }

    class TestCase
    {
        List<int> _Scores = new List<int>();        

        public TestCase(IEnumerable<int> scores)
        {
            _Scores = new List<int>(scores);

            if (GetAudienceValues().Sum() < 99.999 || GetAudienceValues().Sum() > 100.001)
            {
                Debug.WriteLine(GetAudienceValues().Sum());
                System.Diagnostics.Debugger.Break();
            }
        }

        public IEnumerable<double> GetAudienceValues()
        {
            List<int> tempScores = new List<int>(_Scores);
            int scoreTotal = tempScores.Sum();
            double totalTarget = (double)(scoreTotal + _Scores.Sum()) / (double)tempScores.Count;

            while (tempScores.Max() > totalTarget)
            {
                tempScores.Remove(tempScores.Max());
                totalTarget = (double)(tempScores.Sum() + _Scores.Sum()) / (double)tempScores.Count;
            }

            for (int i = 0; i < _Scores.Count; i++)
            {
                if (_Scores[i] >= totalTarget)
                    yield return 0;
                else
                    yield return 100 * ((totalTarget - _Scores[i]) / (double)scoreTotal);
            }
        }
    }
}
