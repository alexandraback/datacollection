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
        private static string[] palSQ = new[]
            {
                "1",
                "2",
                "3",
                "11",
                "22",
                "101",
                "111",
                "121",
                "202",
                "212",
                "1001",
                "1111",
                "2002",
                "10001",
                "10101",
                "10201",
                "11011",
                "11111",
                "11211",
                "20002",
                "20102",
                "100001",
                "101101",
                "110011",
                "111111",
                "200002",
                "1000001",
                "1001001",
                "1002001",
                "1010101",
                "1011101",
                "1012101",
                "1100011",
                "1101011",
                "1102011",
                "1110111",
                "1111111",
                "2000002",
                "2001002",
                "10000001",
                "10011001",
                "10100101",
                "10111101",
                "11000011",
                "11011011",
                "11100111",
                "11111111",
                "20000002",
                "100000001",
                "100010001",
                "100020001",
                "100101001",
                "100111001",
                "100121001",
                "101000101",
                "101010101",
                "101020101",
                "101101101",
                "101111101",
                "110000011",
                "110010011",
                "110020011",
                "110101011",
                "110111011",
                "111000111",
                "111010111",
                "111101111",
                "111111111",
                "200000002",
                "200010002"
            };
        private static BigInteger[] palBI;
        static CaseSolver()
        {
            palBI = palSQ.Select(x => BigInteger.Parse(x)).ToArray();
        }


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
            for (int i=0; i<palBI.Length; i++)
            {
                if(palBI[i] >= sqA && palBI[i] <= sqB)
                {
                    result++;
                }
            }
            //for (; sqA <= sqB; sqA++)
            //{
            //    if (IsPalindrome(sqA) && IsPalindrome(sqA * sqA))
            //    {
            //        result++;
            //    }
            //}
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
