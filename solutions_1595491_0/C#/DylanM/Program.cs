using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Dancing_with_the_Googlers
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> MaxScores = new List<int>();

            using (StreamReader sr = new StreamReader("input_small.txt"))
            {
                int numOfTestCases = int.Parse(sr.ReadLine());

                for (int i = 0; i < numOfTestCases; i++)
                {
                    int[] nums = sr.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
                    int numOfGooglers = nums[0];
                    int numOfSuprisingScores = nums[1];
                    int scoreTarget = nums[2];

                    List<double> scores = new List<double>();

                    for (int j = 3; j < nums.Length; j++)
                    {
                        scores.Add((double)nums[j]);
                    }

                    MaxScores.Add(GetMaxNumberOfGooglers(numOfGooglers, numOfSuprisingScores, scoreTarget, scores));
                }
            }

            using (StreamWriter sw = new StreamWriter("output_small.txt"))
            {
                for (int i = 0; i < MaxScores.Count; i++)
                {
                    sw.WriteLine("Case #" + (i + 1).ToString() + ": " + MaxScores[i]);
                }
            }
        }

        private static int GetMaxNumberOfGooglers(int numOfGooglers, int numOfSuprisingScores, int scoreTarget, List<double> scores)
        {
            if (scoreTarget == 0)
                return scores.Count;

            if (scoreTarget == 1)
                return scores.Count(s => s > 0);

            if (scoreTarget == 2)
                return scores.Count(s => s > 3) + scores.Where(s => s == 2 || s == 3).Take(numOfSuprisingScores).Count();

            int maxCount = 0;
            int usedSuprises = 0;

            for (int i = 0; i < scores.Count; i++)
            {
                if ((int)Math.Ceiling(scores[i] / 3.0) >= scoreTarget)
                {
                    maxCount++;
                }
                else if ((int)(scores[i] + 4) >= scoreTarget * 3  && usedSuprises < numOfSuprisingScores)
                {
                    maxCount++;
                    usedSuprises++;
                }
            }

            return maxCount;
        }
    }
}
