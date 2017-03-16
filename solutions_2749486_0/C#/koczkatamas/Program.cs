using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace Round1C_B
{
    class Program
    {
        static void Main(string[] args)
        {
            var inputFn = "input.txt";
            var historyPostfix = DateTime.Now.ToString("HHmmss");

            File.Copy(inputFn, "input_" + historyPostfix + ".txt");
            Action<string> wl = line =>
            {
                Console.WriteLine(line);
                File.AppendAllLines("output_" + historyPostfix + ".txt", new[] { line });
            };

            //var stat = new List<Tuple<int, int, >>

            var inLines = File.ReadAllLines(inputFn);
            var testCaseCount = int.Parse(inLines[0]);
            var linesPerTestCase = 1;
            var iLine = 1;
            for (int iCase = 1; iCase <= testCaseCount; iCase++, iLine += linesPerTestCase)
            {
                var dX = int.Parse(inLines[iLine + 0].Split(' ')[0]);
                var dY = int.Parse(inLines[iLine + 0].Split(' ')[1]);

                var result = "";

                var x = 0;
                var y = 0;

                while(dX < x)
                {
                    result += "EW";
                    x--;
                }

                while (dX > x)
                {
                    result += "WE";
                    x++;
                }

                while (dY < y)
                {
                    result += "NS";
                    y--;
                }

                while (dY > y)
                {
                    result += "SN";
                    y++;
                }

                wl(String.Format("Case #{0}: {1}", iCase, result));
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
