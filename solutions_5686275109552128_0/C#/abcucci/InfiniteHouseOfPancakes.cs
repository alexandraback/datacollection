using System;
using System.Collections.Generic;
using System.Text;
using NUnit.Framework;

namespace QualificationRound
{
    public class InfiniteHouseOfPancakes
    {
        public string Run(string inputText)
        {
            string[] lines = inputText.Split(new char[] { '\r', '\n' }, StringSplitOptions.RemoveEmptyEntries);
            int N = lines.Length;

            String answer = "";
            for (int i = 2; i <= N; i += 2)
            {
                string line = lines[i];
                List<int> values = new List<int>();
                foreach (string s in line.Split(' '))
                {
                    int value = int.Parse(s);
                    values.Add(value);
                }

                int minCount = this.Solve((int[])values.ToArray());

                answer += string.Format("Case #{0}: {1}", (i / 2), minCount);
                answer += Environment.NewLine;
            }

            return answer;
        }

        public int Solve(int[] values)
        {
            int min = int.MaxValue;
            for (int t = 1; t <= 1001; ++t)
            {
                int count = t;
                foreach (int value in values)
                {
                    if (value > t)
                    {
                        int div = value / t;
                        if ((value % t) != 0) { ++div; }
                        count += div - 1;
                    }
                }
                min = Math.Min(min, count);
            }
            return min;
        }
    }

    [TestFixture]
    public class testInfiniteHouseOfPancakes
    {
        [TestCase(new int[] { 1 }, 1)]
        [TestCase(new int[] { 2 }, 2)]
        [TestCase(new int[] { 3 }, 3)]
        [TestCase(new int[] { 4 }, 3)]
        [TestCase(new int[] { 5 }, 4)]
        [TestCase(new int[] { 6 }, 4)]
        [TestCase(new int[] { 1, 1, 1, 64 }, 15)]
        [TestCase(new int[] { 8, 8, 8 }, 7)]
        [TestCase(new int[] { 1, 2, 1, 2 }, 2)]
        [TestCase(new int[] { 9 }, 5)]
        public void testSolve(int[] values, int expected)
        {
            InfiniteHouseOfPancakes instance = new InfiniteHouseOfPancakes();
            int answer = instance.Solve(values);
            Assert.AreEqual(expected, answer);
            return;
        }
    }

}
