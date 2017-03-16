using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2016
{
    class Round1c
    {
        public static void Main(string[] args)
        {
            new Round1c().Run("C-small.in");
        }

        TextWriter sw;
        int caseNo = 1;
        int n;
        internal void Run(string p)
        {
            using (var sr = File.OpenText(p))
            using (sw = File.CreateText("1csmall.out"))
            {
                sr.ReadLine();
                var parts = sr.ReadLine().Split(' ').Select(i => Int32.Parse(i)).ToArray();
                n = parts[0];
                var j = parts[1];

                var lowerbound = (1 << (n - 1)) + 1;
                var upperbound = (1 << n) - 1;

                sw.WriteLine("Case #1");
                foreach (var candidate in GenerateAll(lowerbound, upperbound).Take(j))
                {
                    sw.WriteLine(String.Join(" ", candidate));
                }
            }
        }

        private IEnumerable<BigInteger[]> GenerateAll(Int32 lowerbound, Int32 upperbound)
        {
            for (Int32 candidate = lowerbound; candidate <= upperbound; candidate += 2)
            {
                var result = new BigInteger[10];

                result[0] = candidate;
                var digits = GetBits(candidate);

                for (int b = 2; b <= 10; b++)
                {
                    var baseCandidate = Convert(digits, b);
                    var divisor = TestForPrime(baseCandidate);
                    if (divisor == 0) break;
                    result[b - 1] = divisor;

                    if (b == 10)
                    {
                        result[0] = baseCandidate;
                        yield return result;
                    }
                }
            }
        }

        private BigInteger TestForPrime(BigInteger baseCandidate)
        {
            if (baseCandidate % 2 == 0) return 2;
            BigInteger t = 3;
            BigInteger stop = new BigInteger(Math.Exp(BigInteger.Log(baseCandidate) / 2));

            while (t < stop)
            {
                if (baseCandidate % t == 0) return t;
                t += 2;
            }

            return 0;
        }

        private Int32[] GetBits(Int32 candidate)
        {
            var bits = new Int32[n];
            for (int i = 0; i < n; i++)
            {
                bits[i] = candidate % 2;
                candidate >>= 1;
            }

            return bits;
        }

        private BigInteger Convert(int[] digits, int b)
        {
            BigInteger result = 0;
            BigInteger mul = 1;
            for (int i = 0; i < n; i++)
            {
                result += digits[i] * mul;
                mul *= b;
            }

            return result;
        }
    }
}
