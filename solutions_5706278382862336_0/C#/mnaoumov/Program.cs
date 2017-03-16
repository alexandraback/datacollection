using System;
using System.IO;

namespace ProblemA.PartElf
{
    class Program
    {
        static void Main(string[] args)
        {
            var inputFile = "A-small-attempt0.in";
            var outputFile = "A-small-attempt0.out";

            using (var reader = new StreamReader(inputFile))
            using (var writer = new StreamWriter(outputFile))
            {
                var T = Convert.ToInt32(reader.ReadLine());
                for (var i = 1; i <= T; i++)
                {
                    string inputLine = reader.ReadLine();
                    var PQ = inputLine.Split('/');
                    var P = Convert.ToInt64(PQ[0]);
                    var Q = Convert.ToInt64(PQ[1]);
                    var result = GetMinimumGenerationString(P, Q);
                    if (i != 1)
                        writer.WriteLine();
                    writer.Write("Case #{0}: {1}", i, result);
                }
            }
        }

        static string GetMinimumGenerationString(long P, long Q)
        {
            var minimumGeneration = GetMinimumGeneration(P, Q);

            if (minimumGeneration == null)
                return "impossible";

            return minimumGeneration.ToString();
        }

        static int? GetMinimumGeneration(long P, long Q, bool mayHaveCommonFactors = true)
        {
            if (mayHaveCommonFactors)
            {
                var d = GCD(P, Q);
                return GetMinimumGeneration(P / d, Q / d, mayHaveCommonFactors: false);
            }

            if (!IsPowerOfTwo(Q))
                return null;

            var generation = 0;
            var Q1 = Q;
            while (Q1 > P)
            {
                Q1 >>= 1;
                generation++;
            }

            return generation;
        }

        static bool IsPowerOfTwo(long n)
        {
            return (n & (n - 1)) == 0;
        }

        static long GCD(long P, long Q)
        {
            var a = P;
            var b = Q;

            while (b != 0)
            {
                var r = a % b;
                a = b;
                b = r;
            }

            return a;
        }
    }
}
