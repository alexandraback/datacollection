using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace GCJ.GCJ2012.Round1B
{
    internal class A
    {
        public static int GetMin(List<int> nums, int ex)
        {
            int min = 1000;

            for (int i = 0; i < nums.Count; ++i)
            {
                if (nums[i] < min && i != ex)
                    min = nums[i];
            }
            return min;
        }

        public static void Main()
        {
            var inputStream = new StreamReader(@"C:\Users\asaraswat\Downloads\A-large.in");
            var outputStream = new StreamWriter(@"C:\Users\asaraswat\Downloads\A-large.out");

            Console.SetIn(inputStream);
            Console.SetOut(outputStream);

            int totalCases = GetInt();
            for (int cs = 1; cs <= totalCases; ++cs)
            {
                var list = GetListOfInt();

                int n = list[0];

                var nums = list.GetRange(1, list.Count - 1);

                int total = 0;
                var targetSet = new SortedSet<int>();

                for (int i = 0; i < n; ++i)
                {
                    total += nums[i];
                    targetSet.Add(nums[i]);
                }

                List<double> ret = new List<double>();
                for (int i = 0; i < n; ++i)
                    ret.Add(0.0);

                bool goodToGo = true;
                int rem = total;
                if (targetSet.Count > 1)
                {
                    var targetList = targetSet.ToList();
                    for (int ii = 1; goodToGo && ii < targetList.Count; ++ii)
                    {
                        int target = targetList[ii];

                        var candidates = new List<int>();
                        for (int i = 0; goodToGo && i < n; ++i)
                        {
                            if (nums[i] < target)
                            {
                                candidates.Add(i);
                            }
                        }

                        if (candidates.Count > 0)
                        {
                            var votesNeeded = target - nums[candidates[0]];
                            if (votesNeeded * candidates.Count > rem)
                            {
                                goodToGo = false;
                            }
                            else
                            {
                                for (int c = 0; c < candidates.Count; ++c)
                                {
                                    ret[candidates[c]] += votesNeeded * 100.0 / total;
                                    rem -= votesNeeded;
                                    nums[candidates[c]] += votesNeeded;
                                }
                            }
                        }
                    }
                }

                int min = nums.Min();

                var cn = new List<int>();
                for (int i = 0; i < n; ++i)
                {
                    if (nums[i] == min)
                    {
                        cn.Add(i);
                    }
                }

                for (int c = 0; c < cn.Count; ++c)
                {
                    ret[cn[c]] += ((rem * 1.0) / cn.Count) * 100.0 / total;
                }

                Console.Write("Case #{0}:", cs);

                for (int i = 0; i < ret.Count; ++i)
                    Console.Write(" {0:N6}", ret[i]);
                Console.WriteLine();
            }

            inputStream.Close();
            outputStream.Close();

        }

        private static int GetInt()
        {
            string p = Console.ReadLine();
            return Convert.ToInt32(p);
        }

        private static List<int> GetListOfInt(char separator = ' ')
        {
            string p = Console.ReadLine();
            return p.Split(separator).Select(t => int.Parse(t)).ToList();
        }
    }
}
