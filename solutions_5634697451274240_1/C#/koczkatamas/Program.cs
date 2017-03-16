using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemB
{
    class Program
    {
        static void Main(string[] args)
        {
            var testCases = File.ReadAllLines("input.txt").Skip(1).Select(x => x.ToCharArray()).ToArray();
            var result = testCases.Select(testCase =>
            {
                var flipCount = 0;
                Action<int> flip = len =>
                {
                    for (int i = 0; i < (len + 1) / 2; i++)
                    {
                        var j = len - i - 1;
                        var tmp = testCase[i];
                        testCase[i] = testCase[j] == '+' ? '-' : '+';
                        if(i != j)
                            testCase[j] = tmp == '+' ? '-' : '+';
                    }
                    flipCount++;
                };

                var steps = new List<string>();
                for (int i = testCase.Length - 1; i >= 0; i--)
                {
                    steps.Add(new string(testCase));
                    if (testCase[i] == '+') continue;

                    if (i == 0)
                        flip(1);
                    else if (testCase[0] == '-')
                        flip(i + 1);
                    else // testCase[0] == '+'
                    {
                        int j;
                        for (j = 0; j < i; j++)
                            if (testCase[j] != '+')
                                break;
                        flip(j);
                        flip(i + 1);
                    }
                }
                return flipCount;
            });
            var resultStr = String.Join("\r\n", result.Select((x, i) => $"Case #{i + 1}: {(x == -1 ? "INSOMNIA" : x.ToString())}"));
            Console.WriteLine(resultStr);
            File.WriteAllText("output.txt", resultStr);
        }
    }
}
