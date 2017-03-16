using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;

namespace CodeJam
{
    class EqualSums
    {
        List<int> numbers;

        public EqualSums(List<int> numbers)
        {
            this.numbers = numbers;
        }

        public void Solve(StreamWriter sw)
        {
            PowerSet(numbers, new List<int>(), 0, numbers.Count - 1, new Dictionary<int, List<int>>(), sw);
        }

        public bool PowerSet(List<int> nums, List<int> res, int lb, int ub, Dictionary<int, List<int>> table, StreamWriter sw)
        {
            if (lb > ub)
            {
                var sum = res.Sum();

                //sw.WriteLine(string.Join(" ", res));
                
                if (table.ContainsKey(sum))
                {
                    sw.WriteLine(string.Join(" ", res));
                    sw.WriteLine(string.Join(" ", table[sum]));
                    return true;
                }
                else
                {
                    table.Add(sum, new List<int>(res));
                    return false;
                }
            }

            if (false == PowerSet(nums, res, lb + 1, ub, table, sw))
            {
                res.Add(nums[lb]);
                if (false == PowerSet(nums, res, lb + 1, ub, table, sw))
                {
                    res.Remove(nums[lb]);
                }
                else
                    return true;
            }
            else
                return true;

            return false;
        }

        static void Main(string[] args)
        {
            string fileName = "EqualSumsS";
            using (StreamReader sr = new StreamReader(File.OpenRead(fileName + ".in")))
            {
                using (StreamWriter sw = new StreamWriter(File.OpenWrite(fileName + ".out")))
                {
                    string line = sr.ReadLine();
                    int numOfTests = Int32.Parse(line);
                    for (int i = 0; i < numOfTests; i++)
                    {
                        line = sr.ReadLine();
                        var row = Regex.Split(line, "\\s+").Select(x => Int32.Parse(x)).ToList();
                        var numbers = new List<int>();

                        int n = row[0];
                        for (int j = 0; j < n; ++j)
                        {
                            numbers.Add(row[j + 1]);
                        }
                        var program = new EqualSums(numbers);
                        sw.WriteLine("Case #{0}:", i + 1);
                        program.Solve(sw);
                        //var result = ;
                        
                    }
                }
            }
        }
    }
}
