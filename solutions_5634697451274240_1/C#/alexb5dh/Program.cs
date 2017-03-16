using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Security.Principal;

namespace ConsoleApplication1
{
    public static class Program
    {
        private static string[] ReadInput()
        {
            using (var reader = new StreamReader("input.txt"))
            {
                var testsNum = int.Parse(reader.ReadLine());
                var testCases = new string[testsNum];

                for (int i = 0; i < testsNum; i++)
                    testCases[i] = reader.ReadLine();

                return testCases;
            }
        }

        private static void WriteOutput(int[] solutions)
        {
            using (var writer = new StreamWriter("output.txt"))
            {
                for (int i = 0; i < solutions.Length; i++)
                {
                    writer.WriteLine("Case #{0}: {1}", i + 1, solutions[i]);
                }
            }
        }

        private static void Main()
        {
            Solve("-+");
            WriteOutput(ReadInput().Select(Solve).ToArray());
        }

        public static int Solve(string stack)
        {
            int @switch = 0;
            for (int i = 1; i < stack.Length; i++)
            {
                if (stack[i] != stack[i - 1])
                    @switch += 1;
            }

            if (stack[0] == '+' && @switch == 0)
                return 0;

            return @switch + (stack.Last() == '-' ? 1 : 0);
        }
    }
}