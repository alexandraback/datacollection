using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace ProblemA
{
    public class ProblemA
    {
        static void Main(string[] args)
        {
            int T = GetInt();
            for (int i = 0; i < T; i++)
            {
                string[] ints = GetWords();
                BigInteger r = BigInteger.Parse(ints[0]);
                BigInteger t = BigInteger.Parse(ints[1]);
                BigInteger result = Sqrt(2 * t);
                BigInteger d = t / r;
                if (d < result)
                    result = d;
                d = (result * (result - 1) / 2) + result * r;
                while (d > t)
                {
                    result--;
                    d = (result * (result - 1) / 2) + result * r;
                }
                WriteResult(i, (result) / 2);
            }
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
        #region Library

        static string GetLine()
        {
            return Console.ReadLine();
        }

        static string[] GetWords()
        {
            return GetLine().Split();
        }

        static int GetInt()
        {
            return int.Parse(GetLine());
        }

        static int[] GetInts()
        {
            return GetWords().Select(x => int.Parse(x)).ToArray();
        }

        private static void WriteResult(int iterator, BigInteger res)
        {
            Console.WriteLine("Case #{0}: {1}", iterator + 1, res.ToString());
        }

        #endregion
    }
}
