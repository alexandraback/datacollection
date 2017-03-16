using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace StudyingConsoleCSharp.CodeJam._2016Qualification
{
    public class CoinJam
    {
        private const string Path = @"C:\_Development\Git\Study\StudyingConsole\StudyingConsoleCSharp\CodeJam\2016Qualification\";

        public void Process()
        {
            var result = new StringBuilder();
            using (var textReader = File.OpenText(Path + "in_C.txt"))
            {
                var testsCount = int.Parse(textReader.ReadLine());
                for (var t = 1; t <= testsCount; ++t)
                {
                    var ps = textReader.ReadLine().Split(' ').Select(int.Parse).ToArray();

                    var r = Solve(ps[0], ps[1]);
                    result.AppendLine($"Case #{t}:");
                    foreach (var kv in r)
                        result.AppendLine($"{kv.Key} {string.Join(" ", kv.Value)}");
                }
            }
            using (var textWriter = File.CreateText(Path + "out_C.txt"))
                textWriter.Write(result.ToString());
        }

        private static Dictionary<string, long[]> Solve(int N, int J)
        {
            Dictionary<string, long[]> result = new Dictionary<string, long[]>();

            long[] numbers = new long[11];
            long[] prenums = new long[11];
            for (int k = 2; k <= 10; ++k)
                prenums[k] = (long)Math.Pow(k, N - 1) + 1;

            var divisors = GetDivisors(prenums);
            if (divisors != null)
                result.Add(GetString(N, 0), divisors.Skip(2).ToArray());

            int j = 1;
            int maxNumber = (int)Math.Pow(2, N - 2); // do not consider the first and the last value of the jamcoin in generator.
            while (j < maxNumber && result.Count < J)
            {
                for (var k = 2; k <= 10; ++k)
                    numbers[k] = prenums[k] + GetNumber(j, k);

                divisors = GetDivisors(numbers);
                if (divisors != null)
                    result.Add(GetString(N, j), divisors.Skip(2).ToArray());

                ++j;
            }

            return result;
        }

        private static string GetString(int N, int j)
        {
            var sb = new StringBuilder();
            sb.Append('1');
            var counter = 1;
            while (j > 0)
            {
                sb.Append((j & 1) == 1 ? '1' : '0');
                j >>= 1;
                counter++;
            }
            for (var i = counter + 1; i < N; ++i)
                sb.Append('0');
            sb.Append('1');

            var result = sb.ToString();
            result = new string(result.Reverse().ToArray());

            return result;
        }

        private static long[] GetDivisors(long[] numbers)
        {
            long[] result = new long[11];
            for (var i = 2; i <= 10; ++i)
            {
                var divisor = GetDivisor(numbers[i]);
                if (divisor == null)
                    return null;

                result[i] = divisor.Value;
            }

            return result;
        }

        private static long GetNumber(int j, int b)
        {
            long i = b;
            long result = 0;
            while (j > 0)
            {
                if ((j & 1) == 1)
                    result += i;
                i *= b;
                j >>= 1;
            }
            return result;
        }

        private static long? GetDivisor(long n)
        {
            if (n <= 1)
                return null;
            if (n <= 3)
                return null;

            if (n%2 == 0)
                return 2;

            if (n%3 == 0)
                return 3;

            long i = 5;
            while (i*i <= n)
            {
                if (n%i == 0)
                    return i;
                if (n%(i + 2) == 0)
                    return i + 2;

                i += 6;
            }
            return null;
        }
    }
}
