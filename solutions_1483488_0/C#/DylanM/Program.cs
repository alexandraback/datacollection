using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace Recycled_Numbers
{
    class Program
    {
        private static Dictionary<int, List<int>> Permutations = new Dictionary<int, List<int>>();

        private static void BuildAllPermutations()
        {
            for (int i = 1; i < 2000000; i++)
            {
                List<string> perms = new List<string>();
                string strNum = i.ToString();

                for (int j = 0; j < strNum.Length - 1; j++)
                {
                    perms.Add(strNum.Substring(strNum.Length - 1 - j) + strNum.Substring(0, strNum.Length - 1 - j));
                }

                Permutations.Add(i, perms.Select(s => int.Parse(s)).Where(n => n < i).Distinct().ToList());
            }
        }

        static void Main(string[] args)
        {
            BuildAllPermutations();

            List<long> results = new List<long>();

            using (StreamReader sr = new StreamReader("input_small.txt"))
            {
                int numOfTestCases = int.Parse(sr.ReadLine());

                for (int i = 0; i < numOfTestCases; i++)
                {
                    int[] nums = sr.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
                    
                    int min = nums[0];
                    int max = nums[1];

                    results.Add(GetMatches(min, max));
                }
            }

            using (StreamWriter sw = new StreamWriter("output_small.txt"))
            {
                for (int i = 0; i < results.Count; i++)
                {
                    sw.WriteLine("Case #" + (i + 1).ToString() + ": " + results[i]);
                }
            }
        }

        private static long GetMatches(int min, int max)
        {
            long count = 0;

            for (int i = max; i > min; i--)
            {
                count += Permutations[i].Count(n => n >= min);
            }

            return count;
        }
    }
}
