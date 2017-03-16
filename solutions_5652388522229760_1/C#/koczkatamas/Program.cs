using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            var testCases = File.ReadAllLines("input.txt").Skip(1).Select(int.Parse).ToArray();
            var result = testCases.Select(x =>
            {
                if (x == 0) return -1;

                int currNum = x;
                var nums = new bool[10];
                while (true)
                {
                    var digits = currNum;
                    while (digits != 0)
                    {
                        nums[digits % 10] = true;
                        digits /= 10;
                    }
                    if (nums.All(y => y))
                        return currNum;
                    currNum += x;
                }
            });
            var resultStr = String.Join("\r\n", result.Select((x, i) => $"Case #{i+1}: {(x == -1 ? "INSOMNIA" : x.ToString())}"));
            Console.WriteLine(resultStr);
            File.WriteAllText("output.txt", resultStr);
        }
    }
}
