using System;
using System.IO;
using System.Numerics;

namespace GoogleContest1
{
    class Program
    {
        static void Main(string[] args)
        {
            var sr = new StreamReader(@"C:\Users\Sonu\Desktop\Contest\Google\1\A-large.in");
            var sw = new StreamWriter(@"C:\Users\Sonu\Desktop\Contest\Google\1\A-large_output.in", true);
            sw.AutoFlush = true;
            var count = int.Parse(sr.ReadLine().Trim());
            for (var i = 0; i < count; i++)
            {
                    var line = sr.ReadLine().Split(' ');
                    sw.WriteLine(string.Format("Case #{0}: {1}", i + 1, NoOfRings(BigInteger.Parse(line[0]), BigInteger.Parse(line[1]))));                
            }
        }

        private static long NoOfRings(BigInteger r, BigInteger t)
        {
            var b = 2 * r - 1;
            var x = Sqrt(b * b + 8 * t);
            return (long)((-2 * r + 1 + x) / 4);
        }

        public static BigInteger Sqrt(BigInteger n)
        {
            if (n == 0) return 0;
            if (n > 0)
            {
                int bitLength = Convert.ToInt32(Math.Ceiling(BigInteger.Log(n, 2)));
                BigInteger root = BigInteger.One << (bitLength / 2);

                while (!isSqrt(n, root))
                {
                    root += n / root;
                    root = root >> 1;
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
