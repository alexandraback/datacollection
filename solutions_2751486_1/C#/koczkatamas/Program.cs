using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace Round1C_A
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
                //if (iCase <= 2) continue;

                var parts = inLines[iLine + 0].Split(' ');
                var str = parts[0];
                var n = int.Parse(parts[1]);

                var L = str.Length;

                //var massalLens = new int[L];
                //var massalIns = new int[L];
                //var massalSum = new int[L];
                var plusCounts = new int[L];
                var lastPlusOffsets = new int[L];

                var result = 0;
                var plusCount = 0;
                var lastPlusOffset = 0;

                var massalLen = 0;
                for(int i = 0; i < L; i++)
                {
                    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
                        massalLen = 0;
                    else
                        massalLen++;

                    if (massalLen >= n)
                    {
                        var start = i - n + 1;
                        plusCount += (start - lastPlusOffset) + 1;
                        lastPlusOffset = i - n + 2;
                    }

                    plusCounts[i] = plusCount;
                    lastPlusOffsets[i] = lastPlusOffset;

                    result += plusCount;


                    /*massalLens[i] = massalLen;

                    if (massalLen >= n)
                        massalIns[i] = 1;

                    var x = i - massalLen + 1;
                    if (x >= 0 && massalLen >= n)
                        massalSum[x] = massalLen;*/
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

/*var massalResultAdd = new int[L];
var afterCounts = new int[L];
var beforeCounts = new int[L];
var startFroms = new int[L];

var result = 0;

var startFrom = 0;
for (int i = 0; i < L; i++)
{
    if (massalSum[i] != 0)
    {
        var len = massalSum[i];
        var selfPos = len - n + 1;

        for(var iS = 0; iS < selfPos; iS++)
        {
            var lettersAfter = L - i;
            var letterDoesNotCount = n - 1;

            var after = lettersAfter - letterDoesNotCount;
            var before = i - startFrom;

            afterCounts[i] = after;
            beforeCounts[i] = before;

            var resultAdd = before + after;
            massalResultAdd[i] = resultAdd;
            result += resultAdd;

            startFroms[i] = startFrom;
            startFrom = i + 1;
            i++;
        }
        i--;
    }
    else
    {
        massalResultAdd[i] = -1;
        afterCounts[i] = -1;
        beforeCounts[i] = -1;
        startFroms[i] = -1;
    }
}*/

