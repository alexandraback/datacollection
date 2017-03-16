using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemD
{
    class Program
    {
        static void Main(string[] args)
        {
            var testCases = File.ReadAllLines("input.txt").Skip(1).Select(x => x.Split(' ').Select(int.Parse).ToArray()).Select(x => new { K = x[0], C = x[1], S = x[2] }).ToArray();
            var result = new List<string>();
            foreach (var testCase in testCases)
            {
                if (testCase.K != testCase.S)
                {
                    result.Add("IMPOSSIBLE");
                    continue;
                }

                var res = new List<ulong>();
                for (int i = 0; i < testCase.K; i++)
                {
                    ulong val = 0;
                    for (int j = 0; j < testCase.C; j++)
                        val = val * (ulong)testCase.K + (ulong)i;
                    res.Add(val + 1);
                }
                result.Add(String.Join(" ", res));
            }
            var resultStr = String.Join("\r\n", result.Select((x, i) => $"Case #{i + 1}: {x}"));
            Console.WriteLine(resultStr);
            File.WriteAllText("output.txt", resultStr);
        }
    }
}
