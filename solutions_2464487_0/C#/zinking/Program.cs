using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;

namespace CodeJamQA
{
    class Program
    {
        static void Main(string[] args)
        {
            string line = Console.ReadLine();
            int n = Int32.Parse(line);
            for( int i=0; i<n; i++ )
            {
                line = Console.ReadLine();
                PA(i+1, line);
            }
        }

        public static void PA(int i, string line)
        {
            string[] ss = line.Split();
            BigInteger r = BigInteger.Parse(ss[0]);
            BigInteger t = BigInteger.Parse(ss[1]);
            BigInteger tt = ( BigInteger.Pow( (r*2-1), 2 )) + t*8;
            BigInteger result = (( 1-2*r) + Sqrt(tt))/4;
            Console.WriteLine("Case #{0}: {1}", i, result );
        }

        public static BigInteger Sqrt( BigInteger n)
        {
            if (n == 0) return 0;
            if (n > 0)
            {
                int bitLength = Convert.ToInt32(Math.Ceiling(BigInteger.Log(n, 2)));
                BigInteger root = BigInteger.One << (bitLength / 2);

                while (!isSqrt(n, root))
                {
                    root += n / root;
                    root /= 2;
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
