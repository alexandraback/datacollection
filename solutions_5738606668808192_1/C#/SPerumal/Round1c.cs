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
            new Round1c().Run("C-large.in");
        }

        TextWriter sw;
        int caseNo = 1;
        int n;
        internal void Run(string p)
        {
            using (var sr = File.OpenText(p))
            using (sw = File.CreateText("1clarge.out"))
            {
                caseNo = int.Parse(sr.ReadLine());

                string line;
                while ((line = sr.ReadLine()) != null)
                {
                    var parts = line.Split(' ').Select(i => Int32.Parse(i)).ToArray();
                    n = parts[0];
                    var j = parts[1];

                    var lowerbound = BigInteger.Pow(10, n - 1) + 1;
                    var upperbound = BigInteger.Pow(10, n) - 1;

                    sw.WriteLine("Case #{0}:", caseNo++);
                    foreach (var candidate in GenerateAll(lowerbound, upperbound).Take(j))
                    {
                        sw.WriteLine(String.Join(" ", candidate));
                    }
                }
            }
        }

        private IEnumerable<BigInteger[]> GenerateAll(BigInteger lowerbound, BigInteger upperbound)
        {
            for (BigInteger candidate = lowerbound; candidate <= upperbound; candidate += 2)
            {
                var result = new BigInteger[10];

                result[0] = candidate;
                var digits = GetBits(candidate);
                Console.WriteLine(Convert(digits, 10));
                
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
                if (t > 1000000) break;
            }

            return 0;
        }

        private Int32[] GetBits(BigInteger candidate)
        {
            var bits = new Int32[n];
            for (int i = 0; i < n; i++)
            {
                bits[i] = (Int32)(candidate % 2);
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
