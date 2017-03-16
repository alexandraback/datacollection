using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;

namespace Z1
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int i = 0; i < T; i++)
            {
                var rt = Console.ReadLine().Split(' ')
                    .Select(x => long.Parse(x))
                    .ToArray();

                Console.WriteLine("Case #{0}: {1}",
                    i + 1,
                    new Solver(rt[0], rt[1]).Solve());

            }

        }
    }

    class Solver
    {
        private BigInteger r;
        private BigInteger t;

        private static BigInteger Sqrt(BigInteger n)
        {
            if (n == 0) return 0;
            if (n > 0)
            {
                int bitLength = Convert.ToInt32(Math.Ceiling(BigInteger.Log(n, 2)));
                BigInteger root = BigInteger.One << (bitLength >> 1);

                while (!isSqrt(n, root))
                {
                    root += n / root;
                    root >>= 1;
                }

                return root;
            }

            throw new ArithmeticException("NaN");
        }
        private static Boolean isSqrt(BigInteger n, BigInteger root)
        {
            BigInteger lowerBound = root * root;
            BigInteger upperBound = (root + 1) * (root + 1);

            return (n >= lowerBound && n < upperBound);
        }

        public Solver(BigInteger r, BigInteger t)
        {
            this.r = r;
            this.t = t;
        }

        public BigInteger Solve()
        {
            BigInteger result = 0;

            BigInteger a = 2;
            BigInteger b = new BigInteger(2) * r + 1 - 2;
            BigInteger c = t * (-1);

            BigInteger delta = b * b - 4 * a * c;
            if (delta < 0) throw new InvalidOperationException();
            if (delta == 0)
                result = b * (-1) / (2 * a);
            else
            {

                BigInteger x1, x2;
                x1 = (b * (-1) - Sqrt(delta)) / (2 * a);
                x2 = (b * (-1) + Sqrt(delta)) / (2 * a);

                result =
                    x1 > x2 ? x1 : x2;
            }

            BigInteger sum = ((2 * (new BigInteger(2) * r + 1) + (result - 1) * 4) / 2) * result;
            return sum > t ? --result : result;
        }
    }
}
