using System;
using System.Numerics;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Q_FNS
{
    class Program
    {
        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int i = 0; i < T; i++)
            {
                Console.WriteLine("Case #{0}: {1}", i + 1,
                    new CaseSolver(Console.ReadLine()).Solve());

            }
            
        }
    }

    class CaseSolver
    {
        private BigInteger sqA, sqB;

        public CaseSolver(string sAB)
        {
            var aAB = sAB.Split(' ');
            BigInteger a = BigInteger.Parse(aAB[0]);
            BigInteger b = BigInteger.Parse(aAB[1]);

            sqA = Sqrt(a);
            sqB = Sqrt(b);
            if ((sqA * sqA) < a)
                sqA++;
        }

        public BigInteger Solve()
        {
            BigInteger result = new BigInteger(0);
            for (; sqA <= sqB; sqA++)
            {
                if (IsPalindrome(sqA) && IsPalindrome(sqA * sqA))
                    result++;
            }
            return result;
        }

        private static bool IsPalindrome(BigInteger x)
        {
            string sX = x.ToString();

            for (int i = 0; i < sX.Length / 2; i++)
                if (sX[i] != sX[sX.Length - 1 - i])
                    return false;
            return true;
        }

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

    }
}
