using System;
using System.Diagnostics;
using System.Linq;
using System.Numerics;
using System.Text;

namespace CodeJam2016
{
    static class Program
    {
        static void Main(string[] args)
        {
            //Test();

            var t = int.Parse(Console.ReadLine());

            for (var i = 0; i < t; i++)
            {
                var line = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                var k = line[0];
                var c = line[1];
                var s = line[2];

                var result = Solve(k, c, s);
                var formattedResult = result == null ? "IMPOSSIBLE" : string.Join(" ", result);
                Console.WriteLine($"Case #{i + 1}: {formattedResult}");
            }
        }

        static void Test()
        {
            for (var k = 1; k < 7; k++)
            {
                for (var c = 1; c < 5; c++)
                {
                    for (var s = 1; s <= k; s++)
                    {
                        Test(k, c, s);
                    }
                }
            }
        }

        static string CreatePattern(int length, int? goldPosition)
        {
            var line = new StringBuilder(new string('L', length));
            if (goldPosition.HasValue)
                line[goldPosition.Value] = 'G';

            return line.ToString();
        }

        static string Inflate(string previous, string pattern)
        {
            var result = new StringBuilder();

            foreach (var c in previous)
                result.Append(c == 'G' ? new string('G', pattern.Length) : pattern);

            return result.ToString();
        }

        static string CreateArt(string pattern, int c)
        {
            var art = pattern;

            for (var i = 1; i < c; i++)
                art = Inflate(art, pattern);

            return art;
        }

        static void Test(int k, int c, int s)
        {
            var proposedChecks = Solve(k, c, s);

            if (proposedChecks == null)
            {
                Console.WriteLine($"Can't test {k}, {c}, {s}");
                return;
            }

            var solution = proposedChecks.Select(v => (int)v).ToArray();

            Debug.Assert(false == HasGold(CreateArt(CreatePattern(k, null), c), solution));

            for (var i = 0; i < k; i++)
                Debug.Assert(true == HasGold(CreateArt(CreatePattern(k, i), c), solution));

            Console.WriteLine($"{k}, {c}, {s} - OK");
        }

        static bool HasGold(string art, int[] positions)
        {
            return positions.Any(p => art[p - 1] == 'G');
        }

        static BigInteger[] Range(BigInteger start, int count)
        {
            var values = new BigInteger[count];

            for (var i = 0; i < count; i++)
                values[i] = start + i;

            return values;
        }

        static BigInteger[] Solve(int k, int c, int s)
        {
            if (c == 1)
                return k == s ? Range(1L, k) : null;

            if (k == 1)
                return new[] { BigInteger.One };

            if (s < k - 2)
                return null;

            var result = Range(2, k / 2).Concat(Range(BigInteger.Pow(k, c) - k / 2, k / 2)).ToArray();

            return result;
        }
    }
}