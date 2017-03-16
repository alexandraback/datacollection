using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            var testNo = MyConsole.ReadInt();
            for (int i = 1; i <= testNo;i++)
            {
                var res = GetNumbers();
                var s = string.Join(" ", res);
                Console.WriteLine("Case #"+i+": "+s);
            }
        }

        static IEnumerable<double> GetNumbers()
        {
            var n = MyConsole.GetNextInt();
            var nums = MyConsole.ReadIntArray(n);
            int sum = nums.Sum();

            double avgScore = (sum*2.0)/n;

            var nn = nums.Count(i => i < avgScore);
            var s1 = nums.Where(i => i < avgScore).Sum();

            var avg = (s1+sum)/(double)nn;

            var res=new double[n];

            for (int i = 0; i < n; i++)
            {
                res[i] = nums[i] >= avgScore ? 0 : (avg - nums[i]) * 100 / sum;
                   
            }
            return res;
        }
    }

    
}
