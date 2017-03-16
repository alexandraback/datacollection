using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;

namespace Equal_Sums
{
    class Program
    {
        static void Main(string[] args)
        {
            List<TestCase> cases = new List<TestCase>();

            using (StreamReader sr = new StreamReader("input_small.txt"))
            {
                int numOfTestCases = int.Parse(sr.ReadLine());

                for (int i = 0; i < numOfTestCases; i++)
                {
                    int[] nums = sr.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();

                    cases.Add(new TestCase(nums.Skip(1).ToList()));
                }
            }

            using (StreamWriter sw = new StreamWriter("output_small.txt"))
            {
                for (int i = 0; i < cases.Count; i++)
                {
                    sw.WriteLine("Case #" + (i + 1).ToString() + ": ");
                    sw.Write(cases[i].GetResults());
                }
            }
        }
    }

    class TestCase
    {
        List<List<int>> permuatations = new List<List<int>>();

        public TestCase(List<int> nums)
        {
//            Parallel.For(
            for (int i = 1; i < (1 << nums.Count); i++)
            {
                string binary = Convert.ToString(i, 2).PadLeft(nums.Count(), '0');
                var perm = new List<int>();

                for (int j = 0; j < nums.Count; j++)
                {
                    if (binary[j] == '1')
                    {
                        perm.Add(nums[j]);
                    }
                }

                permuatations.Add(perm);
            }
        }

        internal string GetResults()
        {
            List<long> sums = new List<long>();

            for (int i = 0; i < permuatations.Count; i++)
            {
                sums.Add(permuatations[i].Sum());
            }

            for (int i = 0; i < sums.Count; i++)
            {
                for (int j = i + 1; j < sums.Count; j++)
                {
                    if (sums[i] == sums[j])
                    {
                        string perm1 = string.Join(" ", permuatations[i]) + Environment.NewLine;
                        string perm2 = string.Join(" ", permuatations[j]) + Environment.NewLine;

                        return perm1 + perm2;
                    }
                }
            }

            return "Impossible" + Environment.NewLine;
        }
    }
}
