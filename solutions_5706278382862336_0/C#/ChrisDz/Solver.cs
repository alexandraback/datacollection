using System;
using System.IO;
using System.Linq;
using System.Numerics;

using Numerics; // http://bcl.codeplex.com/wikipage?title=BigRational

namespace Google.CodeJam
{
    internal class Solver
    {
        private static BigInteger Solve(BigRational r)
        {
            if (r == new BigRational(1, 1))
                return 0;

            var parentDenominator = r.Denominator / 2;
            for (var i = parentDenominator; i >= 0; i--)
            {
                var p1 = new BigRational(i, parentDenominator);

                for (var j = 0; j <= parentDenominator; j++)
                {
                    var p2 = new BigRational(j, parentDenominator);
                    if ((p1 + p2) / 2 == r)
                        return Solve(p1) + 1;
                }
            }

            return -1;
        }

        private static void Solve(int id, TextReader reader, TextWriter writer)
        {
            var line = reader.ReadLine().Split('/').Select(long.Parse).ToArray();
            long p = line[0], q = line[1];

            var r = new BigRational(p, q);
            if (!r.Denominator.IsPowerOfTwo || BigInteger.Log(r.Denominator, 2) > 40)
                writer.WriteLine("Case #{0}: {1}", id, "impossible");
            else
                writer.WriteLine("Case #{0}: {1}", id, Solve(r));
        }

        private static void Main(string[] args)
        {
            try
            {
                var inputPath = args[0];
                var outputPath = args[1];

                using (var reader = new StreamReader(inputPath))
                using (var writer = new StreamWriter(outputPath))
                {
                    int count = int.Parse(reader.ReadLine());
                    for (int i = 0; i < count; i++)
                        Solve(i + 1, reader, writer);
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
            }
        }
    }
}
