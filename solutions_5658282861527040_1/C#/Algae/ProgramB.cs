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
                var parameters = ReadIntArray();
                var A = parameters[0];
                var B = parameters[1];
                var K = parameters[2];

                var result = FindSolution(A, B, K);
                Print(c, result);
            }
        }

        private static long FindSolution(long A, long B, long K)
        {
            long k = Math.Min(A, K);
            k = Math.Min(B, k);

            long count = k * (A + B - k);


            for (var a = K; a < A; a++)
            {
                for (var b = K; b < B; b++)
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

        private static int[] ReadIntArray()
        {
            var line = Console.ReadLine();
            return line.Split(' ').Select(int.Parse).ToArray();
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
