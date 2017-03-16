using System;
using System.Globalization;
using System.Linq;

namespace ProblemB
{
    class ProgramB
    {
        static void Main(string[] args)
        {
            var N = ReadInt();

            for (var c = 0; c < N; c++)
            {
                var parameters = ReadLongArray();
                var A = parameters[0];
                var B = parameters[1];
                var K = parameters[2];

                var result = FindSolution(A, B, K);
                Print(c, result);
            }
        }

        private static long FindSolution(long A, long B, long K)
        {
            int count = 0;

            for (int a = 0; a < A; a++)
            {
                for (int b = 0; b < B; b++)
                {
                    if ((a & b) < K)
                        count++;
                }
            }

            return count;
        }

        private static int ReadInt()
        {
            return Int32.Parse(Console.ReadLine());
        }

        private static long[] ReadLongArray()
        {
            var line = Console.ReadLine();
            return line.Split(' ').Select(Int64.Parse).ToArray();
        }

        private static void Print(int caseIndex, string result)
        {
            Console.WriteLine("Case #{0}: {1}", caseIndex + 1, result);
        }

        private static void Print(int caseIndex, long result)
        {
            Print(caseIndex, result.ToString(CultureInfo.InvariantCulture));
        }
    }
}
