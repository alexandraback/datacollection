using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;

namespace ConsoleApplication1
{
    public static class Program
    {
        private static int[] ReadInput()
        {
            using (var reader = new StreamReader("input.txt"))
            {
                var testsNum = int.Parse(reader.ReadLine());
                var testCases = new int[testsNum];

                for (int i = 0; i < testsNum; i++)
                    testCases[i] = int.Parse(reader.ReadLine());

                return testCases;
            }
        }

        private static void WriteOutput(int?[] solutions)
        {
            using (var writer = new StreamWriter("ouput.txt"))
            {
                for (int i = 0; i < solutions.Length; i++)
                {
                    writer.WriteLine("Case #{0}: {1}", i + 1, solutions[i]?.ToString() ?? "INSOMNIA");
                }
            }
        }

        private static void Main()
        {
            WriteOutput(ReadInput().Select(Solve).ToArray());
        }

        public static int? Solve(int number)
        {
            if (number == 0)
                return null;

            var seen = new HashSet<int>();

            var current = number;
            while (true)
            {
                int res = 10, div = 1;

                while (current >= div)
                {
                    int digit =  current % res / div;

                    if (!seen.Contains(digit))
                    {
                        seen.Add(digit);
                        if (seen.Count == 10)
                        {
                            return current;
                        }
                    }

                    res *= 10;
                    div *= 10;
                }

                current += number;
            }
        }
    }
}