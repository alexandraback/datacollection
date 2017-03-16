using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;

namespace GoogleCodeJam2013_Round1A_A_BullsEye
{
    class Program
    {
        static void Main(string[] args)
        {
            var outFn = "output.out";
            ProvideEmptyFile(outFn);
            Action<string> wl = line =>
            {
                //Console.WriteLine(line);
                File.AppendAllLines(outFn, new[] { line });
            };

            var inLines = File.ReadAllLines("input.txt");
            var testCaseCount = int.Parse(inLines[0]);
            for (int iCase = 1; iCase <= testCaseCount; iCase++)
            {
                var r = BigInteger.Parse(inLines[iCase].Split(' ')[0]);
                var t = BigInteger.Parse(inLines[iCase].Split(' ')[1]);

                BigInteger result = ((-r * 10) + 5 + (100 * (r*r - r + 2*t) + 25).Sqrt())/20;

                wl(String.Format("Case #{0}: {1}", iCase, result));
            }
        }

        static void ProvideEmptyFile(string fn)
        {
            if (!File.Exists(fn)) return;

            for (int i = 1; i < 100; i++)
            {
                var bakFn = fn + "_bak_" + i;
                if (File.Exists(bakFn)) continue;
                File.Move(fn, bakFn);
                break;
            }
        }

    }

    public static class Ext
    {
        public static BigInteger Sqrt(this BigInteger n)
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
